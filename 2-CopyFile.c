#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
main(int argc,char *argv[])
{
	int fd1,fd2,n;
	char buff[20];
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_WRONLY|O_CREAT,0644);
 
	if(fd1<0||fd2<0){
		printf("Unable to open files!!\n");
		exit(1);
	}
 
	while(1){
		n=read(fd1,buff,1);
		if(n<=0)
		break;
		write(fd2,buff,1);
	}
 
	close(fd1);
	close(fd2);
 
	fd2=open(argv[2],O_RDONLY);
	if(fd2<0){
		printf("unable to open file");
		exit(1);
	}
 
	while(1){
		n=read(fd2,buff,1);
		if(n<=0)
		break;
		write(1,buff,1);
	}
	close(fd2);
}
