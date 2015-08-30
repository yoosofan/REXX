#ifndef STACKVAL_HPP
#define SATCKVAL_HPP

//#include<classlib/stacks.h>

//  source of        TStackAsVector<variableValue>   in
//#include<\classlib\stacks.h>
#include"stackcls.hpp"
// ifdef tc3
//#define TStackAsVector  BI_StackAsVector
//#include"allexe.hpp"
class variableValue ;

//class stackOfValExpr : public  TStackAsVector<variableValue> {
class stackOfValExpr : public  stackCls<variableValue> {
  int noVInStack ;
  int maxVal;
  void error(char *pp1)
  {cout <<"maxVal is "<<maxVal<<endl; myDebugKey(noVInStack,pp1);exitProgram(0) ; }

 public :
//  stackOfValExpr(void):TStackAsVector<variableValue>(20)
 stackOfValExpr(void):stackCls<variableValue>(29)
  {noVInStack = 0 ; maxVal = 29 ;}
  void push(variableValue  v1)
  {
	  noVInStack++;
//	  myDebugKey(noVInStack , " stack v in push==");
	  if(noVInStack < maxVal)
		Push(v1);
	  else
	    error(" standard stack of exprssion overflow in STACKVAL.HPP" );
  }
  variableValue pop(void)
  {
    if(noVInStack)
		 noVInStack -- ;
    else
     error("standard stack of exprssion underflow end of stack encounter in STACKVAL.HPP ");
//	  myDebugKey(noVInStack , " stack v in pop ==");
	  return  Pop();
   }
   variableValue top(void)
   {		 return  Top();}
   void init(void)
   {noVInStack=0;stackCls<variableValue>::init();}
};
#endif