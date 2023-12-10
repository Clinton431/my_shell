#include "shell.h"

/**
 * main - entry point to shell
 * @ac : arguments to shell
 * @**args : arguments to shell
 * @**env : environment
 * 
 * Return: 0 on success, -1 on failure
*/
int main(int ac, char** args, char** env)
{
        if (ac == 1)
                starting_point_interactive();
        /*else, parse the commands and execute as needed*/
}

int starting_point_interactive()
{
        write (1, "$ ", 2);
        _getline();
}

/**
 * getline- read a line into s, return length 
 * 
 *  
 */
int _getline() /*Chose _funcName to separate from internal*/
{
        /*Convert to our own later*/
        char *linepointer;
        linepointer = malloc(sizeof(char) * MAXSIZE);
        ssize_t buffer_len = MAXSIZE;

        getline(&linepointer, &buffer_len, stdin);
        printf("%s\n", linepointer);

        /*strtok and other functions here*/
        
        starting_point_interactive();
}
 