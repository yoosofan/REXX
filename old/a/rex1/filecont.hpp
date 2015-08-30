#ifndef FILECONT_HPP
#define FILECONT_HPP
// 1378/2/6
// write by ahmad yousefan
#include"all.hpp"
#include"arrems.hpp"
#define FD(s) (((s).rdbuf())->fd())
#define MAXIMUM_FILE_SIZE 32000
class 	fileContainCls /*public fstream */ {
// this class should read from ether FILE and MEMORY
// or you can write other impelementation of this work
//	ifstream sourceFile ;
  EmsArray *file1;
	int Filesize;
  protected:
	char nameFile[MAX_FILE_NAME] ;
	bool fileErrorDetect ;
	long fileSize;
	int noOfLinesFile,posCharInFile ;
 public:
  ~fileContainCls(void)
  {
//	if(sourceFile) sourceFile.close() ;
	 (*file1).~EmsArray();

  }
  fileContainCls(char *name , char *ss = 0);
  bool getLine(char *buffer  /*   */ );
  bool getLineI(char *buffer ,int ind);
  bool eof(void) ;
  void errorFile(void) ;
  void errorOpenFile(void);
  void copyToEms(char far *p1,int kk1);

  int fileContainCls::getLineOfToken(int pos1,int &of1);
  void error(void)
  {cout<<" max pos in line  "<<endl;exitProgram(0);}

};
#endif