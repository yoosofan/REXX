#ifndef EXEREX_HPP
#define EXEREX_HPP
#include"all.hpp"
class executeRexxCls {
  int noOfInternalFunction;
  valBool *pointerOfInternalFunctions(fCallContCls &);
  executeFileRexxCls *curExeFile;
  containFileCls *curFile;
  variableValue resultVariable;
  mapIntCls<containFileCls> listOfFiles;
  map<stringCls,int> nameOfFiles;
  int indexFileExecute;
  int indexProcExecute;
  int noOfFileCompiled;
//  char nameFile[50];

 public:
  executeRexxCls( containFileCls *obFile)
  {
	curFile=obFile;
	curExeFile=new executeFileRexxCls(curFile,this);
	resultVariable=variableValue("");
	noOfInternalFunction = 20;
	indexFileExecute=0;
	indexProcExecute=0;
	nameOfFiles[obFile->getName()]=0;
	listOfFiles[0]=obFile;
	noOfFileCompiled=1;
  }
  valBool run(void)
  { return curExeFile->run(); }
  void exitStmtDetect(void)
  {exitProgram(0);}
 void setGlobalResultVar(variableValue retVal)
 {resultVariable=retVal;}
// return the index of internal function if not found return zero
  int isInternalFunction(fCallContCls &tt);
  valBool callFunction(fCallContCls &tt)
  { int localIndexInterFunction=0;
	 valBool retVal;
	if(localIndexInterFunction=isInternalFunction(tt) )
	 retVal=callInternalFunction(localIndexInterFunction,tt);
	else
	 retVal=callExternalFunction(tt);
	return retVal;
  }
 valBool callInternalFunction(int lif,fCallContCls &tt);
 valBool callExternalFunction(fCallContCls &tt);
 int isInListOfExternal(fCallContCls &tt);
valBool executeFile(int );
bool canOpenNewFile(fCallContCls &tt);
valBool parseAndExecuteNewFile(fCallContCls &tt);
 void getNameFile(char *p1)
 {
	curExeFile->getNameFile(p1);
 }
 void getNameProc(char *p1)
 {
  curExeFile->getNameProc(p1);
 }
 int getCurNoLine(void)
 {
	return curExeFile->getCurNoLine();
 }
};
#endif
