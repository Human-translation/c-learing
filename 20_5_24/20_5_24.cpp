#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

class UdpSvr
{
    public:
        UdpSvr()
        {
            Sock_ = -1;
        }

        ~UdpSvr()
        {

        }

        bool CreateSock()
        {
            Sock_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            if(Sock_ < 0)
            {
                perror("socket");
                return false;
            }
            return true;
        }

        bool Bind(std::string& ip, uint16_t port)
        {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());

            int ret = bind(Sock_, (struct sockaddr*)&addr, sizeof(addr));
            if(ret < 0)
            {
                perror("bind");
                return false;
            }
            return true;
        }

        bool Send(std::string& buf, struct sockaddr_in* destaddr)
        {
            int SendSize = sendto(Sock_, buf.c_str(), buf.size(), 0, (struct sockaddr*)destaddr, sizeof(struct sockaddr_in));
            if(SendSize < 0)
            {
                perror("sendto");
                return false;
            }
            return true;
        }

        bool Recv(std::string& buf, struct sockaddr_in* srcaddr)
        {
            char tmp[1024] = {0};

            socklen_t socklen = sizeof(struct sockaddr_in);
            int RecvSize = recvfrom(Sock_, tmp, sizeof(tmp) - 1, 0, (struct sockaddr*)srcaddr, &socklen);
            if(RecvSize < 0)
            {
                perror("recvfrom");
                return false;
            }
            buf.assign(tmp, RecvSize);
            return true;
        }

        void Close()
        {
            close(Sock_);
            Sock_ = -1;
        }
    private:
        int Sock_;
};