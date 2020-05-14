#include <stdio.h>
#include <unistd.h>
#include <signal.h>
struct sigaction oldact;

//��ǰ�ĺ�����ַ�ᴫ�ݵ��ں˵���ȥ�������������Ҳ���ں˷���ģ����Ǵ������û��ռ䣬����ִ�е�ʱ�������û��ռ����ִ�У��û�̬����ִ��
void sigcallback(int signum)
{
	printf("signum-%d\n", signum);
	sigaction(SIGINT, &oldact, NULL);
}

int main()
{
	//int sigaction(int signum, const struct sigaction *act,
	//                     struct sigaction *oldact);
	//��һ�����
	struct sigaction newact;
	newact.sa_handler = sigcallback;
	newact.sa_flags = 0;
	//���sigset_tλͼ���е�bitλ����bitλȫ����λ0
	sigemptyset(&newact.sa_mask);
	//sigaction�ڲ����������Ϣ����һ������

	sigaction(SIGINT, &newact, &oldact);

	while (1)
	{
		printf("61-linux\n");
		sleep(2);
	}
	return 0;
}
