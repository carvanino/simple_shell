#ifndef SHELL_H

#define SHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

/* String Functions */
char *_strdup(char *str);


/* Costumized Functions */
char **make_args(char *str);

#endif
