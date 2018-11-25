#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(){
    printf("Parent here! (before forking) My pid:%d\n", getpid());
	int f = fork();
	f = fork();
	
	//child process 
	if (f==0)
		printf("Child Here! My pid: %d, My parent pid: %d\n", getpid(), getppid());
	srand( time(NULL) );
	int num_sec = rand() % (16) + 5;
	sleep(num_sec);
	
	if (f){
		int status;
		int childpid = wait(&status);
		if (WIFEXITED (status)){
			printf("Parent Here! My Pid: %d\n" , getpid());			
			printf("Pid of my child: %d, Number of Seconds waited: %d\n", childpid, num_sec);
		} 
		printf("Parent Done\n\n");
	}
	
	return 0;
}