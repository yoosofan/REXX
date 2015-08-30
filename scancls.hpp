#ifndef SCANCLS_HPP
#define SCANCLS_HPP
#include"global.hpp"
#include"enumpars.hpp"
#include"erreport.hpp"
#include"filecont.hpp"
#include"tokCont.hpp"
enum scanForm{Special ,Digit ,Leter ,Quote , eoc='\x7f'};
class scannerCls : public       fileContainCls  {
 public : scannerCls(char *namef , char *sourcep = 0, int tabSize = 3) ;
	~scannerCls(){} ; void getChar(void) ; bool get_token(void);

 protected: errorReportCls outerr;

 private : bool skipComment(void) ; void skipBlank(void) ;
	bool haveStrInToken;
	 bool getWord(void) ; bool getNumber(void);
	 bool getString(void);bool getSpecial(void);bool isNotReservedWord(void);

	 void prepareToken(bool bb1,int curPos,int curLine,int curOffset)
	 {
		 curToken.type=currentTokenType;

//		 curToken.line=curLine;
//		 curToken.offset=curOffset;
//		 addLineAndOfsset(curPos,curLine,curOffset);
		 curToken.start=curPos ;
		 if(currentTokenType == OrdNumber)
		 {
			 curToken.d=doubleForm ;
			 curToken.nameVar = "";
		 }
		 else if(downShiftIsTrue)
			 curToken.nameVar=downShiftTokenString;
		 else if( haveStrInToken)
			  curToken.nameVar=tokenString;
		 else
			  curToken.nameVar = "";
	 }
	void   downShiftWord(void);bool getOrdNumber(NUMBERfORM &d1,int &i1);
	void   scannerCls::errorGetNumber(int  i1 )
	{int ni[4];ni[0]=4;ni[1]=noSourceLine;ni[2]=bufferOffset;ni[3]=posInFile;
	 if( i1 == 1)outerr.report(AfterPointShouldBeNumber ,nameFile ,ni,sourceBuffer);
	 else if(i1 == 2 )outerr.report(AfterEShouldBeNumber,nameFile,ni,sourceBuffer);
	 }
	 void	 errorLenName(void);
	 void errorSkeipComment(int  n1, int n2,int n3)
	 {int ni[4] ;ni[0] =4 ; ni[1] = n1 ; ni[2] = n2; ni[3] = n3 ;
	  outerr . report(UnmatchComment ,nameFile , ni,sourceBuffer) ;
	 }
	 void errorGetWord(int i1)
	 {int ni[4] ; ni[0] = 4; ni[1] = noSourceLine;ni[2]=bufferOffset;ni[3] = posInFile ;
	outerr . report(CanNotPointDuplicate ,nameFile ,ni,sourceBuffer) ;
	 }
	 void errorGetString(int curLine , int curOffset , int curPos)
	 {  int ni[4 ] ;  ni[0] = 4; ni[1] = curLine;ni[2]=curOffset;ni[3] = curPos ;
		  outerr.report(UnMathQuote ,nameFile ,ni,sourceBuffer) ;
	 }
  void errorGetSpecial(int curLine,int curOffset,int curPos,char tempch)
  {int ni[5 ];ni[0]=4;ni[1]=curLine;ni[2]=curOffset;ni[3]=curPos;ni[4]=tempch;
	outerr . report(UnExpectedCharacter ,nameFile ,ni,sourceBuffer) ;
  }
  public : tokenContainCls curToken ;
	  bool anyCharIsValid ;  // for say instruction and get any character
  protected:
	  char sourceBuffer[MAX_LINE_LENGTH];
  private :
	 int noOfTokenAdded;

	char ch ,*bufferp, *tokenp,tokenString[MAX_LINE_LENGTH] ;
	char downShiftTokenString[MAX_LINE_LENGTH];
	scanForm charTable[256];
	NUMBERfORM doubleForm;
	int tabSize,bufferOffset,posInFile ;
	bool downShiftIsTrue ;
	EtokenType currentTokenType ;
/*   ofstream outScan1;
   void initScanDebug(void)
   {outScan1.open("scan.out");}
   void deleteDebugScan(void){outScan1.close();}
   void    myScanDebug(void)
   {outScan1<<noSourceLine<<":::: " <<sourceBuffer<<endl;}
*/
 public: int noSourceLine;
};
#endif