#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	int status, n;
	FILE *fp;
	char a[30];
	if( (pid = fork()) < 0 ) {
		printf("fork error");
		exit(EXIT_SUCCESS);
	}
	else if(pid == 0) {
		fp = fopen("file.txt",w);
		fwrite(fp,"201521197, leesak",20);
		exit(1);
	}
	else {
		if( (wait(&status)) != pid ) {
			fp = fopen("file.txt",r);
			n = fread(fp,a,20);
			fprintf(fp, a, n);
			exit(1);
		}
	}
	exit(EXIT_SUCCESS);
}
