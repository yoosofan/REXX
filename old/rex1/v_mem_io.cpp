//# include "sec.h"  
				/*-------------------------------------------------------------*/
				/* Getchmem function returns character on the column x , line  */
				/* y.                                                          */
				/* Cgetchmem function returns color of character on the column */
				/* x , line y in the given color.															 */
				/*-------------------------------------------------------------*/

#include <Dos.h>
/*
int getchmem(int x , int y)
{
	unsigned long int seg = 0xB800 , off ;

	off = 160*(y-1)+2*(x-1) ;
	return peekb(seg , off) ;
}

int cgetchmem(int x , int y)
{
	unsigned long int seg = 0xB800 , off ;

	off = 160*(y-1)+2*(x-1) ;
	return peekb(seg , off+1) ;
}

				/*------------------------------------------------------------*/
				/* Putchmem function prints given character on the column x , */
				/* line y whithout changing in previous color of that block.  */
				/* Cputchmem function prints given character on the column x, */
				/* line y in the given color.																	*/
				/* Putsmem prints given strung on the column x, line y wihout */
				/* changing in prevoius color of the characters.              */
				/*------------------------------------------------------------*/

void putchmem(int x , int y , unsigned char ch)
{
	unsigned long int segment , offset ;

	segment = 0xB800 ;
	offset = 160 * (y - 1) + 2 * (x - 1) ;
	pokeb(segment , offset , ch) ;
}

void putsmem(const unsigned char *str , int x , int y)
{

	for( ; y <= 25 && *str ; y++)
			for( ; x <= 80 && *str ; x++)
					putchmem(x , y , *str++) ;
}

void cputchmem(int x , int y , unsigned char ch , unsigned char color)
{
	unsigned long int segment , offset ;

	segment = 0xB800 ;
	offset = 160 * (y - 1) + 2 * (x - 1) ;
	pokeb(segment , offset , ch) ;
	pokeb(segment , offset+1 , color) ;
}

void changechcolor(int x , int y , int newcolor)
{
	unsigned long int segment , offset ;

	segment = 0xB800 ;
	offset = 160 * (y - 1) + 2 * (x - 1) + 1 ;
	pokeb(segment , offset , newcolor) ;
}

				/*------------------------------------------------*/
				/* Mov_cursor_to moves cursor to the (x,y) point. */
				/* Get_cursor_position returns x,y of the point   */
				/* in which cursor is locate.                     */
				/* In both function 1 <= x <= 80 , 1 <= x <= 25.  */
				/*------------------------------------------------*/

*/
void move_cursor_to(int x , int y)
{
	union REGS reg ;

	reg.h.ah = 2 ; 				    // Functio number
	reg.h.bh = 0 ;            // Video page number
	reg.h.dh = y - 1 ;        // Screen line
	reg.h.dl = x - 1 ;        // Screen column

	int86(0x10 , &reg , &reg) ;   // Move cursor
}
/*
void get_cursor_position(int *x , int *y)
{
	union REGS reg1 , reg2 ;

	reg1.h.ah = 3 ;					// Function number
	reg1.h.bh = 0 ;         // Video page number

	int86(0x10 , &reg1 , &reg2) ;    		// Get cursor position

	*x = reg2.h.dl + 1 ;				// Get cursor column
	*y = reg2.h.dh + 1 ;				// Get cursor line
}
*/