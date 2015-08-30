#include"procpars.hpp"
containFileCls *fileParserCls::run(char *name1)
{ bool  bb1 ;
  EinstructionWord ews12 ; int ii18;
  curFile = new containFileCls(name1);
  curFile->addNameFile(name1);
//  cout <<(unsigned )_stklen <<endl;
  int i = 0;
  do{
	  curProc =new containProcCls ;
	  init(curProc);
	  if(i++)
	  {
		  changeHeadProc();
		  nextProcSpecification.initContProcImportant();
	  }
	  else
	  {
		 curProc->addName(name1);
		 curProc->addNameFile(name1);
	  }
	  bb1= parserCls::block(ews12,ii18 );
	  if(bb1) addProcToFile();

  }while(bb1 && (ews12 == LabelInstr) ) ;
  if(!bb1) errorInFile=true;
  return curFile;
}
void fileParserCls::addProcToFile(void)
{curFile->addProc(curProc);}
void  fileParserCls::changeHeadProc(void)
{
  curProc->setHead(&nextProcSpecification);
  nextProcSpecification.setExposeNull();
}
