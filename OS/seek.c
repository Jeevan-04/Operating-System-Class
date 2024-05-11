#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int sz, seek_pos=0,seek_pos1,seek_end,l;
	char buf[100], buf1[100];

	int fd=open("jeevan.txt", O_RDWR);

	if(fd<0)
	{
		perror("Error occured during open");
		exit(1);
	}

	seek_pos =lseek(fd,0,SEEK_SET);
	printf("\n Initialized offset position : (%d) \n", seek_pos);

	seek_pos =lseek(fd,2,SEEK_SET);
        printf("\n Offset position : (%d) \n", seek_pos);

	seek_pos =lseek(fd,6,SEEK_SET);
        printf("\n Offset position : (%d) \n", seek_pos);

	sz=read(fd,buf,10);
	printf("\n read bytes from file after lseek is= (%d) \n",sz);
	buf[sz]='\0';
	printf("Read bytes are as follows: \n%s\n",buf);

	seek_end = lseek(fd,0,SEEK_END);
	seek_pos1=lseek(fd,11,SEEK_SET);
	l=(seek_end-seek_pos1)+1;
	sz=read(fd,buf1,l);
	printf("\n read bytes from file after lseek is = (%d) \n",sz);
	buf1[sz]='\0';
	printf("Characters from after 11th to end read bytes are as follows: \n%s\n",buf);

	seek_pos=lseek(fd,0,SEEK_END);
	printf("\n Offset position after (SEEK_END+0) :(%d) \n", seek_pos);

	strcpy(buf,"New string appeded after seek end\n");
	sz=write(fd,buf,strlen(buf));

	close(fd);
	
	return 0;
}
