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

struct Semployee{
	char* name;
	int id;
};

int main(void) {

	struct Semployee emp1={"bolis",15},emp2={"marco",24},emp3={"pavly",49};
	struct Semployee *arr[]={&emp1,&emp2,&emp3};
	struct Semployee*(*parr_emp)[3]= &arr;

	printf(" Exmployee Name : %s \n",(*(*parr_emp))->name);
	printf(" Employee ID :  %d \n",(*(*parr_emp))->id);
}
