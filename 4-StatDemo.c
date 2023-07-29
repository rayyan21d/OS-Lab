#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>

int main(int argc,char * argv[]){
  
	int fd;
	struct stat buff;
	fd=stat(argv[1],&buff);
  
	if(fd<0){
		printf("Unable to open!!");
		exit(1);
	}
  
	printf("Info of %s: \n",argv[1]);
	printf("file size:%d\n",buff.st_size);
	printf("no. of links: %d\n",buff.st_nlink);
	printf("inode no is :%ld\n",buff.st_ino);
	printf("owner id is :%d\n",buff.st_uid);
	printf("group id is :%d\n",buff.st_gid);
	printf("device id is :%d\n",buff.st_dev);
	printf("mode is :%o\n",buff.st_mode);
	printf("last time access :%s\n",ctime(&buff.st_atime));
	printf("last modification time :%s\n",ctime(&buff.st_mtime));
	printf("last status change:%s\n",ctime(&buff.st_ctime));
  
}
