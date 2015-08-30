#include"all.hpp"
// valInt[0] == 0 not "otherwise" presented
// valInt[0] == 1  "otherwise"  presented  at valInt[2] the latest instr is presented
// in valInt[End] the no of statement is presented
bool parserCls::selectStmt(void)
{ bool bb2 = true,bb1;//containStmtCls *cts1=new containStmtCls;
  tokenContainCls tcd1=getCurToken(),tcd2 ;EtokenType e1 ;
  EinstructionWord ett1 = SelectInstr;initEiwCss(SelectInstr);
  int i=3 ,j,cts1valInt[MAX_OF_WHEN];
  bool  etlnoc;EinstructionWord est;cts1valInt[0]=0 ;
  getToken();bb2 = endWhiteLine(); ///select should be in one line
  if(bb2) bb2=syncSelect();
  do
  {bb1 =true;skipWhiteLine();e1=getTokenType() ;
   if(i>MAX_OF_WHEN -2)
   {bb1=false;errorSelect(tcd1,tcd2,1);break;}
   if(e1==When)
   { j = stmtNo;
     if(exprShould(ett1) ) addExprToStmt(i-3)  ;//  addExprToStmt(cts1,i)  ;
     else  bb1 = false;
   }
   else   bb1 = false ;
   if(!bb1)
     syncErrorThen();
   cts1valInt[i] = stmtNo;e1 = getTokenType();tcd2=getCurToken();
   if(e1 ==Then){
     getToken();
     if(!callStmt(etlnoc , est) ) errorCallStmt(tcd1 , tcd2);
   }
   else   errorSelect(tcd1 , tcd2,0);
   skipWhiteLine();
   i++;
  }while( (e1=getTokenType() ) == When ) ;
  if(e1 == Otherwise ){
    cts1valInt[0] =1 ;cts1valInt[i] = stmtNo;i++;tcd2=getCurToken();
    getToken();int a2=0;bb2 =compoundStmt(tcd1 ,a2);
    cts1valInt[i++] = a2 -1;
  }
  else {
     skipWhiteLine();
     if((e1=getTokenType()) !=End)
	errorSelect(tcd1,tcd2,2);
     else
	getToken();
 }
  cts1valInt[2] =stmtNo;cts1valInt[1]=i;//css=cts1;
  noOfValInt=i;
  for(int j1=0;j1<i;j1++) valInt[j1]=cts1valInt[j1];
  return bb2 ;
}