#include "myShell.h"

void forking_executing(char **argInput)
{
        pid_t child_process, usrCmd_process;
        extern char **enviroment;

        if (_stringChr(argInput[0], '/') != NULL)
        {
                child_process = fork();
                if (child_process == -1)
                {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }

                if (child_process == 0)
                {
                        if (execve(argInput[0], argInput, enviroment) == -1)
                        {
                                printf("No such file or directory\n");
                                exit(EXIT_FAILURE);
                        }
                        free(argInput);
                }
                else
                {
                        wait_child(child_process, argInput);
                }
        }
        else
        {
                printf("Command not found\n");
        }
}