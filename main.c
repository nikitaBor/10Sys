#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

static void sighandler(int signo){
	if(signo == SIGINT){
		printf("recieved SIGINT. SHUTTING DOWN BEEP BOOP\n");
		exit(1);
	}
	if(signo == SIGUSR1){
		printf("recieved SIGUSR1\n");
		printf("The parent process PID:%d\n", getppid());
		return;
		
	}
}
	
int main(){
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	
	while(1){
		printf("This is pid: %d\n", getpid());
		sleep(1);
	}	
	return 0;
}