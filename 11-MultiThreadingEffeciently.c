#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void *compute(void *add);

int main(){
  
	int i;
	printf("multithreading efficiently\n");
	pthread_t tid1,tid2;
	long value1=1;
	long value2=2;
	pthread_create(&tid1,NULL,compute,(void *)&value1);

	pthread_join(tid1,0);
	pthread_create(&tid2,NULL,compute,(void *)&value2);

	pthread_join(tid2,0);
	return 0;
}

void *compute(void *add){
	int i;
	long sum=0;
	long *add_num=(long*)(add);
	printf("add=%ld\n",*add_num);
	for(i=0;i<100000000;i++)
		sum+=*(add_num);

}
