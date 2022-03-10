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

    quit    - This command will quit the shell environment and end the process.

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
                        "./myshell < input.txt > output.txt".

Background Execution  - The user can run a background command by simply writing any command
                        they want with a "&" at the end of the input. Typing quit will exit the background execution.


Name: Dawid Lewinski
Student Number: 20466172
I, Dawid Lewinski, acknowledge all of DCU's Academic Integrity Policies.
