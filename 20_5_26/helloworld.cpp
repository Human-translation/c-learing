#include "tcpsvr.hpp"
#include <signal.h>
#include <sys/wait.h>

void sigcb(int signo)
{
	//等待子进程
	(void)signo;
	while (1)
	{
		waitpid(-1, NULL, WNOHANG);
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("./tcpprocess [ip] [port]\n");
		return 0;
	}

	signal(SIGCHLD, sigcb);
	std::string ip = argv[1];
	uint16_t port = atoi(argv[2]);
	TcpSvr ts;
	if (!ts.CreateSock())
	{
		return 0;
	}

	if (!ts.Bind(ip, port))
	{
		return 0;
	}

	if (!ts.Listen(5))
	{
		return 0;
	}

	while (1)
	{
		TcpSvr peerts;
		struct sockaddr_in peeraddr;
		if (!ts.Accept(peerts, &peeraddr))
		{
			continue;
		}
		printf("Have a new connection %s:%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

		int pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			//child
			while (1)
			{
				std::string buf;
				peerts.Recv(buf);
				printf("client say:%s\n", buf.c_str());

				printf("svr say:");
				fflush(stdout);
				std::cin >> buf;

				peerts.Send(buf);
			}
			peerts.Close();
			exit(1);
		}
		else
		{
			//father
			peerts.Close();
		}
	}
	return 0;
}