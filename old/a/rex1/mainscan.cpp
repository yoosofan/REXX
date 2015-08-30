// 1378/2/7
// ahmad yousofan

// this project check the operation of read from file

/*  HELP
				 WHEN REACH THE EOF THE LAST getLine HAVE USEFUL INFORMATION
*/
#include <alloc.h>
//#include<io.h>
#include"all.hpp"
#include"startup.hpp"
startupProgram
outputRexx out1;
//ofstream outDebugError;
inputRexx inpR;
//extern unsigned _stklen = 38210U;
extern unsigned _stklen = 58210U;
void showHelp(void)
{
  clrscr();
  edit("helprexx.hlx","help  rexx",2,2,75,20) ;
	 clrscr();
  exitProgram(0);

}
void checkInput(int argc,char **argv,char *nameFile)
{
 if(argc<=1)
	showHelp();
 else if(argc==2)
	strcpy(nameFile,argv[1]);
 else
  {
	cout<<"many input    (rexx  nameFile.rex )"<<endl;
	exit(0);
  }
}
executeRexxCls  *exr;
int  main(int argc, char *argv[])
{
// int nn1 =9;
// char buffer[MAX_LINE_LENGTH];
  errorReportCls::loadFileError();


 char nameFile[MAX_FILE_NAME]    ;
 checkInput(argc,argv,nameFile);
// outDebugError.clear();
// outDebugError.open("d:\\out\\debugerr.out");
// if(!outDebugError)
// {myDebugKey(1," can not open the file ");exitProgram(0);}
// clrscr();
 errorReportCls::fileError.open("d:\\out\\error.err", ios::out) ;
// strcpy(nameFile , "d:\\rex1\\xxx.rex") ;
 fileParserCls *exfcc= new fileParserCls(nameFile);
 containFileCls *cfc1;
 if((cfc1=exfcc->run(nameFile)))
 {
	if(errorReportCls::noError)	return  1;
	cfc1->print();
	delete exfcc;
//  myDebugKey(1, " after init exeproccls ");
//  executeRexxCls  exRex(cfc1);
  executeRexxCls  *exRex;
exRex=new   executeRexxCls  (cfc1) ;
// exRex.run();
exr=exRex;
exRex->run();
 }
 out1 <<" ram unused " <<(long int) coreleft();
// cout<<endl;
 errorReportCls::fileError.close();
  errorReportCls::deleteFileError();
 return 1;
}
