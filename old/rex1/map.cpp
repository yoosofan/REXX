//#include"globpre.hpp"


#include"map.hpp"


//#ifndef boolean
//  enum  boolean { FALSE , true } ;
//#endif


/*
template <class K ,class V >
boolean map<K,V>::is_in_map(const K & k)
{
	if( head == 0 )
	return FALSE  ;
	link<K,V> *p = head ;
	for(;;){
		 if(p->key == k ){
		current = p ;
		return true ;
		 }
		 if(k < p-> key )
	  return  FALSE  ;

		 link<K,V> *s = p -> suc ;
		 if(s == 0 )
		return FALSE ;
		p = s ;
	}
}


  */







template <class K ,class V >
V& map<K,V>::operator[](const K& k)
{
	if( head == 0 ){
	current = head = new link<K,V>(k,def_val) ;
	current -> pre = current -> suc =  0 ;
	return current -> value ;
	}
	link<K,V> *p =head ;
	for(;;){
		 if(p->key == k ){
		current = p ;
		return current->value ;
		 }
		 if(k < p-> key ) {
	  current = new link<K,V>(k,def_val);
	  current-> pre = p-> pre ;
	  current -> suc  = p ;

	  if(p == head )
		 head = current ;
	  else
		  p -> pre -> suc = current ;
	  p -> pre = current ;
	  return current -> value;
		 }

		 link<K,V> *s = p -> suc ;
		 if(s == 0 ){
		current = new link<K,V>(k,def_val) ;
		current -> pre = p;
		current -> suc = 0 ;
		p -> suc = current ;
		return current->value ;
		}
		p = s ;
	}
}


template <class K ,class V >
map<K,V> &      mapiter<K,V>::operator=(const map<K,V> &mp)
//   void  operator=(const map<K,V> &mp)

	{
	  if(head!=0)
			map<K,V>::~map();
 init();
 if(mp.head)
 { sz = mp.sz;
	for(mapiter<K,V> p = mp.first() ;p ; p++)
		(*this)[p.key()]= p.value();
 }
 else init();
 current = head ;
  return (*this);
}




template <class K ,class V >
	mapiter<K,V>::  map(const map<K,V> & mp)
	{
	 init();
	 if(mp.head)
	 { sz = mp.sz;
		for(mapiter<K,V> p = mp.first() ;p ; p++)
	 (*this)[p.key()]= p.value();
	 }
	 else init();
	 current = head ;
	}




template <class K ,class V >
const K& mapiter<K,V>::key(void)
{  if(p)
      return p-> key ;
   else
      return m->def_key;
}
template <class K ,class V > V& mapiter<K,V>::value(void)
{
  if(p)
     return p-> value ;
  else
     return m->def_val ;
}

template <class K ,class V >
mapiter<K,V>& mapiter<K,V> ::operator--(void)
{
  if(p)
     p = p-> pre ;
 return *this ;
}

template <class K ,class V >
void mapiter<K,V>::operator--(int)
{
   if(p)
      p = p-> pre;
}
template <class K ,class V >
mapiter<K,V>& mapiter<K,V>::operator++(void)
{
  if(p)
	  p =p-> suc ;
  return *this ;
}

template <class K ,class V >
void mapiter<K,V>::operator++(int)
{
   if(p)
      p = p -> suc ;
}

/*
//map<K,V> & map<K,V>::operator=(const map<K,V> & mp)
template <class K ,class V >
void map<K,V>::operator=(const map<K,V> & mp)
{
 if(head!=0)
	map<K,V>::~map<K,V>();
 init();
 if(mp.head)
 { sz = mp.sz;
   for(mapiter<stringCls,int> p = mp.first() ;p ; p++)
      this->[p.key()]= p.value();
 }
 else init();
 current = head ;

}
  */

/*


template <class K ,class V >
boolean map<K,V>::is_in_map(const K & k)
{
   if( head == 0 )
	return FALSE  ;
   link<K,V> *p = head ;
	for(;;){
       if(p->key == k ){
	   current = p ;
	   return true ;
		 }
       if(k < p-> key )
	  return  FALSE  ;

       link<K,V> *s = p -> suc ;
       if(s == 0 )
	   return FALSE ;
      p = s ;
   }
}
  */

template <class K ,class V >
V& map<K,V>::operator[](const K& k)
{
   if( head == 0 ){
	current = head = new link<K,V>(k,def_val) ;
	current -> pre = current -> suc =  0 ;
	return current -> value ;
   }
	link<K,V> *p =head ;
   for(;;){
		 if(p->key == k ){
	   current = p ;
		 return current->value ;
       }
       if(k < p-> key ) {
	  current = new link<K,V>(k,def_val);
	  current-> pre = p-> pre ;
	  current -> suc  = p ;

	  if(p == head )
	    head = current ;
	  else
			 p -> pre -> suc = current ;
	  p -> pre = current ;
	  return current -> value;
			 }

       link<K,V> *s = p -> suc ;
       if(s == 0 ){
	   current = new link<K,V>(k,def_val) ;
	   current -> pre = p;
	   current -> suc = 0 ;
	   p -> suc = current ;
	   return current->value ;
		}
			p = s ;
	}
}
template <class K ,class V >
int map<K,V>::evalSize(void)
{ sz = 0;
	link<K,V> *p = head ;
	if(head)
	{
		for(;;)
		{
			 sz++;
			 link<K,V> *s = p -> suc ;
			 if(s == 0 )
						break;
			 p = s ;
		}
	}
 return sz ;
}
template <class K ,class V >
void map<K,V>::setSz(int ii)
{ sz = ii;}
template <class K ,class V >
bool map<K,V>::is_in_map(const K & k)
{
	 if( head == 0 )
		 return false  ;
	 link<K,V> *p = head ;
	for(;;){
			 if(p->key == k ){
		current = p ;
		 return true ;
			 }
			 if(k < p-> key )
		return  false  ;

			 link<K,V> *s = p -> suc ;
			 if(s == 0 )
		 return false ;
			p = s ;
	 }
}











template <class K ,class V >
const K& mapiter<K,V>::key(void)
{  if(p)
		return p-> key ;
   else
			return m->def_key;
}
template <class K ,class V > V& mapiter<K,V>::value(void)
{
  if(p)
     return p-> value ;
  else
     return m->def_val ;
}

template <class K ,class V >
mapiter<K,V>& mapiter<K,V> ::operator--(void)
{
	if(p)
     p = p-> pre ;
 return *this ;
}

template <class K ,class V >
void mapiter<K,V>::operator--(int)
{
   if(p)
		p = p-> pre;
}
template <class K ,class V >
mapiter<K,V>& mapiter<K,V>::operator++(void)
{
  if(p)
	  p =p-> suc ;
  return *this ;
}

template <class K ,class V >
void mapiter<K,V>::operator++(int)
{
	if(p)
		p = p -> suc ;
}

