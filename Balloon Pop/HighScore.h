void highscore(){
	iShowImage(0,0,1000,800,hscore);

	 //Reading YOUR SCORE from file(fp)
	fp=fopen("score.txt","r");
	fscanf(fp,"%d\n",&score);
	fclose(fp);

	sprintf(sc,"Your Score: %d",score);    //YOUR SCORE is shown on the screen
	iSetColor(0,0,0);
	iText(450,470,sc,GLUT_BITMAP_TIMES_ROMAN_24);

	 //Reading HIGH SCORE from file(fp1)
	if(highScore<score)
	{
		highScore=score;
        fp1=fopen("highscore.txt","r");
	    fscanf(fp1,"%d\n",&highScore);
	    fclose(fp1);
	}

	sprintf(hsc,"High Score: %d",highScore);  //HIGH SCORE is shown on screen
	iSetColor(0,0,0);
	iText(450,420,hsc,GLUT_BITMAP_TIMES_ROMAN_24);
}