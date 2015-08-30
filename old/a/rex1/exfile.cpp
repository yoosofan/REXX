#include"all.hpp"
void executeFileRexxCls::exitStmtDetect(void)
{exitStmtExecuted=true;exRexx->exitStmtDetect();}
valBool executeFileRexxCls::callFunction(fCallContCls &tt)
{ valBool ret1;
  bool bb1 =false ;
  for(int i1=0;i1<objectFile->getSize() ;i1++)
	 if( objectFile->getProc(i1)->getName() == tt.getName())
	 {bb1=true;break;}
  ret1.b = bb1;
  if(bb1)
	 ret1=callFunctionInThisFile(i1,tt);
  else
	  ret1=exRexx->callFunction(tt);
  
  return ret1;
}
void executeFileRexxCls::setGlobalResultVar(variableValue retVal)
{resultVariable=retVal;exRexx->setGlobalResultVar(retVal); }

valBool executeFileRexxCls::callFunctionInThisFile(int i1,fCallContCls &tt12)
{
  valBool ret1;
  saveInStackFun();
  indexCurProcedure=i1;
  curExeProc=new execProcCls(objectFile->getProc(indexCurProcedure),this);
  ret1=curExeProc->run(tt12);
  delete curExeProc ;
  popOfStackFun();
  return ret1 ;
}

void executeFileRexxCls::saveInStackFun(void)
{
 savedInCallFunctionCls sd1(indexCurProcedure,curExeProc->getNameProc(),curExeProc,getNameFile());
 socaf.push(sd1);
}
void executeFileRexxCls::popOfStackFun(void)
{
 savedInCallFunctionCls sd1;
 sd1=socaf.pop();
 indexCurProcedure=sd1.getIndex();
 curExeProc=sd1.getProc();
}
valBool executeFileRexxCls::findNameInUpFunc(stringCls &ltnameVar)
{ valBool vb1;
 indexOfFindNameUp++ ;
 if(indexOfFindNameUp <=socaf.getSize())
	 vb1=socaf.getProcFindName(indexOfFindNameUp-1,ltnameVar);
 indexOfFindNameUp-- ;
 return vb1;
}
void executeFileRexxCls::addNameInUpFunc(stringCls &ltnameVar,variableValue &vv1)
{
 indexOfFindNameUp++ ;
  if(indexOfFindNameUp <=socaf.getSize())
	 socaf.getProcAddName(indexOfFindNameUp-1,ltnameVar,vv1);
 indexOfFindNameUp-- ;
}
valBool executeFileRexxCls::findNameArrInUpFunc(stringCls &nameString1)
{
 indexOfFindNameUp++ ;
 valBool xx;
 if(indexOfFindNameUp <=socaf.getSize())
	 xx=socaf.getProcArrName(indexOfFindNameUp-1,nameString1);
 indexOfFindNameUp-- ;
 return xx;
}
void executeFileRexxCls::addArrNameInUpFunc(stringCls &ltnameVar,variableValue &vv1)

{
 indexOfFindNameUp++ ;
  if(indexOfFindNameUp <=socaf.getSize())
	  socaf.getProcAddArrName(indexOfFindNameUp-1,ltnameVar,vv1);
 indexOfFindNameUp-- ;
}

