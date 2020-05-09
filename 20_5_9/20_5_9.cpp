#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
//#include<sys/wait.h>
char g_Command[1024];
int GetCommand()
{
    memset(g_Command,'\0',sizeof(g_Command));
    printf("[minishell@localhost]$ ");
    fflush(stdout);
    if(!fgets(g_Command,sizeof(g_Command)-1,stdin))
    {
        printf("fgets error\n");
        return -1;
    }
    printf("g_Command = [%s]\n",g_Command);
    return 0;
}

int ExecCommand(char* argv[])
{
    if(argv[0] == NULL)
    {
        printf("ExecCommand error\n");
        return -1;
    }
    pid_t pid;// = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        execvp(argv[0],argv);
        exit(0);
    }
    else
    {
        //waitpid(pid,NULL,0);
    }
    return 0;
}

int DealCommand(char* command)
{
    if(!command || *command == '\0')
    {
        printf("command error\n");
        return -1;
    }
    int argc = 0;
    char* argv[32] = {0};
    while(*command)
    {
        if(!isspace(*command))
        {
            argv[argc] = command;
            argc++;
            while(!isspace(*command) && (*command != '\0'))
            {
                command++;
            }
            *command = '\0';
        }
        command++;
    }
    argv[argc] = NULL;
    for(int i=0;i<argc;i++)
    {
        printf("[%d][%s]\n",i,argv[i]);
    }

    ExecCommand(argv);
    return 0;
}

int main()
{
    while(1)
    {
        if(GetCommand() == -1)
        {
            continue;
        }
        DealCommand(g_Command);
    }
    return 0;
}