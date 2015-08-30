#ifndef CONTSTMT_HPP
#define CONTSTMT_HPP

#include"all.hpp"
#include"exprcont.hpp"

class containStmtCls  {
	EinstructionWord    eiw ;
	int lineStmt ;
	int noEcs,noVint,maxEcs ,maxVint;
	exprContainCls  **ecs ;
	int  *valInt ;
	containStmtCls(containStmtCls &);
	void operator=(containStmtCls &);
 public:
 void init(void)
 {
	eiw = NoInstr ;
	noEcs = noVint = lineStmt = 0 ;
	ecs = valInt = (long)0;
 }
	containStmtCls(void)
	{init();maxEcs = maxVint = 0 ; }
	containStmtCls(int ne1 ,int nv1 )
	{ int i ;
		init() ;
		ecs = new (exprContainCls *)[maxEcs = ne1] ;
		for(i = 0;i<maxEcs;i++)
			 *(ecs + i ) = long(0) ;
		valInt = new int[maxVint = nv1];
	}
	getNoExpr(void) ;
	~containStmtCls(void)
	{
	if(ecs)
	 {
		for(int i=0 ;i<noEcs;i++)
		 if(*(ecs+i))
			delete[] *(ecs+i) ;
		delete[] ecs ;
	 }
	 if(valInt)
		 delete[] valInt;
	}

/*
	void clear(void)
	{
		 if(ecs)
			{
			 for(int i=0 ;i<noEcs;i++)
				if(*(ecs+i))
				 delete[] *(ecs+i) ;
			 delete[] ecs ;
			}
			if(valInt)
				delete[] valInt;
		 init();
	}
*/
	void addExpr(exprContainCls *e1 , int ii1)
	{
	 if(ii1<maxEcs)
			*(ecs+ii1) = e1 ;
	 else
	 {
		 myDebugKey(0," in exprContainCls::addExr ") ;
		 exit(0);
	 }
	}
	void addValInt(int v1 , int ii1)
	{
	 if(ii1 <maxVint)
		*(valInt + ii1) = v1 ;
	 else
	 {
		 myDebugKey(0," in exprContainCls::addVint ") ;
		 exit(0);
	 }
	}
};
#endif
