#include"all.hpp"
bool parserCls::ifStmt(void)
{bool bb1=true ;exprContainCls *ed1;EinstructionWord ew1=IfInstr;

 if(exprShould(IfInstr))
 { ed1 = getNewExpr();
	if(getTokenType() != Then){bb1=false;errorIfStmt(0);}
 }
 else {bb1= false ;errorIfStmt(1);}
 if(!bb1){
	 bool  bb2 = syncIfStmt();  // synch THEN if not found and ; or \n detected or endOfFile  return false
	 if(getTokenType() ==EndOfFile) return false ;
 }
 bool  etlnoc ; EinstructionWord est;getToken();
 callStmt(etlnoc,est);int afterIf=stmtNo;bb1=skipWhiteLine();
 if(getTokenType()== Else )
	{ew1=IfElseInstr ; getToken();callStmt(etlnoc , est);}
	noOfValInt=1;
 initEiwCss(ew1);valInt[0] = afterIf;
 addExprToStmt(ed1,0);
 if(ew1 != IfInstr){valInt[1] = stmtNo;noOfValInt=2;}
 return bb1;
}