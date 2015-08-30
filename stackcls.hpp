#ifndef STACKCLS_HPP
#define STACKCLS_HPP

#include"global.hpp"
#include<stdlib.h>
#define MAX_STACK_SIZE12  20
class far exprCls;
template < class T > class stackCls{

  T *data ;int max ;int current ; bool resizeAble;
//  void resize(void);
  void error(void)
  { myDebugKey(1, " NOT ENUGH MEMORY IN STACKCLS ");exit(0); }
public:
  stackCls(int  m = MAX_STACK_SIZE12  , bool  rr = false )
  { data = new T[max=m];
    if(!data)   error();
       current = 0 ;
    resizeAble = rr;
  }
  ~stackCls(void){ delete[] data;}
  void Push(T &t1 )
  { if(current>=max)
	  // if(resizeAble)	resize();
	  current--;
	 data[current++]=t1 ;
  }
  T & Pop(void)
  { if(current)  current--;
     return data[current];
  }
  T  getIndex(int ii1)
  { if(!((ii1<max)&&(ii1>=0))) ii1=0;
    return data[ii1];
  }

  T & Top(void){return data[current ? (current-1) : current];}
  bool isEmpty() const
  {return bool(current == 0); }
   bool isFull() const	{   return bool(current == max-1);  }
   void Change(int loc1, T tt1)
   {if(loc1 < current)data[loc1] = tt1;
    else{
     myDebugKey(0, " programmer ERROR CAN NOT CHANGE THE STACK IN THIS PART");
     exitProgram(0);
    }
  }
/*    int getItemsInContainer() const{return current;} */


 protected:
    void init(void) { current = 0 ;}
   void flush(void){delete[] data ; current = 0; }
// friend void exprCls::init(exprContainCls *e1);
};
#endif