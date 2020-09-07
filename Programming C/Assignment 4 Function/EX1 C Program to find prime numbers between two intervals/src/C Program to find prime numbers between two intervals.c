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

void primenumber(int x, int z);

int main(void) {
	int x,z;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d" ,&x ,&z);
	printf("prime number between %d and %d:  ", x , z);
	primenumber(x,z);
}




void primenumber(int x,int z){
	int y,i,flag ;

	for(i = x ; i<=z; i++ ){

		flag =0;

		if (i <= 1)
			continue;

		for (y = 2; y <= i / 2; y++) {

			if (i % y == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			printf("%d  ",i);
		}
	}
}
