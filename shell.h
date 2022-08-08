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


int _putchar(char *c);
char *find_path(char **argv);

#endif /* SHELL_H */
