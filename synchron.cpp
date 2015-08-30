#include"all.hpp"

bool parserCls::syncStmtError(void)
{
  bool bb1 =true ;
  EtokenType tt7 = getTokenType();
  while( (tt7!=Semicolon) && (tt7 !=EndOfLine) && (tt7 !=EndOfFile) )
  {
    getToken();
    tt7 = getTokenType();
  }
  if(tt7 == EndOfFile )
  {
    bb1 =false ;
    outerr.unrecover();
  }
  else
    parserErrorOccurred = false ;

  return bb1  ;
}

bool   parserCls::syncSelect(void)
{
  bool bb1 =true ;
  EtokenType tt7 = getTokenType();
  while( (tt7!=Semicolon) && (tt7 !=EndOfLine) && (tt7 !=EndOfFile) && (tt7 != When) )
  {
    getToken();
    tt7 = getTokenType();
  }
  if(tt7 == EndOfFile )
  {
    bb1 =false ;
    outerr.unrecover();
  }
  else
    parserErrorOccurred = false ;

  return bb1  ;
}

bool parserCls::syncErrorThen(void)
{
  bool bb1 =true ;
  EtokenType tt7 = getTokenType();
  while( (tt7!=Semicolon) && (tt7 !=EndOfLine) && (tt7 !=EndOfFile) && (tt7 != Then) )
  {
    getToken();
    tt7 = getTokenType();
  }
  if(tt7 == EndOfFile )
  {
    bb1 =false ;
    outerr.unrecover();
  }
  else
    parserErrorOccurred = false ;
  return bb1  ;
}