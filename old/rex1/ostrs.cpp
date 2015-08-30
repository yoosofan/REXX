#include"all.hpp"
template <class TOstream>
TOstream& operator<<(TOstream &aa1,containStmtCls &bb1)
{
 char pp1[50];
 if(instrFind(bb1.eiw ,pp1))
  TOstream<<"eiw of instr is "<<pp1<<"\n";
 else
  TOstream<<" ERROR THE INSTR IS ERROR  EIW   EIW " <<"\n";
 TOstream<<"line stmt is "<<bb1.lineStmt;
 TOstream<<"no Of Val Int  is "<<bb1.noOfValInt;
 TOstream<<"noEcs "<<bb1.noEcs<<"\n";
 if(valInt)
 { TOstream<<" the value of int is \n";
   for(int ii1;ii1<bb1.noOfValInt;ii1++)
    TOstream<<bb1.valInt[ii1];
   TOstream<<"\n";
 }
 TOstream.flush();
 TOstream<<bb1.ecs ;
 return TOstream;
}
template <class TOstream>
TOstream& operator<<(TOstream &aa1,exprContainCls &bb1)
{
   TOstream<<"noVInStack "<<bb1.noVInStack <<" maxVal "<<bb1.maxVal<<"\n";
   TOstream.flush();
   for(int ii1=0;ii1<bb1.maxVal;ii1++)
   {   TOstream<<bb1.geti(ii1); TOstream.flush();}
}

TOstream& operator<<(TOstream &os1,tokenContainCls &t1)
{
    char p1[40] ;
    tokenFind(t1.type , p1)      ;
    os1<<"nameVar " <<t1.nameVar<<"\n";
    os1<<"type " <<t1. type<<"   " <<p1 <<"\n";
    os1<<"double1 " << t1.d << "\n";
//    os1<<"line " << t1.line << "\n";
	 os1<<"pos " << t1.start << "\n" ;
//    os1<<"offset "<< t1.offset << "\n" ;
    os1.flush();
    return os1 ;
}

}