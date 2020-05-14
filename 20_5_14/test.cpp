#include <stdio.h>
#include <unistd.h>
#include <signal.h>
struct sigaction oldact;

//当前的函数地址会传递到内核当中去，这个函数调用也是内核发起的，但是代码在用户空间，所以执行的时候是在用户空间进行执行，用户态进行执行
void sigcallback(int signum)
{
	printf("signum-%d\n", signum);
	sigaction(SIGINT, &oldact, NULL);
}

int main()
{
	//int sigaction(int signum, const struct sigaction *act,
	//                     struct sigaction *oldact);
	//是一个入参
	struct sigaction newact;
	newact.sa_handler = sigcallback;
	newact.sa_flags = 0;
	//清空sigset_t位图当中的bit位，将bit位全部置位0
	sigemptyset(&newact.sa_mask);
	//sigaction内部进行填充信息，是一个出参

	sigaction(SIGINT, &newact, &oldact);

	while (1)
	{
		printf("61-linux\n");
		sleep(2);
	}
	return 0;
}
