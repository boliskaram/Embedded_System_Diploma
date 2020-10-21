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
	int number_element=5,i=0;
	printf("Enter the number of element : ");
	fflush(stdout);
	scanf("%d",&number_element);
	int arr[number_element];
	int* parr=arr;
	printf("input %d number of element\n", number_element);
	for (i=0 ; i<5; i++){
		printf("element - %d : ",i+1);
		fflush(stdout);
		scanf("%d",parr+i);
	}
	parr--;
	for (i=5 ; i>0 ; i--){
		printf("element - %d : %d\n",i,*(parr+i));
	}
}
