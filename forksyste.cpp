#include <unistd.h> 
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

//**************************************************************************
// C++ program which uses fork system call to start child process(es) in Linux.
// Calls fork() twice to create 3 additional processes. Among them, one process
// is the child of the initial process, but it is also the parent of another process.
// Then invokes the command “ps –f –-ppid ...
//
// @param void.
//
// @return int
//****************************************************************************

int main(void)
{
	//Grabs the first to forks
	int pid = 0;
	int pid2 = 0;
	pid =  fork();
	pid2 = fork();
	// Grabs the initial parent id and id for the parent
	int parent_id;
	int id;

	// If the current process is the parent
	if (pid != 0 && pid2 != 0)
	{
        	id = getpid();
        	parent_id = getppid();
		//Prints the details for parent out
        	printf("PARENT: My PID is %d, my parent's PID is %d. My Children are %d, %d\n", id, parent_id ,pid, pid2);
		// This command will help print out the table 
		string str = "/bin/ps -f --ppid ";
		stringstream ss;
		// Add this string to the system call
		ss << id << "," << parent_id << "," << pid2 << "," << pid;
                string str2 = ss.str();
		str = str + str2;
                const char *command = str.c_str();
		// Prints out the command
		cout << "PARENT: Issuing command: ";
                cout << command << endl;
		// system call for the table
		system(command);
		sleep(3);
		// Prints once children processes are finished
		cout << "PARENT: Children processes are finished." << endl;

	}
	 // If the current process is the intermediate parent
	else if(pid == 0 && pid2 != 0)
	{
		 //Prints the details for intermediate parent out
		printf("INTERMEDIATE PARENT: My PID is %d,  my parent's PID is %d, my child is %d\n", getpid(), getppid(),pid2 );
		sleep(3);
		// Will print once sleep is over.
		cout << "INTERMEDIATE PARENT: " << getpid() << " is awake." << endl;
	}
	 // If the current process is the child
	else if(pid2 == 0 && pid != 0)
	{
		  //Prints the details for child out
		printf("CHILD: My PID is %d, my parent's PID is %d.\n", getpid(),getppid());
		sleep(3);
		// Will print once sleep is over.
		cout << "CHILD: " << getpid() << " is awake." << endl;
	}
	 // If the current process is the grand child
	else if(pid2 == 0 && pid == 0)
	{
		 //Prints the details for grand child out
		printf("GRAND CHILD: My PID is %d, my parent's PID is %d.\n", getpid(),getppid());
		sleep(3);
		 // Will print once sleep is over.
		cout << "GRAND CHILD: " << getpid() << " is awake." << endl;
	}
	// Error check
	else if(pid2 == -1 || pid == -1)
	{
		cout << "Forking Failure!" << endl;
	}
                return 0;
}
