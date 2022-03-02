#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int cd(char *args[])
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    int ch = chdir(args[1]);
    if(ch<0)
        printf("%s\n", cwd);
}

int clr()
{   // clear command
    system("clear");
}

int dir()
{   // list all files and directories
    system("ls -la");
}

int environ(char *envp[])
{
    // looping through and printing all environment variables
    for(int i = 0; envp[i] != NULL; ++i)
    {
        printf("\n%s", envp[i]);
    }
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
    system("cat ../manual/readme.md");
}

int pause()
{   // wait for a userinput
    printf("Press Enter to unpause the shell...");
    getchar(); // wait for user to input enter
}

int quit()
{   // exits the shell
    exit(0);
}


