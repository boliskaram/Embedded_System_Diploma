/*
 * CA.c
 *
 *  Created on: Jan 23, 2021
 *      Author: Bolis
 */

#include "CA.h"
#include "stdio.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;
void (*CA_state)();

void US_Set_distance(int d){

	CA_distance = d;
	(CA_distance <= CA_threshold) ? (CA_state=STATE(CA_waiting)) : (CA_state = STATE(CA_driving) );
	printf("US >>>>>>>>distance = %d>>>>>>>>> CA \n",CA_distance);
}

STATE_define(CA_waiting){
	CA_state_id = CA_waiting;
	printf("CA_waiting State: distance =%d speed =%d \n",CA_distance,CA_speed);
	CA_speed = 0;
	DC_motor(CA_speed);
}

STATE_define(CA_driving){
	CA_state_id = CA_driving;
	printf("CA_driving State: distance =%d speed =%d \n",CA_distance,CA_speed);
	CA_speed = 30;
	DC_motor(CA_speed);
}


