#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
        int fd;
        fd= open("jeevan.txt",O_RDONLY);
        if (fd<0){
                perror("c1");
                exit(1);
        }
        printf("opened the fd=%d \n",fd);

if(close(fd)>0)
{
        perror("c1");
        exit(1);
}
printf("closed the fd \n");
printf("closed the fd=%d \n",fd);
fd=open("jeevan.txt", O_RDONLY);
printf("opened the fd=%d \n",fd);
return 0;
}
