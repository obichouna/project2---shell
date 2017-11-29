#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "loop_headers.h"

//Ozone_read: Reads from stdin

char * ozone_read(){
  //Allocates memory for reading
  char * buffer = (char *)calloc(256, sizeof(char));
  if(!buffer){
    //Checks to see if buffer really allocated
    printf("Ozone: > Allocation Error");
    exit(MEM_ERR);
  }
  fgets(buffer, 256, stdin);
  return buffer;

}

//Ozone_parse: Takes a line and parses it by " "

char ** ozone_parse(char * line){
  
  char **args = (char**)calloc(256, sizeof(char *));
  int i = 0;
  while(line){
    args[i++]= strsep(&line, " ");
  }
  args[i] = NULL;
  
  return args;



}
