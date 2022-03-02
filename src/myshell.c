#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include "commands.h"
#include "functions.h"

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                      // token separators

int main (int argc, char ** argv, char *envp[])
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char shell[0];                             // shell varible
    char ** arg;                               // working pointer thru args

    strcat(shell, getenv("PWD")); // get the current environment variable and set it as shell variable
    strcat(shell, "/myshell"); // add both the shell variable and "/myshell"
    setenv("SHELL", shell, 1); // set the old environment variable to new shell variable

    welcome();

    if(argc == 2)
    {
        FILE *batchfile;
        char c[100];

        batchfile = fopen(argv[1], "r"); // open the batchfile

        if(batchfile == NULL) // if it is empty inform the user no commands are inputted
        {
            printf("Error: no commands supplied.");
        }
        else
        {
            while(fgets(c, sizeof(c), batchfile) != NULL) // while not at the end of the file
            {
                char ** command = split_line(c); // parse the line using the split_line function as if the command was taken from the shell prompt
                execute(command); // run the execute function to run the commands on each line
                printf("\n");
            }
        }

        fclose(batchfile); // close the batchfile containing the commands
    }

    /* keep reading input until "quit" command or eof of redirected input */
    while (!feof(stdin))
    { 
        /* get command line from input */
        // fputs(prompt, stdout); // write prompt

        prompt();

        if (fgets(buf, MAX_BUFFER, stdin ))
        {
            // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input

            while((*arg++ = strtok(NULL,SEPARATORS)));

            // last entry will be NULL
            if (args[0] != NULL)
            {
                // execute(args);
                // continue;
                // if there's anything there
                /* check for internal/external command */
                if (!strcmp(args[0],"cd"))
                    {   // change directory command
                        cd(args);
                        continue;
                    }

                if (!strcmp(args[0],"clr"))
                {   // clear terminal command
                    clr();
                    continue;
                }

                if (!strcmp(args[0],"dir"))
                {   // list directory command
                    dir();
                    continue;
                }

                if (!strcmp(args[0],"environ"))
                {   // get environment command
                    environ(envp);
                    continue;
                }

                if (!strcmp(args[0],"echo"))
                {   // echo command
                    echo(args);
                    continue;
                }

                if (!strcmp(args[0], "help"))
                {   // print readme file
                    help();
                    continue;
                }

                if (!strcmp(args[0], "pause"))
                {   // pause shell command
                    pause();
                    continue;
                }

                if (!strcmp(args[0],"mkdir"))
                {
                    makedir(args);
                    continue;
                }

                if (!strcmp(args[0],"quit"))   
                {   // quit shell command
                    quit();
                    continue;
                }
                else
                {   // if the command does not exist then print the following
                    printf("Error, command \"%s\" not found.\n", args[0]);
                    continue;
                }

                continue;
            }   // if no input command then continue
            else
            {
                continue;
            }
            continue;
        }
    }
}