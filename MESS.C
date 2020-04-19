#include<stdio.h>
#include<string.h>  //for string manipulation
#include<stdlib.h>  

struct mess
{
	int b_time;
	int s_id;
	int w_time;
	int ta_time;
};


void getdata(struct mess list[50],int p)    // taking data from the user.
{
	int j;
	for(j=0; j<p; j++)                    // Taking data for each ID.
	{
		printf("Enter for Proccess %d",j+1);
		
		printf("\nEnter the proccess/Student Id :");  // taking Proccess ID.
		scanf("%d",&list[j].s_id);
		
		
		printf("\nEnter the Burst_Time: ");   // Taking Burst Time. 
		scanf("%d", &list[j].b_time);
		if(list[j].b_time<0)
		{
			printf("Enter burst time should be positive");
			exit(0);
		}
		
	}
}
