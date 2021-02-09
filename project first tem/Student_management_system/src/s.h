/*
 * s.h
 *
 *  Created on: Jan 28, 2021
 *      Author: Bolis
 */

#ifndef S_H_
#define S_H_
#include "stdio.h"

#define DPRINTF(...)	{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}
#define student_size 50
struct SStudent{
	char name[20];
	int ID;
	float GPA;
	int subject_id[5];
};
struct SStudent SN[student_size]; // array of structure size 50 student
int add_student();
void print_student();
void print_all_student();
void delete_student();
void total_student();
#endif /* S_H_ */
