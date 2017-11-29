#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MEM_ERR 42

char * ozone_read();

char ** ozone_parse(char * line);

int ozone_function(char * args);
