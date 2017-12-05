#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "loop_headers.h"

void ozone(){
  //The main loop - Reads from stdin, parses, and runs arguments
  char * line;
  char ** args;
  int run = 1;
  while(run){
    printf("ozone: >");
    line = ozone_read();
    args = ozone_parse(line, ";");
    run = ozone_functions(args);
    free(line);
    free(args);
  }
}

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

char ** ozone_parse(char * line, char * arg){

  char **args = (char**)calloc(256, sizeof(char *));
  int i = 0;
  while(line){
    args[i++]= strsep(&line, arg);
  }
  args[i] = NULL;

  return args;


}

int main(){


  ozone();

  return 0;

}
