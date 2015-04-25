#include<stdio.h>
void main()
{
	int N_proc,i,wait_prev,k,temp,m,l;
	printf("\nEnter the no of processes:");
	scanf("%d",&N_proc);
	int exec[N_proc],start[N_proc],deadline[N_proc], flag[N_proc];
	for(i=0;i<N_proc;i++)
	flag[N_proc] = 0;
	wait_prev = 0;
	printf("\nEnter the following: ");
	printf("\nabsolute start time, exec time and absolute deadline: "); 
	for(i=0;i<N_proc;i++)
	{
		printf("\nFor process P[%d]: ",i+1);
		printf("\nabsolute start time: ");
		scanf("%d", &start[i]); 
		printf("\nabsolute exec time: ");
		scanf("%d", &exec[i]);
		printf("\nabsolute deadline: ");
		scanf("%d", &deadline[i]);
	}
	int time_quatum = 0;
	int end_false = 1;
	int nearest_deadline = 10000;
	int index = -1;
	int count = 0;
	while(end_false)
	{
		for(i = 0; i< N_proc;i++)
		{
			if(start[i] == time_quatum || exec[index] == 0)
			{
				if(flag[i] != 1)
				{
					if((deadline[i] - time_quatum) < nearest_deadline)
					{
						nearest_deadline = (deadline[i] - time_quatum);
						index = i;
					}
				}
			}
		}
		if(exec[index] == 0)
		{
			nearest_deadline = 10000;
			index=-1;
		}
		if(index!=-1)
		{
			printf("\n From time quantum %d to %d, process %d", time_quatum, time_quatum+1, index+1);
			exec[index]--;
			if(exec[index] == 0)
			{
				flag[index]=1;
				count++;
			}
		}
		if(count == N_proc)
		end_false = 0;
		time_quatum++;
	}
}
