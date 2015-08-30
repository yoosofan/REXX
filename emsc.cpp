#include"ems.hpp"

EMS::EMS(unsigned pageCount)
{
	REGS  regs ;
	// first set to "none values"
	handle = 0xffff ;
	noPages = 0 ;

	//if EMS memory not present, give up now
	if( EMSPresent() == 0 )
		return ;
	//otherwise allocate that many from EMS handler
	regs.x.bx = pageCount ;
	if( EMSCall(0x43,regs) == 0 ) {  // if okay ...
		handle = regs.x.dx ;  // ... save handle
		noPages=pageCount ;
	}
}
EMS::~EMS()
{
	union  REGS  regs ;
	//give the EMS member back  ( if we have any )
	if((regs.x.dx = handle) != 0xffff)
		EMSCall(0x45,regs) ;

}
// amp the specified page into the specified frame slot
// return a 0 if succesful
unsigned  EMS::map(unsigned  page , unsigned  frameSlot)
{
	union  REGS  regs ;
	regs.x.bx = page ;
	regs.h.al = (char)frameSlot ;
	if( (regs.x.dx = handle) == 0xffff )
		return  0xffff ;
	return  EMSCall(0x44,regs) ;
}
unsigned  EMS::status()
{
	if( handle == 0xffff)
		//cout<<0xffff ;
		//getch() ;
		return  0xffff ;
	return  EMSStatus() ;
}
// -------- Implementation of the general functions ---------
// EMSPresent  -  return a 0 if EMS handler is present ;
//      otherwise, return the page frame address
void  far *  EMSPresent()
{
	REGS  regs ;
	SREGS  sregs ;
	const  char  EMSName[] = "EMMXXXX0" ;

	struct  EMSHandler {
		char  padding[0x0a] ;
		char  name[9] ;
	}  far *  EMSPtr ;

	// get the address of the EMS handler ( with 0 offset )
	regs.h.al = EMSInt ;
	regs.h.ah = 0x35 ;


	int86x(0x21,&regs,&regs,&sregs) ;
	//int86(0x21,&regs,&regs,&sregs) ;
	EMSPtr = ( EMSHandler  far * )MK_FP(sregs.es,0) ;

	// now check for the name of the EMS handler
	for(int i=0;i<8;i++)
		if( EMSPtr->name[i] != EMSName[i] )
			return  (void *) 0 ;
	// okay , it's there
	if( EMSCall(0x41,regs) )
		return  (void *) 0 ;
	EMS::frameSegment = regs.x.bx ;
	return  EMSSlotAddr(0) ; //return page frame addr
}
// EMSSlotAddr - given a frame slot number calculate its address.
void  far *  EMSSlotAddr(unsigned  slotnum)
{
	const  unsigned frameOffsets[] = {
		0x0000 , 0x4000 , 0x8000 , 0xC000
	} ;
	if(slotnum>3)
		return  0 ;
	return  MK_FP(EMS::frameSegment , frameOffsets[slotnum]) ;
}
// EMSStatus - return the status of the EMS handler
unsigned  EMSStatus()
{
	REGS  regs ;
	return  EMSCall(0x40,regs) ;
}
// EMS_pagecount - return unallocated page count
unsigned  EMSPageCount()
{
	REGS  regs ;
	if(EMSCall(0x42,regs))
		return  0 ;
	return  regs.x.bx ;
}

