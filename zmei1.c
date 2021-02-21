#include <ncurses.h>
#include <stdio.h>
void tank(int y,int x)
{
	mvaddch(y,x,'#');	
	mvaddch(y+1,x+1,'#');
	mvaddch(y-1,x+1,'#');
	mvaddch(y-1,x-1,'#');
	mvaddch(y+1,x-1,'#');
}

void alttank(int y,int x)
{
	
	mvaddch(y,x,'#');	
	mvaddch(y+1,x,'#');
	mvaddch(y-1,x,'#');
	mvaddch(y,x-1,'#');
	mvaddch(y,x+1,'#');
}


int main(void)
{
	initscr();
	uint32_t ch;
	


	int y = LINES/2;
	int x = COLS/2; 
	
	int spec_x = x;
	int spec_y = y -1;
	char tryba = '|';
	keypad(stdscr,TRUE);
	curs_set(0);

	mvaddch(spec_y,spec_x,tryba);
	mvaddch(y,x+1,'#');
	mvaddch(y,x-1,'#');
	tank(y,x);

	while((ch = getch()) != 'u')
	{

		if(ch == 'q')
		{
		clear();
		tryba = '\\';
		spec_y = y-1;
		spec_x = x-1;
		mvaddch(spec_y,spec_x,tryba);
		alttank(y,x);
		}
				
		if(ch == 'e')
		{
		clear();
		tryba = '/';
		spec_y = y-1;
		spec_x = x+1;
		mvaddch(spec_y,spec_x,tryba);
		alttank(y,x);
		}


		if(ch == 'z')
		{
		clear();
		tryba = '/';
		spec_y = y+1;
		spec_x = x-1;
		mvaddch(spec_y,spec_x,tryba);
		alttank(y,x);
		}


		if(ch == 'c')
		{
		clear();
		tryba = '\\';
		spec_y = y+1;
		spec_x = x+1;
		mvaddch(spec_y,spec_x,tryba);
		alttank(y,x);
		}
		

		if(ch == 'w')
		{
		clear();
		tryba = '|';
		spec_y = y-1;
		spec_x = x;
		mvaddch(spec_y,spec_x,tryba);
		mvaddch(y,x+1,'#');
		mvaddch(y,x-1,'#');
		tank(y,x);
		}


		if(ch == 'x')
		{
		clear();
		tryba = '|';
		spec_y = y+1;
		spec_x = x;
		mvaddch(spec_y,spec_x,tryba);
		mvaddch(y,x+1,'#');
		mvaddch(y,x-1,'#');
		tank(y,x);
		}


		if(ch == 'a')
		{
		clear();
		tryba = '-';
		spec_y = y;
		spec_x = x-1;
		mvaddch(spec_y,spec_x,tryba);
		mvaddch(y-1,x,'#');
		mvaddch(y+1,x,'#');
		tank(y,x);
		}

		if(ch == 'd')
		{	
		clear();
		tryba = '-';
		spec_y = y;
		spec_x = x+1;
		mvaddch(spec_y,spec_x,tryba);
		mvaddch(y+1,x,'#');
		mvaddch(y-1,x,'#');
		tank(y,x);
		}

		if(ch == KEY_UP)
		{
			clear();
			y--;
			mvaddch(y,x+1,'#');
			mvaddch(y,x-1,'#');
			tank(y,x);
			spec_y--;
			mvaddch(spec_y,spec_x,tryba);
		}
	
	
		if(ch == KEY_DOWN)
		{
			clear();
			y++;
			mvaddch(y,x+1,'#');
			mvaddch(y,x-1,'#');
			tank(y,x);
			spec_y++;
			mvaddch(spec_y,spec_x,tryba);
			
		}
	
		if(ch == KEY_LEFT)
		{
			x--;
			clear();
			mvaddch(y+1,x,'#');
			mvaddch(y-1,x,'#');
			tank(y,x);
			spec_x--;
			mvaddch(spec_y,spec_x,tryba);
		}
	
		if(ch == KEY_RIGHT)
		{
			x++;
			clear();
			mvaddch(y+1,x,'#');
			mvaddch(y-1,x,'#');
			tank(y,x);
			spec_x++;
			mvaddch(spec_y,spec_x,tryba);
		}

	}
	
	refresh();
	endwin();

	return 0;
}
