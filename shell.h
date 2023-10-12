#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define MAX_INPUT_SIZE 1024
# define MAX_ARGS 64

void tokenize_command(char *command, char *args[]);
void execute_child(char *args[], char *env_vars[]);
void execute_single_command(char *command, char *env_vars[]);
void executeCommand(char *command, char *env_vars[]);
void handleExit(void);
#endif
