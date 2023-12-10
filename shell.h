#ifndef SHELL
#define SHELL

/*Standard libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
/* #include <sys/wait.h> */
#include <sys/stat.h>
/* #include <wait.h> */
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>

/*#defines*/
#define MAXSIZE 1024 /* maximum input line length */

/*Function Prototypes*/
int starting_point_interactive(void);
int getline(char line[], int maxline);
void copy(char to[], char from[]);


/* memory_functions2.c */
int bfree(void **);

/* buildin.c */
void _myExit(shell_t *);
void _printEnv(shell_t *);

#endif
