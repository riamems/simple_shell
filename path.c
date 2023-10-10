#include "shell.h"

/**
 * is_executable - determines if a file is an executable command
 * @info: the info struct
 * @file_path: path to the file
 *
 * Return: 1 if true (executable), 0 otherwise
 */
int is_executable(info_t *info, char *file_path)
{
    struct stat st;

    (void)info;
    if (!file_path || stat(file_path, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * extract_substring - duplicates characters from a string within a range
 * @source_str: the source string
 * @start_idx: starting index
 * @end_idx: ending index
 *
 * Return: pointer to the duplicated substring
 */
char *extract_substring(char *source_str, int start_idx, int end_idx)
{
    static char buffer[1024];
    int i = 0, k = 0;

    for (k = 0, i = start_idx; i < end_idx; i++)
    {
        if (source_str[i] != ':')
        {
            buffer[k++] = source_str[i];
        }
    }
    buffer[k] = '\0';
    return (buffer);
}

/**
 * find_executable_in_path - finds an executable in the PATH variable
 * @info: the info struct
 * @path_var: the PATH variable string
 * @command: the command to find
 *
 * Return: full path to the command if found, or NULL if not found
 */
char *find_executable_in_path(info_t *info, char *path_var, char *command)
{
    int i = 0, current_pos = 0;
    char *full_path;

    if (!path_var)
        return (NULL);
    if ((_strlen(command) > 2) && starts_with(command, "./"))
    {
        if (is_executable(info, command))
        {
            return (command);
        }
    }
    while (1)
    {
        if (!path_var[i] || path_var[i] == ':')
        {
            full_path = extract_substring(path_var, current_pos, i);
            if (!*full_path)
            {
                _strcat(full_path, command);
            }
            else
            {
                _strcat(full_path, "/");
                _strcat(full_path, command);
            }
            if (is_executable(info, full_path))
            {
                return (full_path);
            }
            if (!path_var[i])
            {
                break;
            }
            current_pos = i;
        }
        i++;
    }
    return (NULL);
}
