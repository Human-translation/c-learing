#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    //open
    //flags
    //O_RDONLY 以只读方式打开
    //O_WRONLY 以只写方式打开
    //O_RDWR 以读写方式打开 ----当打开文件的时候，必须选择其中的一个
    //
    //O_CREAT 如果打开的这个文件不存在则创建文件
    //O_TRUNC 打开文件之后，截断文件
    //O_APPEND : 以追加方式打开
    close(0);
    int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
    if(fd < 0)
    {
        perror("open");
        return 0;
    }
    //向文件当中去写
    //write
    //ssize_t write(int fd, const void *buf, size_t count);
    //fd : 文件描述符
    //buf: 我们要写的数据
    //count ：写到数据的大小是多少
    int ret = write(fd, "61-linux", 8);
    if(ret < 0)
    {
        perror("write");
        return 0;
    }

    lseek(fd, 2, SEEK_SET);

    //ssize_t read(int fd, void *buf, size_t count);
    //fd : 要从fd当中读
    //buf：读到哪里去
    //count : 读多少字节，一定要预留\0的位置
    char buf[1024] = {0};
    ret = read(fd, buf, sizeof(buf) - 1);
    if(ret < 0)
    {
        perror("read");
        return 0;
    }
    printf("buf = [%s]\n", buf);
    printf("fd = [%d]\n", fd);
    close(fd);
    return 0;
}