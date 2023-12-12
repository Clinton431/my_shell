#include "shell.h"

/**
 * main - entry point for shell
 * 
 * Return: 0 on success
 */
int main(int ac, char **arg)
{
        /**
         * 1. Create (open) a log file
         * 2. Log (write) that the shell is running
         * 
         */

        if (ac == 1) /*If no arguments are not provided [interactive]*/
                prompt(); 
        else if (ac >= 2)
                handle_execution(arg);
     
        /*else to handle arguments [non-interactive] mode*/
}

/**
 * prompt -prompts the user to enter command
 * 
 * Return: 0 on success
 */
int prompt()
{
        char *prompt;
        char **arg = NULL;
        size_t count;
        ssize_t return_write;
        int return_handle_execution;

        prompt = "$ ";
        count = strlen(prompt);
        return_write = write(1, prompt, count);
        if (return_write == -1)
                perror("Error writing to stdinput");
        else if (return_write < (signed)count)
                perror("Warning: insufficient size");
        else
        {
                return_handle_execution = handle_execution(arg);
                if (return_handle_execution == -1)
                        perror("Error reading from stdin");
                else if (return_handle_execution == -2)
                        perror("Error in execution. See logs above");
        }
}

/**
 * handle_execution - Handles the execution of arguments
 * 
 * Return: 0 on error, 1 on exit command, calls prompt() on success
 */
int handle_execution(char **arg) /*Handle both interactive, non-interactive*/
{
        if (arg == NULL) /*Interactive mode execution*/
        {
                char *linePointer = NULL;
                char *linePointerCopy = NULL;
                char *token;
                int tokenLength;
                int token_count = 0;
                size_t n = MAXSIZE;
                size_t lineLength;
                ssize_t return_getline;
                int i = 0; /*Count in for loop*/

                (void)lineLength;

                linePointer = malloc(sizeof(char) * n);
                return_getline = getline(&linePointer, &n, stdin); /**
                                                                * Replace with
                                                                * get_line();
                                                                */
                if (return_getline == -1)
                        perror("Error reading line"); /*Replace internally*/

                /** (Debugger for echoing what the user has input)
                 * while (linePointer[i] != '\0')
                 *              i++;
                 * lineLength = i;
                 * write(1, linePointer, lineLength); - Debug succesful
                 */

                else if (return_getline == 0)
                {
                        linePointerCopy = malloc(sizeof(char)*return_getline);
                        if (linePointerCopy != NULL)
                        {
                                strcpy(linePointerCopy, linePointer);
                                token = str_tok(linePointerCopy, " ");

                                while (token != NULL)
                                {
                                        token_count++;
                                        token = str_tok(NULL, " ");
                                }
                                token_count++; /*holds the last token:'\0'*/
                                arg = malloc(sizeof(char) * token_count);
                                
                                token = str_tok(linePointer, " ");
                                for (i = 0; token!=NULL; i++)
                                {
                                        tokenLength = strlen(token);
                                        arg[i] = malloc(sizeof(char) * tokenLength); /*Strlen is another utility */
                                        strcpy(arg[i], token);

                                        token = str_tok(NULL, " ");

                                        for (i = 0; i<token_count-1; i++)
                                        {
                                                printf("%s\n", arg[i]);
                                        }
                                }
                                arg[i] = NULL; /*Terminates the args*/
                        }
                        else
                                perror("Error in memory creation (malloc):");
                }
                        prompt();
        }
        else if (arg != NULL) /*Non -interactive mode running*/
        {
                /*Call execve with the respective functions*/
        }
        return (0);
}

/**
 * str_tok - Converts an input string to array of tokens
 * 
 * Return: Pointer to array(char) [string] of tokens
 */
char *str_tok(char *string, const char * delimiter)
{
        char * pointer_location;
        char *return_token;

        (void)pointer_location;
        
        /**
         * Function's own code inside this comment
         * 
         */

        return_token = strtok(string, delimiter);
        return(return_token);
}


