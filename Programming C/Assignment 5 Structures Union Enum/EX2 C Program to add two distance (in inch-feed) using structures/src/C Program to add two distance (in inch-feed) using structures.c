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
struct Sd{
	int feet;
	float inch;
};
struct Sd read();
struct Sd add(struct Sd x,struct Sd y);
int main(void) {
	struct Sd x,y;
	printf("Enter formation for 1st distance\n");
	x=read();
	y=read();
	printf("Enter formation for 2nd distance\n");
	printf("Sum of distances = %d feet and %.2f inch",add(x,y).feet,add(x,y).inch);
}
struct Sd read(){
	struct Sd x;
	printf("Enter feet: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&x.inch);
	return x;
}
struct Sd add(struct Sd x,struct Sd y){
	struct Sd a;
	a.feet=x.feet + y.feet;
	a.inch=x.inch + y.inch;
	if(a.inch>=12){
		++a.feet;
		a.inch-=12;
	}
	return a;
}
