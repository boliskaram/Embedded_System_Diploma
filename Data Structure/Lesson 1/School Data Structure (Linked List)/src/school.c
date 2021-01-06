/*
 * school.c
 *
 *  Created on: Jan 6, 2021
 *      Author: Bolis
 */
#include "school.h"
struct Sstudent* gpFirstStudent = NULL;
int addStudent(){
	struct Sstudent* pNewStudent;
	struct Sstudent* pLastStudent;
	struct Sstudent* pSearchStudent = gpFirstStudent;
	char temp[30];
	DPRINTF("Enter student ID: ");
	gets(temp);
	// if database is empty will be first student without checkabout id
	if(gpFirstStudent == NULL){
		pNewStudent =(struct Sstudent*) malloc(sizeof(struct Sstudent));
		gpFirstStudent = pNewStudent ;
	}
	// will be check if id is exist or no then store in database
	else{
		while(pSearchStudent){
			if(pSearchStudent->student.id == atoi(temp)){
				DPRINTF("\t\"id is exist please try again\"\n");
				return 1;
			}
			pSearchStudent=pSearchStudent->pNextStudent;
		}
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNextStudent)
			pLastStudent=pLastStudent->pNextStudent;
		pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		pLastStudent->pNextStudent = pNewStudent;
	}
	// insert student data
	pNewStudent->student.id = atoi(temp);
	DPRINTF("Enter student name: ");
	gets(pNewStudent->student.name);

	DPRINTF("Enter student age:");
	gets(temp);
	pNewStudent->student.age = atoi(temp);
	// set next student for new student NULL
	pNewStudent->pNextStudent=NULL;
	return 0;
}

int deleteStudent(){
	if(gpFirstStudent){
		char temp[30];
		unsigned int selected_id;
		// get student id
		DPRINTF("Enter Student ID:");
		gets(temp);
		selected_id = atoi(temp);
		// set pointer refer to first student and prev is null
		struct Sstudent* pSelectStudent = gpFirstStudent;
		struct Sstudent* pPrevStudent = NULL;
		// loop to every student in database
		while(pSelectStudent){
			// check if selected student id equal selected id from user
			if(pSelectStudent->student.id == selected_id){
				// selected id not first student
				if(pPrevStudent){
					pPrevStudent->pNextStudent=pSelectStudent->pNextStudent;
				}
				// selected id is first student
				else{
					gpFirstStudent=pSelectStudent->pNextStudent;
				}
				// free student form memory
				free(pSelectStudent);
				return 1 ;
			}
			//id not match selected student id switch to next student in database
			pPrevStudent=pSelectStudent;
			pSelectStudent=pSelectStudent->pNextStudent;
		}
		//if id not match any id in data base
		DPRINTF("Student ID not found in database\n");
		return 0;
	}
	// if database is empty From the beginning
	DPRINTF("\t\"Database is empty\"\n");
	return 0 ;
}

void printAllStudent(){
	// set pointer refer to first student
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	// if database is empty
	if(gpFirstStudent == NULL){
		DPRINTF("not found any student in database to print\n");
	}
	// if database contain student print then loop until reach to null
	else{
		while(pCurrentStudent){
			DPRINTF("\tstudent ID : %d\n",pCurrentStudent->student.id);
			DPRINTF("\tstudent Name : %s\n",pCurrentStudent->student.name);
			DPRINTF("\tstudent Age : %d\n",pCurrentStudent->student.age);
			DPRINTF("\t-----------------\n");
			// to refer to next student before print current student
			pCurrentStudent=pCurrentStudent->pNextStudent;
		}
	}
}

void deleteAllStudent(){
	// set pointer refer to first student
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	// if database is empty
	if(gpFirstStudent == NULL){
		DPRINTF("not found any student in database to delete\n");
	}
	// if database contain student delete then loop until reach to null
	else{
		while(pCurrentStudent){
			// set pointer temp refer to current student
			struct Sstudent* pTemp = pCurrentStudent;
			// refer to next student then delete temp student
			pCurrentStudent=pCurrentStudent->pNextStudent;
			free(pTemp);
		}
		// set first student to null ( database is free )
		gpFirstStudent = NULL;
	}
}

void printStudent(){
	struct Sstudent* pIndexStudent = gpFirstStudent;
	char index [5];
	DPRINTF("please index number of student: ");
	gets(index);
	int count = 1;
	while(pIndexStudent){
		if(count==atoi(index)){
			break;
		}
		pIndexStudent = pIndexStudent->pNextStudent;
		count++;

	}
	if(count == atoi(index)){
		DPRINTF("\tstudent ID : %d\n",pIndexStudent->student.id);
		DPRINTF("\tstudent Name : %s\n",pIndexStudent->student.name);
		DPRINTF("\tstudent Age : %d\n",pIndexStudent->student.age);
		DPRINTF("\t-----------------\n");
	}
	else{
		DPRINTF("this index not found in database\n");
	}
}

void nodesnumber(){
	struct Sstudent* pnodesnumber = gpFirstStudent;
	int count = 1;
	while(pnodesnumber->pNextStudent){
		count++;
		pnodesnumber = pnodesnumber->pNextStudent;
	}
	DPRINTF(" length of student database equal : %d node",count);
	DPRINTF("\n");
}

void printStudentRev(){
	char index_rev[5];
	int len=1;
	int count=1;
	int index;
	struct Sstudent* pIndexStudent = gpFirstStudent;
	struct Sstudent* pStudentRev = gpFirstStudent;
	DPRINTF("please rev_index number of student: ");
	gets(index_rev);
	while(pStudentRev->pNextStudent){
		len++;
		pStudentRev = pStudentRev->pNextStudent;
	}

	index=(len-atoi(index_rev)+1);
	while(pIndexStudent){
		if(count==index){
			break;
		}
		pIndexStudent = pIndexStudent->pNextStudent;
		count++;
	}
	if(count == index){
		DPRINTF("\tstudent ID : %d\n",pIndexStudent->student.id);
		DPRINTF("\tstudent Name : %s\n",pIndexStudent->student.name);
		DPRINTF("\tstudent Age : %d\n",pIndexStudent->student.age);
		DPRINTF("\t-----------------\n");
	}
	else{
		DPRINTF("this index not found in database\n");
	}
}
