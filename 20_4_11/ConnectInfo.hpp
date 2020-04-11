#pragma once
#include <iostream>


#define REGISTER 0
#define LOGIN 1
#define LOGINOUT 2

#define MESSAGE_MAX_SIZE 1024

struct RegInfo
{
    char NickName_[15];
    char School_[20];
    char Passwd_[20];
};

struct LoginInfo
{
    uint32_t UserId_;
    char Passwd_[20];
};

enmu USerStatus
{
    REGFAILED = 0,
    REGISTERED,
    LOGINFAILED,
    LOGINED
};

struct ReplyInfo
{
    int Status;
    uint32_t UserId_;
};

class LoginConnect
{
    public:
        LoginConnect(int Sock,void* Server)
        {
            Sock_ = Sock;
            Server_ = Server;
        }

        int GetTcpSock()
        {
            return Sock_;
        }

        void* GetServer()
        {
            return Server_;
        }
    private:
        int Sock_;

        void* Server_;
};