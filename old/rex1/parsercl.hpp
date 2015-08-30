#ifndef PARSERCL_HPP
#define PARSERCL_HPP
#include"all.hpp"
#include"exprcont.hpp"
extern outputRexx out1 ;
class parserCls:public scannerCls{
  bool exprFound,needOperand,labelFound,inSay,argDtect,
  nextTokenPresent,exprErrorFlag ;
  int stmtNo,noLoop ,noTokenInExpr,inDo, noOfValInt,valInt[MAX_OF_WHEN];
  tokenContainCls nextToken;
  exprContainCls ecs;
  containStmtCls *css ;
  containProcCls *cpc;
//  ofstream parserCheckOut;
  bool parserErrorOccurred;
  void getToken(void);void ungetToken(tokenContainCls &);
  void addEndLineToProc(void);
  tokenContainCls &getCurToken(void){return curToken;}
  EtokenType  getTokenType(void)
  {return curToken.type;}
  bool getLabel(void);
  void initExpr(void);
  void addExprToStmt(int i);
  void addExprToStmt(containStmtCls *cts1,int i);
  void addExprToStmt(int i,exprContainCls *ped1);
  void initEiwCss(EinstructionWord wt1);
  void initStmt(void);void addToValInt(void);
  void initVar(void)
  {inDo=0;exprFound=false;needOperand=false;labelFound=false;
	inSay=false;nextTokenPresent=false;exprErrorFlag=false;
	stmtNo=0;noLoop=0;parserErrorOccurred=false;noTokenInExpr=0 ;
	argDtect = false;noOfValInt=0;
  }
  exprContainCls *getNewExprWithoutReverse(void);
public:

//  ~parserCls(){myDebugKey(1,"in ~patrsercls ");}
  parserCls(char *nn):scannerCls(nn)
  {initVar();getToken();nextProcSpecification.addNameFile(nn);}

protected:
  bool block(EinstructionWord & , int &);
  void init(containProcCls *cp1){cpc=cp1;initVar();}
	 containProcCls nextProcSpecification ;
private:
  void clearStmt(void);
  void addToValnt(int ,int);
  void addExprToStmt(exprContainCls *pp11,int );
  exprContainCls *getNewExpr(void);
  bool assignmentStmt(tokenContainCls &tc7  ) ;
  bool parserCls::isValidName(EtokenType et1 );
  bool statement(bool & etlnoc , EinstructionWord &est);
  bool callStmt(bool &etlnoc,EinstructionWord &est);
/*  void myDebugError(void )
  {
	 out1<<"current line is \n";
	out1<<sourceBuffer <<"\n" ;
	myDebugKey(noSourceLine ," press any key to continue  ") ;
  }
*/

  bool  parserCls::skipWhiteLine(void);
  bool ifStmt(void);bool doStmt(void);bool selectStmt(void);
  bool sayStmt(void);bool parserCls::isValidName(void);
  bool parserCls::pullArgStmt(void);
  inline bool exprssion(void);
  bool parserCls::ArgStmtParse(void);
  void errorParser(EerrorType et1 )
  {
	tokenContainCls tc1=getCurToken();
	int ni[4],jj1;
	ni[0]=4;
	ni[1]=getLineOfToken(tc1.start,jj1);
	ni[2]=jj1;
	ni[3]=tc1.start;
	parserErrorOccurred =true;
	outerr.report(et1,nameFile,ni,sourceBuffer) ;
//	myDebugError();
  }
  void errorPullArgParse(int ii)
  {if(!ii)    errorParser( AfterCommaShouldName);
	else if(ii ==1 )errorParser(NameExpectedAfterComma) ;
   else errorParser(OnlyNameExpectedPA) ;
  }
  bool pullStmt(void);
  void errorArg(void){errorParser(TwoArgStmt);}
  void  blockError(int ii1);bool argStmt(void);bool leaveStmt(void) ;
  bool nopStmt(void);//void initEcs(void);
  bool returnStmt(void);
  void errorExitStmt(void) {errorParser(AfterExitNotExpr);}
  bool exitStmt(void); bool exprStmt(void);
  void errorParser(EerrorType et1,tokenContainCls &tc1 )
  {
	 int ni[4],jj1;
	 ni[0]=4;
	 ni[1]=getLineOfToken(tc1.start,jj1);
	 ni[2]=jj1;
	 ni[3]=tc1.start;
	 outerr.report(et1,nameFile ,ni,sourceBuffer);
	 parserErrorOccurred=true;
//	 myDebugError();
 }
  void exprShouldError(tokenContainCls &tc1,EinstructionWord t1)
  {errorParser(ExprExpected,tc1);}
  inline bool parserCls::exprShould(EinstructionWord t1 );
  bool term1(void);
  inline bool term2(void);bool term3(void);bool term4(void);
  bool term5(void );
  inline bool term6(void );bool factor(void);
  void	parserCls::addOperator(void)
  { noTokenInExpr++;ecs.push(getCurToken());}
  void	parserCls::addOperator(tokenContainCls &tt1)
  { noTokenInExpr++ ;ecs.push( tt1);}
  void	parserCls::addOperator(int loc1 , tokenContainCls &tt1)
  { ecs.change(loc1,tt1);}
  void parserCls::addOperand(void)
  {noTokenInExpr++; ecs.push(getCurToken());}
  void parserCls::addOperand(tokenContainCls &tt1)
  { noTokenInExpr++; ecs.push(tt1) ;}
  void addName(tokenContainCls &lTc1){noTokenInExpr++;ecs.push(lTc1);}
  bool addFunction(tokenContainCls &lTc1);
  void errorRecursLparen(int ii1 ,tokenContainCls &tc1)
  {if(ii1)errorParser(UnmatchParantes,tc1) ;
	else  errorParser(needTokenInParen,tc1) ;
   exprErrorFlag = true ;
  }
  void recursiveLparen(void);
  void errorFactor(void){errorParser(UnExpectedToken);exprErrorFlag=true;}
  void errorUnary(tokenContainCls &t1, int ii1 )
  {errorParser(UnExpectedUnary);exprErrorFlag=true;}
  void errorStmt(int i)
  {if(i==0 ) errorParser(UnExpectedEndInstr);
   else errorParser(UnExpectedInstruction);
  }
  void errorAssign(tokenContainCls &tc1)
  {errorParser(AfterAssignShouldExpr,tc1);}
  void   errorEndLine(void)
  {errorParser(AfterStmtEndStmt);}
  bool  endWhiteLine(void)
  {bool b1=false;EtokenType et1 = getTokenType();
	if((et1==EndOfLine)||(et1 == Semicolon))   b1=true ;
   else   errorEndLine();
   return b1 ;
  }
  bool  syncStmtError(void) ;
  void errorGetLabel(void);
  void errorIfStmt(int i)
  {if(i) errorParser(ExprssionNeeded);else errorParser(ThenNeeded);}
  bool  syncIfStmt(void)
  { return false ;}
  cvContain  controlVarEntry ;
  // TCS1 point to DO token TCS2  point to token error
  void errorCompound(tokenContainCls &tcs1)
  {// tcs1 point to DO  token
    tokenContainCls tc2 = getCurToken();
	 if(tc2.type==EndOfFile) errorParser(EndExpectedNoEOF ,tcs1);
    else errorParser(EndExpectedNoLabel,tcs1);
  }
  void errorDo(int i , tokenContainCls &tcs1,tokenContainCls  & tcs2 )
  {if(i==1)  errorParser(AssignExpectedInDoTo,tcs2 );
	else errorParser(NameOfConVarExpected,tcs2 ) ;
  }
  void errorAddControlVar(tokenContainCls &tcs1)
  {errorParser(ControlVarTwoSame);}
  void addControlVar(tokenContainCls &tcs1  )
  { tokenContainCls tc2 = getCurToken();
   if(controlVarEntry.search(tc2.nameVar))errorAddControlVar(tcs1);
   else controlVarEntry.push(tc2.nameVar , noLoop ) ;
  }
  void  popControlVar(void){controlVarEntry.pop();}
  bool compoundStmt(tokenContainCls &tcs1 ,int & a2);
  // in a2 return the no of  instruction in do ...... end
  void  addNextLine(int curStmtNo);
  void errorLeave(int ii )
  {if(ii== 0) errorParser(ControlVarNotFound);
	else if(ii==1)errorParser(LeaveShouldInLoop);
   else if(ii==2)errorParser(AfterLeaveOnlyName);
  }
  bool   parserCls::syncSelect(void);
  bool  errorCallStmt(tokenContainCls &tcd1 ,tokenContainCls &tcd2 )
  {
  // in "tcd1" the token of "select"  & in "tcd2" token of "then"
  // current token contain the error instr
  // such as "else" in select
  bool bb1=false;errorParser(AfterThenShouldStmt ,tcd2);
  if(syncStmtError()) bb1 = true ;
  return bb1 ;
  }
  bool errorSelect(tokenContainCls &tcd1 ,tokenContainCls &tcd2,int i )
  {bool bb1=false;
	if(i==1)  errorParser(MaxOfWhen,tcd1);
	else if(i==2) errorParser(AfterSelectShouldEnd,tcd1);
	else{errorParser(InWhenThenNeeded,tcd2);if(syncStmtError())bb1=true;}
	return bb1 ;
  }
 bool syncErrorThen(void);
// friend void main(void) ;
};
#endif
