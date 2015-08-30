#include"all.hpp"
// use function  map::clear   for  free the previouse object

EtokenType ordList[][8] = { { And , Or , ExOr ,NULL} ,
				 { ExEq, Ne , Ge , Le , NULL} ,
				 { Eq , Lt , Gt , NULL },
				 { Concat , NULL } ,
				 { Plus , Minus , NULL } ,
				 { Mul , Div , Mod , NULL} ,
				 { Pow , NULL} ,
				 { Not , Minus , Plus , NULL }
			  };
bool parserCls::exprStmt(void )
{
 bool bb1 ;
 ecs.clear();


 bb1 = exprssion() ;
 if(bb1)
  {  css.ecs[0] = ecs ;
	  css.eiw = ExprInstr ;
	  bb1 =  endWhiteLine();
  }

  if(!bb1)
	  css.eiw = ErrorInstr ;
 return bb1 ;
}

bool parserCls::exprShould(EinstructionWord t1 )
{
 tokenContainCls tcs1= getCurToken();
 getToken();

/*//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

 char pp1[200] ;
 curToken.nameVar.get_p(pp1);
 char *p1= "in exprShould the name of variable=====";
 char pp2[200];
 pp2[0]='\0';
 strcat(pp2 ,p1);
 strcat(pp2 ,pp1);
 myDebugKey(1,pp2);

 ////////////////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////


 bool bb1 = exprssion();
 if(bb1)
	  if(!noTokenInExpr)
	  {
		exprShouldError(tcs1, t1);
		bb1 = false ;
	  }
 return bb1 ;
}



bool parserCls::exprssion(void)
{
 exprFound =false ;
 needOperand = false ;
 exprErrorFlag = false ;
 noTokenInExpr = 0 ;
 term();
 return  !exprErrorFlag;
}

bool parserCls::term(void)
{
  do{
		do{
			do{
				 do{
					  do{
							do{
								 do{
									  contExpr(7) ;
									  if(!factor() )
											return false ;
									 }while(contExpr(6) );
							  }while(contExpr(5) ) ;
						 }while(contExpr(4) ) ;
					}while(contExpr(3) ) ;
			  }while(contExpr(2) ) ;
		  } while(contExpr(1) ) ;
	 }while (contExpr(0) ) ;
  return true ;
}




































bool   parserCls::contExpr(int ii1)
{
 bool b2 = !exprErrorFlag ;
 if(b2)
 {
	 if(tokenInExpr(ii1))
	 {
		b2 =true ;
		addOperator();
		getToken() ;
		needOperand = true ;
		noTokenInExpr++;
	 }
	 else
		b2 = false ;
 }
	return b2 ;
}

bool parserCls::tokenInExpr(int ii1 )
{
  EtokenType  t1 = getTokenType();
	 for(EtokenType *tte1 = ordList[ii1] ; *tte1 ; tte1++)
		  if(t1 == *tte1)
			  return true ;
  return false ;
}

bool  parserCls::factor(void)
{
  EtokenType lTt1 = getTokenType();
  bool bb1 = true ;
  tokenContainCls lTc1 =getCurToken();

  switch(lTt1)
  {
	 case OrdNumber:
	 case SciNumber:
	 case String :
	 case Array :
		  addOperand() ;

		  exprFound = true ;
		  needOperand = false ;
		noTokenInExpr++;

		  getToken();
	 break ;
	 case Name :

		 exprFound = true ;
		 needOperand = false ;
		 noTokenInExpr++;
		 getToken();
		 if(getTokenType() == Lparen )
			addFunction(lTc1);
		 else
			 addName(lTc1) ;
	 break ;
	 case Lparen :
		addOperator() ;
		recursiveLparen() ;
	 break ;
	 case Rparen :

	 break ;
	 default :
		if(needOperand)
			 errorFactor();
		 bb1 = false ;
	}
  return bb1 ;
}
