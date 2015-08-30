#ifndef STRINGCl_HPP
#define STRINGCl_HPP
#include<iostream.h>
#include<string.h>
//#include<alloc.h>
//template <class TOstream>
class stringCls {
 struct srep {
	char *s ;
	int n ;
	srep() { n=1; }
   } ;
  public :
	srep *p ;
	  stringCls( char *) ; //stringCls = "abc"
	   stringCls( const char *) ;
	  stringCls() ;  // stringCls x
	  stringCls(const stringCls &) ;  // strin x = stringCls
	  stringCls & operator=(const stringCls & ) ;
	  stringCls & operator=(const char *) ;
	  ~stringCls() ;
//     char & operator[](int i ) ;
//     const char & operator[](int i ) const ;
	  void get_p(char lll[])

{
 strcpy( lll , p->s) ;
//if( heapcheck() == _HEAPCORRUPT )
//{ cout <<"p->s is " <<p->n<<"  "<<p->s <<endl;  cout<< "Heap is corrupted.in get_p string.hpp ???????????????????????????\n" ;}

 lll[size_of_str()+1] = NULL ;

 }
     int size_of_str(void)
     { return strlen(p->s) ; }

	  friend ostream& operator<<(ostream & , const stringCls & ) ;
     friend istream& operator>>(istream & ,  stringCls &  ) ;

     friend int operator==(const stringCls & x , const char * s)
     { return strcmp(x.p->s , s) == 0  ; }

     friend int operator==(const stringCls & x , const stringCls & y)
     { return strcmp(x.p->s , y.p->s) == 0  ; }

     friend int operator!=(const stringCls & x , const char * s)
     { return strcmp(x.p->s , s) != 0  ; }

     friend int operator!=(const stringCls & x , const stringCls & y)
	  { return strcmp(x.p->s , y.p->s) != 0  ; }

     friend int operator<(const stringCls & x , const char * s)
     { return strcmp(x.p->s , s) < 0  ; }

     friend int operator<(const stringCls & x , const stringCls & y)
     { return strcmp(x.p->s , y.p->s) < 0  ; }

     friend int operator>(const stringCls & x , const stringCls & y)
     { return strcmp(x.p->s , y.p->s) > 0  ; }

     friend int operator>(const stringCls & x , const char * s)
	  { return strcmp(x.p->s , s) > 0  ; }


//friend TOstream & operator<<(TOstream & s , const stringCls & x );

} ;// definition of class function

/*
int main(void)
{
  stringCls x ;
  stringCls y = " abcdefghijklmn" ;
  stringCls z = y ;
  x = z ;
  cout  << "  x1 " << x << '\n'  ;
  cout << "  y1 " << y  << '\n' ;
  cout << " z1   " << z << '\n' ;
  x="jdhfgoiwfhjiowhjfoiwhjf" ;
  cout << " x2   " << x << '\n' ;
  cin >> x ;
  cout << " x3   " << x << '\n' ;
  return 0 ;
}

  */
  #endif