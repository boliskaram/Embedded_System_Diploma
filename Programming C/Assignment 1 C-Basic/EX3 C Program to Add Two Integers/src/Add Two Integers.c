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
	int x,y;
	int sum;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d %d",&x,&y);
	sum=x+y;
	printf("Sum: %d",sum);
}
