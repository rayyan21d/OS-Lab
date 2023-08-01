#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid,a[2],rval;
	char str[30],buff[30];

	rval=pipe(a);
	pid=fork();
  
	if(pid<0){
		printf("\nUnable to create process!!");
		exit(1);
	}
	else if(pid==0){
		strcpy(str,"pipe demo");
		write(a[1],str,sizeof(str));
		printf("Child process has sent:%s\n",str);
	}
	else
	{	
		wait(0);
		read(a[0],buff,sizeof(buff));
		printf("parent process has received:%s\n",buff);
	}

	return 0;
}
