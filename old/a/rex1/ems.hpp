#ifndef EMS_HPP
#define EMS_HPP

# include <dos.h>

//these globals are used throughout the program
const  unsigned EMSInt = 0x67 ;
const  unsigned PageSize = 0x4000 ;
// first define  an often used inline function
inline  unsigned  EMSCall(unsigned  EMSCallNum , REGS   & reg)
{
	reg.h.ah = EMSCallNum ;
	int86(EMSInt,&reg,&reg) ;
	return   (unsigned)reg.h.ah ;
}
// prototype declarations for the EMS package
void  far *  EMSPresent() ;
void  far *  EMSSlotAddr(unsigned  SlotNum) ;
unsigned  EMSStatus() ;
unsigned  EMSPageCount() ;

//  the EMS class definition
class EMS {
	friend  void  far *  EMSPresent() ;
	friend  void  far *  EMSSlotAddr(unsigned) ;
private :
	unsigned  handle ;
	unsigned  noPages ;
public :
	static  unsigned frameSegment ;
	// allocate and unallocate the EMS handle
	EMS(unsigned  PageCount) ;
	~EMS() ;
	//map the memory area in
	unsigned  map(unsigned  page,unsigned  frameSlot) ;
	//check an object's status
	unsigned status() ;
} ;

#endif
