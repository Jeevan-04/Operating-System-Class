#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

void main()
{
        int fd, i;

        fd = open("./naiduj.txt",O_RDWR);
        if(fd<0)
        {
                sleep(5);
                fd =open("./naiduj.txt",O_RDWR | O_CREAT, 0666);
                if(fd>0)
                {
                        printf("\nProgram 2 created naiduj.txt\n");
                        close(fd);
                }
        }
}
