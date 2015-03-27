
#include<stdio.h>

void menu()
{
	printf("\n Memory management ");
	printf("\n 1) First Fit");
	printf("\n 2) Best Fit");
	printf("\n 3) Worst Fit");
}

void accept(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

}

void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	 {
	 	printf("\t %d",a[i]);
	 }

}

void sort(int a[],int n)
{
	 int i,j,temp;
	 for(i=0;i<n-1;i++)
	 {
		for(j=0;j<n-1;j++)
		{
			 if(a[j] > a[j+1])
			 {
				 temp=a[j];
				 a[j]=a[j+1];
				 a[j+1]=temp;
			 }
		}
	 }
}

void sort1(int a[],int n)
{
	 int i,j,temp;
	 for(i=0;i<n-1;i++)
	 {
		for(j=0;j<n-1;j++)
		{
			 if(a[j] < a[j+1])
			 {
				 temp=a[j];
				 a[j]=a[j+1];
				 a[j+1]=temp;
			 }
		}
	 }
}

void first_fit(int psize[],int np,int msize[],int nm)
{
	 int i,j,itot,etot,flag[30]={0};

	 itot=etot=0;
	 for(i=0;i<np;i++)
	 {
		for(j=0;j<nm;j++)
		{
			 if(flag[j]==0 && msize[j] >=psize[i])
			 {
			flag[j]=1;
			itot=itot+msize[j]-psize[i];
			break;
			 }

		}
		if(j==nm)
		{
			 printf("\nNo space for process : %d",i);
		}
	 }

	 for(i=0;i<nm;i++)
	 {
		 etot=etot+msize[i];
	 }
	printf("\nProcess : ");
	display(psize,np);
	printf("\nMemory : ");
	display(msize,nm);
	printf("\nInternal fragmentation : %d",itot);
	printf("\nExternal fragmentation : %d",etot);
}

void best_fit(int psize[],int np,int msize[],int nm)
{
	 int i,j,itot,etot,temp[30],flag[30]={0};

	 itot=etot=0;
	 for(i=0;i<nm;i++)
	 temp[i]=msize[j];

	 sort(temp,nm);

	 for(i=0;i<np;i++)
	 {

		for(j=0;j<nm;j++)
		{
			 if(flag[j]==0 && temp[j] >=psize[i])
			 {
				flag[j]=1;
				itot=itot+temp[j] - psize[i];
				break;
			 }
		}

		if(j==nm)
		{
			 printf("\nNo space for process : %d",i);
		}
	 }

	 for(i=0;i<nm;i++)
	 {
		 etot=etot+msize[i];
	 }
	printf("\nProcess : ");
	display(psize,np);
	printf("\nMemory : ");
	display(temp,nm);
	printf("\nInternal fragmentation : %d",itot);
	printf("\nExternal fragmentation : %d",etot);

}


void worst_fit(int psize[],int np,int msize[],int nm)
{
	 int i,j,itot,etot,temp[30],flag[30]={0};

	 itot=etot=0;
	 for(i=0;i<nm;i++)
	 temp[i]=msize[j];

	 sort1(temp,nm);
	 for(i=0;i<np;i++)
	 {
		for(j=0;j<nm;j++)
		{
			 if(flag[j]==0 && temp[j] >=psize[i])
			 {
				flag[j]=1;
				itot=itot+temp[j] - psize[i];
				break;
			 }

		}
		if(j==nm)
		{
		 	printf("\nNo space for process : %d",i);
		}
	 }

	 for(i=0;i<nm;i++)
	 {
		 etot=etot+msize[i];
	 }
	printf("\nProcess : ");
	display(psize,np);
	printf("\nMemory : ");
	display(temp,nm);
	printf("\nInternal fragmentation : %d",itot);
	printf("\nExternal fragmentation : %d",etot);
}

void main()
{

	 int ch,np,nm,psize[30],msize[30];

	 printf("\nEnter no. of processes : ");
	 scanf("%d",&np);
	 printf("\nEnter size of processes : ");
	 accept(psize,np);

	 printf("\nEnter no. of memory holes : ");
	 scanf("%d",&nm);
	 printf("\nEnter size of memory holes : ");
	 accept(msize,nm);


	 while(1)
	 {
		menu();
		printf("\n Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			 case 1:
			 printf("\n\n First Fit : \n");
			 first_fit(psize,np,msize,nm);
			 break;

			 case 2:
			 printf("\n\n Best Fit : \n");
			 best_fit(psize,np,msize,nm);
			 break;

			case 3:
			printf("\n\n Next Fit : \n");
			worst_fit(psize,np,msize,nm);
			break;

			case 4:
			exit(0);

			default:
			printf("\n Wrong Choice");

		}
	}
}

