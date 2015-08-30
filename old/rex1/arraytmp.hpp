#ifndef ARRAYTMP_HPP
#define ARRAYTMP_HPP
template class<T> class arrayTempCls{
  T **data ;int index ;int max ;int err;
  error1(int ii1)
  {if(ii1 == 1)
    cout << " AHMAD PROGRAMMER ERROR THE VALUE OF ARRAY TMP == 0 "<<endl;
   else
    cout << " NOT ENUGH MEMORY         " <<endl;
   exit(0);
  }
 public :
   arrayTempCls(int m= 10 )
   {
     if(m <= 0)
       error1(1);
     data = new (T *)[max = m] ;
     for(int i =0 ; i<max;i++)
       *(data+i) = long(0);
     index = 0 ;
     err = 0;
   }
   int isError(void)
   { return err;}
   int getIndex(void){return index;}
   int getMax(void) {return max;}

   void add(T *dt)
   {if(index<max)  *(data+index++) = dt;else }
   void add(T *dt , int ii1 )
   { if(ii1<max) {*(data+index++) = dt; index = ii1;} }
   T *get(void) { return *(data+index++) ; }
   T *get(int i1){ if(i1<max) return *(data+i1); return long(0); }
   ~arrayTempCls(void)
   {  delete[] data;}
};
#endif