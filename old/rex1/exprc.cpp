#include"all.hpp"

void exprContainCls::setReverse(exprContainCls &ec1)
{noVInStack =0;maxVal = ec1.noVInStack;
 for(int i =0; i<maxVal; i++) push(ec1.pop());
}
void exprContainCls::copy(exprContainCls &ec1)
{noVInStack =0;maxVal = ec1.noVInStack;
  for(int i =0; i<maxVal; i++) push(ec1.geti(i));
}

void exprContainCls::error(char *pp1)
{
  cout<<" noVInStack"<<noVInStack<<"max "<<maxVal<<endl;
	for(int i1=0;i1<noVInStack;i1++)
		cout<<pop()<<endl;
	 myDebugKey(1,pp1);
	exitProgram(0);
}
 void exprContainCls::print(void)
 {
//	outDebugError<<"noVInStack "<<noVInStack <<" maxVal "<<maxVal<<"\n";
//	outDebugError.flush();
//	for(int ii1=0;ii1<noVInStack;ii1++)
//	{ outDebugError<<geti(ii1);outDebugError.flush();}
 }
