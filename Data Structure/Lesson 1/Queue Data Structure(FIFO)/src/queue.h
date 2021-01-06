/*
 * queue.h
 *
 *  Created on: Jan 3, 2021
 *      Author: Bolis
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdint.h"

// set element type

#define el_type uint8_t
#define size 5

el_type uart_queue_buf[size];

typedef struct {
	unsigned int length;
	unsigned int count;
	el_type* base;
	el_type* head;
	el_type* tail;
}queue_t;

typedef enum{
	queue_No_Error,
	queue_Full,
	queue_Empty,
	queue_Null
}queue_status;

queue_status Queue_init(queue_t* queue_buf, el_type* buf , uint32_t length);
queue_status Queue_add(queue_t* queue_buf, el_type item);
queue_status Queue_get(queue_t* queue_buf, el_type* item);
queue_status Queue_is_full(queue_t* queue_buf);
queue_status Queue_is_empty(queue_t* queue_buf);
void Queue_print(queue_t* queue_buf);


#endif /* QUEUE_H_ */
