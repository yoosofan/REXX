	/*--------------------------------------------------------------*/  
	/* This Function draws a Menu from(x1 , y1) to (x2 , y2) on the */
	/* screen. Color of lines specifies by color and inside color   */
	/* specifies by background. For using this function range of x  */
	/* and y is: 1 <= x <= 80 and 1 <= y <= 25 .                    */
	/*--------------------------------------------------------------*/

#include <Dos.h>

	void swapint(int *a , int *b) ;
void menu(int x1, int y1, int x2, int y2, int color, int background)
{
	register int x, y ;
	register long unsigned int segment = 0xB800, text_offset, color_offset ;

	if( (x1 == x2) || (y1 == y2) )
			return ;
	if( x1 < 1 || x1 > 80 || x2 < 1 || x2 > 80 )
			return ;
	if( y1 < 1 || y1 > 25 || y2 < 1 || y2 > 25 )
			return ;
	if(x1 > x2)
			swapint(&x1 , &x2) ;
	if(y1 > y2)
			swapint(&y1 , &y2) ;

	text_offset = 160 * (y1 - 1) + 2 * (x1 - 1) ;
	color_offset = text_offset + 1 ;
	pokeb(segment , text_offset, 'É') ;
	pokeb(segment , color_offset, 16*background + color) ;

	for(x = x1+1 ; x < x2 ; x++)
		{
			text_offset = 160 * (y1 - 1) + 2 * (x - 1) ;
			color_offset = text_offset + 1 ;
			pokeb(segment, text_offset, 'Í') ;
			pokeb(segment, color_offset, 16*background + color) ;
		}
	text_offset = 160 * (y1 - 1) + 2 * (x2 - 1) ;
	color_offset = text_offset + 1 ;
	pokeb(segment, text_offset, '»') ;
	pokeb(segment, color_offset, 16*background + color) ;
	for(y = y1+1 ; y < y2 ; y++)
		{
			text_offset = 160 * (y - 1) + 2 * (x2 - 1) ;
			color_offset = text_offset + 1 ;
			pokeb(segment, text_offset, 'º') ;
			pokeb(segment, color_offset, 16*background + color) ;
		}
	text_offset = 160 * (y2 - 1) + 2 * (x2 - 1) ;
	color_offset = text_offset + 1 ;
	pokeb(segment, text_offset, '¼') ;
	pokeb(segment, color_offset, 16*background + color) ;
	for(x = x2-1 ; x > x1 ; x--)
		{
			text_offset = 160 * (y2 - 1) + 2 * (x - 1) ;
			color_offset = text_offset + 1 ;
			pokeb(segment, text_offset, 'Í') ;
			pokeb(segment, color_offset, 16*background + color) ;
		}
	text_offset = 160 * (y2 - 1) + 2 * (x1 - 1) ;
	color_offset = text_offset + 1 ;
	pokeb(segment, text_offset, 'È') ;
	pokeb(segment, color_offset, 16*background + color) ;
	for(y = y2-1 ; y > y1 ; y--)
		{
			text_offset = 160 * (y - 1) + 2 * (x1 - 1) ;
			color_offset = text_offset + 1 ;
			pokeb(segment, text_offset, 'º') ;
			pokeb(segment, color_offset, 16*background + color) ;
		}
	for(y = y1+1 ; y < y2 ; y++)
			for(x = x1+1 ; x < x2 ; x++)
				{
					text_offset = 160 * (y - 1) + 2 * (x - 1) ;
					color_offset = text_offset + 1 ;
					pokeb(segment, text_offset, ' ') ;
					pokeb(segment, color_offset, 16*background + color) ;
				}
}

	/*-------------------------------------------*/
	/* This Function swaps two integer numbers . */
	/*-------------------------------------------*/
void swapint(int *x, int *y)
{
 int z ;
 z = *x ;
 *x = *y ;
 *y = z ;
}
