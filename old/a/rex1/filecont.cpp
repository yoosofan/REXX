#include"all.hpp"

bool fileContainCls::getLineI(char *buffer ,int ind)
{
 register long int i1=0;
// register int nl1=0;
 char c1;
 bool bb1 = true;
 long prePos=posCharInFile;
 if(ind<fileSize)
 {
	for(;(i1<fileSize)&& ind;i1++)
	  if((c1=(*file1)[posCharInFile++])=='\n')
		 ind--;
	posCharInFile=i1;
 }
 else
 {
	bb1=false;
	posCharInFile=0;
 }
 bb1=getLine(buffer);
 posCharInFile=prePos;
 return bb1;
}
bool fileContainCls::getLine(char *buffer  /*   */ )
{
 bool bb1=true ;
 register int i1=0;
 if(posCharInFile<fileSize)
 {
	for(;(i1<MAX_LINE_LENGTH -2)&&(posCharInFile<fileSize);i1++)
	{
	  *buffer=(*file1)[posCharInFile++];
	  if(*buffer=='\n')
		 break;
	  buffer++;
	}
	if(*buffer=='\n')
		*++buffer='\0';
	else if(i1>=MAX_LINE_LENGTH -2)
		error();
	else
	{
		*buffer++='\n';
		*buffer='\0';
	}
 }
 else
	 bb1 = false;
 return bb1;
 /*
 if(eof())bb1 =false ;
 else
 {
	sourceFile.getline(buffer , MAX_LINE_LENGTH) ;
	if(eof())
	{buffer[sourceFile.gcount()]='\n';buffer[sourceFile.gcount()+1] ='\0';}
	else
	{buffer[sourceFile.gcount()-1]='\n';buffer[sourceFile.gcount()]='\0';}
 }
 return  bb1    ;
 */

}
bool fileContainCls::eof(void)
{
 /*
  if(sourceFile.eof())
	  return true;
  return false ;
 */
 return true;
}
void fileContainCls::errorOpenFile(void)
{
  errorReportCls outerr(CanNotOpenFile,nameFile);
  outerr.unrecover();
}
void fileContainCls::errorFile(void)
{
  errorReportCls outerr(CanNotReadFile ,nameFile) ;
  outerr.unrecover();
}
fileContainCls::fileContainCls(char *name , char *ss )
{
	ifstream sourceFile ;
	file1=new EmsArray( MAXIMUM_FILE_SIZE+100, sizeof(char) );
	char far *p1;
	noOfLinesFile=0;
	posCharInFile=0;
	fileErrorDetect = false ;
	strcpy(nameFile , name) ;
	sourceFile.open(nameFile , ios::in , ios::nocreate);
	if(!sourceFile)
	{
	  errorOpenFile();
	  fileErrorDetect = true ;
	}
	else
	{
	 int i1=FD(sourceFile);
	 if(i1<0)
	 {
	  errorOpenFile();
	  fileErrorDetect = true ;
	 }
	 else
	 {
		fileSize=filelength(i1);
		if((fileSize<=0) ||(fileSize>32000L))
		{
		  errorOpenFile();
		  fileErrorDetect = true ;
		}
		else
		{
		 p1=new char[fileSize+10];
		 if(!p1)
		 {
			errorOpenFile();
			fileErrorDetect = true ;
		 }
		 else
		 {
			int kk1=read(i1,p1,fileSize);
			if(kk1==-1)
			{
			  errorOpenFile();
			  fileErrorDetect = true ;
			}
			else
			{
			  p1[kk1]='\0';
			  fileSize=kk1;
			  copyToEms(p1,kk1);
			  delete[] p1;
			  sourceFile.close();
			}
		 }
		}
	  }
	 }
  }
void fileContainCls::copyToEms(char far *p1,int kk1)
{
 register int i1=0;
 for(;i1<=kk1;i1++)
 {
  (*file1)[i1]=p1[i1];
  if(p1[i1]=='\n')
	 noOfLinesFile++;
 }
}
int fileContainCls::getLineOfToken(int pos1,int &of1)
{int no_line1=1;
 for(int j1=0;(j1<posCharInFile)&&(j1<=pos1);j1++)
	if((*file1)[j1]=='\n')
	{
	  no_line1++;
	  of1=1;
	}
	else
	 of1++;
 return no_line1 ;
}


