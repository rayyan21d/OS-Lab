#include<stdio.h>
#include<stdlib.h>

int main(){
  
	int i,j,k,min,rs[25],m[10],count[10],flag[10],n,f,pf=0,next=1;
	float hr,mr;
	system("clear");
  
	printf("Enter the lenght of reference string:");
	scanf("%d",&n);
  
	printf("Enter the string reference:\n");
	for(i=0;i<n;i++){
		scanf("%d",&rs[i]);
		flag[i]=0;
	}
	
  printf("Enter the nmber of frames:\n");
	scanf("%d",&f);
	for(i=0;i<f;i++){
		count[i]=0;
		m[i]=-1;
	}
	printf("The LRU page replacement is:\n");
  
	for(i=0;i<n;i++){
		for(j=0;j<f;j++){
			if(m[j]==rs[i]){
				flag[i]=1;
				count[j]=next++;
				}
		  }
		if(flag[i]==0){
			if(i<f){
				m[i]=rs[i];
				count[i]=next++;
				}
			else{
				min=0;
				for(j=1;j<f;j++){
					if(count[min]>count[j]){
						min=j;
					}
				}
        
				m[min]=rs[i];
				count[min]=next++;
			}
				pf++;
		}
		
		for(j=0;j<f;j++){
			printf("%d\t",m[j]);
		}
			if(flag[i]==0){
				printf("page fault number is %d.",pf);
			}
			printf("\n");
		}
  
	printf("The number of page faults are:%d.\n",pf);

	mr=(pf*100)/n;
	hr=100-mr;
  
	printf("The hit ratio is %f.\n",hr);
	printf("The miss ratio is %f.\n",mr);
  
	return 0;
  
}

