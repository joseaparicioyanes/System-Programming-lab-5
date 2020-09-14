/*
*******************************************************************************************************************************************
 *Purpose/Description:  	This is a simple program whose purpose is to generate two processes independent of the parent where one will 
			execute the command ls -al and the other the command grep minishel.c. It is important to note that the output of the 
			first command is redirected and used as the input of the second command. For the proper functioning of this program, 
			the advantages provided by the pipe (), fork (), and execvp () functions were used. For a better understanding of the 
			program, please browse through the code and the comments.  

 * Author’s Name: Jose Aparicio
 * Author’s Panther ID: 6186111 
 * Certification: I hereby certify that this work is my own and none of it is the work of any other person.
*********************************************************************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char **argv){					//main function

	char *cmd[] = { "/bin/ls","-al", 0 };                           //command for the first child (ls -al)
	char *cmd1[] = { "grep", "minishell.c", 0 };			//command for the second child (grep minishell.c)
	int pid,pid2, pidStatus, done=0;				//integers to store the pid of each process, the process status and done wich is going to be used as boolean
	int fd[2];							//array for the pipes

	pipe(fd);
	printf("\n");

	switch (pid = fork()){						//switch statement for the first child

		case 0: 						//case 0 (child 1) executes cmd
			dup2(fd[1], 1);	                                //making this end of the pipe the standard output
			close(fd[0]); 		                        //closing the other end
			execvp(cmd[0], cmd);	                        // running the command
			printf("ERROR\n");

		case -1:                                                //if pid is less than 0, there is an error
			fprintf(stderr, "fork failed\n");		//printing an error message for the user
			exit(1);
	}

	switch (pid2 = fork()){						//switch statement for the second child
		case 0:							//case 0 (child 1) executes cmd
			dup2(fd[0], 0);					//making this end of the pipe the standard input
			close(fd[1]);					//closing the other end
			execvp(cmd1[0], cmd1);				// running the command
			printf("ERROR\n");

		case -1:						//if pid is less than 0, there is an error
			fprintf(stderr,"fork failed\n");		//printing an error message for the user
			exit(1);
	}
	close(fd[0]); 							//closing
	close(fd[1]);							//closing
	
	while ((pid2 = wait(&pidStatus)) != -1){                        //while loop to wait for all the children to finish
		if(done==1){						//checking if done is true
			printf("\nProcess 1 PID: %d\n",pid);		//printing the pid of child 1
                	printf("Process 2 PID: %d\n\n",pid2);		//printing the pid of child 2
		}
		done=1;							//setting done to true after the first child dies
	}
	return 0;
}
