#include <stdio.h>

void main() {
    FILE *fp;
    char line[100];
	printf("Hello World!\n");
    fp = fopen("log.txt", "w");
    if(fp == NULL) return;
    while(fgets(line, 100, stdin) != NULL) {
        fprintf(fp, "%s", line);
        if(line[0] == 'q') break;        
    }
    close(fp);	
}

