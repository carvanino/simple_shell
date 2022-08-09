#ifndef SHELL_H

#define SHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;


/* String Functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int n_toks(char *str, char *delim);


/* Costumized Functions */
char **make_args(char *str);
char *find_path(char *argv);
void free_args(char **);

#endif /* SHELL_H */
