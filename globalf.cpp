#include"all.hpp"
int debugKeyStart=0 ;
extern outputRexx out1;
//extern ofstream outDebugError;
void myDebugKey(long int a11 ,  char *pp1)
{
  if(pp1)  cout<<pp1<<"  ";
   cout<<a11<<endl ;
  char ch3 = getch();
  if(ch3 == 27)
	exitProgram(1);
}
void exitProgram(int i1)
{
//outDebugError.close();
fcloseall();cout<<"end program"<<endl;exit(i1); }

// same as " strchr " but in locate return the location of characterSearch
char *ahmadStrchr(char *s1,char characterSearch,int &locateCharacter)
{
 register int i1=0;
 for(;*s1;i1++,s1++)
	if(*s1== characterSearch)
		break;
 if(*s1==NULL)	s1=NULL;
 locateCharacter=i1;
 return s1;
}
int ahmadStrcmp(char *s1,char *s2)
{
  register int i1=0,i2=0;
  for(;(*s1) && (*s1== ' ');s1++,i1++);
  for(;(*s2) && (*s2== ' ');s2++);
  for(; *s1 && *s2; s1++,s2++,i1++)
	 if( *s1<*s2)
	 {i2= -i1; break;}
	 else if( *s1>*s2)
	 {i2= i1;break;}
  if(!i2)
	 if(*s1)
	 {
		for(;(*s1) && (*s1== ' ');s1++,i1++);
		if(*s1)
		  i2=i1;
	 }
	 else if(*s2)
	 {
		 for(;(*s2) && (*s2== ' ');s2++);
		 if(*s2)
			i2=-i1;
	 }
 return i2;
}



