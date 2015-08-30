#ifndef EXPRCONT_HPP
#define EXPRCONT_HPP
#include"all.hpp"
#include"stackcls.hpp"
extern ofstream outDebugError;
class exprContainCls : public  stackCls<tokenContainCls> {
//   friend TOstream& operator<<(TOstream &aa1,exprContainCls &bb1);
	int noVInStack ;int maxVal;
	void error(char *pp1);
	exprContainCls(exprContainCls & tec1);
	void operator=(exprContainCls &);
 public :
	exprContainCls(void):stackCls<tokenContainCls>(MAX_TOKEN_EXPR)
	{noVInStack = 0 ; maxVal=MAX_TOKEN_EXPR ;}
	exprContainCls(int noToken):stackCls<tokenContainCls>(noToken)
	{noVInStack=0;maxVal=noToken;}
// this function shoulud after the above functon
	void setReverse(exprContainCls &ec1);
	void copy(exprContainCls &ec1);
	/*   exprContainCls(exprContainCls &ec1):stackCls<tokenContainCls>(ec1.noVInStack)
	{noVInStack = maxVal = ec1.noVInStack;
	 for(int i =0; i<maxVal; i++) push(ec1.pop());
	}
*/
	int size(void){ return noVInStack; }
	void push(tokenContainCls  v1)
	{
	 if(noVInStack < maxVal)
	 { Push(v1);
		//cout<<v1;myDebugKey(1,"in push expr ");
		noVInStack++;
	 }
	 else error("standard stack of exprssion overflow in EXPRCONT.HPP");
	}
 tokenContainCls pop(void)
 {if(noVInStack) noVInStack -- ;
  else  error("standard stack of exprssion underflow in EXPRCONT.HPP");
  return  Pop();
 }
 tokenContainCls geti(int ii1)
 { if(!(ii1<noVInStack && ii1>=0))
	  error("standard stack over or under flow in exprCont.hpp in execute ");
//  if( heapcheck() == _HEAPCORRUPT )
//{   cout<< "Heap is corrupted.in exprcont.hpp  tokenContainCls geti(int ii1)\n" ;exitProgram(1);}

	return getIndex(ii1);
 }
 void change(int loc1,tokenContainCls tt1){Change(loc1,tt1);}
 tokenContainCls top(void){return  Top();}
 void clear(void){noVInStack=0;init();}
 int getMax(void){return maxVal;}
 int getNov(void){ return noVInStack ;}
 void print(void);
};
#endif
