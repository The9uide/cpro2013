#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#define roll 29
#define  column 78
int main()
{
	char display[roll][column];
	int c,m,i,j,count;
	for(c=column;c>=0;c--)
	{
		system("cls");
		for(m=0;m<roll;m++)
		{	
			for(j=0;j<column;j++)
			{
				display[m][j]=' ';
			}

			home(display,c,m);

			for(j=0;j<=column;j++)
			{
				printf("%c",display[m][j]);
			}
			printf("\n");
		}
	}
}
void home(char display[29][78],int c,int m)
{
	int i,count =0;
	char home[6][45]={	{"   _________       _||____      ____         "},
						{"__/---------\\_____/-||----\\____/----\\____    "},
						{" /___________\\   /_________\\  /______\\   \\__ "},
						{"/|           |\\ /|         |\\/|      |\\     |"},
						{" |           |   |         |  |      |      |"},
						{" |___________|   |_________|  |______|      |"}};
	for(i=c;i<=column;i++)
	{
		if(m>10&&m<17)
		{
			display[m][i] = home[m-11][count++];
			if(count==45)
			{
				break;
			}
		}
	}
}

// {"   _________       _||____      ____         "},
// {"__/---------\_____/-||----\____/----\____    "},
// {" /___________\   /_________\  /______\   \__ "},
// {"/|           |\ /|         |\/|      |\     |"},
// {" |           |   |         |  |      |      |"},
// {" |___________|   |_________|  |______|      |"}};