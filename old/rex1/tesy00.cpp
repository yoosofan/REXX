#include<iostream.h>
#include"map.hpp"
#include"all.hpp"

#include"tokcont.hpp"

#include"z:string.hpp"
#include"z:map.hpp"
#include<conio.h>
#include<stdio.h>


#include"string.hpp"
#include<stdio.h>

string::string(){ p =new srep ; p->s = 0 ;}  
string::string(const string & x)
{   x.p->n ++ ; p =x.p ; }
string::string(const char *s)
{
  p= new srep ;
  p-> s = new char[strlen(s) + 2] ;
  strcpy(p->s , s ) ;
}
string::string( char *s)
{  p= new srep ;  p-> s = new char[strlen(s) + 2] ;  strcpy(p->s , s ) ;}

string::~string()
{
  if( --p->n == 0){
	  delete[] p->s ;
	  delete p ;
  }

}



string & string::operator=(const char *s )
{
  if(p-> n > 1 ){
	 p-> n -- ;
	 p = new srep ;
  }else
	  delete[] p->s ;
  p->s = new char[strlen(s)+2] ;
  strcpy(p->s , s ) ;
  return *this ;

}

string & string::operator=(const string &x )
{
  x.p-> n ++ ; //protect against st = st
  if(--p->n == 0)
  {  delete[]  p->s ; delete p ; }
  p = x.p ;
  return *this ;
}


ostream & operator<<(ostream & s , const string & x )
{
 return s << x.p->s ;// return s << x.p->s << "[ " << x.p->n << "]\n";
}

istream & operator>>(istream & s ,const string & x )
{
  char buf[256] ;
  gets(buf) ;
  //s >> buf ;//unsafe might overflow    -
  x = buf ; // overload =
  // err_class_calc << "echo : " << x << '\n' ;
  return s ;
}

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
	for(mapiter<string,int> p = mp.first() ;p ; p++)
		this->[p.key()]= p.value();
 }
 else init();
 current = head ;

}
  */

/*


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
  */









 void main(void)

 {
	#define exprContainCls 	map < int ,tokenContainCls >
//	class exprContainCls :public	map<int , tokenContainCls> {};
//		exprContainCls ec ;
	tokenContainCls ccc1 ;  ///  very important
	// a bad confusing error occured when "tokenContainCls"
	// not defined here

	map <int,tokenContainCls>   ec;
	map<int ,exprContainCls> st ;
	class stst:public map<int , exprContainCls> {}   ;
	stst st2    ;
	 clrscr();
	tokenContainCls t1 ;
	t1.type = Error ;
	t1.nameVar = string("hello");
	t1.start = 225 ;
	ec[0] = t1 ;
	st[0 ] = ec ;
	st2[0 ] = ec ;
	int i=0 ;
	cout <<endl ;
	 cout <<	t1.type<<endl;
	cout<< t1.nameVar<<endl ;
	cout <<t1.start<<endl ;

	cout<< (ec[0]). nameVar <<endl;;
	cout<< (ec[0]). start<<endl; ;
	cout<< (ec[0]). type <<endl;

	exprContainCls ec2(ec) ;
//	ec2 =ec ;

	cout<< ec2[0]. nameVar <<endl;;
	cout<< ec2[0]. start<<endl; ;
	cout<< ec2[0]. type <<endl;

	cout<< (st[0])[0]. nameVar <<endl;;
	cout<< (st[0])[0]. start<<endl; ;
	cout<< (st[0])[0]. type <<endl;

	cout<< (st2[0])[0]. nameVar <<endl;;
	cout<< (st2[0])[0]. start<<endl; ;
	cout<< (st2[0])[0]. type <<endl;
	ec.clear();
	ec[0] = t1 ;
 }
