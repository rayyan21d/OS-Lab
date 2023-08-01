#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	int pid,msq_id;
	char buff[30],str[30];
  
	msq_id=msgget((key_t)2116,IPC_CREAT|0644);
	pid=fork();	
  
	if(pid==0){
		strcpy(str,"message queue demo");
		msgsnd(msq_id,str,sizeof(str),0);
    
		sleep(1);
    
		msgrcv(msq_id,buff,sizeof(buff),0,0);
		printf("message received by parent process:%s\n",buff);
	}
	else if(pid>0){
		msgrcv(msq_id,buff,sizeof(buff),0,0);
		printf("message received by the chid process is:%s.\n",buff);
    
		strcpy(str,"send from parent to child");
		msgsnd(msq_id,str,sizeof(str),0);
	}

	return 0;
}
