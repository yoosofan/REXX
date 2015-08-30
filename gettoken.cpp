#include "all.hpp"
void parserCls::getToken(void)
{ if(nextTokenPresent)
  {nextTokenPresent = false;curToken = nextToken ;}
  else
	 get_token();//call scannerCls::get_token()to init scannerCls::curToken
}
void parserCls::ungetToken(tokenContainCls &t1)
{nextToken=curToken;curToken=t1;nextTokenPresent=true;}
