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
	char ch;
	int count=0;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(string);

	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&ch);

	for(int i=0;string[i] !=0;i++){
		if(ch==string[i]){
			count++;
		}
	}
	printf("Frequency of %c = %d",ch,count);
	
}
