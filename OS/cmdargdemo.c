#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[])
{
	if(strstr(argv[1],"add"))
		printf("\n The Addition of %s and %s is %d", argv[2],argv[3],atoi(argv[2])+atoi(argv[3]));
	else if(strstr(argv[1],"sub"))
		printf("\n The Subtraction of %s and %s is %d", argv[2],argv[3],atoi(argv[2])-atoi(argv[3]));

	else if(strstr(argv[1],"mul"))
                printf("\n The Multiplication of %s and %s is %d", argv[2],argv[3],atoi(argv[2])*atoi(argv[3]));

	else if(strstr(argv[1],"div"))
                printf("\n The Division of %s and %s is %f", argv[2],argv[3],atof(argv[2])/atof(argv[3]));

return 0;
}

