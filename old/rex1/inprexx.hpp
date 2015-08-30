#ifndef INPREXX_HPP
#define INPREXX_HPP

#include"all.hpp"

class inputRexx:public ifstream {

public:
int getKeyIo(void)
{
 int ch = getch();
 if(ch ==27)
   exit(0) ;
 else if(!ch)
   ch = getch()+255;
 return ch ;
}

};

#endif