#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
  
	int bt[10],wt[10],rt[10],tat[10],n,count=0,ts,i,t=0;
	system("clear");
  
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
  
	for(i=0;i<n;i++){
  	printf("Enter the burst time of process[%d]:",i+1);
  	scanf("%d",&bt[i]);
	}
  
	printf("Enter the time slice:");
	scanf("%d",&ts);
  
	for(i=0;i<n;i++){
		rt[i]=bt[i];
	}
  
	while(1){
		for(i=0;i<n;i++){
			if(rt[i]>0){
				if(rt[i]>ts){
					t+=ts;
					rt[i]=rt[i]-ts;
				}
				else{
					t+=rt[i];
					rt[i]=0;
					tat[i]=t;
					count++;
				}
			}
		}
		if(count==n)
			break;
	}
  
	for(i=0;i<n;i++){
		wt[i]=tat[i]-bt[i];
		}
  
	printf("\nprocess_no\tBurst time\tWait time\t Tat time\n");

	for(i=0;i<n;i++)
	  printf("p[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);   

	return 0;
}
