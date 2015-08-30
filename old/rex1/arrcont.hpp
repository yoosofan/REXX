#ifndef ARRCONT_HPP
#define ARRCONT_HPP

#include"all.hpp"

class arrayContCls{
  map<stringCls,variableValue > varTable;
  public :
	valBool search(stringCls &lt1)
	{
	  valBool  xx  ;mapiter<stringCls , variableValue>  mpi(varTable);
	  if(varTable.is_in_map(lt1)==true)
		{mpi.set_p_cur() ;xx.val  =   mpi.value();xx.b=true;}
	  else    xx . b = false ;
	  return xx;
	}
	void addArrTable(stringCls &name,variableValue &vv1)
	{varTable[name]=vv1;}

};
#endif