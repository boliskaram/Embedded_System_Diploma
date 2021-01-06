/*
 ============================================================================
 Name        : main.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "school.h"

int main(){
	char temp[10];
	while(1){
		DPRINTF("\tSELECT YOUR OPTION\n");
		DPRINTF("1:Add Student\n");
		DPRINTF("2:Delete Student\n");
		DPRINTF("3:print All Student\n");
		DPRINTF("4:Delete All Student\n");
		DPRINTF("5:print Student using index\n");
		DPRINTF("6:print length of student database\n");
		DPRINTF("7:print student with reverse index\n");
		DPRINTF("\n  Enter option number: ");
		gets(temp);
		DPRINTF("\n");
		switch(atoi(temp))
		{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			printAllStudent();
			break;
		case 4:
			deleteAllStudent();
			break;
		case 5:
			printStudent();
			break;
		case 6:
			nodesnumber();
			break;
		case 7:
			printStudentRev();
			break;
		default:
			DPRINTF("\t\"WRONG OPTION PLEASE TRY AGAIN\"\n");
			break;
		}
		DPRINTF(" ============================================\n");
	}
	return 0;
}
