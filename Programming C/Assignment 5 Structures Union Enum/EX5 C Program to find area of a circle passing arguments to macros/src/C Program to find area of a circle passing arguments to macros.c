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
#define Pi 3.14
#define area(r) (Pi*r*r)
int main(void) {
	int r;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%d",&r);
	printf("Area = %.2f ",area(r));
}
