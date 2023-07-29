#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int pid,rval;
	printf("Zombie process demo\n");
	pid=fork();
 
	if(pid<0){
		printf("unable to create process\n");
		exit(1);
	}
	else if(pid==0){
		printf("This is child process\n");
		printf("childs process identification is:%d\n",getpid());
	  printf("childs parent process identification is:%d\n",getppid());
	}
	else{
		sleep(2);
		printf("This is parent process\n");
		printf("parents process identification is:%d\n",getpid());
		printf("parents parent process identification is:%d\n",getppid());	
		printf("parents child pid is :%d\n",pid);
  
		system("ps -l");
		rval=wait(0);
  
		printf("the pid returned by the terminated child process is %d",rval);
		system("ps -l");

	}

	return 0;
}
