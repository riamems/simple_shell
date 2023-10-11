#ifndef SHELL_H
#define SHELL_H

typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

typedef struct info {
    char **argv;
    int argc;
    list_t *env;
} info_t;


int _myexit(info_t *info);
int _mycustom(info_t *info);
int _mycd(info_t *info);
int is_executable(info_t *info, char *file_path);
char *extract_substring(char *source_str, 
int start_idx, int end_idx);
char *find_executable_in_path(info_t *info,
char *path_var, char *command);
int myenv(info_t *info);
char *getEnvironmentVariable(info_t *info, const char *name);
int mysetenv(info_t *info);
int myunsetenv(info_t *info);
int populateEnvironmentList(info_t *info);
#endif
