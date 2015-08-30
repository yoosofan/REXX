#include"all.hpp"

valBool stackOfCallFunctionCls::getProcFindName(int indexOfFindNameUp,stringCls &ltName)
{
	 valBool ret1;
	 ret1.b=false;
	 execProcCls *ep1=NULL;
	 if(indexOfFindNameUp<noVInStack)
		 ep1=getiProc(indexOfFindNameUp);
	 if(ep1!= NULL)
		ret1=ep1->findName(ltName);
	 return ret1;
}
void stackOfCallFunctionCls::getProcAddName(int indexOfFindNameUp,stringCls &ltName,variableValue &vv1)
{	 execProcCls *ep1=NULL;
	 if(indexOfFindNameUp<noVInStack)
		 ep1=getiProc(indexOfFindNameUp);
	 if(ep1!= NULL)
		ep1->addVariable(ltName,vv1);
}
valBool stackOfCallFunctionCls::getProcArrName(int indexOfFindNameUp,stringCls &ltName)
{
  valBool ret1;
  ret1.b=false;
  execProcCls *ep1=NULL;
  if(indexOfFindNameUp<noVInStack)
	ep1=getiProc(indexOfFindNameUp);
  if(ep1!= NULL)
	ret1=ep1->findArr(ltName);
  return ret1;
}
void stackOfCallFunctionCls::getProcAddArrName(int indexOfFindNameUp,stringCls &ltName,variableValue &vv1)
{	 execProcCls *ep1=NULL;
	 if(indexOfFindNameUp<noVInStack)
		 ep1=getiProc(indexOfFindNameUp);
	 if(ep1!= NULL)
		ep1->addArrVar(ltName,vv1);
}

/*valBool stackOfCallFunctionCls::getProcFindStemName(int indexOfFindNameUp,stringCls &ltName)
{
	 valBool ret1;
	 ret1.b=false;
	 execProcCls *ep1=NULL;
	 if(indexOfFindNameUp<noVInStack)
		 ep1=getiProc(indexOfFindNameUp);
	 if(ep1!= NULL)
		ret1=ep1->findName(ltName);
	 return ret1;
}
void stackOfCallFunctionCls::getProcAddStemName(int indexOfFindNameUp,stringCls &ltName,variableValue &vv1)
{
	execProcCls *ep1=NULL;
	if(indexOfFindNameUp<noVInStack)
		 ep1=getiProc(indexOfFindNameUp);
	if(ep1!= NULL)
		ep1->addVariable(ltName,vv1);
}
*/
