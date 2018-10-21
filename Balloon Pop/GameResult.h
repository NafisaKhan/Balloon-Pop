//gameover screen
void gameover()
{
	iShowImage(0,0,1000,800,gameOver);

	//Writing YOUR SCORE in file(fp)
	fp=fopen("score.txt","w");
	fprintf(fp,"%d\n",score);
	fclose(fp);

	sprintf_s(sc,"Your Score: %d",score);     //YOUR SCORE is shown on the screen
	iSetColor(255,255,255);
	iText(475,370,sc,GLUT_BITMAP_HELVETICA_18);

	//Writing HIGH SCORE from file(fp1)
    if(highScore<score)
	    {
		    highScore=score;
		    fp1=fopen("highscore.txt","w");
			fprintf(fp1,"%d\n",highScore);
			fclose(fp1);
		}
	
	sprintf(hsc,"High Score: %d",highScore);  //HIGH SCORE is shown on screen
	iSetColor(255,255,255);
	iText(475,340,hsc,GLUT_BITMAP_HELVETICA_18);
}

//win screen for level1 
void winLvl1()
{
	iShowImage(0,0,1000,800,win1);
}

//win screen for level2 
void winLvl2()
{
	iShowImage(0,0,1000,800,win2);

	//Writing YOUR SCORE in file(fp)
	fp=fopen("score.txt","w");
	fprintf(fp,"%d\n",score);
	fclose(fp);

	sprintf_s(sc,"Your Score: %d",score);     //YOUR SCORE is shown on the screen
	iSetColor(178,34,34);
	iText(370,320,sc,GLUT_BITMAP_HELVETICA_18);
    
	//Writing HIGH SCORE from file(fp1)
    if(highScore<score)
	    {
		    highScore=score;
		    fp1=fopen("highscore.txt","w");
			fprintf(fp1,"%d\n",highScore);
			fclose(fp1);
		}
	
	sprintf(hsc,"High Score: %d",highScore);  //HIGH SCORE is shown on screen
	iSetColor(178,34,34);
	iText(370,290,hsc,GLUT_BITMAP_HELVETICA_18);
}