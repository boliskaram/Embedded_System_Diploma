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
	int x,y,i;


		printf("Enter no of elements : ");
		fflush(stdout);
		scanf("%d",&x);

		int arr[x];

		for(i=0;i<x;i++){
			printf("Enter element %d : ",i+1);
			fflush(stdout);
			scanf("%d", &arr[i]);
		}

		printf("Enter the element to be searched : ");
		fflush(stdout);
		scanf("%d",&y);

		for(i=0;i<x;i++){
			if(y==arr[i]){
				printf("Number found at the location = %d",i+1);
				break;
			}
		}
		if(i==x){
			printf("number not found in this array");
		}
}
