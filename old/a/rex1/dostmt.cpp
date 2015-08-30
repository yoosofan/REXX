#include"all.hpp"
bool parserCls::doStmt(void){
 bool bb1=true,bb2=true,foundControlVar=false;
 tokenContainCls tcs1=getCurToken();exprContainCls *ce0,*ce1,*ce2,*ce3;
 int a1=noSourceLine,a2=0,a3=0;
  EtokenType tt2 ;
 EinstructionWord tt1 =ErrorInstr;
 getToken();
 noLoop ++ ;
 switch(getTokenType()){
	case While :
		tt1 = DoWhileInstr;
		bb1 = exprShould(tt1) ;
	break ;
	case Until:
		tt1=DoUntilInstr;
		bb1=exprShould(tt1);
	break ;
	case ForEver:
		tt1=DoForEverInstr ;
		getToken();
	break ;
	case For:
		tt1=DoForInstr;
		bb1 = exprShould(tt1) ;
	break ;
	case Semicolon :
	case EndOfLine :
	  tt1 = DoInstr ;
	  noLoop --;
	break ;
	default:
		tt1=DoToInstr;
		tt2=getTokenType();
	  tokenContainCls   tcs2=getCurToken() ;
	  if((tt2==Array)||(tt2==Name))
	  {
		 addControlVar(tcs2 );foundControlVar=true;
		 ce0=new exprContainCls(1);ce0->push(tcs2);getToken();
		 if(getTokenType() == Eq)
		  {
			bb2 = exprShould(DoToInstr);
			ce1 = getNewExpr();
		  }
		 else
		  {
			 bb2= false ;
			 errorDo(1, tcs1,  tcs2 );
			 foundControlVar=false;
			 popControlVar();
		  }
	  }
	  else
	  {
		 errorDo(2,tcs1,tcs2);
		 bb2=false;
	  }
	  if(bb2)
		if(getTokenType() == To )
		 {
			bb2 = exprShould(DoToInstr);
			ce2 =  getNewExpr();
		 }
		 else
		 {
			errorDo(2 , tcs1 , tcs2 ) ;
			bb2 = false ;
		 }
	  if(bb2)
		if(getTokenType() == By)
		{
		  bb2=exprShould(DoToByInstr);
		  tt1=DoToByInstr;
		  ce3=getNewExpr();
		}
 }
 if((tt1 == DoWhileInstr) || (tt1 == DoForInstr)||(tt1 == DoUntilInstr) )
	ce0=getNewExpr();
 bb1 = bb1 && bb2 ;  bool bb3=true ;
 if(bb1)   endWhiteLine();
 else      bb3 = syncStmtError();
 if(!bb3)  return false ;
 compoundStmt(tcs1,a2 ) ;/// if error not found show the error
 a3 = stmtNo ;
 if(foundControlVar) popControlVar();
 noLoop--; initEiwCss(tt1) ;
 if((tt1==DoWhileInstr)||(tt1==DoUntilInstr)||(tt1==DoForInstr))
	addExprToStmt(ce0,0);
 else if((tt1 == DoInstr)||(tt1==DoForEverInstr))
  {if(tt1 == DoInstr )	 noLoop ++ ;}
 else if( (tt1 == DoToInstr ) || (tt1 == DoToByInstr) )
 {addExprToStmt(ce0,0); addExprToStmt(ce1,1);addExprToStmt(ce2,2);
  if(tt1 == DoToByInstr ) addExprToStmt(ce3,3);
 }
 valInt[0] = a1 ;valInt[1] = a2 -1;valInt[2] = a3;noOfValInt=3;
 return bb1  ;
}