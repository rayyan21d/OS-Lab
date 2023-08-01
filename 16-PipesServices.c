#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int pid,a[2],b[2],rval1,rval2;
	char str[30],buff[30];
  
	rval1=pipe(a);
	rval2=pipe(b);
  
	pid=fork();
  
	if(pid<0){
		printf("\nUnable to create process!!");
		exit(1);
		}
	else if(pid==0){
		strcpy(str,"pipe demo");
		write(a[1],str,sizeof(str));
		printf("Child process has sent:%s\n",str);
		sleep(2);
		read(b[0],buff,sizeof(buff));
		printf("child process has recieved :%s\n",buff);
	}
	else
	{	
		sleep(1);
		read(a[0],buff,sizeof(buff));
		printf("parent process has received:%s\n",buff);
		strcpy(str,"coservice pipes demo");
		write(b[1],str,sizeof(str));
		printf("parent process has sent:%s\n",str);
	}

	return 0;
}
