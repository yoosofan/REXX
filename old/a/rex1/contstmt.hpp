#ifndef CONTSTMT_HPP
#define CONTSTMT_HPP
#include"all.hpp"
#include"exprcont.hpp"
extern ofstream outDebugError;
class containStmtCls  {
 friend class parserCls ;
// friend outDebugError& operator<<(outDebugError &aa1,containStmtCls &bb1);
  EinstructionWord   eiw ;int lineStmt ,noOfValInt,noEcs;
  mapIntCls <exprContainCls> ecs;
  int *valInt ;
  void operator=(containStmtCls &) ;
  containStmtCls(containStmtCls &);
  void error(int i,int j1)
  {
   if(i)
    myDebugKey(j1,"ahmad Programmer error in contstmt.hpp in getValInt loc is ");
   else
    myDebugKey(j1,"ahmad Programmer error in contstmt.hpp access to unexpected expr i is ");
   exitProgram(0);
  }
  void addValInt(int no,int *data);
 public:
  EinstructionWord getEiw(void){return eiw;}
  int getLine(void){return lineStmt;}
  int getNoOdVal(void){return lineStmt;}

  exprContainCls *  getExpr(int i)
  {if(!(i<ecs.size()))
	  containStmtCls::  error(0,i) ;
	 return ecs[i];
  }

  int getValInt(int loc)
  {
	  if(!(loc<noOfValInt))
		containStmtCls:: error(1,noOfValInt);
	  return valInt[loc];

  }

  containStmtCls(void)
  {eiw=NoInstr;noEcs=noOfValInt=lineStmt=0;valInt=(long)0;}
  int getNoExpr(void) ;
  void print(void);
  ~containStmtCls(void) {     }
/*  void clear(void)
  {valInt.clear();ecs.clear();eiw = NoInstr ;lineStmt = 0 ; }
*/
};
#endif