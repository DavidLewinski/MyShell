/*
Name: Dawid Lewinski
Student Number: 20466172
I, Dawid Lewinski, acknowledge all of DCU's Academic Integrity Policies.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include "commands.h"
#include "utility.h"

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token separators

int main (int argc, char ** argv, char *envp[])
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char shell[0];                             // shell varible
    char ** arg;                               // working pointer thru args

    strcat(shell, getenv("PWD"));              // get the current environment variable and set it as shell variable
    strcat(shell, "/myshell");                 // add both the shell variable and "/myshell"
    setenv("SHELL", shell, 1);                 // set the old environment variable to new shell variable

    welcome();

    if(argc == 2)   // if there are 2 arguments when executing shell
    {   // run batchfile
        FILE *file;
        char batch[MAX_BUFFER];

        file = fopen(argv[1], "r"); // open the file

        if(file != NULL)
        {
            while(fgets(batch, MAX_BUFFER, file) != NULL)   // while not at the end of the file
            {
                char ** command = splitline(batch);         // parse the line using the splitline function as if the command was taken from the shell prompt
                printf("-%s-\n", *command);                 // show what command you are running
                execute(command);                           // run the execute function to run the command
            }
        }

        fclose(file);    // close the file containing the commands
    }

    while (!feof(stdin))
    { 
        /* get command line from input */

        prompt();

        if (fgets(buf, MAX_BUFFER, stdin))
        {
            // read a line
            /* tokenize the input into args array */

            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input
            while((*arg++ = strtok(NULL,SEPARATORS)));

            if (args[0] != NULL) // if the inputs are not empty
            {
                if (hasampersand(args) == 1)    // check if there is a ampersand at the end of the input
                {
                    backgroundexecute(args);    // if so then run the background execute
                    // sleep(1);
                }
                else if (hasampersand(args) == 0)
                {
                    execute(args);              // otherwise execute the commands normally
                }
            }
            continue;       // if nothing is inputted, continue
        }
    }
}