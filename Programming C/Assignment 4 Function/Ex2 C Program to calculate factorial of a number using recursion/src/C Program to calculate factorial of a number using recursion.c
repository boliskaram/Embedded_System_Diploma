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

int factorial(int y);

int main(void) {
	int x;
	printf("Enter an positive number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	printf("Factorial of %d = %d",x,factorial(x));

}

int factorial(int y){
	if (y!=1)
	y *=factorial(y-1);
	return y;
}
