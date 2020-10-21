/*
 ============================================================================
 Name        : C.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alpha[27];
	char* pa = alpha;

	for(int i=0 ; i<26 ; i++){

		*(pa+i)='a';
		pa++;
	}
	pa = alpha;

	printf("The Alphabets are :\n");
	for(int i=0;i<26;i++){
		printf("%c ",*pa);
		pa++;
	}

}
