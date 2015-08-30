#include"all.hpp"


#include"stringcl.hpp"
#include<stdio.h>
string::string()
{ p =new srep ; p->s = 0 ;}
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
  //s >> buf ;//unsafe might overflow
  x = buf ; // overload =
  // err_class_calc << "echo : " << x << '\n' ;
  return s ;
}
void main(void)
{
 cvContain cv ;
 clrscr();
 tokenContainCls t1;
 t1.nameVar = "ali";
 t1.line = 1 ;
 cv.push(t1 , 1) ;
 t1.nameVar = "ahmad";
 t1.line = 2 ;
 cv.push(t1 , 2) ;
 t1.nameVar = "ahmadreza";
 t1.line = 13 ;
 cv.push(t1 , 3) ;
 t1.nameVar = "alireza";
 t1.line = 18 ;
 cv.push(t1 , 4) ;
 t1.nameVar = "ahmad";
 t1.line = 2 ;

 cout<< cv.search(t1) <<endl ;
 t1.nameVar = "ali";
 t1.line = 1 ;
 cout<< cv.search(t1) <<endl ;
 t1.nameVar = "alireza";
 t1.line = 18 ;
 cout<< cv.search(t1) <<endl ;

}