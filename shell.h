#ifndef SHELL_H
#define SHELL_H

extern char **environ;
int setenv_cmd(const char *variable, const char *value);
int unsetenv_cmd(const char *variable);
void tokenize_command(char *command, char *args[]);
void execute_child(char *args[]);
void execute_single_command(char *command);
void executeCommand(char *command);
void tokenizecommand(char *command, char *args[]);
void executechild(char *args[]);
void execute_command(char *command);
void executeCommandWithPath(char *command,
		char *const args[], char *const environ[]);
void exit_shell(void);
void handleEnv(void);


#endif
