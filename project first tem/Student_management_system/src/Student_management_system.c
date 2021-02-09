/*
 ============================================================================
 Name        : SMS.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "s.h"
int main(void) {
	char option[5];
	while(1){
		DPRINTF("\t\tSelect your option\n");
		DPRINTF("1:Add student\n");
		DPRINTF("2:Find student by ID\n");
		DPRINTF("3:delete student by ID\n");
		DPRINTF("4:print all student in database\n");
		DPRINTF("5:Find the Total number of Students\n")
		DPRINTF("6:exit\n");
		DPRINTF("-----------------\n");
		DPRINTF("Enter your option: ");
		gets(option);
		DPRINTF("\n");
		switch(atoi(option)){
		case 1:
			add_student();
			break;
		case 2:
			print_student();
			break;
		case 3:
			delete_student();
			break;
		case 4:
			print_all_student();
			break;
		case 5:
			total_student();
			break;
		case 6:
			exit(0);
			break;
		default:
			DPRINTF("\t\"WRONG OPTION PLEASE TRY AGAIN\"\n");
			break;
		}
	}
	return 0;
}
