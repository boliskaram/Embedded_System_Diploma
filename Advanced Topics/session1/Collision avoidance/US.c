/*
 * US.c
 *
 *  Created on: Jan 23, 2021
 *      Author: Bolis
 */

#include "US.h"
#include "stdio.h"
#include "stdlib.h"

void (*US_state)();

int US_distance = 0;

int Get_distance_random(int l,int r,int count){
	int i;
	for(i=0;i<count;i++){
		int rand_num = (rand()%(r-l+1))+l;
		return rand_num ;
	}
}

void US_init(){
	printf("US_init \n");
}


STATE_define(US_busy){

	US_state_id = US_busy;
	US_distance = Get_distance_random(45,55,1);
	printf("US_waiting State: distance =%d \n",US_distance);
	US_Set_distance (US_distance);
	US_state = STATE(US_busy);
}
