#include "tcpsvr.hpp"
#include <sstream>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("./svr [ip] [port]\n");
        return 0;
    }

    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    TcpSvr ts;
    if(!ts.CreateSock())
    {
        return 0;
    }

    if(!ts.Bind(ip, port))
    {
        return 0;
    }

    if(!ts.Listen())
    {
        return 0;
    }
    TcpSvr peerts;
    struct sockaddr_in peeraddr;

    while(1)
    {
        if(!ts.Accept(peerts, &peeraddr))
        {
            return 0;
        }
        printf("svr have a new connect, ip:port --> %s:%d\n", 
                inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        std::string buf;
        peerts.Recv(buf);
        printf("Chrome Send Data : %s\n", buf.c_str());

        //正文数据
        //std::string body = "<html><h1>hello world</h1></html>";
        ////C风格组织
        //char arraybuf[10240] = {0};
        //sprintf(arraybuf, "%s %s %s\r\nContent-Length: %lu\r\nContent-Type: %s\r\n\r\n","HTTP/1.1", "200", "OK", body.size(), "text/html");
        //std::string header;
        //header.assign(arraybuf, strlen(arraybuf));
        //C++风格组织
        
        //std::string body = "<html><h1>hello world</h1></html>";
        //std::stringstream ss;
        //ss << "HTTP/1.1 200 OK\r\n";
        //ss << "Content-Type: text/html\r\n";
        //ss << "Content-Length: " << body.size() << "\r\n";
        //ss << "\r\n";
        //std::string header = ss.str();

        //std::string body = "<html><h1>hello world</h1></html>";
        //std::stringstream ss;
        //ss << "HTTP/1.1 302 Found\r\n";
        //ss << "Content-Type: text/html\r\n";
        //ss << "Content-Length: " << body.size() << "\r\n";
        //ss << "Location: https://www.baidu.com\r\n";
        //ss << "\r\n";
        //std::string header = ss.str();

        //std::string body = "<html><h1>hello world</h1></html>";
        //std::stringstream ss;
        //ss << "HTTP/1.1 404 Page Not Found\r\n";
        //ss << "Content-Type: text/html\r\n";
        //ss << "Content-Length: " << body.size() << "\r\n";
        //ss << "\r\n";
        //std::string header = ss.str();

        std::string body = "<html><h1>hello world</h1></html>";
        std::stringstream ss;
        ss << "HTTP/1.1 502 Bad Gateway\r\n";
        ss << "Content-Type: text/html\r\n";
        ss << "Content-Length: " << body.size() << "\r\n";
        ss << "\r\n";
        std::string header = ss.str();

        peerts.Send(header);
        peerts.Send(body);
        peerts.Close();
    }

    //peerts.Close();
    ts.Close();
    return 0;
}