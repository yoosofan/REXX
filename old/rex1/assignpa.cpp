#include"all.hpp"
bool parserCls::assignmentStmt( tokenContainCls &tc7 )
{bool bb1;exprContainCls *ed1=new exprContainCls(2);ed1->push(tc7);//ed1->print();myDebugKey(1,"in asss ");
 getToken();bb1=exprssion();
 if(bb1)
 { if(noTokenInExpr)
   { addExprToStmt(1) ;initEiwCss(AssignInstr) ;
 //    myDebugKey(1,"in assssssss ");
     addExprToStmt(0,ed1);bb1=endWhiteLine();
    }
   else{errorAssign(tc7);bb1 = false ;}
  }
  if(!bb1) initEiwCss( ErrorInstr );
  
  return bb1   ;
}