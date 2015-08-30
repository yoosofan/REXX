#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
class floatFile{
  static FILE* file1;
  static unsigned  long int  size;
  floatFile();
  float curFloat;
  long first;
  long end;
  long current;
 public:
  floatFile(long int sizeArr1)
  {
	 if(size==0)
	 {
		floatFile::file1=tmpfile();
		 if(!file1)
		{
		 cout <<"can not open file "<<endl;
		exit(0);
		}
	 }
	 curFloat=0;
	 fseek(file1,0,SEEK_SET);
	 current=first =ftell(file1);
	 for(int i11=0;i11<sizeArr1;i11++)
		  fwrite(&curFloat,1,sizeof(float),file1);

	 end=ftell(file1);
	 size += end;
  }
  floatFile& operator[](long int i1)
  {
	 fseek(file1,first+i1*4,SEEK_SET);
	 fread(&curFloat,1,sizeof(float),file1);
	 fseek(file1,first+i1*4,SEEK_SET);
	 return *this;
  }
  float& operator=(float f1)
  {
//	  cout<<"in  "<<f1<<endl;
	  fwrite(&f1,1,sizeof(float),file1);
	  curFloat=f1;
	  return curFloat;
  }
  operator float(){return curFloat;}
// friend ofstream& operator<<(ofstream&,floatFile&);
// friend  ifstream& operator>>(ifstream&,floatFile&);
 friend ostream& operator<<(ostream&,floatFile&);
 friend  istream& operator>>(istream&,floatFile&);

 };
 /*
 ofstream& operator<<(ofstream& of1,floatFile&f1)
{
  float xx;
  xx=f1.curFloat;
  of1<<xx;
  return of1;
}
 ifstream& operator>>(ifstream & if1,floatFile& f1)
{
  float xx;
  if1>>xx;
  f1=xx;
  return if1;
}
*/
ostream& operator<<(ostream& of1,floatFile&f1)
{
  float xx;
  xx=f1;
  of1<<xx;
  return of1;
}
istream& operator>>(istream & if1,floatFile& f1)
{
  float xx;
  if1>>xx;
  f1=xx;
  return if1;
}

 FILE* floatFile::file1;
unsigned long int  floatFile::size=0;

void main(void)
{
 floatFile f1(300);
 for(int i=0;i<200;i++)
	f1[i]=i;
 float xx;
 ofstream ff2("hello.out");
 ff2<<f1[10];
 floatFile f2(600);
 for( i=0;i<600;i++)
	f2[i]=i;

for(i=0;i<600;i++)
 {
	xx=f2[i];
	cout<<f2[i]<<endl;
	if((i%20)==0) getch();
 }

  for(i=0;i<200;i++)
 {
	xx=f1[i];
	cout<<f1[i]<<endl;
	if((i%20)==0) getch();
 }
 xx=f1[5]+132;
 cout<<xx<<endl;
 xx= f2[400]+400;
 cout<<xx<<endl;
// printf("%f",f1[4]);
// printf("%f",xx);
}
