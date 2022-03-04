#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include "commands.h"

#define MAX_BUFFER 1024
#define MAX_ARGS 64
#define SEPARATORS " \t\n"

time_t getTime()
{
    return time(NULL);
}

void welcome() 
{  
    printf("+---------------------------------------+"); 
    printf("\n|");
    printf("\t\t\t\t\t|");
    printf("\n|\t      MyShell v1.0");
    printf("\t\t|");
    printf("\n|\t  Name: Dawid Lewinski");
    printf("\t\t|");
    printf("\n|\tStudent Number: 20466172");
    printf("\t|");
    printf("\n|\t\t\t\t\t|");
    printf("\n+---------------------------------------+"); 
    char* username = getenv("USER"); 
    // time_t rawtime;
    // struct tm * t;
    // time ( &rawtime );
    // t = localtime ( &rawtime );
    time_t t = getTime();
    int h = (t / 3600) % 24;
    int m = (t / 60) % 60;
    int s = t % 60;
    printf ("\nSystem time:     %02d:%02d:%02d", h, m, s);
    printf("\nUSER: @%s", username);
    printf("\nUse \"help\" to access the shell manual.");
    printf("\n\n");
    sleep(1); 
}

void prompt()
{
    char cwd[MAX_BUFFER];
    char* name = getenv("NAME");
    char* username = getenv("USER");
    time_t t = getTime();
    int h = (t / 3600) % 24;  /* ### My problem. */
    int m = (t / 60) % 60;
    int s = t % 60;
    getcwd(cwd, sizeof(cwd)); // gets the current working dir
    printf("╭─ %s@%s %02d:%02d:%02d:\n└── <%s> ", username, name, h, m, s, cwd); // prints the cwd then the prompt
}

int execute(char **args)
{
    // if there's anything there
    /* check for internal/external command */
    if (!strcmp(args[0],"cd"))
        {   // change directory command
            cd(args);
        }

    else if (!strcmp(args[0],"clr"))
    {   // clear terminal command
        clr();
    }

    else if (!strcmp(args[0],"dir"))
    {   // list directory command
        dir();
    }

    else if (!strcmp(args[0],"environ"))
    {   // get environment command
        environ();
    }

    else if (!strcmp(args[0],"echo"))
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

    else if (!strcmp(args[0],"mkdir"))
    {
        makedir(args);
    }

    else if (!strcmp(args[0],"quit"))   
    {   // quit shell command
        quit();
    }

    else
    {   // if the command does not exist then print the following
        printf("Error, command \"%s\" not found.\n", args[0]);
    }
}


char **split_line(char *line)
{
    char *token;
    char **tokens = malloc(MAX_BUFFER);
    int i = 0, MAXB = 64;
    token = strtok(line, SEPARATORS);
    for (i; token != NULL; ++i)
    {
        tokens[i] = token;

        if (i >= MAXB)
        {
            MAXB += 64;
            if (!tokens)
            {
                fprintf(stderr, "lsh: allocation error\n");
            }
        }
    token = strtok(NULL, SEPARATORS);
    }
    tokens[i] = NULL;
    return tokens;
}