#include"all.hpp"
extern int debugKeyStart ;
extern outputRexx out1;
bool isOperator(EtokenType ettt1)
{ bool bb1 = true ;
  switch(ettt1)
  {
    case And:case Or:case ExOr:case ExEq:case Eq:case Lt:case Gt:case Ge:
    case Le: case Ne:case Concat :case Plus :
    case Minus :case Mul:case Div: case Mod :case  Pow:break ;
    default : bb1 = false ;break;
  }
  return bb1;
}
variableValue   exprCls::term(void)
{ variableValue s1,s2;EtokenType et1;bool bb3 =true;int ii11;
  if(factor()>1){
	 while(notExprEnd()&& bb3){
		et1=getTokenType(); bb3 = true;
		do{
	if(isOperator(et1))
	{s2 =stack.pop();s1=stack.pop();}
	switch(et1)
	{ case And:	s1 = s1 &&s2 ;		break;
	  case Or:s1 =   s1 || s2 ;	        break ;
	  case ExOr:s1 = s1 ^ s2 ;             break;
	  case ExEq:s1 =((s1==s2)) ;          break;
	  case Eq:  s1 =(s1==s2);             break;
	  case Lt:  s1 = (s1 < s2 );          break ;
	  case Gt: s1 = (s1 > s2 );            break;
	  case Ge: s1 = (s1>=s2);              break;
	  case Le: s1 = (s1<=s2);              break;
	  case Ne: s1 = (s1!=s2);	        break;
	  case Concat : s1 =s1.concat(s2);     break ;
	  case Plus : s1 = s1+s2;              break ;
	  case Minus :	 s1 = s1- s2 ;          break;
	  case Mul:	 s1 = s1*s2;            break ;
	  case Div:	 s1 = s1/s2 ;           break ;
	  case Mod : s1 = s1.mod(s2);          break;
	  case  Pow: s1 = s1.pow(s2);          break ;
	  default :	 bb3 = false ;          break;
	}
	if(bb3)
	{ getToken();et1 = getTokenType();
	  switch(et1)
	  { case UnaryMinus:getToken(); s1 = -s1 ; break ;
	    case UnaryPlus: getToken();   break ;
	    case Not: getToken();s1 = !s1;break;
	  }
	  stack.push(s1);
	}
	et1=getTokenType();
      }while(bb3 && isOperator(et1) );
      factor();
  }
 }
 s1 = stack.pop();
 return s1;
}
int exprCls::factor(void)
{
 EtokenType lTt1 = getTokenType();
 tokenContainCls lTc1 =getCurToken();

 variableValue s1;int ii1=0;


 do{
	  switch(lTt1){
	  case OrdNumber:s1=(variableValue)getNumber();getToken();
		 factorFound=true;ii1 ++;
	  break ;
	  case String :s1=(variableValue)lTc1.nameVar;getToken();
		 factorFound=true;ii1 ++;
	  break ;
	  case Array :s1=findArrayVal();getToken();
		 factorFound=true;ii1 ++;
	  break ;
	  case Name :s1=findName();getToken();factorFound = true;ii1 ++;break ;
	  case FunctionName: s1=callFunction();factorFound = true;ii1 ++;
	  break ;
	  default: factorFound = false ; break;
	}
	lTt1 = getTokenType();
	bool bb3 = false ;
	if(factorFound)
	 switch(lTt1){
	  case UnaryMinus:bb3 = true; s1 = -s1 ; break ;
	  case UnaryPlus: bb3 = true;// check the error of number
	  break ;
	  case Not: bb3 = true;s1 = !s1;break;
	 }
	if(bb3)  getToken();
	if(factorFound)   stack.push(s1);
	lTt1 = getTokenType();
 }while(factorFound);
/* lTc1 =getCurToken();
  out1<<" s1   " << lTc1 <<"\n";
 out1 << " ii1  " << ii1 << "\n" ;
  */
  return ii1 ;
}
variableValue exprCls::findName(void)
{tokenContainCls lt=getCurToken();valBool v1=epc->findName(lt.nameVar);
 if(v1.b ==false )
 {variableValue vv11( lt.nameVar);v1.val =vv11;}
 return v1.val ;
}
NUMBERfORM exprCls::getNumber(void)
{NUMBERfORM dd1 = getCurToken().d;return dd1 ;}
variableValue exprCls::findArrayVal(void)
{tokenContainCls lt= getCurToken();valBool v1 = epc->findArr(lt.nameVar) ;
 return v1.val ;
}
variableValue exprCls::callFunction(void)
{
 tokenContainCls etc11 = getCurToken();fCallContCls v1(etc11);
 EtokenType  lt1;getToken();int ii = getCurToken().d ;
 if(ii)
	do{
		getToken();v1.addArg(term()) ;lt1= getTokenType();
	}while((lt1==Comma));
getToken(); //fetch the ) from exp
//v1.setLine(etc11.line);
return (epc -> callFunction(v1) );
}
variableValue   exprCls::exprssion(exprContainCls *e1)
{init(e1);variableValue  v1=term();
/// check the stack  is empty and the expr is end
return v1;
}
