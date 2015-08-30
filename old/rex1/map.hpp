#ifndef MAP_HPP
#define MAP_HPP
#include"global.hpp"
template <class K ,class V >  class map;
template <class K ,class V >  class mapiter ;
template <class K ,class V >  class link {
friend class map<K ,V>;friend class mapiter<K ,V>;
  const K key;V value;link *pre;link *suc;
  link( const K & k, const V & v) :key(k),value(v){}
  ~link() {delete suc ;}
} ;
template <class K ,class V > class map {
  friend class mapiter<K,V> ;
  link<K,V> *head;link<K,V> *current;V def_val;K def_key;int sz;
  void find(const K&) ;
  void init(void){sz =0 ; head = 0 ; current=0 ; }
  map(const map&mp);
  map<K,V> & operator=(const map<K,V> &mp);
 public :
  map(void) {init() ;}
  map(const K &k , const V &d) :def_key(k),def_val(d) {init();}
  ~map(void){delete head ;}


  V& getCurValue(void) { return current -> value ;}
  V& operator[](const K&) ;
  bool is_in_map(const K &) ;
  V*  getPi(const K& k);
  int size(void) { return sz ; }
  int evalSize(void);
  void setSz(int ii);
  void clear(void) {if(head)delete head ;init() ;}
  void remove(const K & );
  mapiter<K,V>  element(const K &k )
  {(void) operator[](k);return mapiter<K,V>(this,current);}
  mapiter<K,V> first(void){return mapiter<K,V>(this,head);}
  mapiter<K,V> last(void) ;
} ;
template <class K ,class V >  class mapiter{
 friend class map<K,V> ;
 map<K,V> *m ;link<K,V> *p ;
 mapiter(map<K,V> *mm,link<K,V> *pp){m=mm;p=pp;}
public :
 map<K,V> &  getMap(void ) {return *m;}
 map<K,V> *  getMapPointer(void) {return m ;}
 void setOtherMap(map<K,V> &mm)
 {m =&mm ;p = mm . head ;}
 mapietr() { m=0 ; p=0 ;return 1;}
 mapiter(map<K,V> &mm){m=&mm;p=m->head;}
 void set_p_cur(void){p=m->current;}
 operator void*(void){ return p ;}
 const K& key(void) ;
 V& value(void) ;
 mapiter& operator--(void) ;
 void  operator--(int) ;
 void  operator++(int) ;
 mapiter& operator++(void) ;
};
template <class K,class V>V* map<K,V>::getPi(const K& k)
{bool bb1 = false ;
 if(head){  link<K,V> *p =head ;
  for(;;){
     if(p->key == k )
     {current = p ;bb1 = true ;break;}
     if(k < p-> key )break ;
     link<K,V> *s = p -> suc ;
     if(s == 0 )     break ;
     p = s ;
  }
 }
 if(bb1)  return &(current->value) ;
 else	  return NULL ;
}
template <class K,class V>V& map<K,V>::operator[](const K& k)
{if( head == 0 ){
   current = head = new link<K,V>(k,def_val) ;
   current -> pre = current -> suc =  0 ;
   return current -> value ;
 }
 link<K,V> *p =head ;
 for(;;){
   if(p->key == k )
   {current = p ; return current->value ;}
   if(k < p-> key ) {
     current = new link<K,V>(k,def_val);
     current-> pre = p-> pre ;
     current -> suc  = p ;
     if(p == head ) head = current ;
     else	  p -> pre -> suc = current ;
     p -> pre = current ;
     return current -> value;
   }
   link<K,V> *s = p -> suc ;
   if(s == 0 ){
     current=new link<K,V>(k,def_val);current -> pre = p;
     current->suc=0;p->suc=current;return current->value ;
   }
   p = s ;
 }
}
/*template<class K,class V>map<K,V>& map<K,V>::operator=(const map<K,V> &mp)
{clear();def_val = mp.def_val;def_key = mp.def_key ;
 if(mp.head)
 { sz = mp.sz;
	for(mapiter<K,V> p = mp.first() ;p ; p++)
		(*this)[p.key()]= p.value();
 }
 current = head ; return (*this);
}
template <class K,class V>map<K,V>::map(const map<K,V> & mp)
{init();def_val = mp.def_val;def_key = mp.def_key ;
 if(mp.head)
 { sz = mp.sz;
	for(mapiter<K,V> p = mp.first() ;p ; p++)
	  (*this)[p.key()]= p.value();
 }
 current = head ;
}
*/
template <class K,class V>const K& mapiter<K,V>::key(void)
{  if(p) return p-> key ;else	return m->def_key;}
template <class K ,class V > V& mapiter<K,V>::value(void)
{ if(p)  return p-> value ;else  return m->def_val ;}
template <class K,class V>mapiter<K,V>& mapiter<K,V>::operator--(void)
{if(p)  p = p-> pre ;return *this ;}
template <class K,class V>void mapiter<K,V>::operator--(int)
{if(p)	p = p-> pre;}
template <class K,class V>mapiter<K,V>& mapiter<K,V>::operator++(void)
{if(p)  p =p-> suc ; return *this ;}
template <class K,class V>void mapiter<K,V>::operator++(int)
{if(p)	p = p -> suc ;}
template <class K,class V>bool map<K,V>::is_in_map(const K & k)
{if( head == 0 ) return false  ;
 link<K,V> *p = head ;
 for(;;){
   if(p->key == k )
   {current = p ;return true ;}
   if(k < p-> key )  return  false  ;
   link<K,V> *s = p -> suc ;
   if(s == 0 )	return false ;
   p = s ;
 }
}
template <class K,class V>int map<K,V>::evalSize(void)
{ sz = 0;link<K,V> *p = head ;
  if(head){
    for(;;)
    { sz++;link<K,V> *s = p -> suc ;
      if(s == 0 ) break;
      p = s ;
    }
  }
 return sz ;
}
#endif