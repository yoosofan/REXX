#ifndef FCALCONT_HPP
#define FCALCONT_HPP

#include"all.hpp"
class fCallContCls{
   map<int , variableValue>   v;
	int index ;
	bool notEmpty ;
	tokenContainCls tcc ;// token of functionName
	int lineCall;
	int sz ;
	public:
	int size(void) {return sz;}
	variableValue getArg(int i1)
	{ return v[i1];}
	stringCls getName(void) {return tcc.nameVar;}
	fCallContCls(tokenContainCls &t1)
	{
	  index = 0 ; notEmpty = false;
	  tcc = t1;
	  sz = 0 ;
	  lineCall=-1;
	}
	void addArg(variableValue &v1) {
	  v[index++] = v1 ;
	  notEmpty = true ;
	  sz = index ;
	}
	void set(void) { index = sz ; }
	bool getArg(variableValue &v1)
	{  bool bb1 = true;;
		if(notEmpty && (index))
	v1 = v[--index];
		else
	 bb1 = false ;
	  return bb1 ;
	}
	void setLine(int i11){lineCall=i11;}
	int getLineCall(void){return lineCall;}
};
#endif
