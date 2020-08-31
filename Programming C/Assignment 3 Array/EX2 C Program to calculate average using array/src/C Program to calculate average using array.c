/*
 ============================================================================
 Name        : EX2.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x;
	printf("Enter the numbers of data:");
	fflush(stdout);
	scanf("%d",&x);

	float num[x];
	float sum=0.00;
	for(int i=0 ; i<sizeof(num)/sizeof(num[0]) ; i++){
		printf("%d . Enter number: ",i+1);
		fflush(stdout);
		scanf("%f",&num[i]);
		sum += num[i];
	}
	printf(" Average = %.2f",sum/x);
}
