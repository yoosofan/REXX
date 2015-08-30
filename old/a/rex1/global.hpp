#ifndef GLOBAL_HPP
#define GLOBAL_HPP
enum EerrorType {
	CanNotOpenFile=1 ,CanNotReadFile ,
	 UnmatchComment,CanNotPointDuplicate,AfterPointShouldBeNumber,
	 AfterEShouldBeNumber , UnMathQuote,UnExpectedCharacter,
	 UnmatchParantes , UnExpectedToken , needTokenInParen,
	 AfterAssignShouldExpr , AfterStmtEndStmt, AfterExitNotExpr,
	 AfterCommaShouldName ,  OnlyNameExpectedPA,NameExpectedAfterComma,
	 ExprExpected ,UnExpectedUnary,TwoArgStmt,
	 MaxLineInProcedure ,NoStatementInProc,
	 UnExpectedEndInstr,UnExpectedInstruction,ControlVarTwoSame,
	 ExprssionNeeded,ThenNeeded,MaxOfWhen,
	 EndExpectedNoEOF ,EndExpectedNoLabel,
	 AssignExpectedInDoTo,NameOfConVarExpected,
	 ControlVarNotFound,LeaveShouldInLoop,
  AfterLeaveOnlyName,AfterThenShouldStmt,InWhenThenNeeded,
  AfterExposeShouldName,AfterSelectShouldEnd,
  MaximumLengthOfNameError

};
enum bool{false, true};
void exitProgram(int );
void myDebugKey(long int, char *);
char *ahmadStrchr(char *s1,char charactersearch,int &Locatecharacter);
// same as " strchr " but in locate return the location of characterSearch

int ahmadStrcmp(char *s1,char *s2);
void  edit( char  * s , char  * s1 ,  int  l , int  t , int  r , int  b );
#endif
