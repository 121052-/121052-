#include<stdio.h>
void main()
{
	int N_proc,i,wait_prev,k,temp,m,l;
	wait_prev=0;
	printf("\nEnter the no of processes:");
	scanf("%d",&N_proc);
	int burst[N_proc],wait[N_proc],turnarnd[N_proc],proc[N_proc];
	printf("\nEnter burst time for process: ");
	for(i=0;i<N_proc;i++)
	{
		printf("\nP[%d]: ",i+1);
		scanf("%d",&burst[i]);
	}
	//sorting processes according to their burst time
	int min =100;
	int flag[N_proc];
	for(i=0;i<N_proc;i++)
	flag[i]=0;
	int index;
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	for(i=0;i<N_proc;i++)
	{
		min = 1000;
		for(k=0;k<N_proc;k++)
		{
			if(flag[k]!=1 && min>burst[k])
			{
				min = burst[k];
				index = k;
			}
		}
		
		wait[index]=wait_prev;
		turnarnd[index]=wait[index]+burst[index];
		wait_prev+=burst[index];
		flag[index]=1;
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\n",i+1,burst[index],wait[index],turnarnd[index]);
		
	
	}
	getchar();
	getchar();
}
