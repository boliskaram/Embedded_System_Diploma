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
	int col,row;
	printf("Enter the numbers of row:");
	fflush(stdout);
	scanf("%d",&row);
	printf("Enter the numbers of column:");
	fflush(stdout);
	scanf("%d",&col);

	int a[row][col];
	printf("Enter elements of matrix:\n");

	for(int i=0;i<row;i++){
		for( int y=0 ; y<col ; y++ ){
			printf("Enter element a%d%d",i,y);
			fflush(stdout);
			scanf("%d",&a[i][y]);
		}
	}

	printf("Entered Matrix:\n");
	for(int i=0;i<row;i++){
			for( int y=0 ; y<col ; y++ ){
				printf("%d \t", a[i][y]);
			}
			printf("\n");
		}

	printf("Transpose of Matrix:\n");
		for(int i=0;i<col;i++){
				for( int y=0 ; y<row ; y++ ){
					printf("%d \t", a[y][i]);
				}
				printf("\n");
			}

}
