/*
 * s.c
 *
 *  Created on: Jan 28, 2021
 *      Author: Bolis
 */

#include "s.h"

int i=0 ; // student number in queue

int add_student(){
	if(i<student_size){
		DPRINTF("Enter Your ID: ");
		scanf("%d",&SN[i].ID);

		for(int k=0;k<i;k++){
			if(SN[i].ID==SN[k].ID){
				DPRINTF("sorry ID is exist enter anthor ID \n");
				return 1;
			}
		}
		DPRINTF("Enter Your Name: ");
		gets(SN[i].name);
		DPRINTF("Enter Your GPA: ");
		scanf("%f",&SN[i].GPA);
		DPRINTF("Enter Your subjects id\n");
		for(int j=0 ; j<5 ;j++ ){
			scanf("%d",&SN[i].subject_id[j]);
		}
		// refer to next struct in array (next element)
		i=i+1;
	}else{
		DPRINTF("database is full \n");
	}
	return 0;
}

void print_student(){
	int temp_id;
	DPRINTF("Enter Your student_ID: ");
	scanf("%d",&temp_id);
	for(int j = 0 ; j < i ; j++){
		if(temp_id == SN[j].ID){
			DPRINTF("\tYour ID: %d\n",SN[j].ID);
			DPRINTF("\tYour Name: %s\n",SN[j].name);
			DPRINTF("\tYour GPA: %.2f\n",SN[j].GPA);
			DPRINTF("\tsubjects ID are:");
			for(int k=0;k<5;k++){
				DPRINTF("\t%d",SN[j].subject_id[k]);
			}
			DPRINTF("\n");
			break;
		}

	}
}

void delete_student(){
	int temp_id;
	DPRINTF("Enter Your student_ID: ");
	scanf("%d",&temp_id);
	for(int j = 0 ; j < i ; j++){
		if(temp_id == SN[j].ID){
			for(int k=j;k < student_size;k++){
				SN[k] = SN[k+1];
			}
			i--;
		}
	}
}

void print_all_student(){
	for(int j = 0 ; j < i ; j++){
		{
			DPRINTF("\tYour ID: %d\n",SN[j].ID);
			DPRINTF("\tYour Name: %s\n",SN[j].name);
			DPRINTF("\tYour GPA: %.2f\n",SN[j].GPA);
			DPRINTF("\tsubjects ID are:");
			for(int k=0;k<5;k++){
				DPRINTF("\t%d",SN[j].subject_id[k]);
			}
			DPRINTF("\t\n=====================\n");
		}
	}
}


void total_student(){
	DPRINTF("the total number of student in database is %d\n",i);
	DPRINTF("you can have %d more students\n",5-i);
}








