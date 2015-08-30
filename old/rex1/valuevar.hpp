#ifndef VALUEVAR_HPP
#define VALUEVAR_HPP

#include"all.hpp"
extern inputRexx inpR;
extern outputRexx out1;
enum typeVar{ Str , Real , Logic } ;
class variableValue{
 public:
	typeVar tv ;
	union{
	  bool   b ;
	  NUMBERfORM  d ;
	  char *s;
	};
//	variableValue()    {tv =Real ;d =1 ;}
	variableValue(void){tv =Real ;d =1 ;}
	~variableValue()
	{  deleteStrVar();
//	 if( heapcheck() == _HEAPCORRUPT )
//	  {printf( "Heap is corrupted.in ~valuevar \n" );exitProgram(1);}

	}
	void deleteStrVar(void)
	{
	  if(tv ==Str){delete[] s ;s=0;}
	}
	void deleteStrVar(variableValue &v1)
	{
	  if(v1.tv ==Str){  delete[] v1.s ;		v1.s=0;}
	}

	  variableValue(char * p)
	  {
	  tv = Str ;
	  s = new char[strlen(p)+2] ;
	  strcpy(s,p) ;
//  if( heapcheck() == _HEAPCORRUPT )
//{   cout<< "   Heap is corrupted.in  variableValue(char *p) \n" ;exitProgram(1);}

 }
	  variableValue(stringCls s1)
	  {
		 tv = Str;
		 int i =s1.size_of_str();
		 s=new char[i+4];
		 s1.get_p(s) ;
//  if( heapcheck() == _HEAPCORRUPT )
//{   cout<<i<< "   Heap is corrupted.in  variableValue(stringCls s1) \n" ;exitProgram(1);}

	  }
	  variableValue(NUMBERfORM d1)
	  {      tv =Real; d =d1 ;       }
	  variableValue(bool b1) { tv = Logic ;b = b1 ;}

	  variableValue(variableValue const & v1);

	  NUMBERfORM convertToNumber( char *pp1);
	  void convertNumber(NUMBERfORM , char **pp1);
	  NUMBERfORM  variableValue::getOrdNumber(char *pp1 , int &i1);
	  void variableValue::conVal1(variableValue &v1);
	  void conVal2(variableValue &v1);
		void variableValue::conVal3(variableValue &v1);
	  void variableValue::conVal4(variableValue &v1);
	  void conVal21(void);
	  void conVal11(void);
	  void error(int ii1);
	  void myDebug(variableValue & v1 , char *pp12)
	  {
//		 outR<<"left value== "<< (*this)<<"   "<<pp12<<"   right value== "<<v1;

		 out1<<"left value== "<< (*this)<<"   "<<pp12<<"   right value== "<<v1<<"\n";
	  }
	  void myDebugResult(variableValue  v1 )
	  {
//	 outR<<"  result is== "<<v1<< endl;
//	 out1<<"  result is== "<<v1<< "\n";

//	 myDebug(1,"   ");
//	 inpR.getKeyIo();
	  }
	 bool isZeroD(void)
	 {      bool bb1 = false;
		if(fabs(d)<exp(-MAX_NUMBER_LENGTH) )
		bb1 = true ;
		return bb1 ;
	 }
	 bool isZeroD(variableValue & v1)
	 { bool bb1 = false;
		if(fabs(v1.d)<exp(-MAX_NUMBER_LENGTH) )
		 bb1 = true ;
		return bb1 ;
	 }
	 bool isZeroD(double v1)
	 {
		 bool bb1 = false;
		 if(fabs(v1)<exp(-MAX_NUMBER_LENGTH) )
		 bb1 = true ;
		 return bb1 ;
	 }
	 bool isTrue(void);
	 variableValue concat(variableValue &v1);
	 variableValue mod(variableValue &s2);
	 variableValue pow(variableValue &s2);

//	  variableValue operator==(variableValue &v1);
bool variableValue::operator==(variableValue &v1);
	  variableValue operator<=(variableValue &v1);
	  variableValue operator>=(variableValue &v1);
	  variableValue operator!=(variableValue &v1);
	  variableValue operator>(variableValue &v1);
	  bool operator<(variableValue &v1);

	  variableValue operator&&(variableValue &v1);
	  variableValue operator||(variableValue &v1);
	  variableValue operator^(variableValue &v1);
	  variableValue  variableValue::operator!(void);
	  variableValue  variableValue::operator-(void);


	  variableValue operator+(variableValue &v1);
	  variableValue operator-(variableValue &v1);
	  variableValue operator*(variableValue &v1);
	  variableValue operator/(variableValue &v1);
	  void  operator=(variableValue &v1);
		void  checkEqOfTv(variableValue &v1,char *ss1)
		{ /*char str12[40];
		  strcpy(str12,ss1);
		  strcat(str12,"   master Programmer Error Not eq of tv");
			cout<<" v " << (*this) << " v1 "<<v1<<endl;
		  */
		  if(v1.tv != tv) myDebugKey(0,"master Programmer Error Not eq of tv");
		}
	void variableValue::getStr(stringCls &nameString1);
	char *variableValue::getNewCharPointer(void);
	void variableValue::conVal5(void);
	  NUMBERfORM  variableValue::getNumberOfVar(void)
	  {
		conVal21();
		return d;
	  }

  void  operator=(bool bb1)
  {
	 if(tv == Str)
		deleteStrVar();
	 tv = Logic ;
	 b = bb1 ;

  }



	friend  ostream& operator<<(ostream & , variableValue &);
	friend  outputRexx& operator<<(outputRexx & , variableValue );
	friend  istream& operator>>(istream & , variableValue );
};

struct valBool
{
  variableValue  val ;
  bool b ;
};

#endif