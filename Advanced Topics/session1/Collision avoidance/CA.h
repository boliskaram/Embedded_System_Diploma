/*
 * CA.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Bolis
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum{
	CA_waiting,
	CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);
extern void (*CA_state)();

#endif /* CA_H_ */
