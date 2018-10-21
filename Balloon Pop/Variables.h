//initialization variables
int screenWidth=1000,screenHeight=800;
int i,number=0,x,y;

//main menu image variables
int logoPic,storyLine,menu,instruction,hscore,credit,exitPic,pauseMenu;

//play game image variables
int sky1,sky2,balloonRed,balloonNeg,balloonSmily,balloonSlow,balloonDeath,popRed,pointer,gameOver,win1,win2;

//screen change variable
int screen=-1;

//time change variables
int t1,t2,t3,t;
char tm[100];

//for Joy(red) balloons
int balloon_x[100],balloon_y[100],balloon_f[100],change[100],c[100];

//for Fear(black) balloons
int neg_x,neg_y,neg_f,negTime,negSpd=10;

//for Surprise(smiley) balloons
int smily_x,smily_y,smily_f,smilyTime,smilySpd=15;

//for Hope(slow) balloons 
int slow_x,slow_y,slow_f,slowTime,slowSpd=13,cSp,count,slow;

//for Death(orange) balloons
int death_x,death_y,death_f,deathTime,deathSpd=9;

//pause menu related variables
int paused,level;
int pauseButton[3];

//scoring related variables 
int score=0,highScore;
char sc[100],hsc[100];

// for declaration of flies 
FILE*fp;   //to save score
FILE*fp1;  //to save high score

//music variables
bool musicOn=true;

//all image loading variables
void imageLoading()
{
	//menu page images loading 
	logoPic=iLoadImage("Image\\logoPic.png");
	storyLine=iLoadImage("Image\\storyLine.png");
    menu=iLoadImage("Image\\menu.png");
    instruction=iLoadImage("Image\\instruction.png");
	hscore=iLoadImage("Image\\hscore.png");
	credit=iLoadImage("Image\\credit.png");
	exitPic=iLoadImage("Image\\exitPic.png");
	pauseMenu=iLoadImage("Image\\pause.png");
	//play game images loading 
	sky1=iLoadImage("Image\\sky1.png");
	sky2=iLoadImage("Image\\sky2.png");
	pointer=iLoadImage("Image\\pointer.png");
	popRed=iLoadImage("Image\\popRed.png");
	//balloon images loading 
	balloonRed=iLoadImage("Image\\balloonRed.png");
    balloonNeg=iLoadImage("Image\\balloonNeg.png");
	balloonSmily=iLoadImage("Image\\balloonSmily.png");
	balloonSlow=iLoadImage("Image\\balloonSlow.png");
	balloonDeath=iLoadImage("Image\\balloonDeath.png");
	//game result images loading 
	gameOver=iLoadImage("Image\\gameOver.png");
	win1=iLoadImage("Image\\win1.png");
	win2=iLoadImage("Image\\win2.png");
	//pause buttons images loading 
	pauseButton[0]=iLoadImage("Image\\menuButton.png");
    pauseButton[1]=iLoadImage("Image\\restartButton.png");
    pauseButton[2]=iLoadImage("Image\\resumeButton.png");
}

/*info:::::
for red balloons   -(width:100,higth:110)
for black balloons -(width:100,higth:110)
for smily balloons -(width:80,higth:200)
for slow balloons  -(width:80,higth:110)
for death balloons -(width:140,higth:150)
*/