+---------------------------------------+
|                                       |
|              MyShell v1.0             |
|                                       |
|         Name: Dawid Lewinski          |
|       Student Number: 20466172        |
|                                       |
+---------------------------------------+

Name
    MyShell

Synopsis
    MyShell

Description
    MyShell is a personal project created by me, Dawid Lewinski. It provides some basic
    functionality that can execute commands much like commonly found on Operating Systems
    like Ubuntu.

Here are all the possible commands available for this shell:

    cd      - This command changes current working directory of the user to their desired
              path. User may enter the "cd" command followed by either a "../" to indicate
              that the user wants to go back from their current working directory or a "./"
              to indicate that the user wants to move somewhere within their current working
              directory. The user may also input their desired path, if the user inputs no
              arguments following the command then the current working directory will be
              displayed.

    clr     - This will clear the users screen, essentially clearing the executed command
              history.

    dir     - This command will list all the files and directories in either the current
              current working directory provided no following argument is given, or if a
              existing directory is given as a arguemnt then it will list that directories
              files and directories.

    environ - This command will print all environment variables.

    echo    - This command will print the user input message that is followed after the
              command name.

    help    - This command will print the readme file in the manual folder and list all
              possible commands along with what they do.

    pause   - This command will make the shell cease all functioning until the user interrupts
              the sleep mode with a enter key interrupt.

    mkdir   - This command is used to create a directory in your current working directory.
              To do so you need to provide a name for the directory you wish to create.

    remdir  - This command is used to remove directories in the given path. To do so you
              need to provide a valid directory otherwise an error message will be displayed.

    quit    - This command will quit the shell environment and end the process.

Enviornment Concept   - The environment variables are all set by default by the system 
                        these environment variables are all updated to match the shells 
                        current environment. Variables such as SHELL is update to be 
                        current shell environment in the bin folder location. The PWD 
                        variable is also always updated to be the current working directory 
                        of the shell.

Batchfile             - To run this you will have to be in the bin directory and run 
                        the shell along with the batchfile like so, "./myshell batchfile.txt"
                        this will run all the command that are in the file and execute them 
                        in the shell. Each command will be displayed with a "-<command>-" to 
                        show the user what command is being run. 

I/O Redirection       - My shell somewhat supports this feature however, the prompt 
                        would commonly break and sometimes the output ends up jumbled as 
                        a result. The commands still work and function as they should 
                        however the outputted result will be slightly messy. The way to 
                        actually run this I/O redirection is by simply running the following 
                        command, "./myshell > output.txt". If done so you can run commands 
                        by inputting them into the empty prompt. You can also run a 
                        inputs file that executes the commands in the shell. To do so you can 
                        type "./myshell < input.txt" this works properally. And lastly you 
                        can also redirect the inputs file to run and write the outputs from 
                        the input file into the output file. To do so you can write 
                        "./myshell < input.txt > output.txt". Essentially the ">" sign is used to write the outputs and the "<" is used read the inputs. 

Process Execution     - The user can run a background command by simply writing any command 
                        they want with a "&" at the end of the input. Typing quit will exit 
                        the background execution. The general concept is that a shell can 
                        create a child process which can execute commands separate to the 
                        parent process. A example is that if you run a command in background 
                        execution mode you can quit that process and this returns you back to 
                        the parent process.
                        
                        Difference between background and foreground execution:

                        Foreground  -
                            These are processes which require the user to run or interact 
                            with. An example would be this readme file, depending on the 
                            text editor used to display this, you could say that the 
                            editor is the process/application that the user is running. 

                        Background -
                            Processes that are run in the back or independently of the user 
                            are known as background processes. A example of a background 
                            process could be a music player that you could have playing while 
                            writing or doing work on a foreground process.

References:
    - Graham Healy, Building your Own Shell,
    https://loop.dcu.ie/mod/book/view.php?id=1796411&chapterid=377036
    - Systems Programming in C, Ananda Gunawardena,
    https://www.cs.cmu.edu/~guna/15-123S11/Lectures/Lecture24.pdf
    - The fork() System Call,
    http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html
    - C File Handling,
    https://www.programiz.com/c-programming/c-file-input-output

Name: Dawid Lewinski
Student Number: 20466172
I, Dawid Lewinski, acknowledge all of DCU's Academic Integrity Policies.
