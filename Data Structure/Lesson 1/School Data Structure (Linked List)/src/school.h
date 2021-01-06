/*
 * school.h
 *
 *  Created on: Jan 6, 2021
 *      Author: Bolis
 */

#ifndef SCHOOL_H_
#define SCHOOL_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define DPRINTF(...)	{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

struct Sdata{
	int id;
	char name[30];
	int age;
};
struct Sstudent{
	struct Sdata student;
	struct Sstudent* pNextStudent;
};


int addStudent();
int deleteStudent();
void printAllStudent();
void deleteAllStudent();
void printStudent();
void nodesnumber();
void printStudentRev();

#endif /* SCHOOL_H_ */
