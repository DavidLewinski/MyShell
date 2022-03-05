void welcome();
// void grabmanual();
void prompt();
char **splitline(char *line);
char execute(char **args);
int hasampersand(char *args[]);
int backgroundexecute(char **args);