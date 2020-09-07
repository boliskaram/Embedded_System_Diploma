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
#include <string.h>

void revstr (char c[],int l);

int main(void) {
	char s[100];
	printf("Enter a sentence :");
	fflush(stdin); fflush(stdout);
	gets(s);
	revstr(s , strlen(s));
}

void revstr(char x[], int len){
	if(len!=0){
		printf("%c",x[len-1]);
		revstr(x,--len);
	}
}
