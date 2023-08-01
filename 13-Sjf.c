#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
  
	int bt[10],j,wt[10],tat[10],n,i,total_wt=0,total_tat=0,t,pt[10];
	float avg_wt,avg_tat;
  
	system("clear");
  
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
  
	for(i=0;i<n;i++){
  	pt[i]=i+1;
  	printf("Enter the burst time of process[%d]:",i+1);
  	scanf("%d",&bt[i]);
	}
  
	for(i=0;i<=(n-1);i++)
	{
		for(j=i+1;j<=(n-1);j++)
		{
			if(bt[i]>bt[j])
			{
				t=bt[i];
				bt[i]=bt[j];
				bt[j]=t;
				t=pt[i];
				pt[i]=pt[j];
				pt[j]=t;
			}
		}
	}
  
	for(i=0;i<n;i++)
	  printf("%d\n",bt[i]);
  
	wt[0]=0;
  
	for(i=1;i<n;i++)
	  wt[i]=wt[i-1]+bt[i-1];
  
	for(i=0;i<n;i++)
	{
  	tat[i]=wt[i]+bt[i];
  	total_wt+=wt[i];
  	total_tat+=tat[i];
	}
  
	avg_wt=(float)total_wt/n;
	avg_tat=(float)total_tat/n;
  
	printf("\nprocess_no\tBurst time\tWait time\t Tat time");
  
	for(i=0;i<n;i++)
	  printf("\np[%d]\t\t%d\t\t%d\t\t%d\t\t",pt[i],bt[i],wt[i],tat[i]);  
  
	printf("\nThe average waiting time is :%f.",avg_wt);
	printf("\nThe average tat is: %f.",avg_tat);
  
	return 0;
}
