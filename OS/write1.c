#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
//#include <malloc.h>

void main(){
	int sz;
	char buf[100];

	strcpy(buf,"THis is example of O_TRUNC: Sample file write2 using append flag\n");
	int fd = open("jeevan.txt", O_WRONLY | O_TRUNC);
	if (fd <0)
	{
		perror("Error Occured during open");
		exit(1);
	}
	printf("Length of buf is (%d)", (int)strlen(buf));
	sz = write(fd, buf, strlen(buf));
	printf("\nwrite() returned %d\n", sz);
	close(fd);
}
	
