#ifndef SHELL_H

#define SHELL_H

/* Global variable */
extern char **environ;

/**
 * struct builtin_op - Struct builtin_op
 *
 * @name: name of builtin command
 * @f: function of builtin
 */
typedef struct builtin_op
{
	char *name;
	int (*f)(char **args);
} builtin;


/* Libraries */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


/* Builtin Command Functions */
int shell_exit(char **);


/* String Functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int n_toks(char *str, char *delim);
int _strlen(char *);
int _strcmp(char *, char *);


/** Print Functions */
void _puts(char *);
int _putchar(char);


/* Costumized Functions */
char **make_args(char *str);
char *find_path(char *argv);
void free_args(char **);
char **check_path(char **);
char *path_concat(char *, char *);
int check_builtin(char **);

#endif /* SHELL_H */
