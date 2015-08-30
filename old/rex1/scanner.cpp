#include"all.hpp"
struct RW_STRUCT{
  char *string;
  EtokenType tokenCode;
  };
RW_STRUCT rw[]= { {"DO",Do},{"IF",If},{"TO",To},{"BY",By},
 {"END",End},{"ARG",Arg},{"SAY",Say},{"FOR",For},
 {"ELSE",Else},{"EXIT",Exit},
 {"THEN",Then},{"PULL",Pull},
 {"UNTIL",Until},{"WHILE",While},{"LEAVE",Leave},
 {"EXPOSE",Expose},{"RETURN",Return},
 {"FOREVER",ForEver},{"SELECT",Select},{"WHEN",When},
 {"PROCEDURE",Procedure},{"OTHERWISE",Otherwise},{NULL,0}
};
scannerCls::scannerCls(char *namef , char *sourcep , int tab ):
	fileContainCls(namef, sourcep ){
  int tch ;
  for(tch=0 ; tch<256 ; tch++) charTable[tch]= Special ;
  for(tch='0';tch<='9';tch++   ) charTable[tch]= Digit ;
  for(tch='A';tch<='Z';tch++   ) charTable[tch]= Leter ;
  for(tch='a';tch<='z';tch++   ) charTable[tch]= Leter ;
  charTable['\'']=charTable['\"']=Quote ;charTable[eoc]=eoc ;
  anyCharIsValid=false ;sourceBuffer[0]='\0' ;
  bufferp=sourceBuffer ;posInFile =0 ;
  noSourceLine=0 ;anyCharIsValid= false  ;tabSize=tab ;
  bufferOffset=0 ;//		initScanDebug();
	haveStrInToken=false;
 if(fileErrorDetect) ch=eoc ;
 else getChar();
}
//scannerCls::~scannerCls(void)
//{/* deleteDebugScan();*/}
void scannerCls::getChar(void)
{if(!(*bufferp))
 { if(!getLine(sourceBuffer)) ch=eoc;
	else{bufferp=sourceBuffer;bufferOffset=0 ;ch=*bufferp++ ;}
	noSourceLine++;//		myScanDebug();
 }
 else ch= *bufferp++ ;
 if(ch == '\t'){ch =' ' ;bufferOffset+=tabSize;posInFile    += tabSize ;}
 else{bufferOffset++;posInFile++;}
}
bool  scannerCls::skipComment(void)
{bool bb1=false ;int curPos=posInFile ;int curLine= noSourceLine ;
 int curOffset=bufferOffset;
 do
 {
	if( (ch =='/') && (*bufferp=='*' ))
	{
	  getChar();
	  getChar();
	  skipComment();
	}
	getChar();
 }while( (ch != eoc)&&!(ch=='*'&& *bufferp=='/'));
 if(ch== eoc)errorSkeipComment(curLine,curOffset ,curPos);
 else{getChar();getChar();bb1=true ;}
 return bb1 ;
}
void scannerCls::skipBlank(void){while(ch==' ') getChar();}
bool  scannerCls::get_token(void)
{
 skipBlank();
 int curPos=posInFile;
 int curLine= noSourceLine ;
 int curOffset=bufferOffset;
 tokenp=tokenString;
 tokenString[0]='\0';
 downShiftTokenString[0]='\0' ;
 bool bb2=false;
 downShiftIsTrue=false;
 haveStrInToken=false;
 switch(charTable[ch])
 {
	case Leter:
	  bb2=getWord();
	  downShiftIsTrue =true;
	  haveStrInToken=true;
	break;
	case Digit:
	  bb2=getNumber();
	break;
	case Quote:
		bb2=getString();
		haveStrInToken=true;
	break;
	case eoc:
	  currentTokenType=EndOfFile ;
	break;
	default:
	  bb2=getSpecial();
	break;
  }
  prepareToken(bb2,curPos,curLine,curOffset) ;
  return bb2;
}
// array without any blank between the element of array
bool scannerCls::getWord(void)
{bool isArray=false ;bool preCharIsPoint=false ;
 bool errndetect=true ;
 register int len1=0;
  while( (charTable[ch] == Leter)||(charTable[ch]==Digit)||(ch=='.')){
	 *tokenp++=ch ;
	 if(len1++>MAX_LENGTH_OF_NAME)
		 errorLenName();
	 if(ch == '.' ){
		if(preCharIsPoint)  errorGetWord(1) ;
		isArray=true  ;preCharIsPoint=true  ;
	 }
	 else  preCharIsPoint=false ;
	 getChar();
  }
  *tokenp='\0' ;downShiftWord();
  if(preCharIsPoint)  currentTokenType=Stem ;
  else if(isArray ) currentTokenType=Array ;
  else if(isNotReservedWord()) currentTokenType=Name  ;
 return   errndetect ;
}
void scannerCls::downShiftWord(void)
{ char *tp1=tokenString ;char *tp2=downShiftTokenString ;
  for(;*tp1;tp1++,tp2++) *tp2=toupper(*tp1);
  *tp2 ='\0';
}
bool scannerCls::isNotReservedWord(void)
{int i =0  ;
  for(;rw[i].string ;i++ )
	if(!strcmp( rw[i].string , downShiftTokenString) )
	{currentTokenType= rw[i].tokenCode;return false;}
  return true ;
}
bool scannerCls::getNumber(void)
{bool bb1;bool   errndetect=true;currentTokenType=OrdNumber ;
 NUMBERfORM dd1;int i1 =0 ;bool  sE=false ;getOrdNumber(dd1,i1);
 NUMBERfORM dd2=0 ;
 if(ch== '.' ){
	*tokenp++=ch ;getChar();bb1=getOrdNumber(dd2,i1);
	if(!bb1){errndetect=false;errorGetNumber(1) ;}
	else	dd1=dd1 + dd2 * pow(10,-i1);
 }
 if( (ch == 'E' ) || (ch == 'e' ) ){
	*tokenp++='e' ;getChar();
	if(ch == '+'){*tokenp++=ch ;getChar();}
	else if(ch == '-'){*tokenp++=ch ;getChar();sE=true ;}
	bb1=getOrdNumber(dd2,i1);
	if(!bb1){  errndetect=false;errorGetNumber(2) ;}
	else
	{ int ii2=dd2 ;if(sE) ii2=- ii2 ;
	  dd1=dd1 * pow(10,ii2);
	}
 }
 *tokenp='\0' ;doubleForm=dd1;return errndetect ;
}
bool  scannerCls::getOrdNumber(NUMBERfORM &d1 , int &i1)
{ bool bb1=false ;d1=0 ;i1= 0 ;
  while(charTable[ch] == Digit )
  { bb1=true ;*tokenp ++=ch  ;d1=d1*10 + (ch - '0');
	 i1++; getChar();
  }
  return bb1 ;
}
bool scannerCls::getString(void)
{ char quoteType=ch ; int curPos=posInFile ;
  int curLine= noSourceLine ; int curOffset=bufferOffset;
  bool  errndetect=true ; getChar() ;
  if(ch == '\n')
  {errorGetString(curLine , curOffset,curPos);errndetect=false;}
  else{
	 while( (ch != '\n')&& (ch != eoc ) ){
		 if(ch == quoteType )
		 {
			if(*bufferp != quoteType ) break ;
			 *tokenp++=quoteType ;
			getChar();
			getChar();
		 }
		 else{*tokenp ++=ch ; getChar();}
	 }
  }
  if(ch != quoteType)
  {	errndetect=false;errorGetString(curLine , curOffset , curPos) ;}
  else
	 getChar();
  *tokenp='\0' ;currentTokenType=String ;
  return errndetect  ;
}
bool scannerCls::getSpecial(void)
{bool errndetect=true ;*tokenp++=ch ;char temp_ch=ch ;
 int curPos=posInFile,curLine=noSourceLine,curOffset=bufferOffset;
 getChar();
 switch(temp_ch){
	case '(' : currentTokenType=Lparen;break;
	case ')' : currentTokenType=Rparen;break;
	case '-' :currentTokenType=Minus;break;
	case ',' :currentTokenType=Comma ;break ;
	case '+' : currentTokenType=Plus;break;
	case ';' : currentTokenType=Semicolon ;break;
	case '!' : currentTokenType=Not;break;
	case '\n' : currentTokenType=EndOfLine ;break;
	case ':' : currentTokenType=Colon;break;
	case '*' :if(ch=='*'){*tokenp++=ch ;currentTokenType=Pow ;getChar();}
	  else if(ch=='/')
	  {errndetect=false;currentTokenType=Error ;
		errorGetSpecial(curLine,curOffset,curPos,temp_ch);
	  }
	  else  currentTokenType=Mul ;
	break ;
	case '/' :if(ch == '*' ){getChar();skipComment();get_token();}
	  else if(ch== '/'){*tokenp++=ch ;currentTokenType=Mod ;getChar();}
		else	currentTokenType=Div ;
	break;
	case '<':if(ch =='='){*tokenp++=ch ;currentTokenType=Le ;getChar();}
	  else if(ch== '>' ){*tokenp++=ch ;currentTokenType=Ne ;getChar();}
	  else currentTokenType=Lt ;
	break;
	case '>' :if(ch == '='){*tokenp++=ch ;currentTokenType=Ge ;getChar();}
	  else	currentTokenType=Gt ;
	break;
	case '=':if(ch == '=' ){*tokenp++=ch ;currentTokenType=ExEq ;getChar();}
		 else currentTokenType=Eq ;
	break;
	case '&' :if(ch=='&' ){*tokenp++=ch ;currentTokenType=ExOr;getChar();}
			else currentTokenType=And;
	break;
	case '|' :if(ch == '|'){*tokenp++=ch;currentTokenType=Concat;getChar();}
			else currentTokenType=Or;
	break;
	default :/*	  if(anyCharIsValid){ *tokenp++=ch ;
	if(ch == ' ' && ch == '\n')
	 currentTokenType=AnyCharactersWithSpace ;// say #? hello  //space herer is important
	else  currentTokenType=AnyCharacters ; } else{*/
		errndetect=false;currentTokenType=Error ;
		errorGetSpecial(curLine , curOffset , curPos ,temp_ch);
	break ;
 } *tokenp='\0' ;return errndetect ;
}
void	 scannerCls::errorLenName(void)
{
 int ni[4] ; ni[0] = 4; ni[1] = noSourceLine;ni[2]=bufferOffset;ni[3] = posInFile ;
 outerr . report(MaximumLengthOfNameError ,nameFile ,ni,sourceBuffer) ;
}

