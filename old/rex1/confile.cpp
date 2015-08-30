#include"all.hpp"
void containFileCls::print(void)
{
	 cpcs.evalSize();
	 for(int i=0;i<cpcs.size();i++)
  		cpcs[i]->print();
}
