#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER 1024

int cd(char *args[])
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    int ch = chdir(args[1]);
    if(ch < 0)
        printf("\n%s\n", cwd);
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
        int cd = chdir(args[1]);    // will return -1 if no such directory
        printf("\n");
        if(cd > 0)                 // if the directory exists
            printf("%s\n", cwd);    // print current working directory
            system("ls -la");       // run the system ls command
            chdir(prevwd);          // return to previous directory
        if(cd == -1)                // if the directory does not exist
            printf("\nError, no directory named \"%s\" found. Find list of all possible directories above.\n", args[1]);
    }
    else                            // otherwise just run system ls
    {
        system("ls -la");
    }
    // system("ls -la");
}

int environ()
{
    // looping through and printing all environment variables
    char cwd[MAX_BUFFER];
    getcwd(cwd, sizeof(cwd));
    setenv("PWD", cwd, 1);
    system("env");
    printf("\n");
}

void echo(char *args[])
{
    for (int i = 1; args[i] != NULL; ++i)
    {
        printf("%s ", args[i]);
    }
    printf("\n");
}

int help()
{   // print the readme file in manual folder
    char manual[1000];
    // strcat(manual, "cd ");
    // strcat(manual, getenv("PWD"));
    printf("\n%s\n", manual);
    // chdir("../");
    // chdir(manual);
    // system("cd ..");
    // strcat(manual, getenv("PWD"));
    // system("cat ./readme.md")
    // system("cd ../bin");
    // system("cat ../manual/readme.md");
    // printf("\n");
}

int pause()
{   // wait for a userinput
    printf("Press Enter to unpause the shell...");
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
            printf("Created \"%s\" directory.\n", args[1]);
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


