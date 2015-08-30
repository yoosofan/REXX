#ifndef ARREMS_HPP
#define ARREMS_HPP

# include <strstrea.h>
# include "ems.hpp"
# include<fstream.h>
//# include<conio.h>
#include<string.h>
#include<alloc.h>

//----------  Implementation of the EMS methods  ----------
//   ------------   use of EMSArray   ----------
// Implement a EMS_Virtual Array (similar to the file virtual array)
// Each subsequent array occupies its own single page frame slot so that
// up to a maximum of 4 arrays may be accomodated simultaneously .
#define DataBlock  char

//struct DataBlock ;
class  EmsArray {
	unsigned  emsStatus ;
	int  frameSlot ;
	char  far *  slotAddr ;
	unsigned  currentPage ;
	EMS *  ems ;
	long  noBlocks ;
	unsigned  blockSize ;
	unsigned  noPages ;
	static  int framesInUse[4] ;
	void  operator & (EmsArray &  v)  { }  // grant no access
public :
	enum  EmsStatus {
		okay = 0 , noEMSDriver ,
		noFreeSlot , notEnoughEMS ,
		EMSFailure , outOfRange ,
		uninitialized , readFail
	} ;
	EmsArray(long  no_blocks , unsigned  block_size) ;
	~EmsArray() ;
	DataBlock &  operator[](long  blockNum) ;
	unsigned  status() ;
} ;
#endif
