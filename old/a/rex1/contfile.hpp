#ifndef CONTFILE_HPP
#define CONTFILE_HPP
#include"all.hpp"

class containFileCls {
  mapIntCls<containProcCls> cpcs;
  char nameOfFile[MAX_FILE_NAME];
  int index;
  void error(char *pp1){myDebugKey(1,pp1);exitProgram(0);}
 public:
  stringCls getName(void){return nameOfFile;}
  void addNameFile(char *p1){strcpy(nameOfFile,p1);}
  void getNameFile(char *p1){strcpy(p1,nameOfFile);}
  containFileCls(char *name){index=0;strcpy(nameOfFile,name);}
  void addProc(containProcCls *cp1)
  {cpcs[index++]=cp1;}
  containProcCls *getProc(int ii1)
  { if(ii1>=index)
		containFileCls:: error("access to undef proc in contfile.hpp ");
	 return cpcs[ii1] ;
  }
//  mapIntCls<stringCls> nameOfProcs;
 int  getSize(void)
 {	return cpcs.size();}
 void print(void);

};
#endif
