/*
 * mian.c
 *
 *  Created on: Jan 23, 2021
 *      Author: Bolis
 */

#include "CA.h"
#include "US.h"
#include "DC.h"
void setup(){

	US_init();
	DC_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

void main() {

	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
	}
}

