#include <stdio.h>
#include <stdlib.h>
#define roll 29
#define  column 78

char display[roll][column];
void startinterface();
void cleardis();
void home(char display[roll][column],int column_slide,int m);
int selectmenu();
void moveselectmenu(int select);
void delmoveselectmenu(int select);
void printdis();
void gotomenu(int select);
void gameplay();
void leaderboard();
void option();
void gameplayinterface();

int main() //main
{
	startinterface();
	gotomenu(selectmenu());
}

void startinterface() //first page
{
	int column_slide,m,i,j,count;
	for(column_slide=column;column_slide>=0;column_slide--) //print slide
	{
		system("cls"); //clear display
		cleardis();
		for(m=0;m<roll;m++) 
		{	
			home(display,column_slide,m);
		}
		printdis();
		if(column_slide<15)
			break;
	}
}

void cleardis() //clear  array display
{
	int m,j;
	for(m=0;m<roll;m++)
	{	
		for(j=0;j<column;j++)
		{
			display[m][j]=' ';
		}
	}
}

void home(char display[roll][column],int column_slide,int m) //add interface to display
{
	int i,count =0;
	char home[6][51]={							{" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ "},
                                                {"|   _    _  ___ ___      __     __      ___  __   |"},
                                                {"|  |_)  /_\\  |   |  |   |__    (__ |__|  |  |__)  |"},
                                                {"|  |_) /   \\ |   |  |__ |__     __)|  | _|_ |     |"},
 												{"|                                       ComPrompt |"},
                                                {" -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+ "}}
		
		,start[7][51]={							{"                         Start                     "},
                                                {"                                                   "},
                                                {"                      Leaderboard                  "},
                                                {"                                                   "},
                                                {"                         Option                    "},
                                                {"                                                   "},
                                                {"                          Exit                     "}};

	for(i=column_slide;i<column;i++)
	{
		if(m>=7&&m<13)
		{
			if(count==51)
			{
				break;
			}
			display[m][i] = home[m-7][count];
		}
		if(m>=17&&m<24)
		{
			if(count==51)
			{
				break;
			}
			display[m][i] = start[m-17][count];
		}
		count += 1;

	}
}

int selectmenu() 
{
	char in;
	int select = 0,count = 0;
	while(1) //whait for player select menu
	{
		system("cls");
		moveselectmenu(select);
		printdis();
		delmoveselectmenu(select);
		in = getch(); //input
		if(in == ' ') //select
		{
			return select;
		}
		else if(in == 's' || in == 'S') //down
		{
			select += 1;
			if(select>3)
			{
				select -= 1;
			}
		}
		else if(in == 'w' || in == 'W') //up
		{
			select -= 1;
			if(select<0)
			{
				select += 1;
			}
		}
		else //input not s or w
		{
			continue;
		}
	}
}

void moveselectmenu(int select) 	//add arrow to display
{
	display[17+((select+1)*2)-2][33] = '>';
}

void delmoveselectmenu(int select) //delete arrow 
{
	display[17+((select+1)*2)-2][33] = ' ';
}

void printdis()	//print display
{
	int j,m;
	for(m=0;m<roll;m++) //roll
	{	
		for(j=0;j<column;j++) //column
		{
			printf("%c",display[m][j]);
		}
		printf("\n");
	}
}

void gotomenu(int select) 	//go to page
{
	if(select == 0)
	{
		gameplay();
	}
	else if(select == 1)
	{
		leaderboard();
	}
	else if(select == 2)
	{
		option();
	}
	if(select == 3)
	{
		exit(0);
	}

}

void gameplay()
{
	system("cls");
	cleardis();
	gameplayinterface();
	printdis();
}

void leaderboard()
{
	system("cls");
	printf("Leaderboard");
}
void option()
{
	system("cls");
	printf("Option");
}

void gameplayinterface()
{
	void frame()
	{
		char adds = '#';
		int m,j;
		for(m=0;m<roll;m++)
		{	
			for(j=0;j<column;j++)
			{
				if((m>=0 && m<=4) || m==28 || j<=1 || j>=76)
				{
					display[m][j]= adds;
				}
			}
		}
	}

	frame();

}
// What Work Who Work
// Bank eer	>> Interface & map
// Guide 	>> Game control > Interface > score > pointer move & check 
// Prame 	>> Ranking 
// Yok 		>> Interface move & color 