# ForkSystemCall

This C++ program demonstrates the usage of the fork system call to create child processes in a Linux environment. It utilizes multiple fork calls to create a hierarchy of processes, with each process having different parent-child relationships. After creating the processes, the program invokes the command "ps -f --ppid" to display the process table information.

The program begins by including the necessary header files for process-related functions, I/O operations, and string manipulation.

The main function initializes variables pid and pid2 to store the process IDs returned by the fork calls. It then performs two fork calls consecutively, resulting in a hierarchy of processes.

The subsequent code block checks the process IDs (pid and pid2) to determine the current process's role.

1. If the process IDs are non-zero, it indicates that the process is the parent. It retrieves its own process ID and parent's process ID using getpid and getppid functions, respectively. It prints the parent's PID, its own PID, and the process IDs of its children. It constructs a system command string using the process IDs and issues the command using the system function to display the process table. The parent process then sleeps for 3 seconds and prints a message indicating that the children processes are finished.

2. If the pid is zero and pid2 is non-zero, it signifies an intermediate parent process. It prints its own PID, parent's PID, and the process ID of its child. The intermediate parent process then sleeps for 3 seconds and prints a message indicating that it is awake.

3. If pid2 is zero and pid is non-zero, it represents a child process. It prints its own PID and its parent's PID. The child process then sleeps for 3 seconds and prints a message indicating that it is awake.

4. If both pid2 and pid are zero, it corresponds to a grandchild process. It prints its own PID and its parent's PID. The grandchild process then sleeps for 3 seconds and prints a message indicating that it is awake.

5. If the fork calls result in an error (returning -1), an error message is printed indicating the forking failure.

Finally, the main function returns 0 to exit the program.

In summary, this program demonstrates the creation of child processes using the fork system call and illustrates the hierarchy and relationships between the parent, intermediate parent, child, and grandchild processes. It also utilizes the system function to issue a command and display the process table information.
