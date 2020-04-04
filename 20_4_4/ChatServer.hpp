#pragma once
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/type.h>
#include <unistd.h>
#include <pthread.h>
#include <string>
#include "MsgPool.hpp"
#include "LogSvr.hpp"
#define UDP_PORT 17777
#define THREAD_COUNT 2

class ChatServer
{
    public:
        ChatServer()
        {
            UdpSock_ = -1;
            UdpPort_ = UDP_PORT;
            MsgPool_ = NULL;
        }

        ~ChatServer()
        {
            if(MsgPool_)
            {
                delete MsgPool_;
                MsgPool_ = NULL;
            }
        }

        void InitServer()
        {
            UdpSock_ = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
            if(UdpSock_ < 0)
            {
                perror("socker");
                exit(1);
            }

            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(UdpPort_);
            add.sin_addr.s_addr = inet_addr("0.0.0.0");

            int ret = bind(UdpSock_,(struct sockaddr*)&addr,sizeof(addr));
            if(ret < 0)
            {
                perror("bind addrinfo failed");
                exit(2);
            }

            MsgPool_ = new MsgPool();
            if(!MsgPool_)
            {
                perror("Create MsgPool failed");
                exit(3);
            }
        }

        void Start()
        {
                pthread_t tid;
                for(int i=0;i<THREAD_COUNT;i++)
                {
                    int ret = pthread_create(&tid,NULL,ProductMsgStart,(void*)this);
                    if(ret < 0)
                    {
                        perror("pthread_create new thread failed");
                        exit(4);
                    }

                    ret = pthread_create(&tid,NULL,ConsumeNsgStaet,(void*)this);
                    if(ret < 0)
                    {
                        perror("pthread_create new thread failed");
                        Log(FATAL,__FILE__,__LINE__,"pthread");
                        exit(4);
                    }
                }
        }

        static void* ProductMsgStart(void* arg)
        {
            pthread_detach(pthread_self());
            ChatServer* cs = (ChatServer*)arg;
            while(1)
            {
                cs->RecvMsg();
            }
            return NULL;
        }

        static void* ConsumeNsgStaet(void* arg)
        {
            pthread_detach(pthread_self());
            ChatServer* cs = (ChatServer*)arg;
            while(1)
            {
                cs->BroadcastMsg();
            }
            return NULL;
        }

    private:
        void RecvMsg()
        {
            char buf[10240] = {0};
            struct sockaddr_in cliaddr;
            socklen_t cliaddrlen = sizeof(struct sockaddr_in);
            int recvsize = recvfrom(UdpSock_,buf,sizeof(buf)-1,0,(struct sockaddr*)&cliaddr,&cliaddrlen);
            if(recvsize < 0)
            {
                perror("recvfrom msg failed");
            }
            else
            {
                std::string msg;
                msg.assign(buf,recvsize);
                MsgPool_->PushMsgToPool(msg);
            }
            
        }

        void BroadcastMsg()
        {
            //SendMsg();
            std::string msg;
            MsgPool_->PopMsgFromPool(&msg);

        }

        void SendMsg(const std::string& msg,struct sockaddr_in cliaddr,socklen_t& len)
        {
            size_t sendsize = sendto(UdpSock_,mas.c_str(),msg.size(),0,(struct sockaddr*)&cliaddr,len);
            if(sendsize < 0)
            {
                perror("sendto msg failed");
            }    
            else
            {
                
            }
            
        }

    private:
        int UdpSock_;
        int UdpPort_;

        MsgPool* MsgPool_;
};