#include"contvar.hpp"
//#include"contvar.hpp"
int cvContain::search(stringCls  &t1)
{
 int i;
 if(index)
  for(i= index ; i+1 ; i-- )
	if( t1 == ( tcc[i].tcc) )
		 return tcc[i].nLoop;
 return 0;
}
