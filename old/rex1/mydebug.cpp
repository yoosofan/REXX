
#include"all.hpp"
#include<stdlib.h>

struct ttr{
     char *p1;
     EinstructionWord e1;

     }   ;
 ttr aaa1[]=
     {
	{"ArgInstr", ArgInstr },
	{"AssignInstr" , AssignInstr},
	{ "DoInstr", DoInstr},
	{ "DoUntilInstr",DoUntilInstr},
	{ "DoForInstr", DoForInstr },
	{ "DoForEverInstr" ,DoForEverInstr},
	{ "DoWhileInstr",DoWhileInstr } ,
	{ "DoToInstr", DoToInstr},
	{ "DoToByInstr",DoToByInstr} ,
	{ "ErrorInstr" , ErrorInstr },
	{ "ExprInstr" ,ExprInstr } ,
	{ "ExitInstr",ExitInstr },
	{ "EndOfFileInstr",EndOfFileInstr},
	{ "EndInstr",EndInstr},
	{ "IfInstr"  ,IfInstr },
	{ "IfElseInstr",IfElseInstr},
	{ "LabelInstr" ,LabelInstr },
	{ "LeaveInstr" ,LeaveInstr  },
	{ "LeaveContInstr",LeaveContInstr},
	{ "NopInstr",NopInstr },
	{ "NoInstr",NoInstr},
	{ "PullInstr",PullInstr},
	{ "ReturnInstr",ReturnInstr},
	{ "ReturnOnlyInstr",ReturnOnlyInstr},
	{ "SayInstr" ,SayInstr},
	{ "SelectInstr",SelectInstr},
	{  NULL , 0}
};


struct ttr3 {
   char *p1 ;
   EtokenType  e1;
   };

 ttr3 bbb2[] ={
   {"And",And},
   {"AnyCharacters" ,AnyCharacters},
   {"AnyCharactersWithSpace",AnyCharactersWithSpace},
   {"Arg",Arg},
   {"Array",Array},
   {"Assign",Assign},
   {"By",By},
   {"Colon" ,Colon},
   {"Comma",Comma},
	 {"Concat" ,Concat},
   {"Div" ,Div},
   {"Do",Do},
   {"DoUntil" ,DoUntil},
   {"DoFor" ,DoFor},
   {"DoForever" ,DoForever},
   {"DoWhile" ,DoWhile},
   {"DoTo" ,DoTo},
   {"DoToBy",DoToBy},
   {"Else",Else},
   {"End",End},
   {"Eq",Eq},
   {"Error",Error},
   {"Expose",Expose},
   {"ExEq",ExEq},
   {"ExOr",ExOr},
   {"Eof",Eof},
   {"EndOfLine",EndOfLine},
   {"EndOfFile",EndOfFile},
	 {"Exit",Exit},
   {"For" ,For},
   {"ForEver" ,ForEver},
   {"FunctionName",FunctionName},
   {"Ge",Ge},
   {"Gt",Gt},
   {"If",If},
   {"IfElse",IfElse},
   {"Label",Label},
   {"Le",Le},
   {"Leave",Leave},
   {"Lparen",Lparen},
   {"Lt",Lt},
   {"Mul",Mul},
   {"Minus",Minus},
   {"Mod",Mod},
   {"Name" ,Name},
   {"Ne",Ne},
   {"NoToken",NoToken},
	 {"Not",Not},
   {"Nop",Nop},
   {"OrdNumber",OrdNumber},
   {"Or",Or},
   {"Otherwise",Otherwise},
   {"Plus",Plus},
   {"Pow",Pow},
   {"Procedure",Procedure},
   {"Pull",Pull},
   {"Return",Return},
   {"Rparen",Rparen},
   {"Say",Say},
   {"Select",Select},
   {"Stem",Stem},
   {"String",String},
   {"SciNumber",SciNumber},
   {"Semicolon",Semicolon},
   {"Then",Then},
   {"To",To},
	 {"Until",Until},
	 {"UnaryPlus",UnaryPlus},
	 {"UnaryMinus",UnaryMinus},
	 {"While" ,While},
	 {"When",When},
	 {NULL ,0 }
 };



bool instrFind(EinstructionWord e1 ,char * p1)
{
		int i =0  ;
		bool bb1 = false;
		for(;aaa1[i].p1 ;i++ )
	if(aaa1[i].e1 == e1 )
	{
		strcpy(p1, aaa1[i].p1);
		bb1 = true ;
		break;
	}
	return bb1  ;

}
bool tokenFind(EtokenType e1 ,char*  p1)
{
		int i =0  ;
		bool bb1 = false;
		for(;bbb2[i].p1 ;i++ )
	if(bbb2[i].e1 == e1 )
	{
		strcpy(p1, bbb2[i].p1);
		bb1 = true ;
		break;
	}
	return bb1  ;

}
/*
void parserCls::lineAddedPDP(void)
{    int i =0 ;
//		  parserCheckOut <<" StmtNo ======= " << stmtNo <<endl ;
//cout <<" inline adeed pdp" << endl;
		  parserCheckOut <<"////////////////////////////////////////////////"<<endl;
		  char pp1[50];
		  int j12 = 0;
//		  exprContainCls *pExpr;
		  for(mapiter<int ,exprContainCls> p = css.ecs.first() ;p ; p++)
			{             pp1[0]='\0';
				parserCheckOut <<endl<<endl;
				parserCheckOut <<"NEXT EXPRSSION IN STMT IS ::: " <<p.key()<<endl;
				instrFind(css.eiw , pp1);
				parserCheckOut <<"INSTRUCTION TYPE "<< css.eiw <<"   "<<pp1<<" =====  "<<endl ;
//				parserCheckOut <<"LINE STATEMENT " << css.lineStmt<<endl ;
//				pExpr = & (css.ecs[j12++]);
//				pExpr->evalSize() ;
//				myDebugKey( (css.ecs[j12++]).evalSize() , " evalSize() ==" );
//				myDebugKey((css.ecs[j12-1]).size()  , " size()======== ");
	//				tokenContainCls uu=(p.value())[0];
//				parserCheckOut <<uu;
//				uu= (p.value())[1];
//				parserCheckOut <<uu;
				for(mapiter<int ,tokenContainCls> p2 = p.value() ;p2 ; p2++ ,i++)
				{  if(i>32000)
						return;
					pp1[0]='\0';
					tokenContainCls ttcc1 = p2.value();
	//					parserCheckOut <<endl <<endl;
//               parserCheckOut <<"            p2.key()    " <<p2.key()<< endl ;;
					parserCheckOut <<"NEXT TOKEN::: " <<p2.key();//<< endl;
					tokenFind(ttcc1.type , pp1);
					parserCheckOut <<"TYPE IS ::: " << ttcc1. type<<"  " <<pp1<<" ===== " ;// << endl ;
//					parserCheckOut <<"NAME VAR IS :::" <<ttcc1. nameVar<< endl ;
					parserCheckOut <<"number VAR IS ::: " <<ttcc1. d<< endl ;

	//					parserCheckOut <<"START POS :::  " <<ttcc1. start <<endl;
		//					parserCheckOut <<"LINE TOKEN IS::"<< ttcc1.line << endl;
			//					parserCheckOut <<"OFFSET TOKEN IS :::"<<ttcc1. offset <<endl;
				}

		 }

				parserCheckOut<<endl<<endl;
				parserCheckOut <<"list of numbers in instruction:::" <<endl ;
//			for(mapiter<int ,int > p3 = css.valInt ;p3 ; p3++)
//					parserCheckOut <<"TYPE IS ::: " << p3.value() << endl ;
//		parserCheckOut  <<"///////////////////////////////////////////////////"<<endl;
//	 cout <<endl<<"in lineaddedpdp::::PRESS ESCAPE FOR END "<<endl ;
//	 char ch1= getch();
//	 if(ch1 == 27)
//		exit(0);
//cout <<"////////////////////////////////////////////////"<<endl;
}
*/