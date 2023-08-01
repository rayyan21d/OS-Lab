#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int mutex=1,full=0,empty=3,x=0;

int main(){
  
	int n;
	void producer();
	void consumer();
	int wait();
	int signal();
  
	printf("1.Produce\n2.Consume\n3.Exit\n");
	while(1){
    
		printf("Select ur choice:");
		scanf("%d",&n);
		switch(n){
			case 1 : if(mutex==1&&empty!=0)
				 producer();
				 else
				 printf("Buffer is full");
				 break;
			case 2: if (mutex==1&&full!=0)
				consumer();
				else
				printf("Buffer is empty");
				break;
			case 3: exit(1);

			}
	}
}

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}


void producer(){
	mutex=wait(mutex);
	empty=wait(empty);
	x++;
  
	printf("producer produced an item %d.\n",x);
	full=signal(full);
	mutex=signal(mutex);
  
}


void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	printf("consumer consumed an item %d\n.",x);
	x--;
  
	empty=signal(empty);
	mutex=signal(mutex);
  
}

