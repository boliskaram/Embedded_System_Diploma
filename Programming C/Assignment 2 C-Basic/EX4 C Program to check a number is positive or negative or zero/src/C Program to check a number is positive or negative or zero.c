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
	float x;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%f",&x);

	if(x==0){
		printf("you entered zero .");
	}else if(x>0){
		printf("%f is positive",x);
	}else{
		printf("%f is negative",x);
	}
}
