#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#define roll 29
#define  column 78
int main()
{
	startinterface();
}

void startinterface()
{
	char display[roll][column];
	int column_slide,m,i,j,count;
	for(column_slide=column;column_slide>=0;column_slide--)
	{
		system("cls");
		for(m=0;m<roll;m++)
		{	
			cleardis(display);

			home(display,column_slide,m);

			printdis(display,m);

			printf("\n");
		}	
		if(column_slide<15)
			break;
	}
}

void cleardis(char display[roll][column])
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

void printdis(char display[roll][column],int m)
{
	int j;	
	for(j=0;j<column;j++)
	{
		printf("%c",display[m][j]);
	}
}

void home(char display[roll][column],int column_slide,int m)
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

	for(i=column_slide;i<=column;i++)
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


// What Work Who Work
// Bank eer	>> Interface & map
// Guide 	>> Game control > Interface > score > pointer move & check 
// Prame 	>> Ranking 
// Yok 		>> Interface move & color 