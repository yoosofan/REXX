#include"all.hpp"
#include<math.h>
// function error Should change next
extern int debugKeyStart ;
extern executeRexxCls *exr;

ostream& operator<<(ostream & os1 , variableValue &v1)
{if(v1 . tv == Str)os1 <<v1.s;
 else if(v1.tv == Real)	os1<< v1.d ;
 else	os1<<v1.b;
  return os1;
}
outputRexx& operator<<(outputRexx & os1, variableValue  v1)
{if(v1 . tv == Str)os1 <<v1.s;
 else if(v1.tv == Real)	os1<< v1.d ;
 else	os1<<v1.b;
 return os1;
}
variableValue::variableValue(variableValue const & v1)
{ tv=v1.tv ;
  if(v1.tv == Str)
  {s= new char[strlen(v1.s)+1];strcpy(s , v1.s) ;}
  else if(tv == Logic )	b=v1.b;
  else	d=v1.d;

}
void  variableValue::operator=(variableValue & v1)
{
 if(tv == Str)
 {  deleteStrVar();
	if(v1.tv==Str){tv=Str;s=new char[strlen(v1.s)+1];strcpy(s,v1.s) ;}
	else{tv =v1.tv ;
	if(tv == Logic )b=v1.b;
	else d=v1.d;
	}
 }
 else{tv =v1.tv ;
		if(tv == Logic ) b=v1.b;
		else if(tv ==Real )d=v1.d;
		else{s=new char[strlen(v1.s)+1];strcpy(s , v1.s) ;}
 }
//  if( heapcheck() == _HEAPCORRUPT )
//{   cout<< "Heap is corrupted.in value var .cpp operator=\n" ;exitProgram(1);}

}
void variableValue::conVal1(variableValue &v1)
{ char *pp1;
  switch(tv){
   case Str:
    if(v1.tv == Real)
    {convertNumber(v1.d , &pp1);v1.tv=Str;v1.s=pp1;}
    else if(v1.tv == Logic)
    {char cc1=v1.b;v1.tv=Str;v1.s=new char[2];v1.s[0]=cc1+'0';v1.s[1]=NULL;}
 break;
 case Real:
    if(v1.tv == Str)
    { convertNumber(d , &pp1);
		tv=Str;
      s=pp1 ;
    }
    else if(v1.tv ==  Logic)
    {
		int ii1 =v1.b ;
      v1.d=ii1 ;
      v1.tv=Real ;
    }
 break;
 case Logic:
      if(v1.tv == Real)
      {
	 int ii1=b ;
	 d=ii1;
	 tv=Real ;
      }
      else  if( v1.tv == Str)
      { char cc1=b;
	tv=Str ;
	s=new char[2];
	s[0]=cc1+'0' ;
	s[1]='\0' ;
       }
  break;
 }
}
/*
variableValue variableValue::operator==(variableValue &v1)
{
 variableValue b1=( variableValue)false ;
 conVal1(v1);
 switch(tv)
 {
	  case  Str:
	  if(!strcmp(s, v1.s) )
		  b1=( variableValue)true ;
	  break;
	  case Real:
		 if(d == v1.d)
			b1 =( variableValue) true;
	  break;
	  case  Logic:
	  if(b == v1.b)
		  b1 =( variableValue) true ;
	  break;
 }
//  myDebug(v1 , "==");
//  myDebugResult(b1 );
  return b1;
}
*/
bool variableValue::operator==(variableValue &v1)
{
 bool b1=false ;
 conVal1(v1);
 switch(tv)
 {
	  case  Str:
	  if(!strcmp(s, v1.s) )
		  b1=true ;
	  break;
	  case Real:
		 if(d == v1.d)
			b1 = true;
	  break;
	  case  Logic:
	  if(b == v1.b)
		  b1 = true ;
	  break;
 }
//  myDebug(v1 , "==");
//  myDebugResult(b1 );
  return b1;
}

variableValue variableValue :: operator<=(variableValue &v1)
{
 variableValue b1=(variableValue)false ;
 conVal1(v1);
 switch(tv)
 {
	  case  Str:
	  if(ahmadStrcmp(s, v1.s)<=0 )
	      b1=(variableValue)true ;
	  break;
	  case Real:
	     if(d <= v1.d)
		  b1=(variableValue)true;
	  break;
	  case  Logic:
	  if(b <= v1.b)
		  b1=(variableValue)true ;
	  break;
 }
//	myDebug(v1 , "<=");
//	myDebugResult(b1 );
  return b1;
}


variableValue variableValue :: operator>=(variableValue &v1)
{
 variableValue b1 =(variableValue)false ;
 conVal1(v1);
 checkEqOfTv(v1," >= ");
 switch(tv)
 {
    case  Str:
	  if(ahmadStrcmp(s, v1.s) >= 0 )
       b1=(variableValue)true ;
    break;
    case Real:
      if(d >= v1.d)
	  b1=(variableValue)true;
    break;
    case  Logic:
      if(b >= v1.b)
	  b1=(variableValue)true ;
    break;
 }
// myDebug(v1 , ">=");
// myDebugResult(b1 );
 return b1;
}

variableValue variableValue :: operator!=(variableValue &v1)
{
 variableValue b1 =(variableValue)false ;
 conVal1(v1);
 checkEqOfTv(v1," != ");
 switch(tv)
 {
	  case  Str:
	  if(ahmadStrcmp(s, v1.s) )
			 b1=(variableValue)true ;
	  break;
	  case Real:
	      if(d != v1.d)
		  b1=(variableValue)true;
	  break;
	  case  Logic:
	  if(b != v1.b)
		  b1=(variableValue)true ;
	  break;
 }
//	myDebug(v1 , "!=");
//	myDebugResult(b1 );

  return b1;
}

variableValue variableValue :: operator>(variableValue &v1)
{
 variableValue b1 =(variableValue)false ;
 conVal1(v1);
  checkEqOfTv(v1," > ");
 switch(tv)
 {
	  case  Str:
	  if(ahmadStrcmp(s, v1.s) > 0 )
			 b1=(variableValue)true ;
	  break;
	  case Real:
	       if(d > v1.d)
		  b1=(variableValue)true;
	  break;
	  case  Logic:
	  if(b > v1.b)
		  b1=(variableValue)true ;
	  break;
 }
//	 myDebug(v1 , ">");
//	 myDebugResult(b1 );
  return b1;
}

bool variableValue :: operator<(variableValue &v1)
{
 bool   b1 =false ;
 conVal1(v1);
  checkEqOfTv(v1," < ");
 switch(tv)
 {
	  case  Str:
	  if(ahmadStrcmp(s, v1.s) < 0)
			 b1=true ;
	  break;
	  case Real:
			 if(d < v1.d)
		  b1=true;
	  break;
	  case  Logic:
	  if(b < v1.b)
		  b1=true ;
	  break;
 }
//	myDebug(v1 , "<");
//	myDebugResult(b1 );
  return b1;
}

void variableValue::conVal2(variableValue &v1)
{
 char *pp1;
 NUMBERfORM d1 ;
 switch(tv)
 {
   case Str:
    d1=convertToNumber(s);
	 deleteStrVar();
	 tv=Real ;
    d=d1 ;
    if(v1.tv == Str)
    {
      d1=convertToNumber(v1.s);
		deleteStrVar(v1);
		v1.tv=Real ;
      v1.d =d1 ;
    }
    else if(v1.tv == Logic)
    { int  cc1=v1.b;
      v1.tv=Real ;
      v1.d=cc1 ;
    }
 break;
 case Real:
	if(v1.tv == Str)
	{
	  d1=convertToNumber(v1.s);
	  deleteStrVar(v1);
	  v1.tv=Real ;
	  v1.d=d1;
	}
	else if(v1.tv ==Logic)
	{
	  int ii1 =v1.b ;
	  v1.d=ii1 ;
	  v1.tv=Real ;
	}
 break;
 case Logic:
	 d=v1.b ;
	 tv=Real ;
	 if(v1.tv == Str)
	 {
	   d1=convertToNumber(v1.s);
		deleteStrVar(v1);
		v1.tv=Real ;
	   v1.d=d1;
	 }
	 else if(v1.tv ==Logic)
	 {
	  int ii1 =v1.b ;
	  v1.d=ii1 ;
	  v1.tv=Real ;
	 }
  break;
 }

}

variableValue variableValue::operator+(variableValue &v1)
{ conVal2(v1);
  checkEqOfTv(v1," + ");
// myDebug(v1 , "+");
 variableValue v2 =(NUMBERfORM) (d + v1.d);
// myDebugResult(v2 );
 return (v2);
}

variableValue  variableValue::operator-(variableValue &v1)
{
 conVal2(v1);checkEqOfTv(v1," - ");
//  myDebug(v1 , "-");
  variableValue v2 =(NUMBERfORM) (d - v1.d);
// myDebugResult(v2);
 return (v2);
}

variableValue variableValue::operator*(variableValue &v1)
{
 conVal2(v1);checkEqOfTv(v1," * ");
// myDebug(v1 , "*");
 variableValue v2 =(NUMBERfORM)( d * v1.d);
//  myDebugResult(v2 );
 return (v2);
}
/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
variableValue variableValue::operator/(variableValue &v1)
{
 conVal2(v1);checkEqOfTv(v1," /");
 if(v1.d == 0 )
	error(1);
// myDebug(v1 , "/");
  variableValue v2 =(NUMBERfORM)(d / v1.d) ;
// myDebugResult(v2 );
 return (v2);
}

variableValue variableValue::mod(variableValue &v1)
{
 conVal2(v1);checkEqOfTv(v1," mod ");
 if(isZeroD(v1) )
	error(2);
// myDebug(v1 , "//");
  variableValue v2 =(NUMBERfORM)(fmod(d,v1.d));
// myDebugResult(v2 );
 return (v2);
}

variableValue variableValue::pow(variableValue &v1)
{
 conVal2(v1);checkEqOfTv(v1," pow ");


//  debugKeyStart=45 ;
/*  cout << " hello " <<endl;
  cout << " d   " << d << endl ;
   cout << " v1.d   " << v1.d << endl ;
*/
//  myDebug(v1 , "**");
 bool negativeExp1=false ;
 if(v1.d <= 0 )
	negativeExp1=true ;

//  myDebug(v1 , "**");
  variableValue v2 =(NUMBERfORM)(::pow(d,fabs(v1.d))) ;
 if(negativeExp1)
	if(!isZeroD(v2))
		v2.d=1/(v2.d) ;
//	myDebugResult(v2);
 return (v2);
}
/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


void variableValue::conVal3(variableValue &v1)
{bool bb1 =true;char *pp1;bool bb2 ;
 switch(tv)
 {case Str:
	if(strlen(s) == 1)
	  if(s[0]== '1' ||s[0] =='0')
	  {
		 bb1=false ;
		 bb2=s[0]-'0';
		 deleteStrVar();
		 tv=Logic ;
		 b=bb2 ;
	  }
	  if(bb1)	error(4);
	  bb1=true ;
	  if(v1.tv == Real)
	  {
		 if(isZeroD(v1.d) )    bb1=false ;
		 v1.tv=Logic;v1.b=bb1 ;
	  }
	  else if( v1.tv == Str)
	  {
		if(strlen(v1.s) == 1)
	if(v1.s[0]== '1' ||v1.s[0] =='0')
	{bb1=false;bb2=v1.s[0]-'0';
	 deleteStrVar(v1);
	 v1.tv=Logic;
	 v1.b=bb2;
	}
	if(bb1)  error(5);
	  }
 break;
 case Real:
	  bb1=true;
	  if(isZeroD(d))  bb1=false ;
	  tv=Logic;b=bb1 ;bb1 =true;
	  if(v1.tv == Str)
	  {if(strlen(v1.s) == 1)
	if(v1.s[0]== '1' ||v1.s[0] =='0')
	{bb1=false;bb2=v1.s[0]-'0';deleteStrVar(v1);v1.tv=Logic;v1.b=bb2;}
	 if(bb1)  error(6);
	}
	else if(v1.tv ==  Real)
	{if(isZeroD(v1))    bb1=false ;
	 v1.tv=Logic;
	 v1.b=bb1 ;
	 }
 break;
 case Logic:
	  if(v1.tv == Real)
		 {
	 if(isZeroD(v1.d) )    bb1=false ;
		v1.tv=Logic;
		v1.b=bb1 ;
		 }
		 else  if( v1.tv == Str)
		 {
	if(strlen(v1.s) == 1)
	 if(v1.s[0]== '1' ||v1.s[0] =='0')
	 {bb1=false;bb2=v1.s[0]-'0';deleteStrVar(v1);v1.tv=Logic;v1.b=bb2;}
	 if(bb1)  error(7);
	}
  break;
 }
}
variableValue variableValue::operator&&(variableValue &v1)
{ conVal3(v1);checkEqOfTv(v1," && ");
//  myDebug(v1 , "&");
 variableValue bb1=(variableValue)( (bool)v1.b &&  b);
// myDebugResult(bb1 );
 return bb1;
}

variableValue variableValue::operator||(variableValue &v1)
{
 conVal3(v1); checkEqOfTv(v1," || ");
//  myDebug(v1 , "|");
 variableValue bb1 =(variableValue)( (bool)v1.b ||  b);
// myDebugResult(bb1 );
 return bb1;

}

variableValue variableValue::operator^(variableValue &v1)
{
 conVal3(v1); checkEqOfTv(v1," ^ ");
//  myDebug(v1 , "&&");
 variableValue bb1= (variableValue) ( (bool)v1.b ^  b);
// myDebugResult(bb1 );
 return bb1;

}

NUMBERfORM variableValue::convertToNumber( char *pp1)
{
  NUMBERfORM dd1;
  int i1 =0 ;
  bool sN=false , sE=false ;
  int localSizeOfPp1 = strlen(pp1);
  int localChangedNoOfPp1 =0;
  while(*pp1 == ' ' ){ pp1 ++;localChangedNoOfPp1++ ;}

  if(*pp1 == '+')
  { pp1++;localChangedNoOfPp1++;}
  else if(*pp1 == '-')
  {
	  pp1++;localChangedNoOfPp1++;
	  sN=true ;
  }
  dd1=getOrdNumber(pp1,i1);
  pp1 += i1 ;
  localChangedNoOfPp1+=i1;
  NUMBERfORM dd2=0 ;
  if(*pp1== '.' )
  {
	 pp1 ++;localChangedNoOfPp1++ ;
	 dd2=getOrdNumber(pp1,i1);
	 dd1=dd1 + dd2 * ::pow(10,-i1);
	 pp1 += i1 ;  localChangedNoOfPp1+=i1;
  }
  if( (*pp1 == 'E' ) || (*pp1 == 'e' ) )
  {
	 pp1 ++ ;localChangedNoOfPp1++;
	 if(*pp1 == '+')
	 {      pp1++;localChangedNoOfPp1++;}
	 else if(*pp1 == '-')
	 {
			pp1++;localChangedNoOfPp1++;
			sE=true ;
	 }
	 dd2=getOrdNumber(pp1 , i1);
	 int ii2=dd2 ;
	 if(sE)
		 ii2=- ii2;
	 dd1=dd1 * ::pow(10,ii2);
	 pp1 += i1;  localChangedNoOfPp1+=i1;
  }
  if(*pp1)
	 error(8);
  if(sN)
	  dd1=-dd1 ;
  if(localChangedNoOfPp1!=localSizeOfPp1)
	{cout<<" localSizeOfPp1 "<<localSizeOfPp1;  myDebugKey(localSizeOfPp1, " in convertNumber(char * ) size not eq ");}
  return  dd1 ;
}

NUMBERfORM  variableValue::getOrdNumber(char *pp1 , int &i1)
{ NUMBERfORM d1=0 ;
  i1= 0 ;
  while(isdigit(*pp1))
  {
	 d1=d1*10 + (*pp1-'0' );
	 i1++;
	 pp1 ++  ;
  }
  return d1 ;
}


void variableValue::convertNumber(NUMBERfORM dd1, char **pp1)
{
  char localC11[MAX_NUMBER_LENGTH+30] ;
  gcvt(dd1 ,MAX_NUMBER_LENGTH-5 ,localC11);
//  if( heapcheck() == _HEAPCORRUPT )
//{   cout<< "Heap is corrupted.in value var .cpp convertNumber 12\n" ;exitProgram(1);}
  *pp1=new char[strlen(localC11)+1];
  strcpy(*pp1 , localC11) ;
}
void variableValue::conVal4(variableValue &v1)
{
 char *pp1;
 switch(tv)
 {
  case Str:
	if(v1.tv == Real)
	{
	  convertNumber(v1.d , &pp1);
	  v1.tv=Str;
	  v1.s=pp1;
	}
	else if( v1.tv == Logic)
	{ char cc1=v1.b;
	  v1.tv=Str ;
	  v1.s=new char[2];
	  v1.s[0]=cc1+'0' ;
	  v1.s[1]='\0' ;
	}
 break;
 case Real:
	 convertNumber(d ,& pp1);
	  tv=Str;
	  s=pp1 ;
//cout <<" loacal " <<*pp1<< " \n" ;
	if(v1.tv == Real)
	{
	 convertNumber(v1.d ,&pp1);
	 v1.tv=Str;
	 v1.s=pp1;
	}
	else if(v1.tv ==  Logic)
	{ char cc1=v1.b;
	 v1.tv=Str ;
	 v1.s=new char[2];
	 v1.s[0]=cc1+'0' ;
	 v1.s[1]='\0' ;
	}
 break;
 case Logic: // tv == Logic
	char cc1=b;
	tv=Str ;
	s=new char[2];
	s[0]=cc1+'0' ;
	s[1]='\0' ;
	if(v1.tv == Real)
	{
	 convertNumber(v1.d ,& pp1);
	 v1.tv=Str;
	 v1.s=pp1;
	}
	else if(v1.tv ==  Logic)
	{ char cc1=v1.b;
	 v1.tv=Str ;
	 v1.s=new char[2];
	 v1.s[0]=cc1+'0' ;
	 v1.s[1]='\0' ;
	}
  break;
 }
}



variableValue  variableValue::concat(variableValue &v1)
{
// cout <<" d " << d << "tv "<<tv <<"\n";
 
 conVal4(v1) ;checkEqOfTv(v1," concat ");
 int i12=strlen(s) + strlen(v1.s) +3;
 char *p12=new char[i12];
// myDebug(v1 , "||");
 strcpy(p12, s);
 
 strcat(p12,v1.s);
 variableValue v2 =p12 ;
 delete[] p12;
// myDebugResult(v2);

 return (v2);
}
void variableValue::conVal11(void)
{
 if(tv==Str)
 {
   NUMBERfORM d1=convertToNumber(s);
	deleteStrVar();
	tv=Real ;
	d=d1 ;
 }
}
variableValue  variableValue::operator!(void)
{
 conVal11();
 bool bb2=true ;
 if(tv == Real)
 {if(isZeroD() )	 bb2=false ; }
 else     bb2=b ;
 variableValue v2 =(bool)(!bb2);
// myDebug((*this) , "!");
// myDebugResult(v2);
 return (v2);
}

bool   variableValue::isTrue(void)
{
 conVal11();
 bool bb2=true ;
 if(tv == Real) {if(isZeroD() )	 bb2=false ;}
 else    bb2=b;
 return bb2;
}

void variableValue::conVal21(void)
{
 if(tv==Str)
 {
   NUMBERfORM d1=convertToNumber(s);
	deleteStrVar();
	tv=Real ;
	d=d1 ;
 }
 else if(tv == Logic)
 {
	int ddd1= b ;
	d=ddd1 ;
	tv=Real ;
 }

}

variableValue  variableValue::operator-(void)
{conVal21();variableValue v2 =(*this);
  v2.d=-v2.d ;
// myDebug(*this , "-");
// myDebugResult(v2 );

 return (v2);
}

void variableValue::conVal5(void)
{
 char *pp1;
 if(tv== Real)
 {
	 convertNumber(d ,& pp1);
	  tv=Str;
	  s=pp1 ;
 }
 else if(tv == Logic)
 {
	char cc1=b;
	tv=Str ;
	s=new char[2];
	s[0]=cc1+'0' ;
	s[1]='\0' ;
 }
}

void variableValue::getStr(stringCls &nameString1)
{
  conVal5();
  nameString1=s;
}
char *variableValue::getNewCharPointer(void)
{
  conVal5();
  char *pp1=new char [strlen(s)+2];
  strcpy(pp1,s);
  return pp1;
}
void   variableValue::error(int ii1)
{ cout << " RUN TIME ERROR  :::variableValue:::: " << endl ;
  switch(ii1) {
	case 1:break ;
	case 2:break ;
	case 3:break ;
	case 4:break ;
	case 5:break ;
	case 6:  break ;
   case 7:  break ;
	case 8: cout << "       8_ can not convert to number " <<endl ;
		 cout<<(*this);
       cout<<endl;
	break ;
	default:break ;
 }
 char ss12[60];
 exr->getNameFile(ss12);

 cout<<"nameFile "<<ss12<<endl;
 exr->getNameProc(ss12);

 cout<<"nameProc "<<ss12<<endl;
int aa21=exr->getCurNoLine();

 cout<<"line error "<<aa21<<endl;

 exitProgram(0) ;
}

