#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include "color.h"
#define roll 29
#define column 78

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
void saveScore(char playerName[100] , int playerScore,int swt);
void readScore();
char game_player[2][100];
void sortRank();
void checkSaveRank(char playerName2[100] ,int nowscore2);
char UserRank[3][100];
int scoreRank[3][1],winner,scorewinner;
int first=0,second=0,third=0; // index of rank first = 1 second = 2 Lower = 3

int main() //main
{
	startinterface();
	gotomenu(selectmenu());
	//readScore();
}

void startinterface() //first page
{
	int column_slide,m,i,j,count;
	// system("mode con:cols=79 lines=30");
	for(column_slide=column;column_slide>=0;column_slide-=2) //print slide
	{
		system("cls"); //clear display
		cleardis();
		for(m=0;m<roll;m++) 
		{	
			sleep(1);
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
 												{"|                                        ComPrompt|"},
                                                {" -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+ "}
    },
    start[7][51]={								{"                         Start                     "},
                                                {"                                                   "},
                                                {"                      Leaderboard                  "},
                                                {"                                                   "},
                                                {"                     Change player name            "},
                                                {"                                                   "},
                                                {"                          Exit                     "}
    };

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
//pame code
void home_leader() //add interface to display
{
	readScore();
	int i,count =0;
	char home[6][51]={							{" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"},
                                                {"|  LEADERBOARD_ ___      __     __      ___  __  |\n"}, 
                                                {"|  |_)  /_\\  |   |  |   |__    (__ |__|  |  |__) |\n"},
                                                {"|  |_) /   \\ |   |  |__ |__     __)|  | _|_ |    |\n"},
 												{"|                                       ComPrompt|\n"},
                                                {" -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+\n"}
    };
	printf("%s\n",home[0] ); 
	printf(" > 1st  %s  -  %d Point\n",UserRank[0],scoreRank[0][0] );
	printf(" > 2nd  %s  -  %d Point\n",UserRank[1],scoreRank[1][0] );
	printf(" > 3rd  %s  -  %d Point\n",UserRank[2],scoreRank[2][0] );
	printf("\nPress Any Key to Back\n");


}
void home_option() //add interface to display
{
	readScore();
	int i,count =0;
	char home[6][51]={							{" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"},
                                                {"|  OPTION     _ ___      __     __      ___  __  |\n"}, 
                                                {"|  |_)  /_\\  |   |  |   |__    (__ |__|  |  |__) |\n"},
                                                {"|  |_) /   \\ |   |  |__ |__     __)|  | _|_ |    |\n"},
 												{"|                                       ComPrompt|\n"},
                                                {" -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+\n"}
    };
	printf("%s\n",home[0] ); 
	printf(" > Input player 1 Name: \n");
	gets(game_player[0]);
	printf(" > Input player 2 Name: \n");
	gets(game_player[1]);
	printf("!! Change player name success !! \n Player1 :  %s\n Player2 : %s\n",game_player[0],game_player[1] );
	printf("\nPress Any Key to Back\n");


}
//end pame code
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
			if(display[m][j]== '#')
			{
				color(gray,gray);
			}
			
			printf("%c",display[m][j]);
			reset();
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
		//leaderboard();
		//Print Leaderboard
		// system("mode con:cols=79 lines=30");
		system("cls"); //clear display
		cleardis();
		home_leader();
		//printdis();
		//end Print Leaderboard
		char in = getch(); //input
		startinterface();
		gotomenu(selectmenu());
	}
	else if(select == 2)
	{
		system("cls"); //clear display
		cleardis();
		home_option();
		char in = getch(); //input
		startinterface();
		gotomenu(selectmenu());
	}
	if(select == 3)
	{
		exit(0);
	}
}

void gameplay()
{
	char field1[23][74],field2[23][74],in,fieldp1[23][74],fieldp2[23][74];
	int score1=0,score2=0,time1,x=2,y=5,p1=1,p2=1,sizeship=6,countship=0,playerround=0,countshoot=0;
	
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

		void showscore()
		{
			char 	player1[3][21] = {		{"                     "},
											{"   Player1: 0 Point  "},
											{"                     "}
					},

					player2[3][21] = {		{"                     "},
											{"   Player2: 0 Point  "},
											{"                     "}
					};
			int m,j;
			for(m=0;m<3;m++)
			{	
				for(j=0;j<21;j++)
				{
					display[1+m][3+j] = player1[m][j];
					display[1+m][54+j] = player2[m][j];
				}
			}
		}

		void showheader()
		{
			char p1round[3][26] = { 		{"                          "},
											{"       Player1 Round 1    "},
											{"                          "}},
				 p2round[3][26] = { 		{"                          "},
											{"       Player2 Round 1    "},
											{"                          "}};
			int m,j;
			for(m=0;m<3;m++)
			{	
				for(j=0;j<26;j++)
				{
						display[1+m][26+j] = (playerround%2 == 0) ? p1round[m][j]:p2round[m][j];

				}
			}
		}

		frame();
		showscore();
		showheader();
	}

	void clearfield()
	{
		int m,j;
		for(m=0;m<23;m++)
		{	
			for(j=0;j<74;j++)
			{
				field1[m][j] = ' ';
				fieldp1[m][j] = ' ';
				fieldp2[m][j] = ' ';
			}
		}
	}

	void addpointer()
	{
		char pointer[3][3] = {	{"+-+"},
								{"IOI"},
								{"+-+"}};
		int m,j;
		for(m=0;m<3;m++)
		{	
			for(j=0;j<3;j++)
			{
				display[y+m][x+j] = pointer[m][j];
			}
		}
	}

	void addfield()
	{
		int m,j;
		for(m=0;m<23;m++)
		{	
			for(j=0;j<74;j++)
			{
				display[5+m][2+j] = (playerround%2 == 0) ? field1[m][j]:field2[m][j];
			}
		}
	}

	void movepointer()
	{
		if(in == 'w' || in == 'W')
		{
			y-=1;
			y = (y<5) ? y+1:y;
		}
		else if(in == 's' || in == 'S')
		{
			y+=1;
			y = (y>25) ? y-1:y;
		}
		else if(in == 'a' || in == 'A')
		{
			x-=1;
			x = (x<2) ? x+1:x;
		}
		else if(in == 'd' || in == 'D')
		{
			x+=1;
			x = (x>73) ? x-1:x;
		}
	}

	void deployship()
	{
		void addship()
		{
			char 	small2[3][6] = {{"/----\\"}, //36
									{"<====>"},
									{"\\----/"}},
					mid2[3][9]	= {	{"/-------\\"}, //54
									{"<=======>"},
									{"\\-------/"}},
					big2[3][12]	= {	{"/----------\\"},//72
									{"<==========>"},
									{"\\----------/"}};
			int m,j;
			x = (in == ' ' && x >= 67) ? x-3:x;
			sizeship = (in == ' '&& countship%2 == 0) ? (sizeship < 12) ? sizeship+3:sizeship:sizeship;
			for(m=0;m<3;m++)
			{	
				for(j=0;j<sizeship;j++)
				{
					display[y+m][x+j] = (sizeship==6) ? small2[m][j]:(sizeship==9) ? mid2[m][j]:big2[m][j];
				}
			}
		}

		void moveship()
		{
			if(in == 'w' || in == 'W')
			{
				y-=1;
				y = (y<5) ? y+1:y;
			}
			else if(in == 's' || in == 'S')
			{
				y+=1;
				y = (y>25) ? y-1:y;
			}
			else if(in == 'a' || in == 'A')
			{
				x-=1;
				x = (x<2) ? x+1:x;
			}
			else if(in == 'd' || in == 'D')
			{
				x+=1;
				x = (x>76-sizeship) ? x-1:x;
			}
		}
		void saveship()
		{
			char 	small1[3][6] = {{"@@@@@@"},
									{"@@@@@@"},
									{"@@@@@@"}},
					mid1[3][9]	= {	{"@@@@@@@@@"},
									{"@@@@@@@@@"},
									{"@@@@@@@@@"}},
					big1[3][12]	= {	{"@@@@@@@@@@@@"},
									{"@@@@@@@@@@@@"},
									{"@@@@@@@@@@@@"}};
			int m,j;

			if(in == ' ')
			{
				for(m=0;m<3;m++)
				{	
					for(j=0;j<sizeship;j++)
					{		
						if(playerround%2 == 0)
						{
							fieldp1[y+m-5][x+j-2] = (sizeship==6) ? small1[m][j]:(sizeship==9) ? mid1[m][j]:big1[m][j];
						}
						else
						{
							fieldp2[y+m-5][x+j-2] = (sizeship==6) ? small1[m][j]:(sizeship==9) ? mid1[m][j]:big1[m][j];
						}
					}
				}
				x = 2;
				y = 5;
				countship +=1;
			}
		}

		void addfieldplayer()
		{
			int m,j;
			for(m=0;m<23;m++)
			{	
				for(j=0;j<74;j++)
				{
					
					display[5+m][2+j] = (playerround%2 == 0) ? fieldp1[m][j]:fieldp2[m][j];
				}
			}
		}

		while(1)
		{
			system("cls");
			gameplayinterface();
			addfieldplayer();
			addship();
			printdis();
			in = getch();
			saveship();
			moveship();
			if(countship == 6 && playerround == 1 )
			{
				playerround += 1;
				break;
			}
			if(countship == 6)
			{
				playerround += 1;
				sizeship = 3;
				countship = 0;
			} 
		}
	}

	void checkship()
	{
		int m,j;
		if(in == ' ')
		{
			countshoot++;
			playerround += 1;
			for(m=0;m<3;m++)
			{	
				for(j=0;j<3;j++)
				{
					if(playerround%2 == 0)
					{
						if(fieldp1[y+m-5][x+j-2] == '@')
						{
							field2[y+m-5][x+j-2] = '*';
							score2++;
						}
					}
					else
					{
						if(fieldp2[y+m-5][x+j-2] == '@')
						{
							field1[y+m-5][x+j-2] = '*';
							score1++;
						}
					}
				}
			}
		}
	}

	void addscore()
	{
		char sc[10];
		if(score1<=9)
		{
			itoa(score1,sc,10);
			display[2][15] = sc[0];
		}
		else
		{
			itoa((score1%10),sc,10);
			display[2][15] = sc[0];
			itoa((score1/10),sc,10);
			display[2][14] = sc[0];
		}
		if(score2<=9)
		{
			itoa(score2,sc,10);
			display[2][66] = sc[0];
		}
		else
		{
			itoa((score2%10),sc,10);
			display[2][66] = sc[0];
			itoa((score2/10),sc,10);
			display[2][65] = sc[0];
		}
	}

	void draw()
	{
		startinterface();
		gotomenu(selectmenu());
	}

	void checkwinner() 
	{
		if(score1>score2)
		{
			winner = 0;
			scorewinner=score1;
		}
		else if(score2>score1)
		{
			winner = 1;
			scorewinner = score2;
		}
		else
		{
			draw();
		}
	}

	system("cls");
	cleardis();
	gameplayinterface();
	clearfield();
	printdis();
	deployship();
	while(1)
	{
		system("cls");
		gameplayinterface();
		addfield();
		addpointer();
		addscore();
		printdis();
		printf("%d %d",score1,score2);
		in = getch();
		checkship();
		movepointer();
		if(countshoot>=50)
		{
			checkwinner();
			break;
		}
		
	}
}
// What Work Who Work
// Bank eer	>> Interface & map
// Guide 	>> Game control > Interface > score > pointer move & check 
// Prame 	>> Ranking 
// Yok 		>> Interface move & color 

//
void saveScore(char playerName[100] , int playerScore,int swt)
{
	//use to save score file
	FILE *f = fopen("score.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening score file!\n");
	    exit(1);
	}
	fprintf(f, "%s,%d\n", playerName,playerScore);
	if(swt==0)
	{
		fprintf(f, "%s,%d,%s,%d,%s,%d\n", playerName,playerScore,UserRank[1],scoreRank[1],UserRank[2],scoreRank[2]);
	}
	else if(swt==1)
	{
		fprintf(f, "%s,%d,%s,%d,%s,%d\n", UserRank[0],scoreRank[0],playerName,playerScore,UserRank[2],scoreRank[2]);
	}
	else if(swt==2)
	{
		fprintf(f, "%s,%d,%s,%d,%s,%d\n", UserRank[0],scoreRank[0],UserRank[1],scoreRank[1],playerName,playerScore);
	}
	fclose(f);
}
void readScore()
{
	//use to read score file
   char ch, file_name[25],stringlong[10000];
   int i = 0;
   FILE *fp;
   fp = fopen("score.txt","r");      // opening file in read mode
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   while( ( ch = fgetc(fp) ) != EOF )        //   reading file..
	 { 
	 	stringlong[i] = ch;
	 	i++;
	 }
	 stringlong[i] = '\0';
   fclose(fp);
   //end read file
   //Start fetch file to array
   int i2 = 0,i3=0,i5=0;
   char temp_name[100];
   char temp_score[100];
   int sw = 0;
   for (i2 = 0; i2 <= i; ++i2)
   {
   	if(sw==0)
   	{
   		if(stringlong[i2]==',')
   		{
   			sw = 1 ;
   			int i4 = 0;
   			while(i4<i5)
   			{
   				UserRank[i3][i4] = temp_name[i4];
   				i4++;
   			}
   			UserRank[i3][i4] = '\0';
   			i5 = 0;
   			//printf("%s ",UserRank[i3] );
   		}
   		else
   		{
   			temp_name[i5] = stringlong[i2];
   			i5++;
   		}
   	}
   	else
   	{
   		if(stringlong[i2]==',')
   		{
   			sw = 0 ;
   			temp_score[i5] = '\0';
   			scoreRank[i3][0] = atoi(temp_score);
   			//printf("%d\n",scoreRank[i3][0]);
   			i5 = 0;
   			i3++;
   		}
   		else
   		{
   			temp_score[i5] = stringlong[i2];
   			i5++;
   			if(i2==i-1)
   			{
   				sw = 0 ;
	   			temp_score[i5] = '\0';
	   			scoreRank[i3][0] = atoi(temp_score);
	   			//printf("%d\n",scoreRank[i3][0]);
	   			i5 = 0;
	   			i3++;
   			}
   		}
   	}

   }
   sortRank();
   //End fetch
}
void sortRank()
{
	//use to sort rank
	if (scoreRank[0][0] >=scoreRank[1][0] && scoreRank[1][0] >= scoreRank[2][0])
	{
		first = 0;
		second =1;
		third =2;
	}
	else if(scoreRank[2][0] >=scoreRank[1][0] && scoreRank[1][0] >= scoreRank[0][0])
	{
		first = 2;
		second =1;
		third =0;
	}
	else if(scoreRank[1][0] >=scoreRank[0][0] && scoreRank[0][0] >= scoreRank[2][0])
	{
		first = 1;
		second =0;
		third =2;
	}	
	else if(scoreRank[2][0] >=scoreRank[0][0] && scoreRank[0][0] >= scoreRank[1][0])
	{
		first = 2;
		second =0;
		third =1;
	}
	else if(scoreRank[1][0] >=scoreRank[2][0] && scoreRank[2][0] >= scoreRank[0][0])
	{
		first = 1;
		second =2;
		third =0;
	}
	else if(scoreRank[0][0] >=scoreRank[2][0] && scoreRank[2][0] >= scoreRank[1][0])
	{
		first = 0;
		second =2;
		third =1;
	}
}
//use this
void checkSaveRank(char playerName2[100] ,int nowscore2)
{
	//checkSaveRank <-- PlayerName , Player Score
	//use to check for save
	int i9 = 0;
	if(scoreRank[first][0]<= nowscore2)
	{
		saveScore(&playerName2[100],nowscore2,i9);
	}
	else if(scoreRank[second][0]<= nowscore2)
	{
		i9=1;
		saveScore(&playerName2[100],nowscore2,i9);
	}
	else if(scoreRank[third][0]<= nowscore2)
	{
		i9=2;
		saveScore(&playerName2[100],nowscore2,i9);
	}
}