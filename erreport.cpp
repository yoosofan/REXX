#include"all.hpp"
#include<fstream.h>
extern outputRexx out1 ;
fileContainCls *file1;
int errorReportCls::loadFileError(void)
{
 file1=new fileContainCls("errormsg.hlx");

}

int errorReportCls::deleteFileError(void)
{
 (* file1).~fileContainCls();
}
errorReportCls::errorReportCls(EerrorType e1 , char *name)
{ noError++   ;
	char buff[250];
	file1->getLineI(buff,e1);
/*
	switch( e1)
	{
	 case CanNotOpenFile :

		 // open the database of error and report the error
		 fileError<< " CAN NOT OPEN FILE ::\n"<<name << "\n" ;
		 out1 << " CAN NOT OPEN FILE ::\n"<<name << "\n" ;
	break ;
	case CanNotReadFile :
		 // open the database of error and report the error
		 fileError<<" CAN NOT READ FILE  :: " << name   ;
		 out1 <<" CAN NOT READ FILE  :: \n" << name   ;
	break ;
  }
  */
 fileError<<buff<<endl;
 out1<<buff;
}
void    errorReportCls:: report(EerrorType e1 ,char *nameFile , int *ni,char *lineError)
//errorReportCls::errorReportClsEerrorType e1 ,char *nameFile , int *ni)(
{
char strError1[250];
strcpy(strError1,"no error");
bool bb1=false;
file1->getLineI(strError1,e1);
noError++;
fileError<<"\n"<<"\n"<<noError;
out1<<"\n"<<"\n"<<noError<<"_";
/*
switch (e1)
{
case UnmatchComment:
 fileError<< " UNMATCH  COMMENT IN FILE :::"<<nameFile ;
 out1<< " UNMATCH  COMMENT IN FILE :::"<<nameFile ;
break ;
case CanNotPointDuplicate:
 fileError <<"you can not point after point deffer from IBM REXX " <<"\n" ;
 out1 <<"you can not point after point deffer from IBM REXX \n" <<"\n" ;
break ;
case AfterPointShouldBeNumber:
 fileError <<" AfterPointShouldBeNumber:" <<"\n" ;
 out1  <<"AfterPointShouldBeNumber:\n"  ;
break ;
case AfterEShouldBeNumber:
 fileError <<"in scince number after E should be number" <<"\n" ;
 out1 <<"in scince number after E should be number\n" ;
break ;
case UnMathQuote:
 fileError <<"un match quote  " <<"\n" ;
 out1 <<"un match quote  \n"  ;
break ;
case  UnExpectedCharacter:
 fileError<<" _ unExpectedCharacter  " <<char(ni[4]) <<"\n" ;
 out1    <<" _ unExpectedCharacter  " <<char(ni[4]) <<"\n" ;
break ;
case UnmatchParantes:
 fileError <<" rparen ::: ')'::: expected " <<"\n";
 out1 <<" rparen ::: ')'::: expected \n";
break ;
case needTokenInParen:
 fileError <<" value between  ::: '( )'::: expected " <<"\n";
 out1 <<" value between  ::: '( )'::: expected \n" ;
break ;
case UnExpectedToken:
 fileError <<" this token unExpected " <<"\n";
 out1 <<" this token is  unExpected \n" ;
break ;
case AfterAssignShouldExpr:
 fileError <<" AFTER ASSIGNMENT SHOULD BE AN EXPRESSION :: " <<"\n";
 out1 <<" AFTER ASSIGNMENT SHOULD BE AN EXPRESSION :: \n" ;
break ;
case AfterStmtEndStmt:
 fileError <<" AFTER STATEMENT SHOULD BE A SEMICOLON OR ENDLINE 'N'  :: " <<"\n";
 out1<<" AFTER STATEMENT SHOULD BE A SEMICOLON OR ENDLINE 'N'  :: \n";
break ;
case  AfterExitNotExpr:
 fileError <<" AFTER EXIT STATEMENT SHOULD NOT ANY EXPRSSION :: " <<"\n";
 out1<<" AFTER EXIT STATEMENT SHOULD NOT ANY EXPRSSION :: \n" ;
break ;
case  AfterCommaShouldName:
 fileError <<"AFTER comma SHOULD BE A NAME OF VARIABLE .DEFFERRNT ROM IBM REXX:: " <<"\n";
// fileError <<"IN IBM REXX YOU CAN CONTINUE A INSTRUCTION TO OTHER LINE "<<"\n" ;
// fileError <<" BUT HERE THIS NOT IMPLEMENTED  " <<"\n";
 out1 <<"AFTER comma SHOULD BE A NAME OF VARIABLE .DEFFERRNT ROM IBM REXX:: \n";
// out1 <<"IN IBM REXX YOU CAN CONTINUE A INSTRUCTION TO OTHER LINE \n" ;
// out1 <<" BUT HERE THIS NOT IMPLEMENTED  \n";

break ;
case   OnlyNameExpectedPA:
 fileError <<"IN ARG AND PULL INSTRUCTION ONLY VAR NAME AND ARRAY EXPECTED " <<"\n";
// fileError <<"YOU CAN'T DISPLAY MESSAGE IN PULL STATEMENT  "<<"\n" ;
// fileError <<" IN REXX IBM YOU CAN DEIPLAY MEESAGE IN  PULL INSTRUCTION" <<"\n";
 out1 <<"IN ARG AND PULL INSTRUCTION ONLY VAR NAME AND ARRAY EXPECTED " <<"\n";
// out1 <<"YOU CAN'T DISPLAY MESSAGE IN PULL STATEMENT  "<<"\n" ;
// out1 <<" IN REXX IBM YOU CAN DEIPLAY MEESAGE IN  PULL INSTRUCTION" <<"\n";
break ;
case   NameExpectedAfterComma:
 fileError <<"IN ARG AND PULL INSTRUCTION VAR NAME AND ARRAY EXPECTED AFTER COMMA." <<"\n";
// fileError <<"YOU CAN'T DISPLAY MESSAGE IN PULL STATEMENT  "<<"\n" ;
// fileError <<" IN REXX IBM YOU CAN DEIPLAY MEESAGE IN  PULL INSTRUCTION" <<"\n";
 out1 <<"IN ARG AND PULL INSTRUCTION VAR NAME AND ARRAY EXPECTED AFTER COMMA." <<"\n";
// out1 <<"YOU CAN'T DISPLAY MESSAGE IN PULL STATEMENT  "<<"\n" ;
// out1 <<" IN REXX IBM YOU CAN DEIPLAY MEESAGE IN  PULL INSTRUCTION" <<"\n";
break ;
case  ExprExpected:
 fileError <<" exprddion needed  here  :: " <<"\n";
 out1<<"  EXPRSSION  NEEDED HERE :: " <<"\n";
break ;
case UnExpectedUnary:
 fileError <<"after unary operator you can not use )  or constant String " <<"\n" ;
 out1  <<"after unary operator you can not use )  or constant String " <<"\n" ;
break ;
case TwoArgStmt:
 fileError <<"TWO ARG INSTRUCTION IN ONE PROCEDURE !!!!! " <<"\n" ;
 out1  <<"TWO ARG INSTRUCTION IN ONE PROCEDURE !!!!! " <<"\n" ;
break ;
case MaxLineInProcedure :
 fileError <<"GREATER THAN THE MAXIMUM OF LINE IN ON PROCEDURE " <<"\n" ;
 out1  <<"GREATER THAN THE MAXIMUM OF LINE IN ON PROCEDURE " <<"\n" ;

break ;
case NoStatementInProc:
  fileError <<"EXPECTED INSTRUCTION PROCEDURE EMPTY!!!!" <<"\n" ;
  out1 <<"EXPECTED  INSTRUCTION  PROCEDURE EMPTY!!! " <<"\n" ;
break ;
case UnExpectedEndInstr:
  fileError <<"unExpectd END INSTRUCTION " <<"\n" ;
  out1 <<"UNEXPECTED END INSTRUCTION  " <<"\n" ;
break;
case UnExpectedInstruction:
  fileError <<"UNEXPECTED INSTRUCTION " <<"\n" ;
  out1 <<"UNEXPECTED  INSTRUCTION  " <<"\n" ;
break;
case ExprssionNeeded:
 bb1= true;
 strcpy(strError1," EXPRSSION NEEDED HERE ");
break;
case MaximumLengthOfNameError:
 bb1=true;
 strcpy(strError1," MAXIMUM OF LENGTH NAME REACHED ");
break;

case ThenNeeded:
 bb1= true;
 strcpy(strError1," THEN NEEDED HERE ");
break;
case EndExpectedNoEOF:
 bb1= true;
 strcpy(strError1," END INSTRCUCTION EXPECTED  EOF ENCOUNTER ");
break;
case EndExpectedNoLabel:
 bb1= true;
 strcpy(strError1," END INSTRCUCTION EXPECTED  NO LABEL ");
break;
case AssignExpectedInDoTo:
 bb1= true;
 strcpy(strError1," ASSIGN EXPECTED IN  do to  INSTRUCTION");
break;
case NameOfConVarExpected:
 bb1= true;
 strcpy(strError1," NAME OF CONTROL VARIABLE EXPECTED ");
break;
case MaxOfWhen:
 bb1 =true;
 strcpy(strError1," MAXIMUM OF WHEN IN SELECT IS 300");
break;

case ControlVarTwoSame:
 bb1= true;
 strcpy(strError1," CAN NOT HAVE TWO CONTROL VARIABLE WITH THE SAME NAME");
break;
case ControlVarNotFound:
 bb1= true;
 strcpy(strError1," THE NAME AFTER LEAVE INSTRUCTION IS NOT A CONTROL VARIABLE ");
break;
case LeaveShouldInLoop:
 bb1= true;
 strcpy(strError1," leave instruction should be in  any loop " );
break;
case AfterLeaveOnlyName:
 bb1= true;
 strcpy(strError1," after leave should be only  a  ( Name ) or (Array) ");
break;
case AfterThenShouldStmt:
 bb1= true;
 strcpy(strError1," AFTER THEN SHOULD BE INSTR ");
break;
case InWhenThenNeeded:
 bb1= true;
 strcpy(strError1,"IN  Select  THEN NEEDED HERE  ");
break;
case AfterExposeShouldName:
 bb1 = true ;
 strcpy(strError1," AFTER EXPOSE SHOULDE BE NAME ");
break;
case AfterSelectShouldEnd:
 bb1 =true;
 strcpy(strError1," AFTER SELECT SHOULD ' END ' ");
break;

}
*/
// if(bb1)
 fileError <<strError1<<"\n" ;
 out1 <<strError1 ;
 fileError<< nameFile<<"  NAME FILE IS :::" ;
 fileError<<"line of error ::: "<<  ni[1]<<"\n" ;
 fileError<<"offset error ::: " << ni[2]<<"\n" ;
 fileError<< "absolute position of error in file ::::"<<ni[3]<<"\n";
 out1<< nameFile<<"	NAME FILE IS 	:::" ;
 out1<<"line of error ::: "<<  ni[1]<<"\n";
 out1<<"offset error ::: " << ni[2]<<"\n" ;
 out1<< "absolute position of error in file ::::"<<ni[3]<<"\n";
 cout<<" line of error is "<<endl;
 cout<<lineError<<endl;
 myDebugKey(noError,"PRESS ANY KEY TO CONTINUE ...");
}