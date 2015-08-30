#include"all.hpp"
bool parserCls::isValidName(EtokenType et1 )
{bool bb1 = false ;
 if( (et1 ==Name ) || (et1 == Array ) ) bb1= true ;
  return bb1 ;
}
bool parserCls::pullArgStmt(void)
{bool bb1= true  ;int i =0 ;
 EtokenType et1 ;initExpr();
 bool commaDetect = false ;
 for(;;)
 { getToken(); et1 = getTokenType()  ;
   if( isValidName(et1) )
   { i++;ecs.push(getCurToken());}
   else{bb1 =false;break ;}
   getToken();et1 = getTokenType();
   if( et1 == Comma )commaDetect = true;
   else{commaDetect = false ; break ;}
 }
 if(bb1)
 { if(!( (et1 == Semicolon) || (et1 == EndOfLine ) ))
   {bb1= false;errorPullArgParse(1);}
 }
 else if(commaDetect) errorPullArgParse(0);
 else errorPullArgParse(2);
 addExprToStmt(0);valInt[0]=i;noOfValInt=1;
 return bb1 ;
}
bool parserCls::ArgStmtParse(void)
{bool bb1= true  ;int i =0 ;
 EtokenType et1 ;initExpr();
 bool commaDetect = false ;
 for(;;)
 { getToken(); et1 = getTokenType()  ;
   if( isValidName(et1) )
   { i++;ecs.push(getCurToken());}
   else{bb1 =false;break ;}
   getToken();et1 = getTokenType();
   if( et1 == Comma )commaDetect = true;
   else{commaDetect = false ; break ;}
 }
 if(bb1)
 { if(!( (et1 == Semicolon) || (et1 == EndOfLine ) ))
	{bb1= false;errorPullArgParse(1);}
 }
 else if(commaDetect) errorPullArgParse(0);
 else errorPullArgParse(2);
 cpc->argList=getNewExprWithoutReverse();cpc->noOfArgList=i;
 return bb1 ;
}