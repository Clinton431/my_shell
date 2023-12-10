#include "shell.h"

/**
  * print_longest_line - print the longest input line
  *  
  * Return: 0 on success
  */
int print_longest_line()
{
        int len; /* current line length */
        int max; /* maximum length seen so far */
        char line[MAXLINE]; /* current input line */
        char longest[MAXLINE]; /* longest line saved here */

        max = 0;

        while ((len = getline(line, MAXLINE)) > 0)
        {
                if (len > max)
                {
                        max = len;
                        copy(longest, line);
                }
        }
        if (max > 0) /* there was a line */
        printf("%s", longest);
        return 0;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
} 