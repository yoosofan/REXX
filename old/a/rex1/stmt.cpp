#include"all.hpp"
bool parserCls::callStmt(bool &etlnoc,EinstructionWord &est)
{containStmtCls *pcss12 = css;bool bb12=statement(etlnoc,est);
 css=pcss12; return bb12;
}
bool  parserCls::statement(bool & etlnoc , EinstructionWord &est)
//est return the type of instruncton added
//etlnoc show the error occurred in instruction parse
{
 int curStmtNo= stmtNo;bool addLine =true;//,etlnoc = true;
 skipWhiteLine();EtokenType tt7 = getTokenType();
 initStmt();stmtNo++;
 switch(tt7){
	case Do       :   etlnoc= doStmt(); est = DoInstr; break ;
	case Say      :   etlnoc= sayStmt();est = SayInstr;break ;
	case End      :    est  = EndInstr;
	  if(inDo){ getToken();etlnoc= endWhiteLine();}
	  else{errorStmt(0);etlnoc = false ;}
	  addLine = false;stmtNo--;
	break ;
	case EndOfFile:addLine=false;est= EndOfFileInstr;stmtNo--;break;
	case Select   :etlnoc=selectStmt();est =SelectInstr;break;
	case Arg:etlnoc=argStmt();est=ArgInstr;addLine=false;stmtNo--;break;
	case Pull:etlnoc=pullStmt();est = PullInstr;break ;
	case If:etlnoc=ifStmt();est = IfInstr;break ;
	case Leave:etlnoc=leaveStmt();est = LeaveInstr;break ;
	case Exit:etlnoc= exitStmt();est=ExitInstr;break ;
	case Return:etlnoc= returnStmt();est=ReturnInstr;break ;
	case Nop:etlnoc= nopStmt();est= NopInstr;break ;
	default  :  // case  a=nfd  +2 ;or  nnf()
	 tokenContainCls tc7 = getCurToken();getToken();
	 EtokenType tt8 = getTokenType();
	 if( (tt7 ==  Name || tt7 == Array || tt7 == Stem) )
	 {if(tt8 == Eq ){etlnoc=assignmentStmt( tc7 );est  =AssignInstr;}
	  else if(tt8 == Colon)
     {ungetToken(tc7);est=LabelInstr;labelFound=true;addLine=false;stmtNo--;}
     else{ungetToken(tc7); est  =ExprInstr;etlnoc=exprStmt();}
    }
    else if((tt7 == SciNumber) || (tt7 == OrdNumber ) )
    { ungetToken(tc7); etlnoc= exprStmt();est=ExprInstr; }
    else
    {addLine=false;stmtNo--;errorStmt(1);est= ErrorInstr;etlnoc=false;}
 }
 if(!etlnoc) syncStmtError() ;
 if(addLine)   addNextLine(curStmtNo) ;
 else   clearStmt();
 return addLine;
}
bool  parserCls::skipWhiteLine(void)
{ bool b1 = true ; EtokenType et1 = getTokenType();
  if( (et1 == EndOfLine) || (et1 == Semicolon) )
    while((et1 == EndOfLine) || (et1 == Semicolon) )
    {getToken();et1 = getTokenType();}
    else  b1 = false ;
 return b1 ;
}
