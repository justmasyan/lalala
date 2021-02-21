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





int main(void)
{
	initscr();
	uint32_t ch;
	


	int y = LINES/2;
	int x = COLS/2; 

	keypad(stdscr,TRUE);
	curs_set(0);
	mvaddch(y-1,x,'|');
	mvaddch(y,x+1,'#');
	mvaddch(y,x-1,'#');
	tank(y,x);
	while((ch = getch()) != 'q')
	{
		
		if(ch == KEY_UP)
		{
			clear();
			y--;
			mvaddch(y-1,x,'|');
			mvaddch(y,x+1,'#');
			mvaddch(y,x-1,'#');
			tank(y,x);
		}
	
	
		if(ch == KEY_DOWN)
		{
			clear();
			y++;
			mvaddch(y+1,x,'|');
			mvaddch(y,x+1,'#');
			mvaddch(y,x-1,'#');
			tank(y,x);
			
		}
	
		if(ch == KEY_LEFT)
		{
			x--;
			clear();
			mvaddch(y,x-1,'-');
			mvaddch(y+1,x,'#');
			mvaddch(y-1,x,'#');
			tank(y,x);
		}
	
		if(ch == KEY_RIGHT)
		{
			clear();
			x++;
			mvaddch(y,x+1,'-');
			mvaddch(y+1,x,'#');
			mvaddch(y-1,x,'#');
			tank(y,x);
		}

	}
	
	refresh();
	endwin();

	return 0;
}
