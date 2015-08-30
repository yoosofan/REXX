#include"all.hpp"
/* say only  exprssions
   EXAMPLE ::
      SAY hello ali ?
  *****************   ERROR *************************
     * NOT DEFINED CHARACTER SHOULD IN " " OR ' '

      SAY HELLO ALI '?'
     *CORRECT
*/
bool parserCls::sayStmt(void)
{int i = 0 ;bool bb1;initEiwCss( SayInstr);getToken();

 do{initExpr();bb1=exprssion();
   if(noTokenInExpr && bb1) addExprToStmt(i++) ;
 }while(noTokenInExpr && bb1 ) ;
 valInt[0] = i ;noOfValInt=1;
  return bb1 ;
}