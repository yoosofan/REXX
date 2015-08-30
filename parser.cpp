#include"all.hpp"
void parserCls::addExprToStmt(int i){css->ecs[i]=getNewExpr();//css->ecs[i]->print();myDebugKey(i,"iiii  int i is ");
}
void parserCls::addExprToStmt(containStmtCls *cts1,int i)
{ cts1->ecs[i]=getNewExpr();//myDebugKey(i,"iiiicontainStmtCls *cts1,int i  is ");cts1->ecs[i]->print();
}
void parserCls::addExprToStmt(int i,exprContainCls *ped1)
{
 css->ecs[i]=ped1;
 if(ped1)ped1->print();
}
void parserCls::clearStmt(void){delete css;css=long(0);}
void parserCls::initStmt(void)
{
  noOfValInt=0;
  css=new containStmtCls;
  css->lineStmt=noSourceLine;
}
void parserCls::addExprToStmt(exprContainCls *pp11 ,int i )
{
  css->ecs[i]=pp11;
  //myDebugKey(i,"iiii  exprContainCls *pp11 ,int i   is ");css->ecs[i]->print();
}
void parserCls::addToValInt(void)
{
  if(noOfValInt)
	  css->addValInt(noOfValInt,valInt);
}
void parserCls::initEiwCss(EinstructionWord wt1){css->eiw=wt1;}
void  parserCls::blockError(int ii1)
{if(ii1 == 0) errorParser(MaxLineInProcedure) ;
 else  errorParser(NoStatementInProc) ;
}
bool    parserCls::compoundStmt(tokenContainCls &tcs1 ,int & a2)
{bool  etlnoc, bb2 = false ; EinstructionWord est;inDo++;
 do{a2++;callStmt(etlnoc,est);
 }while((est!=EndInstr)&&(est!=EndOfFileInstr)&&(est!=LabelInstr));
 if(est != EndInstr)  errorCompound(tcs1);
 else  bb2 = true ;
 inDo--;return bb2;
}
bool parserCls::block(EinstructionWord &ews12 , int & ii18 )
{EinstructionWord est;bool etlnoc , bb1 = true ;int ii12 = 0 ;
 for(;;){
	statement(etlnoc , est) ;// return can addLine ;
	if(etlnoc == false )   bb1 = false ;
	if(errorReportCls::unrecoverAbleError)
	{out1<<"unrecover able error occurred "<<"\n";bb1=false;break;}
	if((est==EndOfFileInstr)||(est==LabelInstr)||(est==NoInstr)) break;
	if(++ii12 >=MAX_LINE_IN_PROCEDURE )
	{bb1 = false ;est = EndOfFileInstr;blockError(0) ;break;}
 }
 if(bb1)
	if(!ii12) blockError(1);
	else if(est==LabelInstr)
	  bb1=getLabel();
 ews12 = est ; ii18 = ii12+2 ;addEndLineToProc();
 return bb1 ;
}
void parserCls::addEndLineToProc(void)
{
  initStmt();
  initEiwCss(EndOfFileInstr);
 cpc->ccs[stmtNo]=css;
}

// expose and name of next procedure save in current procedure
bool parserCls::getLabel(void)
{bool bproc1 = false,bexpose1=false,bb2=true;
 nextProcSpecification.addName(getCurToken());
 getToken();getToken();
 if(getTokenType() == Procedure)
 {bproc1 = true ;
  getToken();
  if(getTokenType()== Expose)
  {bexpose1=true;
	do{
	 getToken();
	 if((getTokenType()==Name)||(getTokenType()==Array)||(getTokenType()==Stem))
	 {nextProcSpecification.addListExpose(getCurToken());getToken();}
	 else{bb2=false; errorGetLabel();}
	}while(getTokenType()==Comma);
  }
 }
 if(bb2)
	 bb2=endWhiteLine();
 if(bb2 && bproc1)
	if(bexpose1)nextProcSpecification.addProcType(ProcedureWithExposeType);
	else	nextProcSpecification.addProcType(ProcedureType);
 else nextProcSpecification.addProcType(LabelType);
 return bb2;
}
void parserCls::errorGetLabel(void)
{errorParser(AfterExposeShouldName);syncStmtError();}

bool parserCls::argStmt(void)
{bool bb1=false;
 if(argDtect) errorArg() ;
 else{argDtect=true;bb1=ArgStmtParse();}
 return bb1 ;
}
bool parserCls::nopStmt(void)
{bool bb1;getToken();bb1=endWhiteLine();initEiwCss(NopInstr);return bb1;}
bool parserCls::returnStmt(void)
{initExpr();getToken();bool bb1=exprssion();
 if(bb1){
	if(noTokenInExpr){addExprToStmt(0);initEiwCss(ReturnInstr);}
	else   initEiwCss(ReturnOnlyInstr);
	bb1=endWhiteLine();
 }
 if(!bb1)  initEiwCss(ErrorInstr) ;
 return bb1 ;
}
bool parserCls::exitStmt(void)
{
 getToken();
 bool bb1=endWhiteLine();
 if(bb1)initEiwCss(ExitInstr);
 else {errorExitStmt(); initEiwCss(ErrorInstr) ;}
 return bb1 ;
}
void parserCls::addNextLine(int curStmtNo)
{
 addToValInt();
 css->ecs.evalSize();
 cpc->ccs[curStmtNo]=css;
 if(curStmtNo>DEMO_HEHEHEHEHEHHEHEH)
	 exitProgram(0);
}
bool parserCls::pullStmt(void)
{bool bb1=pullArgStmt();initEiwCss(PullInstr); return bb1;}
exprContainCls *parserCls::getNewExpr(void)
{exprContainCls *ppecs1 = new exprContainCls(ecs.size());//ecs.print();myDebugKey(ecs.size(),"size of expr ");
 ppecs1->setReverse(ecs); return ppecs1 ;
}
exprContainCls *parserCls::getNewExprWithoutReverse(void)
{exprContainCls *ppecs1 = new exprContainCls(ecs.size());//ecs.print();myDebugKey(ecs.size(),"size of expr ");
 ppecs1->copy(ecs); return ppecs1 ;
}
