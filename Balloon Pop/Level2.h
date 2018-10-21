void timer()
{
	if(screen==3)
	{
		t--;    //time decreasing
	}
}
void processLvl2()
{
	t=50;
	level=2;
	paused=0;
	number=0;

	//for Joy(red) balloons
	for(i=0;i<100;i++)
	{
		balloon_f[i]=0;
		balloon_x[i]=rand()%900; //rand returns an int from 0 to 2^16-1
		change[i]=rand()%10+5;   // this rand returns an int from 10 to 14
		balloon_y[i]=-50;
	}

	//for Fear(black) balloons
	neg_f=0;
	neg_x=rand()%900;       //[ScreenWidth - BalloonWidth =1000-100 =900]
	negTime=rand()%5+10;    // this rand returns an int from 5 to 14
	neg_y=-50;

	//for Surprise(smiley) balloons
	smily_f=0;
	smily_x=rand()%920;     //[ScreenWidth - BalloonWidth =1000-80 =920]
	smilyTime=rand()%5+20;  // this rand returns an int from 5 to 24
	smily_y=-50;

	//for Hope(slow) balloons
	slow_f=0;
	slow_x=rand()%910;      //[ScreenWidth - BalloonWidth =1000-80 =920]
	slowTime=rand()%25+20;  // this rand returns an int from 25 to 44
	slow_y=-50;

    //for Death(orange)balloons
	death_f=0;
	death_x=rand()%850;      //[ScreenWidth - BalloonWidth =1000-140 =860]
	deathTime=rand()%25+20;  // this rand returns an int from 25 to 44
	death_y=-50;
}

void lvl2()
{
	iShowImage(0,0,1000,800,sky2);

	iSetColor(0,0,0);
	iText(450,750,"LEVEL-2",GLUT_BITMAP_TIMES_ROMAN_24);   //showing level no on screen

	sprintf_s(sc,"Score: %d",score);         //showing score updates on screen
	iSetColor(0,0,0);
	iText(800,750,sc,GLUT_BITMAP_HELVETICA_18);

	sprintf(tm,"Timer: %d sec",t);          //showing timer countdown on screen
	iSetColor(0,0,0);
	iText(100,750,tm,GLUT_BITMAP_HELVETICA_18);

	//for Joy(red) balloons
	for(i=0;i<100;i++)
	{
		if(balloon_f[i]==1)
			iShowImage(balloon_x[i],balloon_y[i],100,110,balloonRed);

	    //poping Joy(red) balloons
		if(balloon_f[i]==0 && balloon_y[i]>=0 && balloon_y[i]<=800)
		{
			iShowImage(balloon_x[i],balloon_y[i],60,90,popRed);
			c[i]++;
			if(c[i]>=100)
			{
				c[i]=0;
				balloon_y[i]=-50;
			}
		}
	}
	
	//for Fear(black) balloons
	if(neg_f==1)
		iShowImage(neg_x,neg_y,100,110,balloonNeg);

	//for Surprise(smiley) balloons
	if(smily_f==1)
		iShowImage(smily_x,smily_y,80,200,balloonSmily);
	else if(smily_y>=0 && smily_y<=800)
	{
		iShowImage(smily_x,smily_y,60,90,popRed);
		cSp++;
		if(cSp>=7)   
		{
			cSp=0;
			smily_y=-50;
		}
	}

	//for Hope(slow) balloons
	if(slow_f==1)
		iShowImage(slow_x,slow_y,80,110,balloonSlow);

	//for Death(orange) balloons
	if(death_f==1)
		iShowImage(death_x,death_y,140,150,balloonDeath);

	//poping pointer image
	iShowImage(x,y,30,30,pointer);

	//for pause menu-Resume/Restart
	if(paused%2==0)
	{
		iResumeTimer(t1);
		iResumeTimer(t2);
		iResumeTimer(t3);
	}
	else
	{
		screen=4;
		iPauseTimer(t1);
		iPauseTimer(t2);
		iPauseTimer(t3);
	}
	//showing screen-GAME OVER or WIN for level2
	if(screen==3 && number>=99)
	{
		if(score<=1000)
		   screen=5;     //GAME OVER
	   else
		  screen=7;     //GAME WIN 
	}
}
