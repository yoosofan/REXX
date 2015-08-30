#ifndef STACKFUN_HPP
#define STACKFUN_HPP

#include"all.hpp"

class execProcCls ;
class stringCls;
class savedInCallFunctionCls{
	int indexProc;
	stringCls nameProc;
	execProcCls *exeProc;
	stringCls nameFile;

 public:
  int getIndex(void){return indexProc;}
  execProcCls *getProc(void){ return exeProc;};
  stringCls getNameFile(void){return nameFile;}
  stringCls getNameProc(void){ return nameProc ;}
	savedInCallFunctionCls(int i1,stringCls n1,execProcCls *ep1,stringCls nf)
	{
	  indexProc=i1;
	  nameProc=n1;
	  exeProc=ep1;
	  nameFile=nf;
	}
	savedInCallFunctionCls( void)
	{
		indexProc=-1;
		exeProc=long(0);
	}
};
#include"stackcls.hpp"
class stackOfCallFunctionCls : public stackCls<savedInCallFunctionCls>{
  int noVInStack ;
  int maxVal;
  void error(char *pp1)
  {cout <<"maxVal is "<<maxVal<<endl; myDebugKey(noVInStack,pp1);exitProgram(0) ; }

 public :
  stackOfCallFunctionCls(int sz=MAX_NESTED_CALL_FUNCTION):stackCls<savedInCallFunctionCls>(sz)
  {noVInStack = 0 ; maxVal = sz ;}
  int getSize(void){return noVInStack;}
  void push(savedInCallFunctionCls v1)
  {
	  noVInStack++;
	  if(noVInStack < maxVal)
		Push(v1);
	  else
		error(" standard stack of function  overflow in STACKVAL.HPP" );
  }

  savedInCallFunctionCls pop(void)
  {
	 if(noVInStack)
		 noVInStack -- ;
	 else
	  error("standard stack of function underflow end of stack encounter in STACKVAL.HPP ");
	  return  Pop();
  }
  savedInCallFunctionCls top(void)
  {return  Top();}
  valBool getProcFindName(int indexOfFindNameUp,stringCls &ltName);
  void getProcAddName(int indexOfFindNameUp,stringCls &ltname,variableValue &vv1);
  valBool getProcArrName(int indexOfFindNameUp,stringCls &ltName);
  void getProcAddArrName(int indexOfFindNameUp,stringCls &ltName,variableValue &vv1);
//  valBool getProcFindStemName(int indexOfFindNameUp,stringCls &ltName);
//  void getProcAddStemName(int indexOfFindNameUp,stringCls &ltName,variableValue &vv1);

  execProcCls *getiProc(int indexOfFindNameUp)
  {
	 execProcCls *ep1=NULL;
	 if(indexOfFindNameUp<noVInStack)
		 ep1=getIndex(noVInStack-indexOfFindNameUp-1).getProc();
	 return ep1;
  }


};
#endif
