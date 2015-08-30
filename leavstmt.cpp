#include"all.hpp"
bool parserCls::leaveStmt(void)
{bool bb2= true;EtokenType ett2 ;int n1;exprContainCls *ed1;
 if(noLoop){
   getToken();
   if(((ett2=getTokenType())==Array)||(ett2==Name))
     if((n1= controlVarEntry.search(getCurToken().nameVar)))
     {valInt[0]=n1;ed1=new exprContainCls(1);ed1->push(getCurToken());
      addExprToStmt(ed1,0);initEiwCss(LeaveContInstr);getToken();
     }
     else{errorLeave(0) ;bb2 = false ;}
     else if(endWhiteLine()) initEiwCss(LeaveInstr);
     else{errorLeave(2); bb2 = false ;}
 }
 else{errorLeave(1) ;bb2 = false ;}
 if(bb2)
  if(!endWhiteLine() ) bb2=false;
 noOfValInt=1;
 return bb2 ;
}
