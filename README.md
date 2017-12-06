## Ozone: > The Ozone Shell (like the Ozone layer!)

It's a pun.

It's bad.

I'm sorry.


### What it does:
* Takes input from the user, reads it, parses it, and finally runs it!

### Note:
Separate commands with semicolons with no spaces:

  Ex) ls;echo hello


#### Bugs:
* Sighandler does not work properly, giving a SIGINT will close the entire shell

#### Functions:
```c
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ozone();
use: The main loop, runs all the other functions

args: void

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~
char * ozone_read();
use: Reads from stdin

args: void

returns: char * (String)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~
char ** ozone_parse(char * line, char * arg);
use: Parses a string by a given argument

args: char * line: String that is being parsed
      char * arg: The argument that a string is parsed by

returns: Pointer to pointer of chars (String) - 2D array of strings
~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ozone_prompt();
use: prints the shell prompt with current working directory

args: void

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void signhandler(int signo);
At the moment not working properly - keep getting error about int sigaddint
use: Catches the signal interrupted from the user and closes the program

args: int signo: the interrupted signal

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~
int ozone_functions(char ** args);
use: Forks a child process, and runs the commands given by the user

args: char ** args: 2D array of strings that
                    represent the arguments of the commands

returns: int - used for the run status
~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~
void pipe_func(char * cmd1, char * cmd2);
use: Acts as the bash shell pipes

args: char * cmd1: The command that will be used as the input
      char * cmd2: The command that will use cmd1 as input

returns: void
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


```
