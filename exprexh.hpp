#ifndef EXPREXE_HPP
#define EXPREXE_HPP
#include"all.hpp"
class stackOfValExpr ;
class execProcCls ;
//global ------- errorExeCls exErC;
//extern errorExeCls exErC
class exprCls {
  execProcCls *epc ;exprContainCls *ecc;
   int indexToken;bool factorFound ;stackOfValExpr stack ;
   tokenContainCls tempToken ;
   bool notExprEnd(void)
   { bool bb1 = false ;
     if(indexToken>=0)    bb1 = true ;
     return bb1 ;
   }
   int  factor(void);variableValue findName(void);
   variableValue recursiveLparen(void);
   void   exprCls::error(int ii1)
   {myDebugKey(1, " run time error in exprexe.hpp     exprCls::error " );
	  exitProgram(0);
   }
   NUMBERfORM exprCls::getNumber(void);
   variableValue findArrayVal(void);
   variableValue callFunction(void);
      variableValue   term(void);

  public:
   variableValue  exprssion(exprContainCls *e1);
   exprCls(execProcCls *e1):tempToken(Rparen,0,0)
   {epc=e1;stack.init();indexToken=ecc->size()-1; }
   void init(exprContainCls *e1)
   {stack.init();ecc=e1;if(ecc) indexToken=ecc->size()-1;else indexToken =-1; }
    int  getToken(void)// the first call for second token
    // defferent from parser section
    //{ ecc->pop();}
    {--indexToken; return indexToken;}
    tokenContainCls getCurToken(void)
    {if(notExprEnd())  return ecc->geti(indexToken);
      else     {return tempToken;}
    }
    EtokenType getTokenType(void)
    { if(notExprEnd()) return ecc->geti(indexToken).type ;
       else      return Rparen;
    }

};
#endif