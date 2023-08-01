#include<stdio.h>
#include<stdlib.h>

int main()
{
  
	int max[10][10],need[10][10],alloc[10][10],avail[10],fin[10],safe[10];
	int pr_cnt,res_cnt,i,j,count=0,process;
	system("clear");
  
	printf("Enter the system state information:\n");
	printf("Enter the number of programs:\n");
	scanf("%d",&pr_cnt);
  
	for(i=0;i<pr_cnt;i++)
		fin[i]=0;
  
	printf("Enter the number of resources:\n");
	scanf("%d",&res_cnt);
  
	for(i=0;i<res_cnt;i++)
		avail[i]=0;
  
	printf("Enter the max matrix for all thr processes:");
	for(i=0;i<pr_cnt;i++)
		for(j=0;j<res_cnt;j++){
			printf("\nEnter instance for max[%d][%d]=",i,j);
			scanf("%d",&max[i][j]);
		}

	for(i=0;i<pr_cnt;i++)
		for(j=0;j<res_cnt;j++){
			printf("\nEnter instance for alloc[%d][%d]=",i,j);
			scanf("%d",&alloc[i][j]);
	}
  
	printf("\nEnter the available resources in the system:");
	for(i=0;i<res_cnt;i++){
		printf("\navailable[%d]=",i);
		scanf("%d",&avail[i]);
	}
  
	printf("Need matrix\n");
	for(i=0;i<pr_cnt;i++){
		for(j=0;j<res_cnt;j++){
			need[i][j]=max[i][j]-alloc[i][j];
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
  
	do{
		printf("Available resources are :\n");
		for(i=0;i<res_cnt;i++)
			printf("%d\t",avail[i]);
    
		printf("\nMax matrix: \t\t Allocation matrix:\n");
		for(i=0;i<pr_cnt;i++){
			for(j=0;j<res_cnt;j++){
				printf("%d\t",max[i][j]);
		}
		printf("\t");
			for(j=0;j<res_cnt;j++){
				printf("%d\t",alloc[i][j]);
			}
		printf("\n");
		}

		process=-1;
		for(i=0;i<pr_cnt;i++){
			if(fin[i]==0){
				process=i;
				for(j=0;j<res_cnt;j++){
					if((avail[j]) < (need[i][j])){
						process=-1;
						break;
					  }
				}
			}
      
			if(process!=-1)
				break;
		}
    
		if(process!=-1){
			printf("Process %d runs to completion.\n",process);
			safe[count++]=process;
		
		for(j=0;j<res_cnt;j++){
			avail[j]+=alloc[process][j];
			alloc[process][j]=0;
			max[process][j]=0;
			fin[process]=1;
		}
      
	}
	}while(count!=pr_cnt && process!=-1);
	
	
	if(count==pr_cnt){
		printf("The system is in safe state\n");

		printf("The available resources at the end are as follows:\n");
		for(i=0;i<res_cnt;i++)
			printf("%d\t",avail[i]);
    
		printf("Safe sequence:<");
		for(i=0;i<pr_cnt;i++)
			printf("p%d,",safe[i]);
		printf(">\n");
	}
	else
		printf("The system is not in safe sequence!!!");

	return 0;
}
