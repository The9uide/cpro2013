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
                        cleardis(display);

                        home(display,c,m);

                        printdis(display,m);

                        printf("\n");
                }
                if(c<18)
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

void home(char display[roll][column],int c,int m)
{
        int i,count =0;
        char home[5][51]={        				{" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ "},
                                                {"|   _        ___ ___      __     __      ___  __  |"},
                                                {"|  |_)  /_\\  |   |  |   |__    (__ |__|  |  |__) |"},
                                                {"|  |_) /   \\ |   |  |__ |__     __)|  | _|_ |    |"},
 												{"|                                       ComPrompt |"}
                                                {" -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+ "}},

                start[7][51]={        			{"                         Start                     "},
                                                {"                                                   "},
                                                {"                      Leaderboard                  "},
                                                {"                                                   "},
                                                {"                         Option                    "},
                                                {"                                                   "},
                                                {"                          Exit                     "}};
        for(i=c;i<=column;i++)
        {
                if(m>=7&&m<13)
                {
                        if(count==45)
                        {
                                break;
                        }
                        display[m][i] = home[m-7][count];
                }
                if(m>=17&&m<22)
                {
                        if(count==45)
                        {
                                break;
                        }}
                        display[m][i] = start[m-17][count];
                }
                count += 1;

        }
