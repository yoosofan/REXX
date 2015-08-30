#include"arrems.hpp"

//extern int  EmsArray::framesInUse[];
EmsArray::EmsArray(long  noBlks , unsigned  blockSz)
{
	// first make sure that EMS is even present
	frameSlot = -1 ;
	if( !EMSPresent() ) {

		emsStatus = noEMSDriver ;
		return ;
	}

	// find a free slot in the EMS page frame
	for(int i=0;i<4;i++)
		if( framesInUse[i] == 0 )
			frameSlot = i ;
	if( frameSlot == -1 )  {
		emsStatus = noFreeSlot ;
		return ;
	}
	framesInUse[frameSlot] = 1 ;
	slotAddr = (char  far *)EMSSlotAddr( frameSlot ) ;

	// calculate the number of pages
	blockSize = blockSz ;
	noBlocks = noBlks ;
	noPages = ((blockSize * noBlocks) + PageSize - 1)/PageSize ;
	currentPage = -1 ;

	// and then go allocate the necsssary EMS memory
	if(noPages > EMSPageCount()) {
		emsStatus = notEnoughEMS ;
		return ;
	}
	ems = new   EMS(noPages) ;
	emsStatus = okay ;
	if(ems->status()) {
		emsStatus = uninitialized ;
		framesInUse[frameSlot] = 0 ;
	}
}
EmsArray::~EmsArray()
{
	delete  ems ;  // restore the EMS memory
	framesInUse[frameSlot] = 0 ;  // free the page frame slot
	emsStatus = uninitialized ; // clear the status
}
// Status - simply return the last status
unsigned  EmsArray::status()
{
	return  emsStatus ;
}
// Operator [] - return the (address of the) record
DataBlock &  EmsArray::operator[](long  blockNum)
{
	// calculate the page within EMS
	// and the offset within the frame
	long  recordOffset = blockNum * blockSize ;
	unsigned  page = recordOffset / PageSize ;
	unsigned  pageOffset = recordOffset % PageSize ;

	// if this page is not already mapped in , map it
	emsStatus = okay ;
	if(page!=currentPage)
		if(page>noPages)
			emsStatus = outOfRange ;
		else if(ems->map(page,frameSlot))
			emsStatus = readFail ;

	// then return the address of the offset
	// within the page frame slot
	if( emsStatus == okay )
		currentPage = page ;
	return  (DataBlock  &)slotAddr[pageOffset] ;

}


