 //headerfiles
#include "iGraphics.h"
#include "Variables.h"
#include "RoutineWorks.h"
#include "HomeMenu.h"
#include "Balloons.h"
#include "Level1.h"
#include "Level2.h"
#include "GameResult.h"
#include "HighScore.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	if(screen==-1) logo();
	else if(screen==0) storyline();
	else if(screen==1) mainmenu();
	else if(screen==2) lvl1();
    else if(screen==3) lvl2();
    else if(screen==4) pausemenu();
	else if(screen==5) gameover();
	else if(screen==6) winLvl1();
    else if(screen==7) winLvl2();
	else if(screen==8) instruct();
	else if(screen==9) highscore();
	else if(screen==10) credits();
	else if(screen==11) exit();
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx,int my)
{

}

void iPassiveMouseMove(int mx,int my)
{
	x=mx;
	y=my;
}

void iMouse(int button,int state,int mx,int my)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(screen==-1 && mx>=0 && mx<=1000 && my>=0 && my<=800)      //LOGO page
		{	
			screen=0;                                               
		}

		else if(screen==0 && mx>=0 && mx<=1000 && my>=0 && my<=800)      //STORYLINE page
		{	
			screen=1;                                               
		}

		else if(screen==1)  //inside menu page options
		{
			if(mx>=631 && mx<=780 && my>=580 && my<=655)   //menu page PLAY click for LEVEL1
			{	
				processLvl1();
			    screen=2;
			}
			if(mx>=632 && mx<=793 && my>=471 && my<=549)   //menu page INSTRUCTION click
		    {	
				screen=8;
			}
			if(mx>=638 && mx<=795 && my>=364 && my<=444)   //menu page HIGHSCORE click
			{
				screen=9;
			}
			if(mx>=637 && mx<=796 && my>=260 && my<=340)   //menu page CREDITS click
			{
				screen=10;
			}
			if(mx>=632 && mx<=801 && my>=149 && my<=230)   //menu page EXIT click
			{
				screen=11;
			}
		}

		else if(screen==4) //inside pause menu options
		{
			if(mx>=300 && mx<=700 && my>=500 && my<=600)  //PAUSE menu RESUME click
			{
				paused++;
				if(level==1)
					screen=2;
				else if(level==2)
					screen=3;
			}
			if(mx>=300 && mx<=700 && my>=350 && my<=450)  //PAUSE menu RESTART click
			{
				if(level==1 || level==2)
				{
					processLvl1();
				    screen=2;
			    }
			}
			if(mx>=300 && mx<=700 && my>=200 && my<=300)  //PAUSE menu MAIN MENU click
			{
				screen=1;
			}
		}

		else if(screen==5) //inside GAMEOVER page options
		{
			if(mx>=232 && mx<=492 && my>=228 && my<=299)  //GAMEOVER page PLAY AGAIN click
			{
				processLvl1();
				screen=2;
			}
			if(mx>=232 && mx<=495 && my>=126 && my<=197)  //GAMEOVER page MAIN MENU click
			{
				screen=1;
			}
		}

		else if(screen==6) //inside WIN LEVEL1 page options
		{
			if(mx>=701 && mx<=930 && my>=237 && my<=302)  //WIN LEVEL1 page CONTINUE click for LEVEL2
			{
				processLvl2();
				screen=3;
			}
		}

		else if(screen==7) //inside WIN LEVEL2 page options
		{
			if(mx>=508 && mx<=723 && my>=188 && my<=247)  //WIN LEVEL2 page PLAY AGAIN click
			{
				processLvl1();
				screen=2;
			}
			if(mx>=511 && mx<=723 && my>=101 && my<=160)  //WIN LEVEL2 page EXIT click
			{
				screen=11;
			}
		}

		else if(screen==8 && mx>=37 && mx<=145 && my>=53 && my<=136)    //INSTRUCTION page BACK click
		{
			screen=1;
		}
		else if(screen==9 && mx>=41 && mx<=149 && my>=54 && my<=137)    //HIGHSCORE page BACK click
		{
			screen=1;
		}
		else if(screen==10 && mx>=45 && mx<=153 && my>=54 && my<=137)    //CREDITS page BACK click
		{
			screen=1;
		}
		
		else if(screen==11)    //inside EXIT page options
		{
			if(mx>=310 && mx<=484 && my>=354 && my<=401)  //EXIT page YES click
			{
				exit(0);
		    }
			if(mx>=569 && mx<=736 && my>=356 && my<=402)  //EXIT page NO click
			{
			screen=1;
			}
		}

	  //balloons hitting 
		if(screen==2||screen==3) 
		{
		  //Joy(red) balloons hit in level1 & level2
			for(i=0;i<100;i++)
			{
				if(paused%2==0 && balloon_f[i]==1 && mx>=balloon_x[i] && mx<=balloon_x[i]+100 && my>=balloon_y[i] && my<=balloon_y[i]+110)
				{
					balloon_f[i]=0; 
					score+=7;       //poping each Joy(red) balloon will add 7 points in score
				}
			}

		  //Fear(black) balloons hit in level1 & level2
			if(paused%2==0 && neg_f==1 && mx>=neg_x && mx<=neg_x+100 && my>=neg_y && my<=neg_y+110) 
			{
				neg_f=0;
				neg_y=-50;
				score-=3;      //poping a Fear(black) balloon will deduct 3 points from score
			}
		}

		if(screen==3)
		{
			//Surprise(smily) balloons hit in level2
			if(paused%2==0 && smily_f==1 && mx>=smily_x && mx<=smily_x+80 && my>=smily_y && my<=smily_y+200)
			{
				smily_f=0;
				for(i=0;i<100;i++)
				{
					if(balloon_f[i]==1)
					{
						balloon_f[i]=0;
						score+=7;      //poping a Surprise(smily) balloon will add 7 points for every single Joy(red) balloon that was in the screen that time
					}
				}
				balloon_f[number]=1;
				number++;
			 }

			//Hope(slow) balloons hit in level2
			if(paused%2==0 && slow_f==1 && mx>=slow_x && mx<=slow_x+80 && my>=slow_y && my<=slow_y+110)
			{
				slow_f=0;
				slow_y=-50;
				slow=5;
			}
			//Death(orange) balloons hit in level2
			if(paused%2==0 && death_f==1 && mx>=death_x && mx<=death_x+140 && my>=death_y && my<=death_y+150)
			{
				death_f=0;
				death_y=-50;
				screen=5;     //showing screen-GAME OVER for level2 
			}
		}
	}
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key==32) //press Spacebar(ascii code-32) for showing pause menu
	{
		paused++;
		if(paused%2==0)
		{
			if(level==1)
				screen=2;
			else if(level==2)
				screen=3;
		}
	}

	else if(key==27)    
	{
		screen=11;      //press Esc(ascii code-27) for exiting the game anytime
	}

	else if(key==13)    
	{
		if(screen==-1)
			screen=0;        //press Enter(ascii code-13) for entering to storyline page from logo page
		else if(screen==0)
			screen=1;        //press Enter(ascii code-13) for entering to the menu page from storyline page
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key==GLUT_KEY_RIGHT)
	{
	
	}
	if(key==GLUT_KEY_LEFT)
	{	

	}
	if(key==GLUT_KEY_END)
	{
		if(musicOn)
		{
			musicOn=false;    //press END to OFF  background music if music is ON
		    PlaySound(0,0,0);
		}
		else
		{
			musicOn=true;
			PlaySound("Music\\Background.wav",NULL,SND_LOOP|SND_ASYNC);  //press END to ON background music if music is OFF
		}
	}
	if(key==GLUT_KEY_HOME)
	{
	    screen=1;       //for coming to menu page from any stage of the game
	}
}

int main()
{
	srand(time(NULL));
	iInitialize(screenWidth,screenHeight,"BALLOON  POP");
	t1=iSetTimer(20,balloonUP);
	t2=iSetTimer(500,balloonCreate);
	t3=iSetTimer(1000,timer);

	//image loading fuction
    imageLoading();

	//for background music
	music();

	//pausemenu button placement 
	int sum=200;
	for(i=0;i<=2;i++)
	{
		bCordinate[i].x=300;
		bCordinate[i].y=sum;
		sum+=150;
	}

	iStart();
	return 0;
}