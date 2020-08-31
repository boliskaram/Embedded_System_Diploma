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
	char str1[100];
	int count=0,start,end;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str1);

	for(int i=0;str1[i] !=0;i++){
		if((str1[i] >= 'a' && str1[i] <= 'z')|| (str1[i] >= 'A' && str1[i] <= 'Z') || str1[i] == ' ' ){
			count++;
		}
	}

	end=count-1;

	char str2[count];
	for(start=0 ; start < count ; start++){
		str2[start]=str1[end];
		end--;
	}

	str2[start]='\0';
	printf("reverse string is: %s",str2);
}
