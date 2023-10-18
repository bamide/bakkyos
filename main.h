#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include "main.h" 

/*PROTOTYPES*/ 
char *get_location(char *command);
void execmd(char **argv);
void current_env(char *const envn[]);
int hsh_cd(char **args);
char *_getenv(const char *name, char **envp);
int launch_child(char **args, char **directories);
int new_process(char **args);
int own_cd(char **args);
int own_env(char **args);
void print_env(char **env);
void handle_exit(char *input);
void handle_cd(char **args, int num_args);
void print_prompt(void);
char *read_input(void);
void execute_command(char *input, char **env);
int tokenize_input(char *input, char *args[]);
int handle_builtin_commands(char **args, int num_args, char *input, char **env);
void call_and_execute(char *args[]);

/* GLOBAL VAR*/
extern char **environ;

#endif 
