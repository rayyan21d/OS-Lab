#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid;
	printf("Fork usage demo\n");
	pid=fork();
 
	if(pid<0){
		printf("unable to create process\n");
		exit(1);
	}
 
	else if(pid==0){
		printf("This is child process\n");
		printf("childs process identification is:%d\n",getpid());
	  printf("childs parent process identification is:%d\n",getppid());
		sleep(5);

		printf("childs process identification is:%d\n",getpid());
	  printf("childs parent process identification is:%d\n",getppid());
	}
	else{
		printf("This is parent process\n");
		printf("parents process identification is:%d\n",getpid());
		sleep(2);
    
		printf("parents parent process identification is:%d\n",getppid());	
		printf("parents child pid is :%d\n",pid);
	}

	return 0;
}
