/*
 ============================================================================
 Name        : case.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char op;
	float x,y,res;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&op);
	printf("Enter first number : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);
	printf("Enter second number : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y);

	switch(op){
	case '+':
	{
		res = x+y;
		printf("%f + %f = %f",x,y,res);
		break;
	}
	case '-':
	{
		res = x-y;
		printf("%f - %f = %f",x,y,res);
		break;
	}
	case '*':
	{
		res = x*y;
		printf("%f * %f = %f",x,y,res);
		break;
	}
	case '/':
	{
		res = x/y;
		printf("%f / %f = %f",x,y,res);
		break;
	}
	}
}
