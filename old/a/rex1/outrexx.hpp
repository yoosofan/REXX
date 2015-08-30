#ifndef OUTREXX_HPP
#define OUTREXX_HPP
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include"stringcl.hpp"
#include"global.hpp"
//#define outputRexx cout
//extern outputRexx out1;
class outputRexx:public ofstream {
  ofstream outFile ;
  int typeOut ;

 public:
  ~outputRexx(void)
 {
   if(typeOut)
     outFile.close();
 }
 outputRexx(int t1 = 0 ,char *p1 =NULL)
 {
/*     cout << " in outputRexx press any key " << endl;
     getch();*/
     if(t1)
     {
       outFile.open(p1);
       if(!outFile)
       {
	 cout<<" can not open outRexx file " << endl;
	 exitProgram(0);
       }
     }
     typeOut = t1 ;
  }
 outputRexx & operator<<(char *p1)
 {
   if(typeOut)
   {
     outFile << p1 ;
     outFile.flush();
   }
   else
      cout << p1 ;
    return (*this);
}
 outputRexx & operator<<(stringCls & p1)
 {
   char *p2 = new char[p1.size_of_str()+3] ;
   p1.get_p(p2);
   if(typeOut)
   {
     outFile << p2 ;
     outFile.flush();
   }
   else
      cout << p2 ;
   delete[] p2 ;
   return (*this);
}

 outputRexx & operator<<(int p1)
 {
   if(typeOut)
   {
      outFile << p1 ;
     outFile.flush();
   }

   else
      cout << p1 ;
    return (*this);
}
 outputRexx & operator<<(long int p1)
 {
   if(typeOut)
   {
      outFile << p1 ;
     outFile.flush();
   }

   else
      cout << p1 ;
    return (*this);
}

 outputRexx & operator<<(float p1)
 {
   if(typeOut)
   {
      outFile << p1 ;
     outFile.flush();
   }

   else
      cout << p1 ;
       return (*this);
}
 outputRexx & operator<<(double p1)
 {
   if(typeOut)
   {
      outFile << p1 ;
     outFile.flush();
   }

   else
      cout << p1 ;
    return (*this);
}
outputRexx & operator<<(char  p1)
{
   if(typeOut)
   {
      outFile << p1 ;
     outFile.flush();
   }

   else
      cout << p1 ;
    return (*this);
}


};

#endif