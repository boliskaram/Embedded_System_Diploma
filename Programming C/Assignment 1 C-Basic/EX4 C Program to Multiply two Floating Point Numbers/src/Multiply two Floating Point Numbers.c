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
	float x,y;
		float sum;
		printf("Enter two integers: ");
		fflush(stdout);
		scanf("%f %f",&x,&y);
		sum=x*y;
		printf("Sum: %f",sum);
}
