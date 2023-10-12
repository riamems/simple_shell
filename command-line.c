#include "shell.h"

extern int setenv_cmd(const char *variable, const char *value);
extern int unsetenv_cmd(const char *variable);

#define MAX_ARGS 64
#define MAX_INPUT_SIZE 1024

/**
 * tokenize_command - Tokenize a command string into args
 * @command: The command string to be tokenized
 * @args: Array to store
 */
void tokenize_command(char *command, char *args[])
{
char *token;
int j = 0;

token = strtok(command, " ");

while (token != NULL)
{
args[j++] = token;
token = strtok(NULL, " ");
}
args[j] = NULL;
}

/**
 * execute_child - Execute the child process
 * @args: Array of arguments for the command
 */
void execute_child(char *args[])
{
char **child_env = environ;
setenv("CUSTOM_ENV_VAR", "custom_value", 1);

if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}

/**
 * execute_single_command - Execute a single command
 * @command: Command to be executed
 */
void execute_single_command(char *command)
{
char *args[MAX_ARGS];
int status;

pid_t pid = fork();

tokenize_command(command, args);

if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
execute_child(args);
}
else
{
waitpid(pid, &status, 0);
if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);

if (exit_status != 0)
{
fprintf(stderr, "custom_shell: %s: Exit status %d\n", args[0], exit_status);
}
}
}
}

/**
 * executeCommand - Execute multiple commands separated by a newline
 * @command: Commands to be executed
 */
void executeCommand(char *command)
{
char *commands[MAX_ARGS];
char *token;
int a = 0;
int b = 0;

char command_copy[MAX_INPUT_SIZE];

strncpy(command_copy, command, sizeof(command_copy));
command_copy[sizeof(command_copy) - 1] = '\0';

token = strtok(command_copy, "\n");
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
execute_single_command(commands[j]);
}
}
