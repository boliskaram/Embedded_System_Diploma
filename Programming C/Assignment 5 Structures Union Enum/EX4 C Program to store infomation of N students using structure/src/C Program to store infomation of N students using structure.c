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
struct Ss{
	char name [50] ;
	int roll ;
	float mark ;
};
struct Ss read();
void print(struct Ss x);
int main(void) {
	struct Ss x[3];
	int size = sizeof(x)/sizeof(x[0]);
	for(int i=0;i<size;i++){
		printf("Enter information of students %d:\n",i+1);
		x[i]=read();
	}
	for(int i=0;i<size;i++){
		printf("Displaying information student %d:\n",i+1);
		print(x[i]);
	}
}

struct Ss read(){
	struct Ss X;
	printf("Enter name : ");
	fflush(stdin);fflush(stdout);
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

	printf("name: %s\nroll: %d\nmark: %.2f\n",x.name,x.roll,x.mark);
}
