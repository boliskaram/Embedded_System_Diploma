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

	char str[30];
	char revstr[30];
	char* ps=str;
	char* pr=revstr;
	int i,count=0;

		printf("Enter sentence : ");
		fflush(stdout);
		gets(str);

	for(i=0;*ps!=0;i++){
		count++;
		ps++;
	}

	for(i=0;i<count;i++){
		ps--;
		*pr=*ps;
		pr++;
	}
	*pr='\0';
	printf("reverse sentence : %s ",revstr);
}
