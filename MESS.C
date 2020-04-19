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
void allocation(struct mess list[50],int p)      //allocation of proccesss.
{
	int j,k;
	struct mess q;
	for (j=0; j<p-1;j++)
    {
        for (k=0; k<(p-1-j); k++)
        {
        	 if (list[k].b_time < list[k+1].b_time)     // if burst time first is less than next proccess.
            {
                q = list[k];
                list[k] = list[k+1];
                list[k+1] = q;
            } 
            else if(list[k].b_time== list[k+1].b_time)  // if both proccess have same burst time then allocation depend on process id.
            {
            	if(list[k].s_id> list[k+1].s_id)       // allocation depend on proccess id.
            	{
            	q= list[k];
                list[k] = list[k+1];
                list[k+1] = q;
                }
			}
		}
	}
}
void waiting_time(struct mess list[50], int p)    // calculating waiting time.
{
	int k;
    list[0].w_time=0;
    for(k=1;k<p;k++)
    {
        list[k].w_time=list[k-1].w_time+list[k-1].b_time;   // WaitingTime=WaitingTime(Previous)+BurstTime.
    }
}





void turn_aroundtime(struct mess list[50], int p)  // calculating TurnAroundTime.
{
	int k;
    
    for(k=0;k<p;k++)
    {
        list[k].ta_time=list[k].w_time+list[k].b_time;     // TrunAroundTime = WaitingTime + BurstTime.
    }
}
