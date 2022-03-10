/*
Name: Dawid Lewinski
Student Number: 20466172
I, Dawid Lewinski, acknowledge all of DCU's Academic Integrity Policies.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER 1024

int cd(char *args[])
{   // changes the current working directory to whatever the user inputs
    char cwd[MAX_BUFFER];
    getcwd(cwd, sizeof(cwd));
    if (args[1] == NULL)                // if there is no second argument then
    {
        printf("\n%s\n", cwd);          // print current working directory
    }
    else
    {
        int check = chdir(args[1]);     // check if the command worked
        if (check == -1)                // if the command failed i.e returned a -1 then
        {                               // print the following
            printf("Error, could not find the path \"%s\".\n", args[1]);
        }
    }
}

int clr()
{   // clear command
    system("clear");
}

int dir(char *args[])
{   // list all files and directories
    char cwd[MAX_BUFFER], prevwd[MAX_BUFFER];
    getcwd(cwd, sizeof(cwd));       // gets the current working directory
    getcwd(prevwd, sizeof(cwd));    // set previous working directory variable
    if (args[1] != NULL)            // if there is a second argument
    {
        int check = chdir(args[1]); // will return -1 if no such directory
        printf("\n");
        if(check > 0)               // if the directory exists
            printf("%s\n", cwd);    // print current working directory
            system("ls -la");       // run the system ls command
            chdir(prevwd);          // return to previous directory
        if(check == -1)             // if the directory does not exist
            printf("\nError, no directory named \"%s\" found. Find list of all possible directories above.\n", args[1]);
    }
    else                            // otherwise just run system ls
    {
        system("ls -la");
    }
}

int environ()
{
    // run system environment command
    char cwd[MAX_BUFFER];
    getcwd(cwd, sizeof(cwd));
    setenv("PWD", cwd, 1);  // sets current working directory as PWD environment variable
    system("env");
    printf("\n");
}

void echo(char *args[])
{   // loop through inputs untill no more are found
    for (int i = 1; args[i] != NULL; ++i)
    {
        printf("%s ", args[i]);
    }
    printf("\n");
}

int help()
{   // cat the readme file in manual folder
    system("cat ../manual/readme.md");
}

int pause()
{   // wait for a userinput
    printf("Press the Enter key to unpause the shell...");
    getchar(); // wait for user to input enter
}

// function that creates directories in current working directory
int makedir(char *args[])
{
    // if no dirname given print an error message
    if(args[1] == NULL)
    {
        printf("Error, please provide a name for the directory.\n");
    }
    // else create a directory in the current directory with the given name
    else
    {
        int check = mkdir(args[1], MAX_BUFFER);

        // check if the directory has been created
        if(check == 0)
        {
            printf("Created a directory named, \"%s\".\n", args[1]);
        }
        else
        {
            printf("Error, directory \"%s\" already exists.\n", args[1]);
        }
    }
}

int quit()
{   // exits the shell
    exit(0);
}
