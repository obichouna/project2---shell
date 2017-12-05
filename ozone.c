#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include "loop_headers.h"

char * strsep (char **string_ptr, const char *delimiter);

void ozone(){
  //The main loop - Reads from stdin, parses, and runs arguments
  char * line;
  char ** args;
  int run = 1;
  while(run){
    //signal(SIGINT, sighandler);
    ozone_prompt();
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
  buffer[strlen(buffer) - 1] = 0;
  return buffer;

}

//Ozone_parse: Takes a line and parses it by " "

char ** ozone_parse(char * line, char * arg){

  char **args = (char**)calloc(64, sizeof(char *));
  int i = 0;
  while(line){
    args[i++] = strsep(&line, arg);
  }
  args[i] = NULL;

  return args;
}

void ozone_prompt(){
  char cwd[256];
  getcwd(cwd, sizeof(cwd));
  fprintf(stdout, "Ozone:%s$ ", cwd);
}

// static void sighandler(int signo){
//   if(signo == SIGINT){
//     printf("Program interrupted\n");
//     exit(0);
//   }
// }


int ozone_functions(char ** args){
  if(!args[0]){
    return NO_ARGS;
  }
  int x = 0;
  while(args[x]){
    char ** func = ozone_parse(args[x], " ");
    if (!strncmp("exit", func[0], 4)){
      exit(USER_EXIT);
    }else if (!strncmp("cd", func[0], 2)){
      chdir(func[1]);
    }else{
    int parent = fork();
    if (!parent){
      execvp(func[0], func);
      //execvp(args[0], args);
      exit(0);
    }else{
      int status;
      wait(&status);
    }
  }
    x++;
}
  return 1;
}

int main(){


  ozone();

  return 0;

}
