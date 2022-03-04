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
#define SEPARATORS " \t\n"                      // token separators

int main (int argc, char ** argv, char *envp[])
{
    char buf[MAX_BUFFER];                         // line buffer
    char manual[2][20] = {"", "../manual"};
    char * args[MAX_ARGS];                        // pointers to arg strings
    char shell[0], manual1[MAX_BUFFER];     // shell varible
    char ** arg;                                            // working pointer through args

    strcat(shell, getenv("PWD"));   // get the current environment variable and set it as shell variable
    // strcat(shell, "/MyShell");           // add both the shell variable and "/myshell"
    setenv("SHELL", shell, 1);         // set the old environment variable to new shell variable

    welcome();

    cd(manual);
    getcwd(manual1, sizeof(MAX_BUFFER));
    printf("%s\n", manual1);

    if(argc == 2)   // if there are 2 arguments when executing shell
    {   // run batchfile
        FILE *file;
        char batch[MAX_BUFFER];

        file = fopen(argv[1], "r"); // open the file

        if(file != NULL)
        {
            while(fgets(batch, MAX_BUFFER, file) != NULL) // while not at the end of the file
            {
                char ** command = split_line(batch); // parse the line using the split_line function as if the command was taken from the shell prompt
                printf("-%s-\n", *command);    // show what command you are running
                execute(command); // run the execute function to run the command
            }
        }
        else // if it is empty tell the user no commands are inputted
        {
            printf("Error: no commands supplied.");
        }

        fclose(file); // close the file containing the commands
    }
    // else if(argc == 3)   // if there are 3 arguments when executing shell
    // {   // i/o redirect, reads from one input file and redirects the output to a second file
    //     FILE *file1;
    //     FILE *file2;
    //     char batch[MAX_BUFFER];

    //     file1 = fopen(argv[1], "r"); // open the file
    //     file2 = fopen(argv[2], "w"); // open the file

    //     if(file1 != NULL)
    //     {
    //         while(fgets(batch, MAX_BUFFER, file1) != NULL)      // while not at the end of the file
    //         {
    //             char ** command = split_line(batch);            // parse the line using the split_line function as if the command was taken from the shell prompt
    //             fputs("TEST1\n", file2);
    //             // fputs((fprintf("-%s-\n", *command)), file2);    // show what command you are running
    //             // fputs((execute(command)), file2);               // run the execute function to run the command
    //         }
    //         printf("Successfully completed i/o redirect.\n");
    //     }
    //     else // if it is empty tell the user no commands are inputted
    //     {
    //         printf("Error: no commands supplied.");
    //     }

    //     fclose(file1); // close the file containing the commands
    //     fclose(file2);
    // }

    /* keep reading input until "quit" command or eof of redirected input */
    while (!feof(stdin))
    { 
        /* get command line from input */
        // fputs(prompt, stdout); // write prompt

        prompt();

        if (fgets(buf, MAX_BUFFER, stdin))
        {
            // read a line
            /* tokenize the input into args array */

            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenise input

            while((*arg++ = strtok(NULL,SEPARATORS)));

            // last entry will be NULL
            if (args[0] != NULL)
            {
                execute(args);
            }   // if no input command then continue
            else
            {
                continue;   // if the command does not exist then continue
            }
            continue;   // if enter key pressed just continue
        }
    }
}