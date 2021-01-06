/*
 ============================================================================
 Name        : Stack.c
 Author      : Bolis Karam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main(void) {
	el_type i, data;

		stack_t uart_stack;
		if(Stack_init(&uart_stack,uart_stack_buf,5) == stack_No_Error)
			printf("stack initialized\n");

		for(i=0;i<sizeof(uart_stack_buf)+2;i++){
			if(Stack_add(&uart_stack , i) == stack_No_Error ){
				printf("\tadd (%X) in stack done\n",i);
			}else
				printf("add (%X) in stack failed\n",i);
		}
		Stack_print(&uart_stack);
		if(Stack_get(&uart_stack,&data) == stack_No_Error)
			printf("get data from stack: %x \n",data);
		if(Stack_get(&uart_stack,&data) == stack_No_Error)
			printf("get data from stack: %x \n",data);
		if(Stack_get(&uart_stack,&data) == stack_No_Error)
				printf("get data from stack: %x \n",data);
		if(Stack_get(&uart_stack,&data) == stack_No_Error)
				printf("get data from stack: %x \n",data);
		if(Stack_get(&uart_stack,&data) == stack_No_Error)
				printf("get data from stack: %x \n",data);
		if(Stack_get(&uart_stack,&data) == stack_No_Error)
				printf("get data from stack: %x \n",data);
		Stack_print(&uart_stack);
}
