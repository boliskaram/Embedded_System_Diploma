/*
 ============================================================================
 Name        : C.c
 Author      : Bolis karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Ss{
	char name [50] ;
	int roll ;
	float mark ;
};
struct Ss read();
void print(struct Ss x);
int main(void) {
	struct Ss x;
	printf("Enter information of students:\n");
	x=read();
	printf("Displaying information\n");
	print(x);
}

struct Ss read(){
	struct Ss X;
	printf("Enter name : ");
	fflush(stdout);
	gets(X.name);
	printf("Enter roll : ");
	fflush(stdout);
	scanf("%d",&X.roll);
	printf("Enter mark : ");
	fflush(stdout);
	scanf("%f",&X.mark);
	return X;
}
void print(struct Ss x){

	printf("name: %s\nroll: %d\nmark: %.2f",x.name,x.roll,x.mark);
}
