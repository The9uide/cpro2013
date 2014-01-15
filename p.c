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
void saveScore(char playerName[100] , int playerScore);
void readScore();
char UserRank[3][100];
int scoreRank[3][1];

int main() //main
{
	startinterface();
	gotomenu(selectmenu());
	//readScore();
}

void startinterface() //first page
{
	int column_slide,m,i,j,count;
	system("mode con:cols=79 lines=30");
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
	char field1[23][74],in;
	int score1=5,time1,x=2,y=5;
	
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
											{"                     "}}
					,player2[3][21] = {		{"                     "},
											{"   Player2: 0 Point  "},
											{"                     "}};
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
			char 	p1round[3][26] = { 		{"                          "},
											{"       Player1 Round      "},
											{"                          "}};
			int m,j;
			for(m=0;m<3;m++)
			{	
				for(j=0;j<26;j++)
				{
					display[1+m][26+j] = p1round[m][j];
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
				display[5+m][2+j] = field1[m][j];
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

	system("cls");
	cleardis();
	gameplayinterface();
	clearfield();
	printdis();
	while(1)
	{
		system("cls");
		addfield();
		addpointer();
		printdis();
		in = getch();
		movepointer();
	}
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

// What Work Who Work
// Bank eer	>> Interface & map
// Guide 	>> Game control > Interface > score > pointer move & check 
// Prame 	>> Ranking 
// Yok 		>> Interface move & color 

//
void saveScore(char playerName[100] , int playerScore)
{
	//use to save score file
	FILE *f = fopen("score.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening score file!\n");
	    exit(1);
	}
	fprintf(f, "%s,%d\n", playerName,playerScore);
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
   			printf("%s ",UserRank[i3] );
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
   			printf("%d\n",scoreRank[i3][0]);
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
	   			printf("%d\n",scoreRank[i3][0]);
	   			i5 = 0;
	   			i3++;
   			}
   		}
   	}

   }
   //End fetch
}