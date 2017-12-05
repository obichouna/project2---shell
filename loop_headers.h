#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MEM_ERR 42
#define NO_ARGS 7
#define USER_EXIT 0

void ozone_prompt();

char * ozone_read();

char ** ozone_parse(char * line, char * arg);

int ozone_functions(char ** args);
