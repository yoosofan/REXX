#include"all.hpp"
//#include<alloc.h>

#include<malloc.h>
bool parserCls::exprStmt(void )
{bool bb1 ;initExpr();bb1 = exprssion() ;
 if(bb1)
 { initEiwCss(ExprInstr);addExprToStmt(0);
   initEiwCss(ExprInstr);bb1=endWhiteLine();
 }
 if(!bb1) initEiwCss( ErrorInstr );
 return bb1 ;
}
void parserCls::initExpr(void){ecs.clear();}
bool parserCls::exprShould(EinstructionWord t1 )
{tokenContainCls tcs1= getCurToken();initExpr();getToken();
 bool bb1=exprssion();
 if(bb1)if(!noTokenInExpr){exprShouldError(tcs1,t1);bb1=false;}
 return bb1 ;
}
bool parserCls::exprssion(void)
{exprFound=false;needOperand=false;exprErrorFlag=false;
 noTokenInExpr = 0 ; term1();
 if(exprErrorFlag)
	return false;
 return  true;;
}
bool   parserCls::term1(void)
{ bool s1 = term2();
  if(s1==false) return false ;
  EtokenType et1=getTokenType();tokenContainCls t1 ;
  while( (et1== And )||(et1 == Or )|| (et1 == ExOr))
  {
	  t1 =getCurToken();getToken();bool s2 = term2();
	  if(s2==false) return false ;
	  addOperator(t1);et1 = getTokenType();
  }
  return  s1 ;
}
bool   parserCls::term2(void)
{  bool s1 = term3();if(s1==false) return false ;
   EtokenType et1=getTokenType();tokenContainCls t1 ;
   if((et1==ExEq)||(et1==Ne)||(et1==Ge)||(et1==Le)||
	  (et1==Gt)||(et1==Lt)||(et1==Eq)  )
   {   t1=getCurToken();getToken();bool s2 = term3();
       if(s2==false)	 return false ;
       addOperator(t1);et1 = getTokenType();
   }
   return  s1 ;
}
bool   parserCls::term3(void)
{ bool s1 = term4();if(s1==false) return false ;
  EtokenType et1 =  getTokenType();tokenContainCls t1 ;
  while( (et1== Concat ) )
  {  t1 =getCurToken();getToken();bool s2 = term4();
     if(s2==false) return false ;
     addOperator(t1);
	  et1 = getTokenType();
  }
  return  s1 ;
}
bool   parserCls::term4(void)
{  bool s1 = term5();if(s1==false) return false ;
   EtokenType et1 =  getTokenType();
   tokenContainCls t1 ;
   while( (et1== Plus )||(et1 == Minus ) )
   { t1 =getCurToken(); getToken();bool s2 = term5();
     if(s2==false) return false ;
     addOperator(t1); et1 = getTokenType();
   }
   return  s1 ;
}
bool   parserCls::term5(void)
{  bool s1 = term6();if(s1==false) return false ;
   EtokenType et1 =  getTokenType();tokenContainCls t1 ;
   while( (et1== Mul )||(et1 == Div )|| (et1 == Mod))
   { t1 =getCurToken();getToken();bool s2 = term6();
	  if(s2==false)	 return false ;
     addOperator(t1);et1 = getTokenType();
   }
   return  s1 ;
}
bool   parserCls::term6(void)
{ bool s1 = factor();if(s1==false) return false ;
  EtokenType et1 =  getTokenType();tokenContainCls t1 ;
  if(et1== Pow)
  { t1 =getCurToken(); getToken(); bool s2 = factor();
	 if(s2==false) return false ;
	 addOperator(t1); et1 = getTokenType();
  }
  return  s1 ;
}
bool  parserCls::factor(void)
{ EtokenType lTt1 = getTokenType();bool bb1 = true ;
  tokenContainCls lTc1 =getCurToken() ,lTc2;bool seeUnary= false;


  if( (lTt1 == Plus) || (lTt1==Minus) || (lTt1 == Not) )
  { if(lTt1== Plus)	 lTc1.type = UnaryPlus;
	 else if(lTt1== Minus) lTc1 . type = UnaryMinus;
	 lTc2=lTc1;getToken();lTt1=getTokenType();
	 lTc1=getCurToken();seeUnary=true;
  }
  switch(lTt1){
	 case OrdNumber:case SciNumber:case Array :
	addOperand() ;exprFound = true ;needOperand = false ;getToken();
	 break ;
	 case String :
		 if(seeUnary)
	 {errorUnary(lTc2 ,1);bb1 = false;break ;}
		 addOperand();exprFound=true;needOperand=false ;getToken();
	 break ;
	 case Name : exprFound = true ;needOperand=false;getToken();
	if(getTokenType() == Lparen ) bb1=addFunction(lTc1);
	else   addName(lTc1) ;
	 break ;
	 case Lparen :recursiveLparen() ;break ;
	 case Rparen :if(seeUnary)
		 {errorUnary(lTc2 , 2);bb1 = false ;break ;}
	 break ;
	 default :if(needOperand)	 errorFactor();
	  bb1 = false ;
	 break ;
  }
  if(seeUnary && bb1)	addOperator(lTc2);
  return bb1 ;
}
/// fa+b,c+d)
/// f is the name of function
// one error not checked f(a,,b)
bool parserCls::addFunction(tokenContainCls &lTc1)
{ lTc1.type = FunctionName; addOperand(lTc1);bool bb2 = true ;
  bool bb3=false;EtokenType  lt1;int iiExpr12=0,indexX=noTokenInExpr++;
  addOperand(lTc1); // for stack for change after end
 do{ if(bb3)	addOperand();
	  else 	 bb3 = true ;

	  getToken();// get next token after (
	  if(!term1() ){ bb2 = false   ;break ;}
	  if((noTokenInExpr-2) > (indexX))
			iiExpr12++;
	  lt1= getTokenType();
 }while((lt1==Comma));
 if(bb2) if(lt1 != Rparen)
	 {bb2 = false; errorRecursLparen(1, lTc1);}
 else {addOperator();getToken();}
 tokenContainCls lTc2(iiExpr12,1);
  addOperator(indexX, lTc2);
 return bb2 ;
}
void parserCls::recursiveLparen(void)
{tokenContainCls tc1=getCurToken();//save the Lparen token for error Reprot
 int curNoTok1 = noTokenInExpr;	getToken();// get next token after (
 if(term1() )
 { EtokenType  lt1= getTokenType();
	if(lt1 != Rparen) errorRecursLparen(1, tc1);
	else if(noTokenInExpr-curNoTok1 == 0) errorRecursLparen(0, tc1);
	else	getToken();
 }
}