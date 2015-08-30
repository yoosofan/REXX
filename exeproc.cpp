#include"all.hpp"
extern  int debugKeyStart ;
#include"outrexx.hpp"
extern outputRexx out1;
void execProcCls::sayStmt(void)
{ int i1 = getNextValInt();variableValue v12(NUMBERfORM (1));
  for(int j1 =0 ; j1<i1 ; j1++) out1<<exprStmt()<<" ";
  out1 <<"\n";
}
void execProcCls::debugStmt(EinstructionWord y2)
{ char ll1[50];
 if(debugNumber)
  if(instrFind(y2,ll1)) {strcat(ll1,"  "); myDebugKey(y2,ll1);}
  else myDebugKey(y2," not instruction ");
}
void execProcCls::statement(EinstructionWord &est)
{  initNextStmt();initExpr();setValInt();EinstructionWord tt7=getStmtType();
 debugStmt(tt7);

 switch(tt7) {
   case NopInstr : est = NopInstr  ; break;
	case SelectInstr   :selectStmt();est =SelectInstr;break ;
	case DoInstr: doStmt() ;est=DoInstr;break ;
	case DoUntilInstr: doUntilStmt();est=DoUntilInstr;break;
	case DoForInstr :doForStmt();est=DoForInstr;break;
	case DoForEverInstr:doForEverStmt();est=DoForEverInstr;break;
	case DoWhileInstr:doWhileStmt();est=DoWhileInstr;break;
	case DoToInstr :doToStmt();est=DoToInstr;break;
	case DoToByInstr:doToByStmt();est=DoToByInstr;break;
	case LeaveInstr : leaveStmt();est = LeaveInstr;break ;
	case LeaveContInstr: leaveContStmt();est = LeaveInstr;break ;
	case IfElseInstr :ifElseStmt();est=IfElseInstr; break ;
	case IfInstr :    ifStmt();est=IfInstr; break ;
	case PullInstr :pullStmt();est = PullInstr;break ;
	case SayInstr  : sayStmt();est=SayInstr;break ;
	case AssignInstr: assignmentStmt();est=AssignInstr;break;
	case ExprInstr:exprStmt();est=ExprInstr;break ;
	case ReturnInstr:returnStmt(); est=ReturnInstr; break;
	case ReturnOnlyInstr:returnOnlyStmt();est=ReturnOnlyInstr ;break;
	case ExitInstr:exitStmt();est=ExitInstr; break;
	case EndOfFileInstr:est=EndOfFileInstr ;leaveNumber=-20; break;
	default:error(3) ;break;
 }
}
void execProcCls::assignmentStmt(void )
{
  initNextExpr();
  tokenContainCls t1=getCurToken();
  EtokenType et1=getTokenType();
  if(et1==Name)
	 addVariable(t1.nameVar, exprStmt());
  else if(et1 == Array )
	 addArrVar(t1.nameVar,exprStmt());
  else if(et1 == Stem )
	 addStemVar(t1.nameVar,exprStmt());
  else
	 error(4);

}
void execProcCls::ifStmt(void )
{ EinstructionWord ess1 ;variableValue vv11 =exprStmt();
  if(vv11.isTrue())    statement(ess1);
  else     skipStmt( getNextValInt());
}
void execProcCls::ifElseStmt(void )
{ EinstructionWord ess1 ;variableValue vv11 =exprStmt();
  int i1 = getNextValInt();int i2 = getNextValInt();
  if(vv11.isTrue() )
  {statement(ess1); skipStmt(i2);}
  else{skipStmt(i1); statement(ess1);}
}
void execProcCls:: doStmt(void)
{ getNextValInt();int ii11 = getNextValInt(),ii22=getNextValInt();
 compoundStmtExe(ii11 ,ii22);
}
void execProcCls:: doToStmt(void)
{ getNextValInt();int ii11 = getNextValInt();initNextExpr();
  int ii22 = getNextValInt();
 tokenContainCls t1 = getCurToken();variableValue vv11 =exprStmt();
 addVariable(t1.nameVar, vv11); variableValue  vv22 = exprStmt();
 variableValue vv33 = (vv11 <= vv22); variableValue vv44 = NUMBERfORM(1) ;
 int curStmtNo = stmtNo ;noLoop ++;
 while(vv33.isTrue())
 { setStmtNo(curStmtNo);compoundStmtExe(ii11, ii22);
	if(leaveIsDetect() )
	{leaveIncrease();break ;}
	vv11 = vv11 +vv44;vv33 =(vv11 <= vv22);
	 addVariable(t1.nameVar, vv11);
 }
	 addVariable(t1.nameVar, vv11); noLoop --;
}
void execProcCls:: doToByStmt(void)
{getNextValInt();int ii11 = getNextValInt(),ii22=getNextValInt();
 initNextExpr();tokenContainCls t1 = getCurToken();
 variableValue vv11 =exprStmt();	 addVariable(t1.nameVar, vv11);
 variableValue  vv22 = exprStmt();variableValue  vv44 = exprStmt();
 variableValue vv33 = (vv11 <= vv22);
 int curStmtNo = stmtNo ;noLoop ++;
 while(vv33.isTrue())
 { setStmtNo(curStmtNo);compoundStmtExe(ii11, ii22);
	if(leaveIsDetect() )
	{ leaveIncrease();break ;}
	vv11 = vv11 + vv44 ;vv33 = (vv11 <= vv22);
   	 addVariable(t1.nameVar, vv11);
 }
  	 addVariable(t1.nameVar, vv11); noLoop --;
}
void execProcCls:: doWhileStmt(void)
{ getNextValInt();
 int ii11 = getNextValInt(),ii22 = getNextValInt();
 variableValue vv11 =exprStmt();exprContainCls *pecs1 = curExpr;
 int curStmtNo = stmtNo ;noLoop ++;
 while(vv11.isTrue())
 { setStmtNo(curStmtNo);compoundStmtExe(ii11, ii22);
	if(leaveIsDetect()){leaveIncrease();  break ;}
	vv11 =  expr.exprssion(pecs1);;
 }
 noLoop --;
}
void execProcCls:: doUntilStmt(void)
{getNextValInt();int ii11=getNextValInt(),ii22=getNextValInt();
 variableValue vv11 =exprStmt();bool bb46 = false ;
 exprContainCls *pecs1 = curExpr;int curStmtNo=stmtNo;noLoop ++;
 do{
	setStmtNo(curStmtNo);compoundStmtExe(ii11, ii22);
   if(leaveIsDetect() ){leaveIncrease(); break ;}
   if(bb46)  vv11 =  expr.exprssion(pecs1);
	else   bb46 = true ;
 }while(vv11.isTrue());
 noLoop --;
}

void execProcCls:: doForStmt(void)
{ getNextValInt();int ii11 = getNextValInt(),ii22=getNextValInt();
  variableValue vv11=exprStmt();variableValue vv33 = double(1);
  int curStmtNo=stmtNo;noLoop ++;
 while(vv11.isTrue())
 { setStmtNo(curStmtNo); compoundStmtExe(ii11, ii22);
	if(leaveIsDetect() ) {leaveIncrease();break ;}
	vv11 = vv11 - vv33 ;
 }
  noLoop --;
}
void execProcCls:: doForEverStmt(void)
{getNextValInt();int ii11 = getNextValInt(),ii22 = getNextValInt();
 int curStmtNo=stmtNo;noLoop ++;
 while(1){
	setStmtNo(curStmtNo); compoundStmtExe(ii11 ,ii22);
	if(leaveIsDetect() )
	{leaveIncrease(); break ;}

 }
  noLoop --;
}
bool execProcCls::compoundStmtExe(int ii11 , int ii22)
{
  EinstructionWord est1 ;
  bool bb1 = true ;
  for(;ii11;ii11--){
	 statement(est1);
  if(leaveIsDetect()){bb1=false ;break ;}
  }
  if(leaveIsDetect())  setStmtNo(ii22);
  return bb1 ;
}
//// should be changed
// error when no of pull vars is less than the number of inputs
void  execProcCls::pullStmt(void)
{ variableValue vv1 ;char pp12[100] ,*pp11,*pp22,*prepointer,pp44[100];
 pp11 = pp12+2;pp22 = pp12;pp12[0] = 77;cgets(pp12);bool bb2 = true;
 if(int(pp12[1])==0)  bb2 = false ;int ii1 = getNextValInt();
 tokenContainCls t1;initNextExpr();
 for(int j =0 ; j<ii1 ; j++)
 { t1 = getCurToken();
	if(bb2)
	{ pp22 = strchr(pp11, ' ');
	  if(pp22){
		 strncpy(pp44 ,pp11,pp22-pp11);pp44[pp22-pp11]= '\0';
	vv1 = (variableValue)pp44;	 addVariable(t1.nameVar, vv1);
	prepointer = pp11 ;pp11 = pp22+1;
	  }
	  else{
	strcpy(pp44 ,pp11);vv1 = (variableValue)pp44;
		 addVariable(t1.nameVar, vv1);bb2 = false ;
	  }
	}
	else
	{ vv1 = (variableValue)"";	 addVariable(t1.nameVar, vv1);}
	getToken();
 }
 if(pp22 && bb2)
 {strcpy(pp44, prepointer);vv1 =(variableValue) pp44;
	 addVariable(t1.nameVar, vv1);
 }
 out1<<"\n";
}
void execProcCls::selectStmt(void)
{ EinstructionWord est1;

 int ii4,ii6 ;int ii1 = getNextValInt();int ii2 = getNextValInt();
 int ii3 = getNextValInt();bool bb2 = false ;//exprStmt() ;

 if(ii1)  ii2 -=2;
 variableValue vv1;
 for(ii4=3 ;ii4<ii2;ii4++){
	vv1 = exprStmt() ;
	ii6=getNextValInt();
	if(vv1.isTrue()){bb2 = true ;break;}
 }
 if(bb2){ setStmtNo(ii6); statement(est1);}
 else if(ii1)
 {ii6 = getNextValInt();setStmtNo(ii6);ii4 = getNextValInt();compoundStmtExe(ii4, ii3);}
 setStmtNo(ii3);
}
bool execProcCls::isInExposeList(stringCls &ltnameVar)
{
  int n1=curProc->getNoExpose();

  for(int i1=0;i1<n1;i1++)
	 if(ltnameVar==curProc->getExpose(i1))
		 return true;
 
  return false;
}
valBool execProcCls::findName(stringCls &ltnameVar)
{ valBool  xx  ;mapiter<stringCls , variableValue>  mpi(varTable);
  if(isInExposeList(ltnameVar))
	 xx=exFile->findNameInUpFunc(ltnameVar);
  else if(varTable.is_in_map(ltnameVar)==true)
	 {mpi.set_p_cur() ;xx.val  =   mpi.value();xx.b=true;}
  else    xx . b = false ;
  return xx ;
}
void execProcCls::addStemVar(stringCls &nameVar1,variableValue &vv1)
{
  variableValue vvName=nameVar1;
  stemTable[vvName]=vv1;
}
valBool execProcCls::findStem(variableValue &nameVar1)
{// end of nameVar is " . "
 valBool  xx  ;mapiter<variableValue , variableValue>  mpi(stemTable);
//  if(isInExposeList(ltnameVar))
//	 xx=exFile->findNameInUpFunc(ltnameVar);
  if(stemTable.is_in_map(nameVar1)==true)
	 {mpi.set_p_cur() ;xx.val  =   mpi.value();xx.b=true;}
  else    xx . b = false ;
  return xx ;
}

void execProcCls::addArrVar(stringCls &name123,variableValue vv1)
{
 valBool xx;
 xx.b=false;
 char *s1;
 int i1 =name123.size_of_str();
 s1=new char[i1+4];
 name123.get_p(s1) ;
 int localLocatePoint1;
 char *s2;
  s2=ahmadStrchr(s1,'.',localLocatePoint1);
 if(!s2)
	error(1,"AHMAD PROGRAMMER ERROR IN addD ARR IS NOT A ARRAY ");
 char varName1[MAX_LENGTH_OF_NAME];

 strncpy(varName1,s1,localLocatePoint1);
 varName1[localLocatePoint1]=NULL ;
 stringCls nameString1=varName1;
 char *pointCont12=".";
 variableValue pointContVar12=pointCont12;
 variableValue resArr1=varName1;
 variableValue containPreName1=pointCont12;

 resArr1 = resArr1.concat( pointContVar12);

 valBool xb1=findStem(resArr1);
 valBool xb2;xb2.b=false;

 while(s2)
 {
	s1=++s2;
	s2=ahmadStrchr(s1,'.',localLocatePoint1);
	strncpy(varName1,s1,localLocatePoint1);
    varName1[localLocatePoint1]=NULL ;
	nameString1=varName1;
	xx=findName(nameString1);
	if(xx.b)
	  resArr1=resArr1.concat(xx.val);
	else
	{
	  containPreName1=variableValue(varName1);
	  resArr1=resArr1 .concat( containPreName1);
	}
	if(s2)
	  resArr1=resArr1.concat( pointContVar12);
 }
 resArr1.getStr(nameString1);
 if(isInExposeList(nameString1))
  exFile->addArrNameInUpFunc(nameString1,vv1);
	
 else
	 arrayTable.addArrTable(nameString1,vv1);


}
valBool execProcCls::findArr(stringCls &name123)
{
 valBool  xx ;
 xx.b=false;
 char *s1;
 int i1 =name123.size_of_str();
 s1=new char[i1+4];
 name123.get_p(s1) ;
 int localLocatePoint1;
 char *s2=ahmadStrchr(s1,'.',localLocatePoint1);
 if(!s2)
	error(1,"AHMAD PROGRAMMER ERROR IN FIND ARR IS NOT A ARRAY ");
 char varName1[MAX_LENGTH_OF_NAME];
 strncpy(varName1,s1,localLocatePoint1);
 varName1[localLocatePoint1]=NULL ;
 stringCls nameString1=varName1;
 char *pointCont12=".";
 variableValue pointContVar12=variableValue(pointCont12);
 variableValue resArr1=varName1;
//  cout<<endl;
// cout<<curProc->getName()<<"     findArr   "<<s2<<"     "<<resArr1<<endl;
// myDebugKey(localLocatePoint1," in find aRRarygbbr  ");

 variableValue containPreName1=pointCont12;
 resArr1=resArr1.concat(pointContVar12);

 valBool xb1=findStem(resArr1);
 valBool xb2;xb2.b=false;

 while(s2)
 {
	s1=++s2;
	s2=ahmadStrchr(s1,'.',localLocatePoint1);
	strncpy(varName1,s1,localLocatePoint1);
	 varName1[localLocatePoint1]=NULL ;
	nameString1=varName1;

	xx=findName(nameString1);

	if(s2)
	{
	  xb2=findStem(resArr1);
	  if(xb2.b)
		 xb1=xb2;
	}
	if(xx.b)
	 { resArr1=resArr1.concat(xx.val);

	 }
	else
	{
	  containPreName1=variableValue(varName1);
	  resArr1=resArr1.concat( containPreName1);
	}
	if(s2)
	  resArr1=resArr1.concat(pointContVar12);
 }
 resArr1.getStr(nameString1);


 if(isInExposeList(nameString1))
 {
	xx=exFile->findNameArrInUpFunc(nameString1);

 }
 else
	 xx=arrayTable.search(nameString1);
 if(xx.b==false)
	if(xb1.b==true)
		xx=xb1;
	else
	  xx.val=variableValue(nameString1);
 xx.b=true;
 return xx;
}

int execProcCls::getToken(void)
{return expr.getToken();}
tokenContainCls  execProcCls::getCurToken(void)
{return expr.getCurToken();}
EtokenType  execProcCls::getTokenType(void)
{return expr.getTokenType();}
void execProcCls::initExpr(void){indexExpr = 0 ;}
void execProcCls::initNextExpr(void)
{ curExpr=curStmt->getExpr(indexExpr++);
  if(!curExpr)   error(1);
  expr.init(curExpr);
}
variableValue execProcCls:: exprssion(void)
{ return expr.exprssion(curExpr);}
void execProcCls::setValInt(void){indexValInt =0  ; }
int execProcCls::getNextValInt(void)
{ return curStmt->getValInt(indexValInt++); }
void execProcCls::initNextStmt(void)
{
  curStmt=curProc->ccs[stmtNo++];
  if(!curStmt)    error(2);
}
EinstructionWord execProcCls::getStmtType(void){return curStmt->getEiw();}
void execProcCls::skipStmt(int i1){ setStmtNo(i1); }
variableValue execProcCls::exprStmt(void)
{initNextExpr();variableValue vv1=exprssion();return vv1;}
void execProcCls::setStmtNo(int curStmtNo){stmtNo = curStmtNo ;}
bool execProcCls::leaveIsDetect(void)
{bool bb1 = false  ;
 if(leaveNumber &&leaveNumber<= noLoop) bb1 = true ;
 else leaveNumber = 0 ;
 return bb1 ;
}
void  execProcCls::leaveStmt(void){leaveNumber=noLoop;}
void  execProcCls::leaveContStmt(void){leaveNumber=getNextValInt();}
valBool execProcCls::run(fCallContCls &tt1)
{
 valBool retVal;
 retVal.val=variableValue("");
 retVal.b=false;
 EinstructionWord est1;
 argStmt(tt1);
 compoundStmtExe(curProc->getSize(),1);
 if(leaveNumber<0)
	if(leaveNumber==-1)
		exitStmtDetect();
	else if(leaveNumber==-2)
	{retVal.val=resultValue;retVal.b=true;}
 setGlobalResultVar(retVal.val);
 return retVal;
}
void execProcCls::error(int i)
{if(i==1) myDebugKey(1,":::ahmad programmer::::: cur Expr is Zero ");
 else if(i==2)
	myDebugKey(1,":::ahmad programmer::::: cur Stmt is Zero ");
 else if(i==3 )
  myDebugKey(1,":::ahmad programmer::::: cur Stmt is not correct stmt  ");
 else if(i==4)
  myDebugKey(1,":::ahmad programmer::::: in assign stmt the left value not correct  ");
 exitProgram(0) ;
}
void execProcCls::exitStmtDetect(void)
{exFile->exitStmtDetect();}
void execProcCls::setGlobalResultVar(variableValue retVal)
{exFile->setGlobalResultVar(retVal); }
variableValue execProcCls::callFunction(fCallContCls &tt)
{
 valBool  vb1=exFile->callFunction(tt);
 return vb1.val;
}
void  execProcCls::argStmt(fCallContCls &ft1)
{int ii1 = ft1.size(),j;
  variableValue vv1;
 int noOfArg=curProc->noOfArgList;
 if(noOfArg ==ii1)
 {
	 for(j=0;j<ii1;j++)
	  addVariable(curProc->getArg(j),ft1.getArg(j));
 }
 else if(noOfArg <ii1)
 {
	if(noOfArg)
	{
	 for(j=0;j<noOfArg-1;j++)
	  addVariable(curProc->getArg(j),ft1.getArg(j));
	 for(;j<ii1;j++)
		 vv1=vv1.concat(ft1.getArg(j));
	  addVariable(curProc->getArg(noOfArg-1),vv1);
	}
 }
 else
 {  char *pp22="";
	 vv1=variableValue(pp22);
	 for(j=0;j<ii1;j++)
	  addVariable(curProc->getArg(j),ft1.getArg(j));
	 for(;j<noOfArg;j++)
			  addVariable(curProc->getArg(j),vv1);
 }
}
void execProcCls::addVariable(stringCls &name1,variableValue &vv1)
{
	 if(isInExposeList(name1))
		 exFile->addNameInUpFunc(name1,vv1);
	 else
		 varTable[name1]= vv1;
}
void execProcCls::error(int i,char *str1)
{
  myDebugKey(i,str1);
  exitProgram(0);
}

