#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define THREADCOUNT 4

int g_tickets = 100;

pthread_mutex_t g_mutex;

//线程的任务就是抢票，现在有100张票，每抢到一张就进行减1操作
void* thread_start(void* arg)
{
    (void)arg;
    while(1)
    {
        // A B C D --> 抢锁然后进行加锁操作 假设，B抢到了，A C D没有抢到
        // A C D线程，都还卡在pthread_mutex_lock
        // B 在进行 资源减减之后，重新 回到了while循环,也需要执行pthread_mutex_lock进行抢锁，但是呢，锁本身就被他自己拿着，自己没有释放锁，但是还想在获取锁，这会他也就被阻塞了
        pthread_mutex_lock(&g_mutex);
        //当判断 g_tickets的值为0的时候，走了else逻辑
        if(g_tickets > 0)
        {
            g_tickets--;
            printf("i am thread [%p], i have ticket num is [%d]\n", pthread_self(), g_tickets + 1);
        }
        else
        {
            //从break跳出了循环
            pthread_mutex_unlock(&g_mutex);
            break;
        }
        pthread_mutex_unlock(&g_mutex);
    }
    //从return 进行返回了
    return NULL;
}

int main()
{
    pthread_t tid[THREADCOUNT];
    int i = 0;
    pthread_mutex_init(&g_mutex, NULL);
    for(; i < THREADCOUNT; i++)
    {
        pthread_create(&tid[i], NULL, thread_start, NULL);
    }
    
    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&g_mutex);
    return 0;
}