/*      enum   { PGUP=73 ,PGDOWN=81 , ArrowLeft=75 ,ArrowRight=77,Home=71 ,ALT_F3=106 ,
		Ctrl_PGUP=132 ,Ctrl_PGDOWN=118 ,Ctrl_Home=119 ,Ctrl_End=117 ,
		ArrowDown=80 ,ArrowUp=72 ,ESC=27 ,ENTER=13 , ALT_X=45,End=79,
		F1=59 , F2=60 ,F3=61 ,F5=63 ,F7=65, F10=68 , TAB=9 , Shift_Tab=15
*/
# include <strstrea.h>
# include "arrems.hpp"
//# include<fstream.h>
//# include<conio.h>
//#include<string.h>
#include<alloc.h>
//#include"sayeh.hpp"

//#include "air.hpp"

# define ESC     27
# define HOME    327
# define END     335
# define PGUP    329
# define PGDOWN  337

# define LEFTARR   331
# define RIGHTARR  333
# define UPARR     328
# define DOWNARR   336

# define ALT_F3  362

#define CTRL_PGUP  388
#define CTRL_PGDOWN   374
#define CTRL_HOME     375
#define CTRL_END      373
#define   F9          323
#define   F8          322
#define   F7          321
int getchcode(void);
void menu(int x1, int y1, int x2, int y2, int color, int background);
void   putinscreen(int x1 ,int y1,char *str,unsigned int back=1, unsigned int = 14);
void move_cursor_to(int x , int y);

//void  edit( char * , char * = 0 ,int  = 1 , int  = 2 , int  =  80 , int  = 25 ) ;


# include <stdio.h>
# include <conio.h>

#define MAX_NO_LINE_OF_MONITOR 80
#define MAX_NO_LINE  400
#define MAX_NO_COL 77
#define MAX_NO_FILE 10
const long NO_ALL_CHAR=long(MAX_NO_COL+3)*long(MAX_NO_LINE)*long(MAX_NO_FILE);


char  file_name2[30] ;
class baseEdit {
 public:
	int hevent(int)=0;
};

class editDebug:public baseEdit{
// check is neeed for limit of no character in one line
// start_x  and  start_y is constant

	int first_line,end_line,first_col,end_col,limit_line,limit_col,check;
	int x_curs , y_curs , no_lines,start_x,start_y ;
	baseEdit *upEdit;

	int saved_first_line,saved_end_line,saved_first_col,saved_end_col,saved_limit_line,saved_limit_col,saved_check;
	int saved_x_curs , saved_y_curs , saved_no_lines,saved_start_x,saved_start_y ;
	void save_var(void)
	{
	  saved_first_line=first_line;
	  saved_end_line=end_line;
	  saved_first_col=first_col;
	  saved_end_col=end_col;
	  saved_limit_line=limit_line;
	  saved_limit_col=limit_col;
	  saved_check=check;
	  saved_x_curs=x_curs;
	  saved_y_curs =y_curs ;
	  saved_no_lines=no_lines;
	  saved_start_x=start_x;
	  saved_start_y=start_y;
  }
 void pop_var(void)
 {
	 first_line =saved_first_line;first_line
	 end_line=saved_end_line;
	 first_col=saved_first_col;
	 end_col=saved_end_col;
	 limit_line=saved_limit_line;
	 limit_col=saved_limit_col;
	 check=saved_check;
	 x_curs=saved_x_curs;
	 y_curs=saved_y_curs  ;
	 no_lines=saved_no_lines;
	 start_x=saved_start_x;
	 start_y=saved_start_y;
 }
	public:
	editDebug(int no_line,int left,int top , int right , int bottom,baseEdit *up1=0)
	{
	  upEdit=up1;
	  check=195;
	  no_lines = no_line ;
	  first_line=0 ;
	  limit_line=bottom -top - 1 ;
	  limit_col=right - left - 1 ;
	  first_col =0 ;
	  start_x = left + 1 ;
	  start_y = top  + 1 ;
	  end_col = first_col+limit_col;
	  end_line= first_line+limit_line;
	  x_curs=start_x;
	  y_curs=start_y;
	  if(end_line>no_line)
		 end_line=no_line;
	  save_var();
	}
	void init_cursor_to_line(int l1,intcol1);
	void draw(void);
	int hevent(char *);
	void  editDebug::display();
	int getLine(char *l1,int li1,int col11);
};
void  editDebug::draw(void)
{
  char  l1[MAX_NO_LINE_OF_MONITOR];
  long  z = end_line   ;
  register int  k = 0 , j,color=36;
  for(  j = first_line ; j < z ; j ++ , k++ )
  {
	  if(upEdit)
		 color=upEdit->get_line(l1,j, first_col );
	  else
		 l1[0]='\0';
	  putinscreen(start_x ,start_y+k,l1,color<<4,color>>4);
  }
  move_cursor_to(x_curs,y_curs);
}

void  editDebug::initLine(int linen1,int col1=0)
{ first_col=col1;
  end_col=first_col+limit_col;
  if(!((linen1>=first_line) && (linen1<=end_line) ))
  {
	 if(linen1-limit_line>=0)
	 {
		end_line=linen1;
		first_line=end_line-limit_line;
	 }
	 else
	 {
		first_line=0;
		end_line=first_line+limit_line;
	 }

  }
 init_cursor_to_line( (linen1-limit_line)%limit_line,(first_col1-limit_col1)%limit_col);
}

/*void  editDebug::display()
{
	char  l1[80];
	long  z = end_line  * 200 ;
	register int  k = 0  ;
	for( long int  j = 200 *( first_line+1) ; j < z ; j += 200 , k++ )
		cout << "line="<<(int)(unsigned char)linesEditFile[j-(long)2 ]<< endl; ;
}
  */
int  editDebug::hevent(int code1)
{
  int  p ;
  int noch;
  int  l = start_x - 1 ;
  int  t = start_y - 1 ;
  int  r = start_x + limit_col  ;
  int  b = limit_line + start_y + 1 ;
  long j;
  int c = getchcode() ;
  int  m = 0 , z = 1 ,jj1=0;
  if(upEdit)
	c=upedit->hevent(c);
 if(c<32000)
 {
  switch(c) {
	case    HOME   :

		 x_curs = start_x ;
		 if( first_col != 0 )
			first_col = 0 , m = 1 ;

		break ;
	case    END    :
		 j= (long)(first_line+y_curs-(long)start_y + 1 )*200  ;
		 noch =(int)(unsigned char)linesEditFile[j-2 ] ;
//              cout<<"noch = "<<noch<<"   j="<<j <<"    " ;

		if( noch - first_col < limit_col )
			x_curs = noch - first_col + start_x ;
		else {
			first_col = noch - limit_col + 1 ;
			m = 1 ;
			x_curs = start_x + limit_col - 1 ;
		}
		break ;
	case    PGUP   :
		  if(first_line >0)
		  {
			if( first_line - limit_line + 1 > 0 )
				first_line -= limit_line -1 ;
			else
				first_line = 0 ;
			end_line = first_line + limit_line ;
			m=1 ;
		  }
		  else
			 y_curs = start_y ;
		break ;
	case   PGDOWN  :
			if( end_line >= no_lines - 1 )
			break ;
			if( end_line > no_lines - 1 - limit_line ) {
			first_line = no_lines - 1 - limit_line ;
			end_line = no_lines - 1 ;
			m = 1 ;
			} else {
			first_line += limit_line - 1 ;
			end_line += limit_line - 1 ;
			m = 1 ;
			}
		break ;
	case   LEFTARR :
		if( x_curs != start_x )
			x_curs -- ;
		else if( first_col != 0 ) {
			first_col -- ;
			m = 1 ;
		}
		break ;
	case  RIGHTARR :
		if( x_curs != limit_col + start_x -1 )
			x_curs ++ ;
		else if( first_col + limit_col < 195 ) {
			first_col ++ ;
			m = 1 ;
		}
		break ;
	case   UPARR   :
		if( y_curs > start_y )
			y_curs -- ;
		else if( first_line > 0 ) {
			first_line -- ;
			end_line -- ;
			m = 1 ;
		}
		break ;
	case  DOWNARR  :
		if( y_curs < limit_line + start_y - 1 )// && first_line + y_curs -2 >no_lines )
			y_curs ++ ;
		else if( end_line < no_lines - 1 ) {
			first_line ++ ;
			end_line ++ ;
			m = 1 ;
		}
		break ;
	case    CTRL_PGUP :
		if( first_line == 0 )
			break ;
		first_line = 0 ;
		end_line = first_line + limit_line ;
		m=1 ;
		y_curs = start_y ;
		break ;
	case    CTRL_PGDOWN:
			if( end_line >= no_lines - 1 )
			break ;
			first_line = no_lines - 1 - limit_line ;
			end_line = no_lines - 1 ;
			m = 1 ;
			break ;
	case    CTRL_HOME :
			y_curs = start_y ;
			break;
	case    CTRL_END :
			if( end_line < first_line + limit_line )
			y_curs = end_line - first_line + start_y ;
			else
			y_curs = start_y + limit_line - 1 ;
			break;
	case   ALT_F3  :
	case   ESC :
		z = 0 ;
		break ;
  }
  if( m )
		draw() ;
  move_cursor_to(x_curs,y_curs);
 }
  return z;
}

int  init1(char *name,int &no_lines)
{

	register unsigned long int i,j ;
	if(linesEditFile.status() != EmsArray::okay) {
		cout<<"error allocating  x = "<<(int)linesEditFile.status()<<'\n' ;

	return  1 ;
	}

	no_lines = 0 ;
	char l1[200];
	ifstream  fn(name);
	if( ! fn ) {
		cout<<"can not open file " ;
		return 2 ;
	}
	for( i = 0 ; i < NO_ALL_CHAR ; i++ )
		linesEditFile[i] = ' ' ;
	fn.getline(l1,sizeof(l1),'\n');
	while( ! fn.eof() ) {
		j = 0 ;
		for( i = 0 ; ( i < 195 ) && l1[i] ; i++,j++) {
			if( l1[i] == '\t' )
				for(int  zi = 0 ; zi < 7 ; zi++ , j++ )
					linesEditFile[(long)(200*(long)no_lines+(long)j)] = ' ' ;
			else
				linesEditFile[(long)(200*(long)no_lines+(long)j)]=l1[i];
		}
		if( no_lines > 497 )
			return  3 ;
		no_lines++ ;

		linesEditFile[200*(long)(no_lines)-(long)2]=(unsigned char)j ;
		linesEditFile[200*(long)(no_lines)-(long)1]='\0' ;

		fn.getline(l1,sizeof(l1),'\n');
	}
	strcpy(file_name2,name) ;
	return 0 ;
}


class newEditDebug{
  static int no_of_file_in_use;
  long first,end;
  int  no_lines ;
  EmsArray *linesEditDebugFile ;//( NO_ALL_CHAR , sizeof(char) ) ;
 public:
  newEditDebug(char *name1,)
  {

  }

  void  edit( char  * s , char  * s1 ,  int  l , int  t , int  r , int  b )
  {
//	_setcursortype(_NORMALCURSOR) ;

	int err = 0 ;
	if ( (err = init1( s , no_lines )) )
	{
		char buf12[50];
		for(int ii=0 ; ii<49;ii++)
			buf12[ii]=' ' ;
		buf12[ii]= '\0';
		for(ii=0;ii<5;ii++)
			putinscreen(5,5+ii,buf12,5);
		if(err == 1 )
			putinscreen(10,8," can not allocate memory " ,1);
		else if(err==3)
			putinscreen(10,8," file is too big  " ,1);
		else
			putinscreen(10,8," can not open file  1" ,1);
		getchcode();
		return ;
	}
	editDebug  e1(no_lines,l,t,r,b-1);
	menu(l, t, r, b-1, WHITE, BLUE) ;
//	putinscreen( r - 14 , b - 1 , " " ,5) ;

	if( s1 )
		putinscreen( l + ( r - l ) / 2 - strlen(s1) / 2 - 1 ,t,s1 ,5) ;
	e1.draw() ;
	while(e1.hevent(s1));
}
int hevent(int c)
{
 switch(c) {
	case     F9  :
	 save_var();

	 if( y_curs < limit_line + start_y - 1 )// && first_line + y_curs -2 >no_lines )
			y_curs ++ ;
	 else if( end_line < no_lines - 1 ) {
			first_line ++ ;
			end_line ++ ;
	 }
	pop_var();
	m=1 ;
	break;
	case F8 :
	  save_var();

		if( y_curs < limit_line + start_y - 1 )// && first_line + y_curs -2 >no_lines )
			y_curs ++ ;
		else if( end_line < no_lines - 1 ) {
			first_line ++ ;
			end_line ++ ;
		}
	  pop_var();
	  m=1;
	break;
	case F7:
	 save_var();

		if( y_curs < limit_line + start_y - 1 )// && first_line + y_curs -2 >no_lines )
			y_curs ++ ;
		else if( end_line < no_lines - 1 ) {
			first_line ++ ;
			end_line ++ ;
		}
	  pop_var();
	  m=1;
	break;
	case F5:
	  save_var();

	  pop_var();
	  m=1;
	break;
	case F4:
	  save_var();

	  pop_var();
	  m=1;
	break;
 }

};
/*
main(int argc,char *argv[])
{
//	clrscr();textbackground
	cout<<"cor  "<<coreleft()<<endl;

	if(argc<3) {
		cout<<" .£ö« ‹¥›‹ ü©Œõ«‹öú ¥‹¦ê‹ ò¥õ ï¢‹£ ¦‹ £þŒ“ øóŒõ¥“ ôþ‹\n" ;
	}
	else {
		int  l,t,r,b ;
		char  s[80] ;
		ostrstream   a1(s,80) ;
		a1<<' ' ;
		for( int  i = 2 ; i < argc - 1 ; i++ )
			a1<<argv[i]<<' ' ;
		a1<<'\0' ;
		sscanf(argv[argc-1],"%d_%d_%d_%d",&l,&t,&r,&b) ;
		cout<<" l  " << l <<" t " <<t <<" r "<<r<<" b "<<b<<"  " <<argv[argc-1]<<endl;

		edit(argv[1],s,l,t,r,b) ;
	}

		_setcursortype(_NORMALCURSOR) ;
		EmsArray lines2( NO_ALL_CHAR , sizeof(char) ) ;
		EmsArray lines3( NO_ALL_CHAR , sizeof(char) ) ;
		cout<<"cor  "<<coreleft()<<endl;
}
*/
