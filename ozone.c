#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include "loop_headers.h"

/*
I know this is bad practice, but I could not remove the
Implicit declaration error
*/
char * strsep (char **string_ptr, const char *delimiter);

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ozone();
use: The main loop, runs all the other functions

args: void

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
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

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
char * ozone_read();
use: Reads from stdin

args: void

returns: char * (String)
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

char * ozone_read(){
  //Allocates memory for reading
  char * buffer = (char *)calloc(256, sizeof(char));
  if(!buffer){
    //Checks to see if buffer really allocated
    printf("Ozone: > Allocation Error\n");
    exit(MEM_ERR);
  }
  fgets(buffer, 256, stdin);
  buffer[strlen(buffer) - 1] = 0;
  return buffer;

}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
char ** ozone_parse(char * line, char * arg);
use: Parses a string by a given argument

args: char * line: String that is being parsed
      char * arg: The argument that a string is parsed by

returns: Pointer to pointer of chars (String) - 2D array of strings
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

char ** ozone_parse(char * line, char * arg){

  char **args = (char**)calloc(64, sizeof(char *));
  int i = 0;
  while(line){
    args[i++] = strsep(&line, arg);
  }
  args[i] = NULL;

  return args;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ozone_prompt();
use: prints the shell prompt with current working directory

args: void

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void ozone_prompt(){
  char cwd[256];
  getcwd(cwd, sizeof(cwd));
  fprintf(stdout, "Ozone:%s$ ", cwd);
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void signhandler(int signo);
At the moment not working properly - keep getting error about int sigaddint
use: Catches the signal interrupted from the user and closes the program

args: int signo: the interrupted signal

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

// static void sighandler(int signo){
//   if(signo == SIGINT){
//     printf("Program interrupted\n");
//     exit(0);
//   }
// }


/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
int ozone_functions(char ** args);
use: Forks a child process, and runs the commands given by the user

args: char ** args: 2D array of strings that
                    represent the arguments of the commands

returns: int - used for the run status
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

int ozone_functions(char ** args){
  if(!args[0]){
    return NO_ARGS;
  }
  int x = 0;
  while(args[x]){
    char ** func = ozone_parse(args[x], " ");
    //Credit to Md Abedin and Yiduo Ke for helping me with cd and exit
    if (!strncmp("exit", func[0], 4)){
      exit(USER_EXIT);
    }else if (!strncmp("cd", func[0], 2)){
      chdir(func[1]);
    }else{
    int parent = fork();
    if (!parent){
      if(execvp(func[0], func) == -1){
        printf("error: incorrect input\n");
        free(func);
        exit(NO_ARGS);
      }else{
        execvp(func[0], func);
        //execvp(args[0], args);
        exit(0);
      }
    }else{
      int status;
      wait(&status);
    }
  }
    x++;
    free(func);
}
  return 1;
}

int main(){


  ozone();

  return 0;

}
