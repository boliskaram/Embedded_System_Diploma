/*
 ============================================================================
 Name        : Assignment.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a, b ,temp;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of b = %f",b);
}
