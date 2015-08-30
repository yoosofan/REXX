//	#include"edit.hpp"  
#include<conio.h>
#include<dos.h>
#include<string.h>
// #include<iostream.h>


int getchcode(void);
/*
void putinmem(unsigned long int segment, unsigned long int offset,
									char * string )
{
	register int i ;

	for(i = 0 ; i < strlen(string) ; i++)
			pokeb(segment, offset+i, *(string+i) ) ;

}

*/
void   putinscreen(int x1 ,int y1,char *str,unsigned int background = 1 ,unsigned int color1=14)
{
//  void menu(int x1, int y1, int x2, int y2, int color, int background)
//{
	register long unsigned int segment = 0xB800, text_offset, color_offset ;
	unsigned int color = color1 ;
	/*      	for(x = x1+1 ; x < x2 ; x++)
		{
			text_offset = 160 * (y1 - 1) + 2 * (x - 1) ;
			color_offset = text_offset + 1 ;
			pokeb(segment, text_offset, 'Í') ;
			pokeb(segment, color_offset, 16*background + color) ;
		}
		*/
// start (1,1)
	for(int x=x1 ; *str ; x++, str++)
	{
		text_offset = 160 * (y1 - 1) + 2 * (x - 1) ;
		color_offset = text_offset + 1 ;
		pokeb(segment,text_offset , *str ) ;
		pokeb(segment,color_offset, (background << 4) +  color) ;
		 }
 }
/*
void  clean(void)
{

	int color =WHITE ;
	int background = BLUE  ;
  long unsigned int segment = 0xB800, text_offset, color_offset ;
  for(int x=1 ; x< 77; x++)
  {
	   text_offset = 160 * (1 - 1) + 2 * (x - 1) ;
	   color_offset = text_offset + 1 ;
	   pokeb(segment, text_offset , ' ' ) ;
	   pokeb(segment , color_offset, 16 * background + color) ;
       }
}
*/

int getchcode(void)
{
	int ch ;

	return ( (ch = getch()) == 0 ) ? 256+getch() : ch ;
}
/*
void main(void)
{
  for (int i=0 ; i<4; i++)
   cout<< " " <<getchcode()<< endl;
}

*/