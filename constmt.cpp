#include"all.hpp"
void containStmtCls::addValInt(int no,int *data)
{ if(valInt) delete[] valInt;
	 valInt= new int[noOfValInt=no];
	 for(int i1=0;i1<no;i1++)valInt[i1]=data[i1];
}
 void containStmtCls::print(void)
  {
	char pp1[50];
/* if(instrFind(eiw ,pp1))
  outDebugError<<"eiw of instr is "<<pp1<<"\n";
 else
 { outDebugError<<" ERROR THE INSTR IS ERROR  EIW   EIW " <<"\n";return; }
 if(eiw==NoInstr)  return ;
 */
  ecs.evalSize();
  /*
 outDebugError<<"line stmt is "<<lineStmt;
 outDebugError<<"no Of Val Int  is "<<noOfValInt;
 outDebugError<<"noEcs "<<noEcs<<"\n";
 outDebugError.flush();
 if(valInt)
 { outDebugError<<" the value of int is \n";
	for(int ii1=0;ii1<noOfValInt;ii1++)
	 outDebugError<<valInt[ii1]<<"     ";
	outDebugError<<"\n";

 }
 outDebugError.flush();

// myDebugKey(ecs.size()," next stmt ");
// myDebugKey(eiw,pp1);

 for(int i1=0;i1<ecs.size();i1++)   ecs.getPi(i1)->print();
*/
 }  