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
#include <stdbool.h>
#include "commands.h"

#define MAX_BUFFER 1024
#define SEPARATORS " \t\n"

time_t getTime()
{
    return time(NULL);
}

void welcome() 
{  
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|              MyShell v1.0             |\n");
    printf("|                                       |\n");
    printf("|         Name: Dawid Lewinski          |\n");
    printf("|       Student Number: 20466172        |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");

    char* username = getenv("USER");

    time_t t = getTime();
    int h = (t / 3600) % 24;    // getting time as hours
    int m = (t / 60) % 60;      // getting time as minutes
    int s = t % 60;             // getting time as seconds

    printf ("\n\nSystem time:    %02d:%02d:%02d", h, m, s); // printing the system time
    printf("\nWelcome,        @%s", username);              // welcomes the user
    printf("\nUse \"help\" to access the shell manual.");   // informs user about help manual
    printf("\n\n");

    sleep(1);
}

void prompt()
{
    char cwd[MAX_BUFFER];
    char* name = getenv("NAME");
    char* username = getenv("USER");
    time_t t = getTime();
    int h = (t / 3600) % 24;    // time as hours
    int m = (t / 60) % 60;      // time as minutes
    int s = t % 60;             // time as seconds
    getcwd(cwd, sizeof(cwd));   // gets the current working dir
    printf("\n╭── %s@%s %02d:%02d:%02d \n└── <%s> ", username, name, h, m, s, cwd); // prints the cwd then the prompt
}

char execute(char **args)
{   // run a check for the existence of commands and call the commands function if found
    if (!strcmp(args[0], "cd"))
        {   // change directory command
            cd(args);
        }

    else if (!strcmp(args[0], "clr"))
    {   // clear terminal command
        clr();
    }

    else if (!strcmp(args[0], "dir"))
    {   // list directory command
        dir(args);
    }

    else if (!strcmp(args[0], "environ"))
    {   // get environment command
        environ();
    }

    else if (!strcmp(args[0], "echo"))
    {   // echo command
        echo(args);
    }

    else if (!strcmp(args[0], "help"))
    {   // print readme file
        help();
    }

    else if (!strcmp(args[0], "pause"))
    {   // pause shell command
        pause();
    }

    else if (!strcmp(args[0], "mkdir"))
    {   // creates a directory
        makedir(args);
    }

    else if (!strcmp(args[0], "remdir"))
    {   // removes a directory
        removedir(args);
    }

    else if (!strcmp(args[0], "quit"))   
    {   // quit shell command
        quit();
    }

    else
    {   // if the command does not exist then print the following and run the command in system terminal
        printf("\nError, command \"%s\" not found. Running command in system shell.\n\n", args[0]);
        system(*args);
    }
}

char **splitline(char *input)           // tokenize inputs
{
    char *token;
    char **tokens = malloc(MAX_BUFFER);
    int i = 0, MAXB = 64;
    token = strtok(input, SEPARATORS);  // tokenize each input using the separators
    for (i; token != NULL; ++i)
    {
        tokens[i] = token;              // set current token at position i

        if (i >= MAXB)                  // if i is greater than or equal to the max size
        {
            MAXB += 64;                 // increase buffer
        }
    token = strtok(NULL, SEPARATORS);
    }
    tokens[i] = NULL;
    return tokens;
}

int hasampersand(char *args[])
{
    int count = 0;
    for (int i = 1; args[i] != NULL; ++i)   // loops through all argument inputs until end is reached
    {
        ++count;                            // until the input reaches the end increment count
    }
    if (!strcmp(args[count], "&"))          // if the last input is an ampersand then
    {
    	return true;
    }
    else
    {
        return false;
    }
}

int backgroundexecute(char **args)
{
    pid_t pid = fork(); // creates a child process
    if (pid == 0)
    {
        if (!strcmp(args[0], "cd"))
        {   // change directory command
            cd(args);
        }

        else if (!strcmp(args[0], "clr"))
        {   // clear terminal command
            clr();
        }

        else if (!strcmp(args[0], "dir"))
        {   // list directory command
            dir(args);
        }

        else if (!strcmp(args[0], "environ"))
        {   // get environment command
            environ();
        }

        else if (!strcmp(args[0], "echo"))
        {   // echo command
            echo(args);
        }

        else if (!strcmp(args[0], "help"))
        {   // print readme file
            help();
        }

        else if (!strcmp(args[0], "pause"))
        {   // pause shell command
            pause();
        }

        else if (!strcmp(args[0], "mkdir"))
        {   // creates a directory
            makedir(args);
        }

        else if (!strcmp(args[0], "remdir"))
        {   // removes a directory
            removedir(args);
        }

        else if (!strcmp(args[0], "quit"))   
        {   // quit shell command
            quit();
        }

        else
        {   // if the command does not exist then print the following
            printf("\nError, command \"%s\" not found. Running command in system shell.\n", args[0]);
        }
    }
    else if(pid == -1)
    {
        printf("Error, fork failed.\n");
    }
}