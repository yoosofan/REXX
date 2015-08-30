#ifndef TOSTR_HPP
#define TOSTR_HPP

#include"all.hpp"
class outDebugError:public ofstream{
  ofstream outFile ;
  int typeOut ;

 public:
  ~outDebugError(void)
 {
   if(typeOut)
     outFile.close();
 }
 outDebugError(char *p1 =NULL)
 {
/*     cout << " in outDebugError press any key " << endl;
     getch();*/
       outFile.open(THEOUTPUTOFDEBUGERRORFILE);
       if(!outFile)
       {
	 cout<<" can not open outdEBUGeRROR Rexx file " << endl;
	 exitProgram(0);
       }
     typeOut = 1 ;
  }
 outDebugError & operator<<(char *p1)
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
 outDebugError & operator<<(stringCls p1)
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

 outDebugError & operator<<(int p1)
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
 outDebugError & operator<<(long int p1)
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

 outDebugError & operator<<(float p1)
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
 outDebugError & operator<<(double p1)
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
outDebugError & operator<<(char  p1)
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
