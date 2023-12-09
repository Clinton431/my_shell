#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int get_max_process_id();
int _atoi(char *s[]);

/**
 * main - print process id
 * 
 * Return: 0 Always
*/
int main()
{
        pid_t pid;
        pid_t ppid;

        pid = getpid();
        ppid = getppid();        

        printf("Process id for self: %d\n", pid);
        printf("Parent PPID: %d\n", ppid);
        printf("Max process id size = %d\n", get_max_process_id());

}

/**
 * get_max_process_id - returns the max process value a pid_t can take
 * 
 * Return: process id size on success, -1 on failure
*/
int get_max_process_id()
{
        FILE *fp;
        char pid_val[1000];
        char test_pid[12];
        char c;
        int i = 0;

        fp = fopen("/proc/sys/kernel/pid_max", "r");

        while ((c = getc(fp)) != EOF)
        {
                pid_val[i] = c;
                i++;
        }
        pid_val[++i] = '\0';

        int max_process_val = _atoi(pid_val);

        return max_process_val;

}

/** 
 * _atoi: convert s to integer 
 * 
 * Return: integer value
*/
 int _atoi(char *s[])
 {
        int i;
        int n;
        
        n = 0;
        for (i = 0; s[i] >= '0' && s[i] <= '9' && s[i] != '\0'; ++i)
                n = 10 * n + (s[i] - '0'); /*multiply by increments of ten to
                                             produce a correct value: i.e 10,
                                             110, 1110.. */   
        return n;
 } 