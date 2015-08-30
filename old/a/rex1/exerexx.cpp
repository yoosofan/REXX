#include"exerex.hpp"

int executeRexxCls::isInListOfExternal(fCallContCls &tt)
{
 int i1=0;
 mapiter<stringCls,int> mp12(nameOfFiles);
 if(nameOfFiles.is_in_map(tt.getName())==true)
 {
  mp12.set_p_cur() ;
  i1=mp12.value();
  i1++;
 }
 return i1;
}
valBool executeRexxCls::executeFile(int i1)
{
  executeFileRexxCls *preExeF=curExeFile;
  containFileCls *preConF=curFile;
  curFile=listOfFiles.getPi(i1);
  curExeFile=new executeFileRexxCls(curFile,this);

  int pre1=	indexFileExecute;
  int pre2=	indexProcExecute;

  indexFileExecute=i1;
  indexProcExecute=0;

  valBool vb1=run();
  delete curExeFile;
  curFile=preConF;
  curExeFile=preExeF;
  indexFileExecute=pre1;
  indexProcExecute=pre2;

  return vb1;
}
bool executeRexxCls::canOpenNewFile(fCallContCls &tt)
{ char nameF1[MAX_FILE_NAME];
  tt.getName().get_p(nameF1);
  strcat(nameF1,".rex");
 nameF1[MAX_FILE_NAME-1]=NULL;

 ifstream f1(nameF1);
 if(f1)
 {
	 f1.close();
	 return true;
 }
 return false;
}
valBool executeRexxCls::parseAndExecuteNewFile(fCallContCls &tt)
{
 valBool vb1;
 vb1.b=false;
 char nameF1[MAX_FILE_NAME];
 tt.getName().get_p(nameF1);
 strcat(nameF1,".rex");
 nameF1[MAX_FILE_NAME-1]=NULL;
 bool bb12=false;
 fileParserCls *exfcc= new fileParserCls(nameF1);
 containFileCls *cfc1;
 if((cfc1=exfcc->run(nameF1)))
 {
	if(errorReportCls::noError)  exitProgram(0);
	cfc1->print();
	delete exfcc;
	bb12=true;
 }
 else exitProgram(0);
 if(bb12)
 {
	nameOfFiles[tt.getName()]=noOfFileCompiled;
	listOfFiles[noOfFileCompiled]=cfc1;
	noOfFileCompiled++;
	vb1=executeFile(noOfFileCompiled-1);
 }
 return vb1;
}
valBool executeRexxCls::callExternalFunction(fCallContCls &tt)
{
 int i1=0;
 valBool ret1;

 if((i1=isInListOfExternal(tt)))
 {ret1=executeFile(i1-1);}
 else if(canOpenNewFile(tt))
	ret1=parseAndExecuteNewFile(tt);
 else
	{
	char sss12[50];
	getNameFile(sss12);
  cout<<" error in file   "<<sss12<<endl;
	getNameProc(sss12);
	 cout<<" error in procedure   "<<sss12<<endl;
	  cout<<" LINE OF ERROR "<<getCurNoLine()<<endl;
	  cout <<" name function is not found     " <<tt.getName()<<endl;
	  myDebugKey(0,"can not execute function ");
	  exitProgram(0);

	}
 return ret1;
}

struct nameInternalFunc{
	  char *name ;
	  int noOfArg ;
	  int maxOfArg;
  };

struct nameInternalFunc namesInterFunc[] = {
//					 minimum argument     maximum argument
//	{ "ABBREV" ,      2,                   3},// -1 IDENTIFY UNLIMITED ARGUMENT
	{ "ABS",1,1},
//	{ "ADDRESS",      0,                   0 },
//	{ "ARG" ,         0 ,                  0},
//	{ "ARG" ,         1,                   1 },
//	{ "ARG",          2 ,                  0},
//	{ "BITAND",       1,                   3},
//	{ "BITOR",1,3},
//	{ "BITXOR",1,3},
//	{ "B2X",1,1 },
//	{ "CENTER",2,3},
//	{ "CENTRE",2,3},
//	{ "CHARIN",0,3},
//	{ "CHAROUT",0,3},
//	{ "CHARS",0,1},
//	{ "CMSFLAG",1,1},
	{ "COMPARE",2,2},
//	{ "COMPARE",2,3},
//	{ "CONDITION",1,1},
//	{ "CONDITION",0,0},
//	{ "COPIES",-5,-5}, //	{ "COPIES",2,2},
//	{ "CSL",1,1},
//	{ "C2D",1,2},
//	{ "C2X",1,1},
//	{ "DATATYPE",1,1},
//	{ "DATE",0,0},
//	{ "DATE",1,1},
//	{ "DELSTR",2,2},
//	{ "DELSTR",3,3},
//	{ "DELWORD",2,2},
//	{ "DELWORD",3,3},
//	{ "DIAG",-1,-1},
//	{ "DIAGRC",-1,-1},
//	{ "D2C",1,2},
//	{ "D2X",1,2},
//	{ "ERRORTEXT",1,1},
//	{ "EXTERNALS",0,0},
//	{ "FIND",2,2},
//	{ "FORM",0,0},
//	{ "FORMAT",1,3},
//	{ "FUZZ",0,0},
//	{ "INDEX",2,3},
//	{ "INSERT",2,5},
//	{ "JUSTIFY",2,3},
//	{ "LASTPOS",2,3},
//	{ "LEFT",2,3},
//	{ "LENGTH",1,1},
//	{ "LINEIN",0,3},
//	{ "LINEOUT",0,3},
//	{ "LINES",0,1},
//	{ "LINESIZE",0,0},
//	{ "MAX",1,-1},
//	{ "MIN",1,-1},
  //	{ "OVERLAY",2,5},
//	{ "POS",2,3},
//	{ "QUEUED",0,0},
//	{ "RANDOM",0,3},
//	{ "REVERSE",1,1},
//	{ "RIGHT",2,3},
//	{ "SIGN",1,1},
//	{ "SOURCELINE",0,1},
//	{ "SPACE",1,3},
//	{ "STORAGE",0,0},
//	{ "STORAGE",2,2},
//	{ "STORAGE",3,3},
//	{ "STREAM",1,2},
//	{ "STREAM",3,3},
//	{ "STRIP",1,3},
	{ "SUBSTR",2,3},//	{ "SUBSTR",2,4},
	{ "SUBWORD",-5,-5},//	{ "SUBWORD",2,3},
//	{ "SYMBOL",1,1},
	{ "TIME",0,0},
//	{ "TIME",1,1},
//	{ "TRACE",0,0},
//	{ "TRACE",1,1},
//	{ "TRANSLATE",1,4},
	{ "TRUNC",1,2},
//	{ "USERID",0,0},
//	{ "VALUE",1,1},
//	{ "VALUE",2,2},
//	{ "VALUE",2,3} ,
//	{ "VERIFY",2,4},
//	{ "VERIFY",3,4},
	{ "WORD",2,2},
	{ "WORDINDEX",2,2},
	{ "WORDLENGTH",2,2},
//	{ "WORDPOS",2,3}
	{NULL,-5,-5}
 };

int executeRexxCls::isInternalFunction(fCallContCls &tt)
{ register int indexF=0;
  for(;namesInterFunc[indexF].noOfArg>=-1;indexF++)
	if(tt.getName()==(namesInterFunc[indexF].name) )
	  if((tt.size()>=namesInterFunc[indexF].noOfArg || namesInterFunc[indexF].noOfArg==-1)&&
	(tt.size()<=namesInterFunc[indexF].maxOfArg || namesInterFunc[indexF].maxOfArg==-1))
		 return indexF+1;
	return 0;
}
valBool executeRexxCls::callInternalFunction(int lif,fCallContCls &tt)
{ //return pointerOfInternalFunctions[lif-1](tt);
	valBool ret1;
	ret1.b=true;
	NUMBERfORM  dd12=0;
	variableValue vv11,vv22,vv33;
	  char *p1,*p2;
	 int cmp1,i1,i2,j;
	 int no_arg=tt.size();
  switch (lif)
  {
	 case 1:
// 	   ABS
		 ret1.val=tt.getArg(0);
		 dd12=ret1.val.getNumberOfVar();
		 dd12=fabs(dd12);
		 ret1.val=variableValue(dd12);
	 break;
	 case 2:
//	{ "COMPARE",2,2},

	  vv11=tt.getArg(0);
	  vv22=tt.getArg(1);

	  p1=vv11.getNewCharPointer();
	  p2=vv22.getNewCharPointer();
		cmp1=ahmadStrcmp(p1,p2);
	  ret1.val=variableValue(cmp1);
	  delete[] p1;
	  delete[] p2;

	 break;
	 case 3:
			vv11=tt.getArg(0);
			vv22=tt.getArg(1);

			p1=vv11.getNewCharPointer();
			cmp1=vv22.getNumberOfVar();
		 i1=strlen(p1)+1;

		 if(no_arg==3)
		 {
			vv33=tt.getArg(2);
			i1=vv33.getNumberOfVar();

		 }
		 j=0;
		 for(;*p1&&(*p1==' ');p1++);
		 i2=strlen(p1)+1;
		 p2=new char[i2+2];
	  if(!( ( i2<cmp1) || ( cmp1<0 ) ) )
	  {
		 for(;*(p1+cmp1);p1++)
		 {
		  if(!i1)
			 break;
		  i1--;
		  p2[j++]=*(p1+cmp1);
		 }
		 p2[j]=NULL;
		 ret1.val=variableValue(p2);
	  }
	  else
		ret1.val=variableValue("");

		delete[] p2;
	  ret1.b=true;

	 break;
/*
	 case 4:

	 break;

	 case 5:

	 break;
	 case 6:

    break;
    case 7:

    break;
    case 8:

    break;
    case 9:

	 break;
    case 10:

    break;
    case 11:

    break;
	 case 12:

	 break;
    case 13:

    break;
	 case 14:

    break;
    case 15:

    break;
    case 16:

    break;
    case 17:

    break;
	 case 18:

	 break;
	 case 19:

    break;
    case 20:

	 break;
    case 21:

    break;
    case 22:

    break;
	 case 23:

    break;

    case 24:

    break;
	 case 25:

	 break;
	 case 26:

	 break;
	 case 27:

	 break;
	 case 28:

	 break;
	 case 29:

	 break;
	 case 30:

	 break;
  */
	default :
	break;
}
return ret1;
}