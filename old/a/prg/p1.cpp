#include<ctype.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<complex.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<alloc.h>
//ios:: precision()
struct cit{
			char city[16];
	} ;
struct ind{
		  char index[16];
};
extern  size_t _stklen=32000;
void exitProgram(void)
{
  getch();
  system("sayeh5/u");
  clrscr();
  exit(0);
}
void myK(void)
{
  char ch=getch();
  if(ch==27)
	 exitProgram();
}
float myPow(float a1, float a2)
{
  if(fabs(a1)>1e15 ||( fabs(a1)<1e-15  && a1!=0))
  {
	 cout << " ovar 1 "<<a1<<endl;
		myK();
  }
  if(fabs(a2)>1e15 || fabs(a2)<1e-15 )
  {	  cout<<" over  2"<<a2<<endl;
		  myK();
  }
  return pow(a1,a2);
}

class floatFile{
  static FILE* file1;
  static unsigned  long int  size;
  floatFile();
  float curFloat;
  unsigned long first, end,  current;
  unsigned long int mi1;
//  floatFile &operator=(floatFile &);
 public:
  floatFile(long int sizeArr1)
  {
	 if(size==0)
	 {
		floatFile::file1=tmpfile();
		 if(!file1)
		{
		 cout <<"can not open file in floatFile "<<endl;
		exitProgram();
		}
	 }
	 curFloat=0;
	 fseek(file1,0,SEEK_END);
	 current=first =ftell(file1);
	 for(int i11=0;i11<sizeArr1;i11++)
	 {
		  fwrite(&curFloat,sizeof(float),1,file1);
		  fflush(file1);
	 }
	 end=ftell(file1);
	 size = end;
	 fseek(file1,current,SEEK_SET);
	 mi1=size;
  }
  void error(void)
  { cout <<"size not enopg ggg "<<endl;
	  getch();
	  exitProgram();
  }
  floatFile& operator[](unsigned long int i1)
  {
	 if(  ( (first+i1*sizeof(float)) >=end ) ||   ( (first+i1*sizeof(float)) < first)  )
		error();
	 fseek(file1,first+i1*sizeof(float),SEEK_SET);
	 fread(&curFloat,sizeof(float),1,file1);
	 fseek(file1,first+i1*sizeof(float),SEEK_SET);
	 current=first+i1*sizeof(float);

	 return *this;
  }
  float operator=(float f1)
  {

	 if(  ( (current) >=end ) ||   ( (current) < first)  )
		error();

	 fseek(file1,current,SEEK_SET);
	 fwrite(&f1,sizeof(float),1,file1);
//	 fflush(file1);
	 fseek(file1,current,SEEK_SET);
	 curFloat=f1;  
	  return curFloat;
  }

  floatFile &  operator=(floatFile &  f2)
  {
	 if(  ( (current) >=end ) ||   ( (current) < first)  )
		error();
	 fseek(file1,current,SEEK_SET);
	 fwrite(&f2.curFloat,sizeof(float),1,file1);
	 fseek(file1,current,SEEK_SET);
  //	 fflush(file1);
	 curFloat=f2.curFloat;
	 return (*this);
  }

  operator float(){return curFloat;}
// friend ofstream& operator<<(ofstream&,floatFile&);
// friend  ifstream& operator>>(ifstream&,floatFile&);
 friend ostream& operator<<(ostream&,floatFile&);
 friend  istream& operator>>(istream&,floatFile&);
 void remove(void)
 { rmtmp();}
 };
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
int fileOutCorrect;
#define NO_OF_CITY 100
const int multy_city =NO_OF_CITY * NO_OF_CITY;

void exitProgramOutMemory(void)
{ endl;
  printf(" out of memory \n");
  exitProgram();
}
void error(int i1)
{
  cout << " in input file data not compelete " <<i1<<endl;
  exitProgram();

}
void getInput(char *pp1)
{
 int i11=0;
 char ch;
 do{
	 ch=getch();
	 if(ch!=13)
	 {
		*pp1=ch;
		*pp1++;
	 }
	 i11++ ;
	 if(i11 >30)
		break;
 }while(ch != 13);
 *pp1=NULL;
}
void getPassword(void)
{
 char  passwordProgram[100];

for(int passI=0;passI<10;passI++)
{
  cout<<endl;
  cout<<"enter password : ";
  getInput( passwordProgram);
  if(strcmp(passwordProgram,"hhoolloo"))
  {
	 cout <<" incorrect password "<<endl;
	 if(passI>5)
		exit(0);
  }
  else
	 break;
}
}
void firstUp(void)
{
 getPassword();
// spawnlp(P_WAIT,"m.exe"," m.exe ",NULL);
spawnlp(P_WAIT,"vs7","vs7",NULL);
system("sayeh5") ;
textbackground(BLUE);
 textcolor(YELLOW);
 clrscr();
 printf("\n                              ‹£¢ òŒõ“             \n");
 printf("\n                       ( üóöõö©íŒ— ) TAXONOMY\n");
 printf("\n                ëàŒõó üî—êŒş øä©ö— ø›¥£ ôııä— û‹¥“ ü«ö¥      \n");
 printf("\n\n                                                  ¦‹¥ı« ÷Œî«õ‹£  \n");
 printf("\n                                            û¥Œóäó ö¥õú ÷£í«õ‹£  \n");
 printf("\n                                                   û¦Œ©¥ù«  ª¢“  \n");
 printf("\n                                      û‹ øìàõó û¦ş¥ øóŒõ¥“  ¨¥£  \n");
 printf("\n                     111353     üúŒõ•Œ¯¥£óŸó                     \n");
 printf("\n\n                           1378  ¥Œù“                           \n");
 printf("\n\n\n                                 1 øŸê­                       \n");
 getch();
 clrscr();
 printf("\n\n\n\n\n\n\n\n\n\n                           ôö¥¦Œí ôŒ—©¥ù« øä©ö— ¥à\n");
 printf("\n\n\n\n\n\n\n\n\n\n\n                     2 øŸê­              \n\n");
 getch();
 clrscr();
}
floatFile x(multy_city);

void loadFloat(char *nameFile1,int &n ,int &m,cit *s1,ind *s2);
void sort(int k,floatFile &cio,int *);
void getInputXX(char *nameFile1,int &n ,int &m,cit *s1,ind *s2);
void inputFromKeyWord(char *nameFile1,int &n ,int &m,cit *s1,ind *s2);
void main(void)
{
firstUp();
float xx_contain;
floatFile cio(NO_OF_CITY);
struct cit *s1= new cit[NO_OF_CITY];
floatFile minNumber(multy_city);
floatFile d(multy_city);
cit  *s3= new cit[NO_OF_CITY];
floatFile xoj(NO_OF_CITY);
floatFile xjb(NO_OF_CITY);
floatFile xojp(NO_OF_CITY);
floatFile sj(NO_OF_CITY);
struct ind *s2=new ind[NO_OF_CITY];
if(!s2)
  exitProgramOutMemory();

int jj1=0,kk12=0;
int n,m,i,j;

char nameFile1[80];
fileOutCorrect=1;
getInputXX(nameFile1,n,m,s1,s2);

FILE * outFile;
char nameFileOut[50];

strcpy(nameFileOut,nameFile1);
if(fileOutCorrect)
  strcat(nameFileOut,".out");

outFile=fopen(nameFileOut,"w");
if(!outFile)
{
  printf("can not open output file ");
  exitProgram();
}
fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
fflush(outFile);
fprintf(outFile,"**  Œú ÷£‹£  ¨ş¥—Œó ïıí«— ïö‹ øñŸ¥ó \n ");
fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
  fflush(outFile);
 fprintf(outFile,"****  Œú ÷£‹£  ¨ş¥—Œó 1 ïö£›****\n");
 fprintf(outFile,"  ¬¢Œ« :    ");
 for(j=0 ;j<m ;++j)
		fprintf(outFile,"%-6s",s2[j].index);
 fflush(outFile);
 fprintf(outFile,"\n ¥ù«     -------------------------------------------------------------\n");

 for(i=0 ;i<n ;++i)
  {fprintf(outFile,"  %-8s",s1[i].city);
	for(j=0 ;j<m ;++j)
	{ xx_contain=x[i*NO_OF_CITY+j];

	  fprintf(outFile,"%1.3f ",xx_contain);
	  //	fprintf(outFile,"%f ",xx_contain);
	}
	 fprintf(outFile,"\n");
  }
	fflush(outFile);
 fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
 fprintf(outFile,"*** . £¥‹£õŒ—©‹  ¨ş¥—Œó ïıí«— 2 øñŸ ¥ó ***\n\n");
 fflush(outFile);
 float sum;

 sum=0;

	for(j=0 ;j<m ;++j)
	{
	 for(i=0 ;i<n ;++i)
		xoj[j]=x[i*NO_OF_CITY+j]+xoj[j] ;
	 xjb[j]= float(xoj[j])/ float(n) ;
	 xojp[j]=myPow(xoj[j],(float)2)/(float)n ;
	}
  cout<<"xxxx "<<endl;
 fprintf(outFile," . £«Œ“ üó ¥Œıäó ¦‹ ê‹¥Ÿõ‹ :s \n");
 fflush(outFile);
 for(j=0 ;j<m ;++j)
 {
	 for(i=0 ;i<n ;++i)
		 sum=sum+myPow((float)(x[i*NO_OF_CITY+j]),(float)2)		 ;

	 sj[j]=sqrtl(fabs( (sum-(float)(xojp[j]) ) /n)) ;
	 xx_contain=sj[j];
	 sum=0;
	 fprintf(outFile," %-5s : %1.3f\n",s2[j].index,xx_contain);
//	 fprintf(outFile," %-5s : %f\n",s2[j].index,xx_contain);

 }

  fflush(outFile);
  fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
 fprintf(outFile,"*** .  £¥‹£õŒ—©‹  ¨ş¥—Œó 2 ïö£›  *****\n");
 fprintf(outFile,"  ¬¢Œ«  : ");
 for(j=0 ;j<m ;j++)
						fprintf(outFile," %s  ",s2[j].index);
 fprintf(outFile,"\n  ôŒ—©¥ù« ---------------------------------------------------------------\n");
 fflush(outFile);
 floatFile z(multy_city);

  for(i=0 ;i<n ;++i)
  {  fprintf(outFile,"    %s",s1[i].city);
	 fflush(outFile);
	  for(j=0 ;j<m ;++j)
	  {
			 if((float)sj[j]!=0)
			 {
				z[i*NO_OF_CITY+j]=(float)( ((float)( x[i*NO_OF_CITY+j])-(float)(xjb[j] )) / (float)(sj[j]) );
			  xx_contain=z[i*NO_OF_CITY+j];
				fprintf(outFile," %1.3f",xx_contain);
				//fprintf(outFile," %f",xx_contain);
			 }
			 else{ fprintf(outFile,"   ¥ê­ ¥“ òı©ì— sj[j]\n ");z[i*NO_OF_CITY+j]=0;}
		}

	  fprintf(outFile,"\n");
  }

  fprintf(outFile,"******  ŒùõŒ—©¥ù« ôı“ ï­‹öê ø“©ŒŸó 3 øñŸ¥ó **\n\n");
  int a,b;
 fflush(outFile);
  sum=0;
  fprintf(outFile,"   ôŒ—©¥ù«:");
  for (j=0 ;j<n ;++j)
								 fprintf(outFile,"%-7s ",s1[j].city);
  fprintf(outFile,"\n  ôŒ—©¥ù« ---------------------------------------------------------\n");
	fflush(outFile);
  for(a=0 ;a<n ;++a)
	 {for(b=0 ;b<n ;++b)
		{for(j=0 ;j<m ;++j)
			sum=sum+myPow((z[a*NO_OF_CITY+j]-z[b*NO_OF_CITY+j]),(float)2) ;
		 xx_contain=d[a*NO_OF_CITY+b]=sqrt(fabs(sum)) ;
		 if( b==0 )
			  fprintf(outFile,"  %-8s",s1[a].city);
		 fprintf(outFile,"%1.3f   ",xx_contain);
		 sum=0 ;
		 }
		fprintf(outFile,"\n");
	 }
	  fflush(outFile);

  fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
 fprintf(outFile,"\n***  ï­‹öê ôş¥—úŒ—öí ôııä— 4 øñŸ¥ó ***\n\n");
 fprintf(outFile,"  ôŒ—©¥ù«:");
  for (j=0 ;j<n ;++j)
	 fprintf(outFile,"%-6s ",s1[j].city);
  fprintf(outFile," d       \n ôŒ—©¥ù« --------------------------------------------------\n");
 fflush(outFile);
 for(a=0 ;a<n ;++a)
 {
	if(a)
		  minNumber[a*NO_OF_CITY+n]=d[a*NO_OF_CITY+0];
	else
		  minNumber[a*NO_OF_CITY+n]=d[a*NO_OF_CITY+1];
	for(b=0 ;b<n ;++b)
	{
		if(( a!=b)&&(d[a*NO_OF_CITY+b] < minNumber[a*NO_OF_CITY+n]) )
							minNumber[a*NO_OF_CITY+n]=d[a*NO_OF_CITY+b];


		if( b==0 )
				  fprintf(outFile," %-8s ",s1[a].city);
		xx_contain=d[a*NO_OF_CITY+b];
		fprintf(outFile," %1.3f ",xx_contain);
	}
	 fflush(outFile);
	xx_contain=minNumber[a*NO_OF_CITY+n];
	fprintf(outFile," %1.3f \n", xx_contain);
 }
 fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
fprintf(outFile,"  øõıù“ ¥‹£öóõ ò©¥ 5 øñŸ¥ó \n");
 fflush(outFile);
float db,dbp,sd,sump,dp,dm ;
sump=db=dm=dbp=sd=0 ;
for(a=0 ;a<n ;++a)
{
	 db=db+(float)(minNumber[a*NO_OF_CITY+n]);
	sump=sump+myPow(minNumber[a*NO_OF_CITY+n],(float)(2));
}
dbp=myPow((float)(db),(float)(2));
dbp=dbp/n;
db=db/n ;       //db=d bar
sd=(sump-dbp)/n ;
dp=db+2*sd ;   //dp=d(+)
dm=db-2*sd ;   //dm=d(-)

int k=0;
fprintf(outFile,"\n £õ«Œ“ üó ôîóú ¥ş¦ ûŒùõŒ—©¥ù« \n");
for(b=0 ;b<n ;++b)
  if(d[b]<=dp && d[b]>=dm)
	{fprintf(outFile,"%-8s ",s1[b].city);
					  strcpy(s3[b].city,s1[b].city) ;
		  k=k+1;
		 }
 fflush(outFile);
  fprintf(outFile,"\n*******+++++++*******+++++++*******+++++++*******+++++++*******\n");
fprintf(outFile,"  üî—êŒş øä©ö— áŒŸñ ¦‹ ŒùõŒ—©¥ù«  û£õ“ ø“—¥ 6 øñŸ¥ó:\n");
if(k==n)
  fprintf(outFile,"  £õ ¥‹£ ¥‹¥ì ôîóú ÷ö¥î íş ¥£ ŒùõŒ—©¥ù«  òŒó— \n");
fprintf(outFile," \n  ¬¢Œ« ¥ú û‹¥“  ï‰÷£ş‹ ¥‹£ìó ô£¥ö‰ –©£ ø“ \n");
 fflush(outFile);
floatFile max(NO_OF_CITY);

for(j=0 ;j<m ;++j)
  { xx_contain=z[j];
	 max[j]=xx_contain;
	 for(i=1 ;i<n ;++i)
		if(z[i*NO_OF_CITY+j]>max[j] )
		{
		  xx_contain=z[i*NO_OF_CITY+j];
		  max[j]=xx_contain;
		}
	fprintf(outFile,"  û‹¥“ ï‹÷£ş‹ ¥‹£ìó %-5s :   %1.3f \n",s2[j].index,xx_contain);
  }
	fflush(outFile);
fprintf (outFile,"\n\n**  ôŒ—©¥ù« ¥ú û‹¥“ øä©ö— ë«ó¥© ô £¥ö‰ –©£ ø“**\n\n");
 fflush(outFile);
  if( heapcheck() == _HEAPCORRUPT )
{   cout<< "Heap is corrupted in tokcont.hpp.\n" ;getch();exitProgram();}
//cout <<" fkkkkkk " <<k <<endl;
for(i=0 ;i<k ;++i)
{
 for(j=0 ;j<m ;++j)
	cio[i]=myPow((float)( (float)(d[i*NO_OF_CITY+j])-(float)(max[j]) ),(float)(2))+(float)(cio[i]);

 xx_contain=sqrt(fabs(cio[i]));
 cio[i]=xx_contain;
 fprintf(outFile," %-10s   cio[%d]  :%1.3f \n",s1[i].city,i+1,xx_contain);
}
fprintf(outFile,"\n*******------+*******------+*******+++++++*******+++++++*******\n");
fprintf(outFile,"*** ŒùõŒ—©¥ù«  øä©ö— ÷› ¥£ ø“©ŒŸó 7 øñŸ¥ó ***\n");
fflush(outFile);
float ciob,sio,co;
floatFile fi(NO_OF_CITY);
ciob=sio=co=0;
if(k!=0)
{
for(i=0;i<k;++i)
  ciob +=cio[i];
  ciob=ciob/k;
for(i=0;i<k;++i)
  sio=myPow((float)((float)(cio[i])-ciob),(float) (2))+sio;
sio=sqrt(fabs(sio/k));
co=ciob+2*sio;
for(i=0;i<k;++i)
  fi[i]=(float)(cio[i])/(float)(co);
}
else
 fprintf(outFile,"  £¥‹£õ £ö›ö  ôîóú   ôŒ—©¥ù«   \n");

 fprintf(outFile," êş£¥     ôŒ—©¥ù«                cio      fi  \n");

float xxx2;
int ssArr[NO_OF_CITY];
sort(k,cio,ssArr);
for(i=0;i<k;++i)
{xxx2=fi[i];
 xx_contain=cio[i];
 fprintf(outFile,"   %2d         %-15s      %1.3f     %1.3f\n",i+1,s1[ssArr[i]].city,xx_contain,xxx2);
}
fclose(outFile);
spawnlp(P_WAIT,"ncedit.exe",nameFileOut,nameFileOut,NULL);
//x.remove();
delete[] s1;
delete[] s2;
delete[] s3;
system("sayeh5/u");
clrscr();
}
void sort(int k,floatFile &cio,int *ssArr)
{int i=0,j=0;
 float minCio1,xx;
 int cMin;
 for(i=0;i<k;i++)
	ssArr[i]=i;
  for( i=0;i<k;i++)
  {
	 minCio1=cio[i];
	 cMin=i;
	 for(j=i+1;j<k;j++)
		if(cio[j]<minCio1)
		{
		  minCio1=cio[j];
		  xx=cio[i];
		  cio[j]=xx;
		  cio[i]=minCio1;
		  cMin=ssArr[i];
		  ssArr[i]=ssArr[j];
		  ssArr[j]=cMin;
		}
  }

}

int getOneNumber(void)
{
  char ch;
  do{
	 ch=getch();
  }while(!isdigit(ch));
  return ch;
}

void svaeInputFile(char *nameFile1,int &n ,int &m,cit *s1,ind *s2)
{
 char nam[50];
 strcpy(nam,nameFile1);
 strcat(nam,".in");
 ofstream f11(nam);
 int i,j;
 if(!f11)
  cout<<"can not save to file input data "<<endl;
 else
 {
	f11<<n<<endl;;
	for(i=0;i<n;i++)
	  f11<<s1[i].city<<endl;
	f11<<m<<endl;
	for(i=0;i<m;i++)
	  f11<<s2[i].index<<endl;
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
		 f11<<x[i*NO_OF_CITY+j]<<endl;
	f11.close();
 }

}


void inputFromKeyWord(char *nameFile1,int &n ,int &m,cit *s1,ind *s2)
{
	int i,j;
  printf("  ôí £¥‹ö ‹¥ ¥ù« £‹£ä— : ");
  cin>>n;
  while ( NO_OF_CITY<=n )
	 {printf("  £«Œ“ üóõ ¦Œ›ó 50 ¦‹ ¥—«ı“ ¥ù« £‹£ä—  \n");
	  printf("   šö¥¢ û‹¥“ 0 Œş ôí £¥‹ö 50 ¦‹ ¥—óí ‹¥ ¥ù« £‹£ä— : :");
	  cin >>n;
	  if(n==0)
		 exitProgram();
	  }
 for(i=0 ;i<n ; i++	)
 {
	printf("  ÷¥Œó« ¥ù« %d:",i+1);
	cin >> s1[i].city ;
 }

 printf("  30 Œ— 0 ôı“  ¬¢Œ« £‹£ä— ôí £¥‹ö :");
 cin >>m;
 while (NO_OF_CITY<m)
	 {printf(" £«Œ“ üóõ ¦Œ›ó  ¬¢Œ« £‹£ä— \n");
	  printf("  šö¥¢ û‹¥“ 0 Œş 30 Œ— 0 ôı“  ¬¢Œ« £‹£ä— ôí £¥‹ö : ");
	  cin >>m;
	  if(m==0)
		 exitProgram();
	  }
 for(j=0 ;j<m ;++j )
			 {printf("   ÷¥Œó«  ¬¢Œ« %d:",j+1);
//		scanf("%s",s2[j].index) ;
		cin >>s2[j].index ;
	  }

  printf("***********\n");
		  printf("**  Œú ÷£‹£  ¨ş¥—Œ ó ïıí«— ïö‹ øñŸ¥ó \n ");

 for(i=0;i<n ;++i)
  for(j=0 ;j<m ;++j)
  {printf("  ôí £¥‹ö  x[%d][%d]:",i+1,j+1);
		  cin>>x[i*NO_OF_CITY+j] ;
  }
  cout << "save the input in file ?[0] ";
  char ch=getOneNumber();
  cout<<endl;
  if(ch=='0')
  {
	 cout <<" please get the file for save :";
	 cin>>nameFile1;
	 svaeInputFile(nameFile1,n,m,s1,s2);
	 cout<<endl;
	 fileOutCorrect=1;
  }
  else
  {
	 nameFile1[0]=NULL;
	 if(!tmpnam(nameFile1))
	 {
		cout<<" can not open temp file "<<endl;
		exitProgram();
	 }
	 fileOutCorrect =0;
  }
}
void getInputXX(char *nameFile1,int &n ,int &m,cit *s1,ind *s2)
{
 int i1;
 cout <<" restore from file [0]? or input with hand ? ";
 cin>>i1;
 cout<<endl;
 if(i1)
  inputFromKeyWord(nameFile1,n ,m,s1,s2);
 else
 loadFloat(nameFile1,n,m,s1,s2);
}
void loadFloat(char *nameFile1,int &n ,int &m,cit *s1,ind *s2)
{
 int i,j;
printf("get input file : ");
cin >>nameFile1;
//strcpy(nameFile1,"d:\\out\\data18");
char nameFile[80];
char nameFileIn[50];
strcpy(nameFileIn,nameFile1);
strcat(nameFileIn,".in");
strcpy(nameFile,"ncedit.exe  ");
strcat(nameFile,nameFileIn);

//system(nameFile);
spawnlp(P_WAIT,"ncedit.exe",nameFileIn,nameFileIn,NULL);
ifstream inpFile(nameFileIn);
if(!inpFile)
{
  printf("can not open input file ");
  exitProgram();
}
 inpFile>>n;
 if(inpFile.eof())
	error(1);

 for(i=0 ;i<n ; i++	)
  {
	inpFile >> s1[i].city ;
	if(inpFile.eof())
	  error(2);
 }
 inpFile>>m;
	if(inpFile.eof())
	  error(3);

 for(j=0 ;j<m ;++j )
  {
		inpFile >>s2[j].index ;
	if(inpFile.eof())
	  error(4);

  }

 for(i=0;i<n ;++i)
  for(j=0 ;j<m ;++j)
  {
		 inpFile>>x[i*NO_OF_CITY+j] ;

	if(inpFile. eof())
	  error(4);
  }
 inpFile.close();
}

