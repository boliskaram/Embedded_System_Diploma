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
	char string[100];
	int count=0;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(string);


	for(int i=0;string[i] !=0;i++){
		if((string[i] >= 'a' && string[i] <= 'z')|| (string[i] >= 'A' && string[i] <= 'Z') || string[i] == ' ' ){
			count++;
		}
	}
	printf("Length of string = %d",count);
}
