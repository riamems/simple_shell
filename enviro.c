#include <stdio.h>
#include "shell.h"
/**
 * handleEnv - Handle the "env" built-in command
 * to print the current environment.
 */
void handleEnv(void)
{
char **env = environ;
while (*env)
{
printf("%s\n", *env);
env++;
}
}
