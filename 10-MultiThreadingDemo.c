#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *runner1();
void *runner2();

int main(){
  
	int i,ret1,ret2;
	printf("Demo of Multiple Threads!!\n");
	pthread_t tid1,tid2;
  
	ret1=pthread_create(&tid1,NULL,runner1,0);
	pthread_join(tid1,0);
	ret2=pthread_create(&tid2,NULL,runner2,0);
	pthread_join(tid2,0);
	
	if(ret1<0 ||ret2<0){
  	printf("error in creation of thread");
  	exit(1);
	}
	for(i=0;i<5;i++){
  	printf("%d inside main\n",i);	
  	sleep(1);
	}
	
	return 0;
}

void *runner1(){
	int i;
	for(i=0;i<5;i++){
	printf("%d inside thread 1\n",i);	
	sleep(1);}
	pthread_exit(0);
}

void *runner2(){
	int i;
	for(i=0;i<5;i++){
	printf("%d inside thread 2\n",i);	
	sleep(1);}
	pthread_exit(0);
}
