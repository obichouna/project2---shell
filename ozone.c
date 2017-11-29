#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ozone(){
  //The main loop - Reads from stdin, parses, and runs arguments
  printf("ozone: >");
  char * line;
  char * args;
  int run = 1;
  while(run){
    printf("ozone: >");
    line = ozone_read();
    args = ozone_parse(line);
    run = ozone_functions(args);
    free(line);
    free(args);
  }
}


int main(){


  ozone();

  return 0;

}
