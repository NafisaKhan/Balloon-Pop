//for creating different balloons
void balloonCreate()
{
	if(screen==2||screen==3)
	{
	    //for Joy(red) balloons
	    balloon_f[number]=1;
		if(number<99)
			number++; 

		//for Fear(black) balloons
		if(number%negTime==0 && number<99)
			neg_f=1;
	}

	//other special balloons create for level2
	if(screen==3)
	{
		//for Surprise(smiley) balloons
		if(number%smilyTime==0 && number<99)
			smily_f=1;
		
		//for Hope(slow) balloons 
		if(number%slowTime==0 && number<99)
			slow_f=1;
		if(slow>0)
		{
			count++;
			if(count==14)
			{
				slow=0;
				count=0;
			}
		}

		//for Death(orange) balloons
		if(number%deathTime==0 && number<99)
			death_f=1;
	}
}

//for sending balloons upwards
void balloonUP()
{
	//red and black balloon up for level1 & level2
	if(screen==2||screen==3)
	{
		//for Joy(red) balloons
		for(i=0;i<=99;i++)
		{
			if(balloon_f[i]==1)
			{
				balloon_y[i]+=change[i]-slow;
				if(balloon_y[i]>=800)
				{
					balloon_f[i]=0;
				    balloon_y[i]=-50;
				}
			}
		}
		
		//for Fear(black) balloons
		if(neg_f==1)
		{
			neg_y+=negSpd;
			if(neg_y>=800)
			{
				neg_f=0;
				neg_y=-50;
			}
		}
	}

	//other special balloons up for level2
	if(screen==3)
	{
		//for Surprise(smiley) balloons
		if(smily_f==1)
		{
			smily_y+=smilySpd;
			if(smily_y>=800)
			{
				smily_f=0;
				smily_y=-50;
			}
		}
	
		//for Hope(slow) balloons 
		if(slow_f==1)
		{
			slow_y+=slowSpd;
			if(slow_y>=800)
			{
				slow_f=0;
				slow_y=-50;
			}
		}

		//for Death(orange) balloons
		if(death_f==1)
		{
			death_y+=deathSpd;
			if(death_y>=800)
			{
				death_f=0;
				death_y=-50;
			}
		}
	}
}