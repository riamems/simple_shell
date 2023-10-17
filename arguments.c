#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_ARGS 64
#define MAX_INPUT_SIZE 1024
/**
 * tokenizecommand - Tokenize a command string into args
 * @command: The command string to be tokenized
 * @args: Array to store
 */
void tokenizecommand(char *command, char *args[])
{
char *token;
int i = 0;

token = strtok(command, " ");

while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
}

/**
 * executechild - Execute the child process
 * @args: Array of arguments for the command
 */
void executechild(char *args[])
{
if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
/**
 * execute_command - Execute multiple commands separated by a newline
 * @command: Commands to be executed
 */
void execute_command(char *command)
{
char *commands[MAX_ARGS];
char *token;
int a = 0;
int b;
char cmd_copy[MAX_INPUT_SIZE];

strncpy(cmd_copy, command, sizeof(cmd_copy));
cmd_copy[sizeof(cmd_copy) - 1] = '\0';

token = strtok(cmd_copy, "\n");
while (token != NULL)
{
if (strlen(token) > 0)
{
commands[a++] = token;
}
token = strtok(NULL, "\n");
}
commands[a] = NULL;

for (b = 0; b < a; b++)
{
char *args[MAX_ARGS];
tokenizecommand(commands[b], args);
executechild(args);
}
}
