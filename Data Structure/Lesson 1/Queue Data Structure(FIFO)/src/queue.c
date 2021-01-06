/*
 * queue.c
 *
 *  Created on: Jan 3, 2021
 *      Author: Bolis
 */
#include "queue.h"
#include "stdio.h"
queue_status Queue_init(queue_t* queue_buf, el_type* buf , uint32_t length){

	if(buf == NULL)
		return queue_Full;
	queue_buf->base = buf;
	queue_buf->head = buf;
	queue_buf->tail = buf;
	queue_buf->length = length;
	queue_buf->count = 0 ;

	return queue_No_Error;
}
queue_status Queue_add(queue_t* queue_buf, el_type item){

	if(!queue_buf->base || !queue_buf->head || !queue_buf->tail)
		return queue_Null;

	if(Queue_is_full(queue_buf)== queue_Full)
		return queue_Full;

	*(queue_buf->head)=item;
	queue_buf->count++;

	if(queue_buf->head == (queue_buf->base + (queue_buf->length * sizeof(el_type))))
		queue_buf->head = queue_buf->base  ;
	else
		queue_buf->head++;

	return queue_No_Error;
}
queue_status Queue_get(queue_t* queue_buf, el_type* item){

	if(!queue_buf->base || !queue_buf->head || !queue_buf->tail)
		return queue_Null;
	if(Queue_is_empty(queue_buf)== queue_Empty)
		return queue_Empty;
	*item = *(queue_buf->tail);
	queue_buf->count--;
	if(queue_buf->tail == (queue_buf->base + (queue_buf->length * sizeof(el_type))))
		queue_buf->tail = queue_buf->base  ;
	else
		queue_buf->tail++;

	return queue_No_Error;
}
queue_status Queue_is_full(queue_t* queue_buf){

	if(!queue_buf->base && !queue_buf->head && !queue_buf->tail)
		return queue_Null;
	if(queue_buf->count == queue_buf->length)
		return queue_Full;
	return queue_No_Error;
}
queue_status Queue_is_empty(queue_t* queue_buf){

	if(!queue_buf->base && !queue_buf->head && !queue_buf->tail)
		return queue_Null;
	if(queue_buf->count == 0)
		return queue_Full;
	return queue_No_Error;
}
void Queue_print(queue_t* queue_buf){
	el_type* temp;
	el_type i;
	if(Queue_is_empty(queue_buf)== queue_Empty)
		printf("Queue is empty\n");
	else
		temp = queue_buf->tail;
	for(i=0;i<queue_buf->count;i++){
		printf("\tprint from queue: %x \n",*temp);
		temp++;
	}
}

