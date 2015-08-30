#ifndef STARTUP_HPP
#define STARTUP_HPP

#include"all.hpp"

#define startupProgram 	   int errorReportCls::noError = 0 ;\
		bool errorReportCls::unrecoverAbleError= false ;\
	  ofstream errorReportCls::fileError ;\
	  int  EmsArray::framesInUse[4] = { 0 , 0 , 0 , 0 } ;\
	  unsigned  EMS::frameSegment ;

#endif