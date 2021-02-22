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

	char oper = '0';
	int count = 0;
	
	int y = LINES/2;
	int x = COLS/2; 
	int help;

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
		if((ch == KEY_UP && oper == 'd') || (ch == KEY_DOWN && oper == 'u') || (ch == KEY_RIGHT && oper == 'l') || (ch == KEY_LEFT && oper == 'r'))
		{
			for(int i = 0; i < 4;i++)
			{
				for(int j = 0;j < 4;j++)// dve {
				{
					if(mass[i].digit == 3 && mass[j].digit == 0 && i != j)
					{
						
						x = mass[i].x;
						y = mass[i].y;
						
						help =	mass[i].x;
						mass[i].x = mass[j].x;
						mass[j].x = help;

						help =	mass[i].y;
						mass[i].y = mass[j].y;
						mass[j].y = help;

					}
					if(mass[i].digit == 2 && mass[j].digit == 1 && i != j)
					{
						
						
						help =	mass[i].x;
						mass[i].x = mass[j].x;
						mass[j].x = help;

						help =	mass[i].y;
						mass[i].y = mass[j].y;
						mass[j].y = help;
					}
				}							
			}
	
		}
	
		mvaddstr(0,COLS/2,"           ");	
		if(ch == KEY_UP)
			{
			y--;
			mvaddch(y,x,'*');
			oper = 'u';
			}
	
	
		if(ch == KEY_DOWN)
			{
			y++;
			mvaddch(y,x,'*');
			oper = 'd';
			}

		if(ch == KEY_LEFT)
			{
				x--;
				mvaddch(y,x,'*');
				oper = 'l';
			}
	
		if(ch == KEY_RIGHT)
			{
				x++;
				mvaddch(y,x,'*');
				oper = 'r';
			}

		for(int i = 0; i < 4;i++)
			{
					mass[i].digit++;
					if(mass[i].digit == 4)
					{
						if(x != mass[i].x || y != mass[i].y)
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
