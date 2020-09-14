# System-Programming-lab-5
1. Carefully study the examples provided: fork.c, myls.c, myshell.c, etc. You need to know how they
work in order for you to finish this assignment; the examples will also get you prepared for
assignment 3.
2. Write a program called minishell that creates two child processes: one to execute 'ls -al' and the
other to execute ‘grep minishell.c’. After the forks, the original parent process waits for both child
processes to finish before it terminates. The parent should print out the pid of each child after it
finishes. The standard output of 'ls -al' process should be piped to the input to the 'grep minishell.c'
process. Make sure you close the unnecessary open files for the three processes. The output should
be the one line that includes the directory entry for minishell.c. You will need to call the source file
minishell.c for this to work properly.
Please follow the following instructions carefully before submitting your work:
* You need to create a Makefile to build your source code into an executable. The Makefile should
also include a target 'clean' to clean up miscellaneous files (*.o, *~, core, etc.). Before submission,
make sure you clean up the directories so that no miscellaneous files are kept around in the
submission. (Grade would be deducted if useless files are found in the homework directories.)
• Take a screenshot of the screen showing the output of running minishell on ocelot. Name it
FirstNameLastName.png or .jpg.
Submit your source file, the screenshot and your Makefile in one zip file called
FirstnameLastnameL5.zip to the assignment dropbox in Canvas.
If the program does not compile and do something useful when it runs it will not earn any credit.
