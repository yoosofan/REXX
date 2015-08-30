#ifndef ALL_HPP
#define ALL_HPP
// 1378/2/1
// write by ahmad yousefan
#define MAX_LINE_LENGTH  255
#define MAX_FILE_NAME  50
#define DEMO_HEHEHEHEHEHHEHEH 20
#define MAX_LINE_IN_PROCEDURE 1000
#define	MAX_TOKEN_EXPR 255
#define NUMBERfORM float
#define MAX_OF_WHEN 300
#define MAX_NESTED_CALL_FUNCTION 40
#define MAX_LENGTH_OF_NAME  200
//#define THEOUTPUTOFDEBUGERRORFILE "debugErr.out"

#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<io.h>
//#include<alloc.h>
//#include"outRexx.hpp"
#include"global.hpp"
//#include"tostr.hpp"

#include"map.hpp"
#include"mapint.hpp"
#include"stringcl.hpp"

#include"enumpars.hpp"


#define MAX_NUMBER_LENGTH 30
#include"outRexx.hpp"
///#include"outrexx.hpp"
#include"inprexx.hpp"

bool tokenFind(EtokenType e1 ,char*  p1);
bool instrFind(EinstructionWord e1 ,char * p1);


#include"erreport.hpp"
#include"filecont.hpp"
#include"tokcont.hpp"
#include"contvar.hpp"
#include"exprcont.hpp"
#include"scancls.hpp"
#include"contstmt.hpp"
#include"contproc.hpp"
#include"contfile.hpp"
#include"parsercl.hpp"
#include"procpars.hpp"


#include"valuevar.hpp"
#include"stackval.hpp"
#include"arrcont.hpp"
#include"fcalcont.hpp"
#include"stackfun.hpp"
#include"exprexh.hpp"

#include"execcls.hpp"
#include"exefile.hpp"
#include"exerex.hpp"

#endif
