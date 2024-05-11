#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

static void * threadFunc(void *arg)
{
        char *str = (char *) arg;
        printf("ThreadFunc2: arguments passed to thread are: %s , pid = (%d)\n", str, getpid());
        (void)sleep(2);
        printf("\nthreadFunc2: exiting now\n");
        return(0);
}

int main(int argc, char *argv[])
{
        pthread_t t1;
        void *res;
        int s;

        s= pthread_create(&t1, NULL, threadFunc, "Hello world");
        if(s!=0)
               perror("Thread create error");
        printf("main thread: Message from main() , pid = (%d)\n", getpid());

        sleep(10);
        printf("\nmain thread: exiting now\n");

        pthread_exit(0);
}
