#include <ncurses.h>
#include <stdio.h>

int main(void)
{
	initscr();
	uint32_t ch;
	

	struct xboct
	{
		int x;
		int y;
		int digit;
	};

	struct xboct mass[4];

	int y = LINES/2;
	int x = COLS/2; 
	mass[0].x = COLS/2;
	mass[0].y = LINES/2;
	
	mass[0].digit = 0;
	mass[1].digit = 3;
	mass[2].digit = 2;
	mass[3].digit = 1;

	keypad(stdscr,TRUE);
	curs_set(0);
	mvaddch(LINES/2,COLS/2,'*');
	while((ch = getch()) != 'q')
	{

		if(ch == KEY_UP)
		{
			y--;
			mvaddch(y,x,'*');
		}
	
	
		if(ch == KEY_DOWN)
		{
			y++;
			mvaddch(y,x,'*');
			
		}
	
		if(ch == KEY_LEFT)
		{
			x--;
			mvaddch(y,x,'*');
		}
	
		if(ch == KEY_RIGHT)
		{
			x++;
			mvaddch(y,x,'*');
		}
		for(int i = 0; i < 4;i++)
				{
					mass[i].digit++;
					if(mass[i].digit == 4)
					{
						mvaddch(mass[i].y,mass[i].x,' ');
						mass[i].x = x;
						mass[i].y = y;
						mass[i].digit = 0;
					}
				}

	}
	
	refresh();
	endwin();

	return 0;
}
