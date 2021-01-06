/*
 ============================================================================
 Name        : Queue.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
	el_type i, data;
	queue_t uart_queue;
		if(Queue_init(&uart_queue,uart_queue_buf,5) == queue_No_Error)
			printf("queue initialized\n");

		for(i=0;i<sizeof(uart_queue_buf)+2;i++){
			if(Queue_add(&uart_queue , i) == queue_No_Error ){
				printf("\tadd (%X) in queue done\n",i);
			}else
				printf("add (%X) in queue failed\n",i);
		}
		Queue_print(&uart_queue);
		if(Queue_get(&uart_queue,&data) == queue_No_Error)
			printf("get data from queue: %x \n",data);
		if(Queue_get(&uart_queue,&data) == queue_No_Error)
			printf("get data from queue: %x \n",data);
		Queue_print(&uart_queue);


}
