/*
 * stack.h
 *
 *  Created on: Jan 3, 2021
 *      Author: Bolis
 */

#ifndef STACK_H_
#define STACK_H_

#include "stdint.h"

#define el_type uint8_t
#define size 5
el_type uart_stack_buf[size];
typedef struct {
	unsigned int length;
	unsigned int count;
	el_type* base;
}stack_t;

typedef enum{
	stack_No_Error,
	stack_Full,
	stack_Empty,
	stack_Null
}stack_status;

stack_status Stack_init(stack_t* stack_buf, el_type* buf , uint32_t length);
stack_status Stack_add(stack_t* stack_buf, el_type item);
stack_status Stack_get(stack_t* stack_buf, el_type* item);
stack_status Stack_is_full(stack_t* stack_buf);
stack_status Stack_is_empty(stack_t* stack_buf);
void Stack_print(stack_t* stack_buf);
#endif /* STACK_H_ */
