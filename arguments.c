#include "shell.h"

/**
 * _mycustom - Custom command
 * @info: Structure containing potential arguments.
 * Return: Returns an exit status if a condition is met.
 */
int _mycustom(info_t *info)
{
if (infO->argc >= 2)
{
if (strcmp(info->argv[1], "hello") == 0)
{
_puts("Hello, world!\n");
}
else if (strcmp(info->argv[1], "greet") == 0)
{
if (info->argc >= 3)
{
_puts("Hello, ");
_puts(info->argv[2]);
_puts("!\n");
}
else
{
_puts("Usage: greet <name>\n");
}
} 
else
{
_puts("Unknown command: ");
_puts(info->argv[1]);
_puts("\n");
}
} 
else
{
_puts("Usage: mycustom <command> [options]\n");
}
return (0);
}

/**
 * _mycd - Change the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
char *dir, buffer[1024];
int chdir_ret;
char *home = _getenv(info, "HOME=");
char *oldpwd = _getenv(info, "OLDPWD=");

if (!info->argv[1])
{
dir = home ? home : _getenv(info, "PWD=");
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (oldpwd)
{
_puts(oldpwd);
_putchar('\n');
dir = oldpwd;
}
else
{
_puts("No previous directory stored.\n");
return (1);
}
}
else
{
dir = info->argv[1]
}

chdir_ret = chdir(dir);

if (chdir_ret == -1)
{
_puts("Can't change to directory: ");
_puts(dir);
_puts("\n");
} 
else
{
_setenv(info, "OLDPWD", 
_getenv(info, "PWD="));
_setenv(info, "PWD", 
getcwd(buffer, 1024));
}

return (0);
}
