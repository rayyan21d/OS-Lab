#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;
	char buff[50];
	fd=open("seek.txt",O_RDWR);
  
	if(fd<0){
		printf("Unable to open the file");
		exit(1);
	}
  
	read(fd,buff,10);
	write(1,buff,10);
	printf("\n");
  
	lseek(fd,5,SEEK_CUR);
	read(fd,buff,10);
	write(1,buff,10);
	printf("\n");
  
	lseek(fd,5,SEEK_SET);
	read(fd,buff,10);
	write(1,buff,10);
	printf("\n");
  
	lseek(fd,-11,SEEK_END);
	read(fd,buff,10);
	write(1,buff,10);
		
	close(fd);
	return 0;
}
