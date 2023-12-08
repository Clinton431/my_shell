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
}

int starting_point_interactive()
{
        write (1, "$ ", 2);
}