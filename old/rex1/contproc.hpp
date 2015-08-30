#ifndef CONTPROC_HPP
#define CONTPROC_HPP
#include"all.hpp"
class far fileParserCls ;
class containProcCls{
 int ncts,noExpose ;
 stringCls nameProc ;
 stringCls nameFile ;
 mapIntCls<stringCls> *listExpose ;
 EProcType eptProc;//{Function,Procedure,Label,ProcedureWithExpose};
 void operator=(containProcCls &);
 containPtocCls(containProcCls &) ;
 void error(int i1,char *p1)
 { myDebugKey(i1, p1);
	exitProgram(0);
 }
 void error(char *pp1)
 { myDebugKey(0,pp1);
	exitProgram(0);
 }
public:
 void initContProcImportant(void)
 {
  noExpose=0;listExpose=long(0);argList=NULL;noOfArgList=0;
  eptProc=FunctionType;
 }

 int getNoExpose(void){return noExpose;}
 stringCls getExpose(int i1)
 { if(!(i1>=0&&i1<noExpose))
	  error(i1,"get the invalid expose ");
	 return *(*listExpose)[i1];
 }

 stringCls getName(void){return nameProc;}
 void addNameFile(char *nn1){nameFile=nn1;}
 void addName(tokenContainCls &tt1){nameProc=tt1.nameVar;}
 void addName(char *tt1){nameProc=tt1;}
 void addListExpose(tokenContainCls pp1)
 {if(!listExpose)
	 listExpose=new mapIntCls<stringCls> ;
  stringCls  *pp2=new stringCls;*pp2=pp1.nameVar;
  (*listExpose)[noExpose++]=pp2;
 }
 void addProcType(EProcType e1){eptProc=e1;}

 mapIntCls<containStmtCls> ccs ;
 exprContainCls *argList;

 int noOfArgList;
 stringCls getArg(int ii1)
 {
	if(argList == NULL)
	 error("ahmad PROGRAMMER ERROR  argList is empty fetch it ?????????????");
	return argList->geti(ii1).nameVar;
 }
 containProcCls(void)
 {
 initContProcImportant();
  eptProc=FunctionType;
 }
  ~containProcCls(void){}
 void setHead(containProcCls *nextProcSpecification)
 {
  nameProc=nextProcSpecification->nameProc;
  listExpose=nextProcSpecification->listExpose;
  eptProc=nextProcSpecification->eptProc;
  nameFile=nextProcSpecification->nameFile;
  noExpose=nextProcSpecification->noExpose;
 }
  void setExposeNull(void){listExpose=long(0);}
  int getSize(void) {return ccs.size();}
  void print(void);

};
#endif
