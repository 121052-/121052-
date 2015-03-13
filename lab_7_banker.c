#include<stdio.h>
 
void main()
 {

	   int process,resource,i,j,instance,k=0,cnt1=0,cnt2=0; 
	 
	   printf("\n\t Enter No. of Process:- ");

	   scanf("%d",&process);                           

	   printf("\t\t");
		
	   printf("\n\tEnter No. of Resources:- ");
	 
	   scanf("%d",&resource);                      

	   printf("\t\t");
	 
	   int available[resource],max[process][resource],allocated[process][resource],need[process][resource],completed[process];
	 
	   for(i=0;i<process;i++)
	   completed[i]=0;                             
	 
	   printf("\n\tEnter No. of available instances\n");
	 
	   for(i=0;i<resource;i++)
	    {
	    	 
	     printf("\t\t");	   
	
	     scanf("%d",&instance);
	 
	     available[i]=instance;                      

	    }
	 
	   printf("\n\tEnter Maximum No. of instances of resources that a Process need:\n");
	 
	    for(i=0;i<process;i++)
	     {
		printf("\n\t For P[%d]: \n",i);
	 
		for(j=0;j<resource;j++)
		 {
		    printf("\t\t");
	 
		    scanf("%d",&instance);
	 
		    max[i][j]=instance;              
		 }
	     }    
	    printf("\n\t Enter no. of instances already allocated to process of a resource:\n");
	 
	     for(i=0;i<process;i++)
	     {
		printf("\n\t For P[%d]: \n",i);
	 
		for(j=0;j<resource;j++)
		 {
		    printf("\t\t");
	 
		    scanf("%d",&instance);
	 
		    allocated[i][j]=instance;
	 
		    need[i][j]=max[i][j]-allocated[i][j];      
		 } 
	    }
		printf("\n need matrix:\n");
		  for(i=0;i<process;i++)
			{
	for(j = 0; j < resource; j++)
	{
	    
	    
	    printf("%d ", need[i][j]);
	    printf("\t");
	}
	    printf("\n");
	    

	}


	    printf("\n\t Safe Sequence is:- \t");
	 
	    while(cnt1!=process)
	    {
	    cnt2=cnt1;
	 
	    for(i=0;i<process;i++)
	     {
	 
	       for(j=0;j<resource;j++)
		{
		    if(need[i][j]<=available[j])
		      {
		         k++;
		      }  
		     
		}    
		if(k==resource && completed[i]==0 )
		 {
		   printf("P[%d]\t",i);
	 
		   completed[i]=1;
	 
		   for(j=0;j<resource;j++)
		     {
		     
		       available[j]=available[j]+allocated[i][j];
		    
		     } 
		     cnt1++;
		      
		 }
		 k=0;
	       }
	  
		 if(cnt1==cnt2)
		 {
		 printf("\t\t Deadlock \n");
	 
		 break;
	       } 
	 }
	   
}            
