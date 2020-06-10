#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <string>

int main()
{
    int flag = fcntl(0, F_GETFL);
    fcntl(0, F_SETFL, flag | O_NONBLOCK);

    int epoll_fd = epoll_create(1);
    if(epoll_fd < 0)
    {
        perror("epoll_create");
        return 0;
    }

    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = 0;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &ev);

    while(1)
    {
        struct epoll_event evs[10];
        int ret = epoll_wait(epoll_fd, evs, 10, -1);
        if(ret < 0)
        {
            perror("epoll_wait");
            continue;
        }

        //遍历的时候，只是遍历事件结构数组当中的有效元素，所以有效元素的判断，从epoll_wait的返回值就可以知道了
        for(int i = 0; i < ret; i++)
        {
            if(evs[i].data.fd == 0)
            {
                std::string read_data;
                while(1)
                {
                    char buf[3] = {0};
                    ssize_t read_size = read(0, buf, sizeof(buf) - 1);
                    if(read_size < 0)
                    {
                        if(errno == EAGAIN || errno == EWOULDBLOCK)
                        {
                            //如果errno当中是EAGAIN 或者 EWOLDBLOCK的时候
                            //就认为数据读缓冲区当中没有数据了
                            goto myend;
                        }
                        perror("read");
                        return 0;
                    }

                    read_data += buf;

                    //判断是否读完了
                    if(read_size < (ssize_t)sizeof(buf) - 1)
                    {
myend:
                        printf("read data is %s\n", read_data.c_str());
                        break;
                    }
                }
            }
        }
    }
    return 0;
}