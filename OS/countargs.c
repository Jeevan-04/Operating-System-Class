#include<stdio.h>
#include<string.h>
int main(int argc, char*argv[])
{
	/*argc and argv are stored in stack frame of the main argv stores the array of pointers to string*/
	int count=0;
	printf("\n Demonstrate the process of command line argument ");
printf("\n The value of argc is %d", argc);
while(count<argc)
{
	printf("\n%d th string is %s", count, argv[count]);
	count++;
}
return 0;
}
