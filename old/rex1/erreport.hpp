#ifndef ERREPORT_HPP
#define ERREPORT_HPP

#include"global.hpp"
#include<fstream.h>

class errorReportCls {
public:
	 static int noError ;
	 static bool unrecoverAbleError ;
//    static outputCls oc ;   any ou put function to this class and
////////////////// this class should be give only (char *) and display it.
//    static dataBaseFile errordbf ;
	static int loadFileError(void);
	static int errorReportCls::deleteFileError(void);
	static ofstream  fileError; // report of all error in this file

	  errorReportCls(EerrorType e1 , char *name) ;
//	  errorReportCls(EerrorType  e1,char * n1, int *n2) ;
	  errorReportCls(void){}
	 void  report(EerrorType  e1,char * n1, int *n2,char *line1) ;
 //       ostream& operator<<(ostream &) ;
	  void unrecover(void) {errorReportCls::unrecoverAbleError = true ;return ;}
	  // and other need ed function
};

#endif
