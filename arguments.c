/**
 * _mycustom - custom command
 * @info: Structure containing potential arguments.
 * Return: Returns an exit status if a condition is met.
 */
int _mycustom(info_t *info)
{
    if (info->argv[1])
    {
        if (strcmp(info->argv[1], "hello") == 0)
        {
            _puts("Hello, world!\n");
        }
        else if (strcmp(info->argv[1], "greet") == 0)
        {
            if (info->argv[2])
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
        return 0;
    }
    return 0;
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = /* TODO: what should this be? */
                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = /* TODO: what should this be? */
            chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("help call works. Function not yet implemented \n");
    if (0)
        _puts(*arg_array); /* temp att_unused workaround */
    return (0);
}
