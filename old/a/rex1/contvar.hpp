#ifndef CONTVAR_HPP
#define CONTVAR_HPP
#include"stringcl.hpp"
#define MAX_CONTROL_VAR     10
#include"global.hpp"
struct ts{
	 stringCls tcc;
	 int nLoop ;
};
class cvContain {
 ts tcc[MAX_CONTROL_VAR];
 int index;
public:
 cvContain(void) {index = 0 ; }
 void push(stringCls &t1,int n){tcc[index].tcc=t1;tcc[index++].nLoop=n;}
 void pop(void)
 {if(index) index--;
  else{
	 myDebugKey(index ," ahmad programmer ERROR IN CONTVAR.HPP POP UNEXPECTED ");
	 exitProgram(0);
  }
 }
 int search(stringCls  &t1);
};
#endif
/* contvar.cpp
#include"contvar.hpp"
int cvContain::search(stringCls  &t1)
{
  int i;
  for(i= index ; i+1 ; i-- )
	if( t1 == ( tcc[i].tcc) )
	    return tcc[i].nLoop;
	return 0;
}*/
