#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <vector>

#define SIZE 4

#define THREADCOUNT 4

class RingQueue
{
    public:
        RingQueue()
            :Vec_(SIZE)
        {
            Capacity_ = SIZE;
            PosWrite_ = 0;
            PosRead_ = 0;

            //生产者的信号量初始化的时候，和数组的大小保持一致，有多少空间可以供生产
            sem_init(&ProSem_, 0, SIZE);
            //消费者信号量初始化的时候，需要和数据当中的元素个数保持一致
            sem_init(&ConSem_, 0, 0);
            //初始化互斥
            sem_init(&LockSem_, 0, 1);
        }
        ~RingQueue()
        {
            sem_destroy(&ProSem_);
            sem_destroy(&ConSem_);
            sem_destroy(&LockSem_);
        }

        void Push(int& Data)
        {
            sem_wait(&ProSem_);
            //加锁
            sem_wait(&LockSem_);
            Vec_[PosWrite_] = Data;
            PosWrite_ = (PosWrite_ + 1) % Capacity_;
            sem_post(&LockSem_);

            //对资源数进行加1 操作，并且唤醒消费者
            sem_post(&ConSem_);
        }
        //出参 int* Data
        void Pop(int* Data)
        {
            //同步，需要将同步的实现代码放到加锁实现代码之前，因为sem_wait这个接口当中没有包含sem_post的功能
            sem_wait(&ConSem_);
            //加锁
            sem_wait(&LockSem_);//一个消费线程现在sem_wait(&LockSem_)
            *Data = Vec_[PosRead_];
            PosRead_ = (PosRead_ + 1) % Capacity_;
            sem_post(&LockSem_);

            sem_post(&ProSem_);
        }
    private:
        std::vector<int> Vec_;
        size_t Capacity_;
        int PosWrite_;
        int PosRead_;
        //同步
        sem_t ProSem_;
        sem_t ConSem_;
        //互斥
        sem_t LockSem_;
};

void* ConStart(void* arg)
{
    RingQueue* rq = (RingQueue*)arg;
    int Data;
    while(1)
    {
        rq->Pop(&Data);
        printf("ConStart consume Data [%p][%d]\n", pthread_self(),  Data);
    }
    return NULL;
}

void* ProStart(void* arg)
{
    RingQueue* rq = (RingQueue*)arg;
    int i = 0;
    while(1)
    {
        rq->Push(i);
        printf("ProStart Produce Data [%p][%d]\n", pthread_self(), i);
        i++;
    }
    return NULL;
}

int main()
{
    pthread_t Con_tid[THREADCOUNT], Pro_tid[THREADCOUNT];
    int i = 0;
    RingQueue* rq = new RingQueue();
    for(; i < THREADCOUNT; i++)
    {
        int ret = pthread_create(&Con_tid[i], NULL, ConStart, (void*)rq);
        if(ret != 0)
        {
            perror("pthread_create");
            return 0;
        }
        ret = pthread_create(&Pro_tid[i], NULL, ProStart, (void*)rq);
        if(ret != 0)
        {
            perror("pthread_create");
            return 0;
        }
    }

    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_join(Con_tid[i], NULL);
        pthread_join(Pro_tid[i], NULL);
    }
    delete rq;
    return 0;
}