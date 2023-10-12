#include "shell.h"


/**
 * handleExit - Handle the "exit" built-in command to exit the shell
 */
void handleExit(void)
{
printf("Exiting the custom shell.\n");
exit(EXIT_SUCCESS);
}
