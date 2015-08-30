#ifndef EXEFILE_HPP
#define EXEFILE_HPP
#include"all.hpp"
class  executeRexxCls;
//class execProcCls;
class executeFileRexxCls{
 containFileCls *objectFile;
 executeRexxCls *exRexx;
 bool exitStmtExecuted;
 variableValue resultVariable;
 int indexCurProcedure;
 execProcCls *curExeProc;
 stackOfCallFunctionCls socaf;
 int indexOfFindNameUp ;

void saveInStackFun(void);
void popOfStackFun(void);
public:
 stringCls getNameFile(void)
 {
  return objectFile->getName();
 }
 void getNameFile(char *p1)
 {
	objectFile->getNameFile(p1);
 }

 void getNameProc(char *p1)
 {
	 curExeProc->getNameProc(p1);
 }
  int getCurNoLine(void)
 {
	return curExeProc->getCurNoLine();
 }

 executeFileRexxCls(containFileCls * curF,executeRexxCls *er ,int iProc=0)
 { objectFile=curF ;indexCurProcedure=iProc;exRexx=er;
	curExeProc=new execProcCls(objectFile->getProc(indexCurProcedure),this);
	exitStmtExecuted=false;
	resultVariable=variableValue("");
	indexOfFindNameUp=0 ;
 }
 valBool callFunctionInThisFile(int i1,fCallContCls &);

 valBool run(void)
 { tokenContainCls to1;
  fCallContCls fcs12(to1);
  return curExeProc->run(fcs12);
 }
 void exitStmtDetect(void);
 valBool callFunction(fCallContCls &tt);
 void setGlobalResultVar(variableValue retVal);
 valBool findNameInUpFunc(stringCls &ltnameVar);
 void addNameInUpFunc(stringCls &ltnameVar,variableValue &vv1);
 valBool findNameArrInUpFunc(stringCls &nameString1);
 void addArrNameInUpFunc(stringCls &nameString,variableValue &);
};
#endif