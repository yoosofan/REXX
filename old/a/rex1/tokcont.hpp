#ifndef TOKCONT_HPP
#define TOKCONT_HPP
#include"stringcl.hpp"
#include"enumpars.hpp"
class tokenContainCls{
public:
//friend TOstream& operator<<(TOstream &aa1,tokenContainCls &bb1);
 EtokenType type;
 stringCls nameVar ;
 NUMBERfORM  d;
 int start ;
 //,line,offset ;

 tokenContainCls(void)
 {
	type = Error ;
	d=0;start =0;
	//line =0 ;offset = 0 ;
	nameVar="";
 }
 tokenContainCls(EtokenType t , stringCls &nave,int st, int lt,int ot )
 {
	type=t;nameVar=nave;start=st;
	//line=lt;offset=ot;
	d=0;
}
 tokenContainCls(int  xx  , int j)
 {type= OrdNumber;start=0;
 //line=0;offset=0;
 d=xx;
 }
 tokenContainCls(EtokenType t1 , int xx , int l )
 {
	type=t1;
	start=xx;
	//line=l;offset=0;
	d=0;
}
 tokenContainCls(const tokenContainCls &t1 )
 {
	type=t1.type;
	nameVar=t1.nameVar;
	start=t1.start;
 //line=t1.line;
  //offset=t1.offset;
  d = t1.d;
//  if( heapcheck() == _HEAPCORRUPT )
//{   cout<< "Heap is corrupted in tokcont.hpp.\n" ;exitProgram(1);}

 }
 tokenContainCls & operator=(tokenContainCls &t1)
 {nameVar = t1.nameVar;
  //line = t1.line;
  start = t1.start ;
  type = t1.type;
  //offset = t1.offset;
  d = t1.d;
  return t1 ;
 }
 int operator==(tokenContainCls t1)
 { if( (t1.nameVar == nameVar) && (t1.start == start) &&
	(t1.type == type ) &&  (t1.d == d) )
		return 1;
  return 0;
}
int operator<(tokenContainCls t1)
{ if(nameVar < t1.nameVar )		 return 1 ;
  return 0 ;
}
int operator>(tokenContainCls &t1)
{  if(nameVar > t1.nameVar )		return 1 ;
	return 0 ;
}
 friend ostream & operator<<(ostream &os1, tokenContainCls &t1);
 friend outputRexx & operator<<(outputRexx &os1, tokenContainCls &t1);
} ;
#endif
