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

int power(int a, int b);

int main(void) {
	int x,p;
	printf("Enter base number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("Enter power number (positive number) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&p);
	printf("result of %d^%d = %d",x,p,power(x,p));
}

int power(int n , int y){

	if(y!=1){
		n*power(n,--y);
		return n;
	}
}
