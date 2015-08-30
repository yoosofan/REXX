#ifndef EXECCLS_HPP
#define EXECCLS_HPP
/*	this class execute one program block
	such as function , procedure ,...etc
	only one procedure is executed
	 for extend you should write other class execute program
	 where all functions and procedures on that class
	 for "EXPOSE" variable use previuos tick
	 save variable to up function in return
*/

#include"all.hpp"
class far  executeFileRexxCls;
class execProcCls {
 executeFileRexxCls *exFile;
 variableValue resultValue;
 exprCls  expr;
 map<stringCls , variableValue> varTable;
 arrayContCls  arrayTable ;
 map<variableValue,variableValue> stemTable;
 int  indexExpr,indexValInt,stmtNo,noLoop, leaveNumber;
 containProcCls *curProc;containStmtCls *curStmt;
 exprContainCls *curExpr;tokenContainCls *curToken ;
 tokenContainCls tempT ;
 int debugNumber;
// map<int , stringCls>  exposeList;
 void error(int i);
 void execProcCls::error(int i,char *str1);
  void initVar(void)
  {
	 debugNumber=0;
	 stmtNo=indexExpr=leaveNumber=noLoop=0;
	 resultValue=variableValue("");
  }
 void execProcCls::debugStmt(EinstructionWord y2);
  int getToken(void);
  EtokenType  execProcCls::getTokenType(void);
  tokenContainCls  getCurToken(void);void initExpr(void);
  void initNextExpr(void);variableValue  exprssion(void);
  void setValInt(void);int getNextValInt(void);
  void   initNextStmt(void);EinstructionWord  getStmtType(void);
 void assignmentStmt(void);void skipStmt(int i1);void sayStmt(void);
 variableValue exprStmt(void);void setStmtNo(int curStmtNo);
 void statement(EinstructionWord &est);bool compoundStmtExe(int,int);
 void execProcCls::selectStmt(void);void ifStmt(void);
 void ifElseStmt(void);void doStmt(void);void doToStmt(void);
 void doToByStmt(void);void doForEverStmt(void);void doWhileStmt(void);
 void doUntilStmt(void);void doForStmt(void);bool leaveIsDetect(void);
 void leaveIncrease(void){}
 void leaveStmt(void);void  leaveContStmt(void);void pullStmt(void);
 void exitStmt(void)
 {leaveNumber=-1;}
 void returnStmt(void)
 {leaveNumber=-2;resultValue=exprStmt();}
 void returnOnlyStmt(void)
 {leaveNumber=-3;}
 void exitStmtDetect(void);
 void setGlobalResultVar(variableValue retVal);
  public:
  void getNameProc(char *p1)
  {
	stringCls aa1 =curProc->getName();
	aa1.get_p(p1);
  }
	int getCurNoLine(void)
	{
	  return curStmt->getLine();
	}

  execProcCls(containProcCls *pProc,executeFileRexxCls *fileRexxParm )//,map<tokenContainCls,stringCls> &exList,map<int,stringCls> a1)
  :expr(this),tempT(Rparen,0 , 0)
  {curProc = pProc;exFile=fileRexxParm;initVar();}
  valBool findName(stringCls &ltnameVar);
  void execProcCls::addStemVar(stringCls &nameVar1,variableValue &vv1);
  valBool execProcCls::findStem(variableValue &nameVar1);

  valBool execProcCls::run(fCallContCls &tt1);
  valBool findArr(stringCls &lt);
  void addArrVar(stringCls &nameVar,variableValue vv1);
  variableValue callFunction(fCallContCls &tt);
  stringCls getNameProc(void)
  {return curProc->getName(); }
  bool isInExposeList(stringCls &ltnameVar);
  void  execProcCls::argStmt(fCallContCls &ft1);
  void addVariable(stringCls &name1,variableValue &vv1);
};
#endif