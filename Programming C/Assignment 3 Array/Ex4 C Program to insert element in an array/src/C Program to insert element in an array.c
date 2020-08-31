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
	int x,y,loc;

	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&x);

	int arr[x];

	for(int i=0;i<x;i++){
		printf("Enter element %d : ",i+1);
		fflush(stdout);
		scanf("%d", &arr[i]);
	}

	printf("Enter the element to be inserted : ");
	fflush(stdout);
	scanf("%d",&y);

	printf("Enter the location : ");
	fflush(stdout);
	scanf("%d",&loc);

	for(int i=x-1;i>=loc-1;i--){
		arr[i+1]=arr[i];
	}

	arr[loc-1]=y;

	for(int i=0;i<=x;i++){
		printf("%d  ",arr[i]);
	}
}
