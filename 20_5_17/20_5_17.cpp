#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define THREADCOUNT 4

int g_tickets = 100;

//线程的任务就是抢票，现在有100张票，每抢到一张就进行减1操作
void* thread_start(void* arg)
{
    (void)arg;
    while(1)
    {
        //线程A g_tickets 1 
        //线程B g_tickets 1
        //线程A g_tickets--(不是原子的)  （减减的时候没有被打断）1 -> 0
        //线程B g_tickets-- 0-->-1
        if(g_tickets > 0)
        {
            g_tickets--;
            printf("i am thread [%p], i have ticket num is [%d]\n", pthread_self(), g_tickets);
            //usleep(1000);
        }
        else
        {
            break;
        }
    }
    return NULL;
}

int main()
{
    pthread_t tid[THREADCOUNT];
    int i = 0;
    for(; i < THREADCOUNT; i++)
    {
        pthread_create(&tid[i], NULL, thread_start, NULL);
    }
    
    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}