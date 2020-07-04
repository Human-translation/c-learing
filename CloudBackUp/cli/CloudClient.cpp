#include "CloudClient.hpp"



#define DATA_FILE "./list.backup"
#define LISTEN_PATH "./backup/"
#define SERVER_IP "106.12.220.112"
#define SERVER_PORT 9000


int main()
{
	CloudClient client(LISTEN_PATH, DATA_FILE, SERVER_IP, SERVER_PORT);
	client.Start();
	return 0;
}