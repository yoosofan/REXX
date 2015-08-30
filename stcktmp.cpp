#include"stackcls.hpp"

template < class T>
void stackCls<T>::resize(void)
{ T *t1 = new T[max+max ];if(!t1)    error();
  for(int i=0 ;i<max; i++)     t1[i]= data[i];
	  delete[] data ;
  data = t1 ;max +=max ;
}
