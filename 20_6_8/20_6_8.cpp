#include "tcpsvr.hpp"
#include "SelectSvr.hpp"

#define CHECK_RET(p) if(p != true){return -1;}

int main()
{
    TcpSvr listen_ts;
    CHECK_RET(listen_ts.CreateSock());
    CHECK_RET(listen_ts.Bind("172.16.99.129", 19999));
    CHECK_RET(listen_ts.Listen());

    SelectSvr ss;
    ss.AddFd(listen_ts.Getfd());

    while(1)
    {
        std::vector<TcpSvr> out;
        if(!ss.SelectWait(&out))
        {
            continue;
        }

        for(size_t i = 0; i < out.size(); i++)
        {
            if(listen_ts.Getfd() == out[i].Getfd())
            {
                //1.侦听套接字的
                 TcpSvr tmp;
                 struct sockaddr_in peeraddr;
                 listen_ts.Accept(tmp, &peeraddr);
                 printf("have a new connection : %s-%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

                 //将连接的套接字描述符添加到可读事件集合当中去
                 ss.AddFd(tmp.Getfd());
            }
            else
            {
                printf("11111\n");
                //2.非侦听套接字的，
                //对于TCP服务器而言，剩下的就是为连接创建的套接字描述符
                std::string buf;
                out[i].Recv(buf);
                printf("client send data is \"%s\"\n", buf.c_str());
            }
        }
    }
    return 0;
}