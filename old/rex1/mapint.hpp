// linkInt::value is pointer to object V
#ifndef MAPINT_HPP
#define MAPINT_HPP
#include"global.hpp"
template <class V >class mapIntCls;
template <class V >class mapiterIntCls ;
template <class V >class linkInt {
friend class mapIntCls<V>;
friend class mapiterIntCls<V>;
	 V *value ;int key;linkInt *pre ;linkInt *suc ;
	 linkInt(void) { value = 0;key = -1 ;}
	 linkInt(V  *v, int k1) {value = v;key = k1;}
	 ~linkInt() {delete suc ;delete value;}
} ;
template <class V > class mapIntCls {
	friend class mapiterIntCls<V> ;
	linkInt<V> *head ;linkInt<V> *current ;int sz ;
	V *def_val;
	void find(int) ;
	void init(void){sz =0 ; head = 0 ; current=0 ; }
	mapIntCls(const V &d) ;//:def_key(k),def_val(d) {init();}
	mapIntCls(const mapIntCls&mp);
	mapIntCls<V> * & operator=(const mapIntCls<V> &mp);
 public :
	mapIntCls(void) {init() ;}
	~mapIntCls(void){delete head ;}
	V *& getCurValue(void)
	{ return current -> value ;}
   V *& operator[]( int) ;
   bool is_in_map(int ) ;
   V*  getPi( int k);
   int size(void) { return sz ; }
   int evalSize(void);
   void setSz(int ii);
   void clear(void) {if(head)delete head ;init() ;}
   void clearVObject(void);
   void remove(int );
	mapiterIntCls<V>  element(const int k )
   {(void) operator[](k);return mapiterIntCls<V>(this,current);}
   mapiterIntCls<V> first(void){return mapiterIntCls<V>(this,head);}
   mapiterIntCls<V> last(void) ;
} ;
template <class V >  class mapiterIntCls{
  friend class mapIntCls<V> ;
  mapIntCls<V> *m ;
  linkInt<V> *p ;
  mapiterIntCls(mapIntCls<V> *mm,linkInt<V>*pp){m=mm;p=pp;}
 public :
    mapIntCls<V> &  getMap(void ) {return *m;}
    mapIntCls<V> *  getMapPointer(void) {return m ;}
    void setOtherMap(mapIntCls<V> &mm){m=&mm;p=mm.head;}
    mapiterIntCls() { m=0 ; p=0 ;}
    mapiterIntCls(mapIntCls<V> &mm){m=&mm;p=m->head;}
    void set_p_cur(void){ p=m -> current ; }
    operator void*(void){ return p ;}
    int  key(void) ;
	 V *& value(void) ;
	 mapiterIntCls& operator--(void) ;
    void  operator--(int) ;
    void  operator++(int) ;
    mapiterIntCls& operator++(void) ;
};
template <class V >V* mapIntCls<V>::getPi( int k)
{
   bool bb1 = false ;
   if(head){
    linkInt<V> *p =head ;
    for(;;){
       if(p->key == k )
       {current = p ;bb1 = true ;break ;}
       if(k < p-> key )	break ;
       linkInt<V> *s = p -> suc ;
       if(s == 0 )	        break ;
       p = s ;
    }
   }
   if(bb1)  return (current->value) ;
	else     return long(0) ;
}
template <class V > void mapIntCls<V>::clearVObject(void)
{linkInt<V> *p = head ;
if(head){
  for(;;){
    delete p->value;p->value = 0;
    linkInt<V>*s=p->suc;if(s==0)break;p=s;
  }
}
}
template <class V >V *& mapIntCls<V>::operator[](int k)
{
  if( head == 0 ){
    current = head = new linkInt<V>;
    current -> pre = current -> suc =  long(0) ;
    current->key = k ;
    current->value=long(0);
    return current -> value ;
  }
  linkInt<V> *p =head ;
  for(;;){
     if(p->key == k ){current = p ;return current->value ;}
     if(k < p-> key ) {
       current = new linkInt<V>;
       current-> pre = p-> pre ;
       current -> suc  = p ;
       if(p == head )	 head = current ;
       else        p -> pre -> suc = current ;
       p -> pre = current ;
       current->value = long(0) ;
       current->key=k; 
       return current -> value;
     }
     linkInt<V> *s = p -> suc ;
	  if(s == 0 ){
       current = new linkInt<V>;current -> pre = p;
       current -> suc =long(0);current->key=k ;
       p -> suc = current;current->value=long(0);
       return current->value ;
	  }
	  p = s ;
//       if( heapcheck() == _HEAPCORRUPT )
//{   printf( "Heap is corrupted.in mapInt.hpp operator[] \n" );exitProgram(1);}

  }
}
template <class V >int  mapiterIntCls<V>::key(void)
{  if(p) return p-> key ;  else	return -1;}
template <class V > V *& mapiterIntCls<V>::value(void)
{
  if(p)
	 return p-> value ;
  else
	 return  m->def_val;
}
template <class V >
mapiterIntCls<V>& mapiterIntCls<V> ::operator--(void)
{if(p)	p = p-> pre ; return *this ;}
template <class V > void mapiterIntCls<V>::operator--(int)
{if(p)	p = p-> pre;}
template <class V>mapiterIntCls<V>& mapiterIntCls<V>::operator++(void)
{if(p)p =p-> suc ;return *this ;}
template <class V >void mapiterIntCls<V>::operator++(int)
{if(p)	p = p -> suc ;}
template <class V >bool mapIntCls<V>::is_in_map(int k)
{ if( head == 0 ) return false  ;
  linkInt<V> *p = head ;
  for(;;){
    if(p->key == k ) {current = p ;return true ; }
    if(k < p-> key )return  false  ;
    linkInt<V> *s = p -> suc ;
    if(s == 0 )	return false ;
    p = s ;
  }
}
template <class V >int mapIntCls<V>::evalSize(void)
{ sz = 0; linkInt<V> *p = head ;
  if(head){for(;;){sz++;linkInt<V>*s=p->suc;if(s==0)break;p=s;}}
 return sz ;
}
#endif