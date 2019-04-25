#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int sum; 
int b;
int main(void) {
	pid_t pid;
	int i,j;
	int status;
	int sum = 0;
	int b = 1;

	for(i=0; i<10; i++) {
		if( (pid = fork()) < 0 ) {
			printf("fork error");
			exit(EXIT_SUCCESS);
		}
	
		else if( pid == 0 ) {
			for(j=b; j<=b+99; j++) {
				sum = sum + j;
			}
			exit(EXIT_SUCCESS);
		}
		else {
			if( wait(&status) != pid ) {
				printf("wait error");
				exit(1);
			}
		}
	}
		
		printf("result sum = %d\n", sum);
		exit(EXIT_SUCCESS);
}
