#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *runner();
int main(){
	
	int i,ret;
	printf("Demo of Thread!!\n");
	pthread_t tid;
	ret=pthread_create(&tid,NULL,runner,0);
	
	if(ret<0){
	printf("error in creation of thread");
	exit(1);
	}
	
	for(i=0;i<5;i++){
	printf("%d inside main\n",i);	
	sleep(2);
	}
	
	return 0;
}

void *runner(){
	int i;
	for(i=0;i<5;i++){
	printf("%d inside thread\n",i);	
	sleep(2);}
	pthread_exit(0);
}
