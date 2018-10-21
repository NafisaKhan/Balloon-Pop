void processLvl1()
{
	//Reading  previous saved HIGH SCORE from file(fp1)
	fp1=fopen("highscore.txt","r");
	fscanf(fp1,"%d\n",&highScore);
	fclose(fp1);
	score=0;
	level=1;
	paused=0;
	number=0;

	//for Joy(red) balloons
	for(i=0;i<100;i++)
	{
		balloon_f[i]=0;
		balloon_x[i]=rand()%900;   //rand returns an int from 0 to 2^16-1
		change[i]=rand()%10+5;     // this rand returns an int from 10 to 14
		balloon_y[i]=-50;
	}

	//for Fear(black) balloons
	neg_f=0;
	neg_x=rand()%900;       //[ScreenWidth - BalloonWidth =1000-100 =900]
	negTime=rand()%5+10;    // this rand returns an int from 5 to 14
	neg_y=-50;

}

void lvl1()
{
	iShowImage(0,0,1000,800,sky1);

	iSetColor(0,0,0);
	iText(450,750,"LEVEL-1",GLUT_BITMAP_TIMES_ROMAN_24);    //showing level no on screen

	sprintf_s(sc,"Score: %d",score);             //showing score updates on screen
	iSetColor(0,0,0);
	iText(800,750,sc,GLUT_BITMAP_HELVETICA_18);

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

	//poping pointer image
	iShowImage(x,y,30,30,pointer);

	//for pause menu-Resume/Restart
	if(paused%2==0)
	{
		iResumeTimer(t1);
		iResumeTimer(t2);
	}
	else
	{
		screen=4;
		iPauseTimer(t1);
		iPauseTimer(t2);
	}

	//showing screen-GAME OVER or WIN for level1
	if(screen==2 && number>=99 && balloon_f[95]==0 && balloon_f[96]==0 && balloon_f[97]==0 && balloon_f[98]==0 && balloon_f[99]==0)
	{
		if(score<=500)
			screen=5;   //GAME OVER
		else
			screen=6;   //GAME WIN
	}
}