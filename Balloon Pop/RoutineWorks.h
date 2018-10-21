//LOGO page screen
void logo(){
	iShowImage(0,0,1000,800,logoPic);
}

//STORYLINE page screen
void storyline()
{
	iShowImage(0,0,1000,800,storyLine);
}

//PAUSE MENU page screen
struct buttonCordinate
{
    int x;
    int y;
}bCordinate[3];
void pausemenu()
{
	iShowImage(0,0,1000,800,pauseMenu);
	
	for(i=0;i<3;i++)
	{
		iShowImage(bCordinate[i].x,bCordinate[i].y,400,100,pauseButton[i]);
	}
}

//for background music
void music()
{
	if(musicOn)
	{
		PlaySound("Music\\Background.wav",NULL,SND_LOOP|SND_ASYNC);
	}
}
