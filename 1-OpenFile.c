#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int fd;
	char fname[20];
	printf("Enter file name to be open:");
	scanf("%s",fname);
	fd=open(fname,O_RDONLY);	
	if(fd<0){
	printf("failed to open file..\n");
	exit(1);
	}
	else
	printf("File opened!!\n");
	close(fd);
	return 0;
}
