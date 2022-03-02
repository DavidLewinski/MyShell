#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include "commands.h"

#define SEPARATORS " \t\n"

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
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ("\nSystem time:     %s", asctime (timeinfo) ); 
    printf("\nUSER: @%s", username);
    printf("\nUse \"help\" to access the shell manual.");
    printf("\n\n");
    sleep(1); 
}

void prompt()
{
    char cwd[1024];
    char* name = getenv("NAME");
    char* username = getenv("USER");
    getcwd(cwd, sizeof(cwd)); // gets the current working dir
    printf("%s@%s:%s$ ", name, username, cwd); // prints the cwd then the prompt
}

int execute(char **args, char *envp[])
{
    // if there's anything there
    /* check for internal/external command */
    if (!strcmp(args[0],"cd"))
        {   // change directory command
            cd(args);
        }

    if (!strcmp(args[0],"clr"))
    {   // clear terminal command
        clr();
    }

    if (!strcmp(args[0],"dir"))
    {   // list directory command
        dir();
    }

    if (!strcmp(args[0],"environ"))
    {   // get environment command
        environ(envp);
    }

    if (!strcmp(args[0],"echo"))
    {   // echo command
        echo(args);
    }

    if (!strcmp(args[0], "help"))
    {   // print readme file
        help();
    }

    if (!strcmp(args[0], "pause"))
    {   // pause shell command
        pause();
    }

    if (!strcmp(args[0],"mkdir"))
    {
        makedir(args);
    }

    if (!strcmp(args[0],"quit"))   
    {   // quit shell command
        quit();
    }
    if ((args[0]) == NULL)
    {   // if the command does not exist then print the following
        printf("Error, command \"%s\" not found.\n", args[0]);
    }
}

char **split_line(char *line)
{
  int bufsize = 64, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens)
  {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, SEPARATORS);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += 64;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens)
      {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, SEPARATORS);
  }
  tokens[position] = NULL;
  return tokens;
}