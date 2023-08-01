#include<stdlib.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int pid,shmid;
	char *p;
 
	shmid=shmget((key_t)2116,100,IPC_CREAT|0600);
	p=(char *)shmat(shmid,NULL,0);
 
	pid=fork();
	if(pid<0){
		printf("failed to create a process!!");
		exit(1);
	}
	else if(pid==0){
		sleep(5);
		strcpy(p,"shared memory region");
	}
	else if(pid>0){
		wait(0);
		printf("%s\n",p);
	}
  
	return 0;
}
