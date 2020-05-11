#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    //1
    int fd[2];
    int ret = pipe(fd);
    if(ret != 0)
    {
        printf("create pipe failed\n");
        return 0;
    }

    //取当前文件描述符的属性，通过返回值返回回来
    int flags = fcntl(fd[0], F_GETFL, 0);
    //给返回的文件描述符的属性加上非阻塞属性
    flags |= O_NONBLOCK;
    //给当前的文件描述符设置属性
    fcntl(fd[0], F_SETFL, flags);
    //fd[1] 写端
    //fd[0] 读端

    //创建进程
    ret = fork();
    if(ret < 0)
    {
        perror("fork");
        return 0;
    }
    else if(ret == 0)
    {

        //close(fd[1]);
        //close(fd[0]);
        //子进程
//        int count = 0;
//        while(1)
//        {
//            printf("write count [%d]\n", count);
//            int ret = write(fd[1], "1", 1);
//            if(ret == -1)
//            {
//                perror("write\n");
//                break;
//            }
//            count++;
//        }
//
        while(1)
        {
            sleep(1);
        }
    }
    else
    {
        //close(fd[0]);
        //close(fd[1]);
        //父进程
        sleep(1);
        char arr[1024] = {0};
        int ret = read(fd[0], arr, sizeof(arr) - 1);
        printf("ret = %d\n", ret);
        if(ret == -1)
        {
            perror("read");
        }
        printf("i am father fd[0] read [%s]\n", arr);
        memset(arr, '0', 1024);
        //是否是把数据取走了
        //read 在这边等待，阻塞
        //由于管道当中的数据已经被取走了，加上管道的读端是一个文件描述符，文件描述符的默认属性是阻塞的，也就是讲，当没有数据的时候，就阻塞等待数据的到来
        //read(fd[0], arr, sizeof(arr) - 1);
        //printf("i am father1 fd[0] read [%s]\n", arr);
        while(1)
        {
            sleep(1);
        }
    }
    

    return 0;
}