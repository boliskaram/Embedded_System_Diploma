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
	char l;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&l);

	if( l=='a' || l=='e' || l=='o' || l=='i'  || l=='u' ){
		printf("%c is a vowel",l);
	}else{
		printf("%c is consonant",l);
	}
}
