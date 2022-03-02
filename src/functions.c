#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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
    char* user = getenv("LOGNAME");
    char* username = getenv("USER");
    getcwd(cwd, sizeof(cwd)); // gets the current working dir
    printf("%s@%s:%s$ ", user, username, cwd); // prints the cwd then the prompt
}