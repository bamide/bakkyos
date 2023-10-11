#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "main.h" 

/*PROTOTYPES*/ 
char *get_location(char *command);
void execmd(char **argv);
void current_env(char *const envn[]);
int hsh_cd(char **args);
char *_getenv(const char *name, char **envp);
int launch_child(char **args, char **directories);

/* GLOBAL VAR*/
extern char **environ;

#endif 
