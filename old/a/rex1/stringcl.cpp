#include"stringcl.hpp"
#include<stdio.h>
stringCls::stringCls()
{p =new srep ; p->s = 0 ;}
stringCls::stringCls(const stringCls & x)
{   x.p->n ++ ; p =x.p ; }
stringCls::stringCls(const char *s)
{
  p= new srep ;
  p-> s = new char[strlen(s) + 2] ;
  strcpy(p->s , s ) ;
}
stringCls::stringCls( char *s)
{  p= new srep ;  p-> s = new char[strlen(s) + 2] ;  strcpy(p->s , s ) ;}

stringCls::~stringCls()
{
  if( --p->n == 0){
     delete[] p->s ;
     delete p ;
  }

}



stringCls & stringCls::operator=(const char *s )
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

stringCls & stringCls::operator=(const stringCls &x )
{
  x.p-> n ++ ; //protect against st = st
  if(--p->n == 0)
  {  delete[]  p->s ; delete p ; }
  p = x.p ;
  return *this ;
}


ostream & operator<<(ostream & s , const stringCls & x )
{
 return s << x.p->s ;// return s << x.p->s << "[ " << x.p->n << "]\n";
}

istream & operator>>(istream & s ,stringCls & x )
{
  char buf[256] ;
  gets(buf) ;
  //s >> buf ;//unsafe might overflow
  x = buf ; // overload =
  // err_class_calc << "echo : " << x << '\n' ;
  return s ;
}
/*
TOostream & operator<<(TOostream & s , const stringCls & x )
{
 return s << x.p->s ;// return s << x.p->s << "[ " << x.p->n << "]\n";
}
*/