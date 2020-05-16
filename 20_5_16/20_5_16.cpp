#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct Thread_info
{
    int ThreadNUm_;
    Thread_info()
    {
        ThreadNUm_ = -1;
    }
}THRINFO;

void* thread_start(void* arg)
{
    THRINFO* thrinfo = (THRINFO*)arg;
    while(1)
    {
        printf("i am new thread - %d\n", thrinfo->ThreadNUm_);
        sleep(1);
    }
    delete thrinfo;
    thrinfo = NULL;
    return NULL;
}

int main()
{
    pthread_t tid;
    char arr[1024] = {0};
    sprintf(arr, "%s", "linux-61");

    for(int i = 0; i < 4; i++)
    {
        THRINFO* thrinfo = new THRINFO();
        thrinfo->ThreadNUm_ = i;
        pthread_create(&tid, NULL, thread_start, (void*)thrinfo);
        //delete thrinfo; 
        //thrinfo = NULL;
    }

    while(1)
    {
        sleep(1);
        printf("i am main thread\n");
    }
    return 0;
}