#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


#define shm_key 0x12345678
int main()
{
    //创建共享内存
    int shmid = shmget(shm_key, 1024, IPC_CREAT | 0664);
    if(shmid < 0)
    {
        perror("shmget");
        return 0;
    }

    struct shmid_ds buf;
    shmctl(shmid, IPC_STAT, &buf);
    printf("shm_size: %ld\n", buf.shm_segsz);

    //附加
    void* lp = shmat(shmid, NULL, 0);
    if(!lp)
    {
        perror("shmat");
        return 0;
    }

    while(1)
    {
        printf("readshm read [%s]\n", (char*)lp);
        sleep(1);
    }

    shmdt(lp);
    //销毁
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}