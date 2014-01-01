#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#define roll 29
#define  column 78
int main()
{
	char display[roll][column],home[6][45]={  {"   _________       _||____      ____         "},
												{"__/---------\\_____/-||----\\____/----\\____    "},
												{" /___________\\   /_________\\  /______\\   \\__ "},
												{"/|           |\\ /|         |\\/|      |\\     |"},
												{" |           |   |         |  |      |      |"},
												{" |___________|   |_________|  |______|      |"}};
	int c,m,i,j,count;
	for(c=column;c>=0;c--)
	{
		system("cls");
		for(m=0;m<roll;m++)
		{	
			count = 0;
			for(j=0;j<column;j++)
			{
				display[m][j]=' ';
			}
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
			for(j=0;j<=column;j++)
			{
				printf("%c",display[m][j]);
			}
			printf("\n");
		}
		usleep(20000);
	}
}
// {"   _________       _||____      ____         "},
// {"__/---------\_____/-||----\____/----\____    "},
// {" /___________\   /_________\  /______\   \__ "},
// {"/|           |\ /|         |\/|      |\     |"},
// {" |           |   |         |  |      |      |"},
// {" |___________|   |_________|  |______|      |"}};