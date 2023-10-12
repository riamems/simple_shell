#include "shell.h"

/**
 * executeCommand - Execute a command with arguments
 * @command: The command to be executed
 */
void executeCommand(char *command) 
{

char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");
int found = 0;

while (dir != NULL) 
{
char full_path[1024];
snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);

if (access(full_path, X_OK) == 0) 
{
found = 1;
pid_t pid = fork();
if (pid == -1) 
{
perror("fork");
exit(EXIT_FAILURE);
} 
else if (pid == 0) 
{
char *args[] = {full_path, NULL};
execve(full_path, args, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else 
{

 int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0) 
{
fprintf(stderr, "custom_shell: %s: 
Exit status %d\n", command, WEXITSTATUS(status));
}
break;  
}
}
dir = strtok(NULL, ":");
}

free(path_copy);

if (!found) 
{
fprintf(stderr, "custom_shell: %s: 
Command not found in PATH\n", command);
}
}
