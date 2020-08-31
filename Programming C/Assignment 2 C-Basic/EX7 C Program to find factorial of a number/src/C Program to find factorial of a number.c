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
	int x,i,fac=1;
	printf("Enter an integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	if(x > 0){
		for(i=x;i>1;i--){
			fac *=i;
		}
		printf("Factorial = %d ",fac);
	}else{
		printf("Error!! Factorial of negative number doesn't exist.");
	}
}
