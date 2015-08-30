#include"all.hpp"
bool tokenFind(EtokenType e1 ,char*  p1);
outputRexx & operator<<(outputRexx &os1 , tokenContainCls &t1)
{
    char p1[40] ;
	tokenFind(t1.type , p1)      ;
	os1<<"nameVar " <<t1.nameVar<<"\n";
	os1<<"type " <<t1. type<<"   " <<p1 <<"\n";
	os1<<"double1 " << t1.d << "\n";
//	os1<<"line " << t1.line << "\n";
	os1<<"pos " << t1.start << "\n" ;
//	os1<<"offset "<< t1.offset << "\n" ;
	return os1 ;
}
ostream & operator<<(ostream &os1 , tokenContainCls &t1)
{       char p1[40] ;
	tokenFind(t1.type , p1)      ;
	os1<<"nameVar " <<t1.nameVar << endl;
	os1<<"type " <<t1. type<<"   " <<p1 <<endl;
	os1<<"double1 " << t1.d << endl;
//	os1<<"line " << t1.line << endl;
	os1<<"pos " << t1.start << endl ;
//	os1<<"offset "<< t1.offset << endl ;
	return os1 ;
}

