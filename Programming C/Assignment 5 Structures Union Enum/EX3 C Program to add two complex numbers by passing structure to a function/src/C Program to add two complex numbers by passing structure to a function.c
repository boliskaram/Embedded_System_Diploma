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
	float Real ;
	float Imaginary;
};
struct Sd read();
struct Sd add(struct Sd x,struct Sd y);
int main(void) {
	struct Sd x,y;
	printf("for X complex number \n");
	x=read();
	printf("for Y complex number \n");
	y=read();
	printf("Sum of X and Y = %.2f+%.2fi",add(x,y).Real,add(x,y).Imaginary);
}
struct Sd read(){
	struct Sd x;
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f",&x.Real,&x.Imaginary);
	return x;
}
struct Sd add(struct Sd x,struct Sd y){
	struct Sd a;
	a.Real=x.Real + y.Real;
	a.Imaginary=x.Imaginary + y.Imaginary;
	return a;
}
