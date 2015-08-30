#ifndef PROCPARS_HPP
#define PROCPARS_HPP
#include"all.hpp"
class fileParserCls:public parserCls{
	 containProcCls *curProc ,curProcSpecification ;
	 void addProcToFile(void);
//	 void changeHeadProc(void);
	 bool errorInFile ;
 public:
	 bool errorDetectFile(void)
	 { return bool(!errorInFile) ; }
	 containFileCls *curFile ;
	 fileParserCls(char *nameFile):parserCls(nameFile)
	 {errorInFile=false;curProc=long(0);curFile=long(0);}
	 ~fileParserCls(void){}
	// {delete curFile;}
//	{myDebugKey(1,"in ~scanner ercls ");}
	 void  fileParserCls::changeHeadProc(void);
	containFileCls *run(char *name1);
};
#endif
