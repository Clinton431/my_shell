#include <fcntl.h>
#include <stdio.h>
#define MAXSIZE 1024

/*This is template code - will not really be used in the system*/
int open_file(char *filePath, char *mode)
{
        FILE *input_fd;
        /* char filePath[MAXSIZE]; - can't figure why assignment's a bother*/

        input_fd =open("/proc/sys/kernel/pid_max", O_RDONLY);

        if (input_fd == -1)
                perror("open failed");
        
}

int read_file(char *filePath)
{

}




