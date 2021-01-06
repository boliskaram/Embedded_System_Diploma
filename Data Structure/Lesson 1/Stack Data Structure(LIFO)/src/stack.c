/*
 * stack.c
 *
 *  Created on: Jan 3, 2021
 *      Author: Bolis
 */

#include "stack.h"
#include "stdio.h"

stack_status Stack_init(stack_t* stack_buf, el_type* buf,uint32_t length)
{
	if(buf == NULL)
		return stack_Full;
	stack_buf->base = buf;
	stack_buf->length = length;
	stack_buf->count = 0 ;

	return stack_No_Error;
}
stack_status Stack_add(stack_t* stack_buf, el_type item){

	//	buffer is valid
	if(!stack_buf->base)
		return stack_Null;
	//	buffer is full

	if(Stack_is_full(stack_buf)== stack_Full)
		return stack_Full;
	//	add item
	*(stack_buf->base) = item;
	//	next address
	stack_buf->base++;
	//	increment counter
	stack_buf->count++;

	return stack_No_Error ;
}
stack_status Stack_get(stack_t* stack_buf, el_type* item){
	//	buffer is valid
	if(!stack_buf->base)
		return stack_Null;

	if(Stack_is_empty(stack_buf)== stack_Empty)
		return stack_Empty;

	stack_buf->base--;
	*item = *(stack_buf->base);
	stack_buf->count--;

	return stack_No_Error;
}
stack_status Stack_is_full(stack_t* stack_buf){
	if(!stack_buf->base)
		return stack_Null;
	if(stack_buf->count == stack_buf->length)
		return stack_Full;
	return stack_No_Error;
}
stack_status Stack_is_empty(stack_t* stack_buf){
	if(!stack_buf->base)
		return stack_Null;
	if(stack_buf->count == 0)
		return stack_Empty;
	return stack_No_Error;
}
void Stack_print(stack_t* stack_buf){
	el_type* temp;
	el_type i;
	if(Stack_is_empty(stack_buf)== stack_Empty)
		printf("stack is empty \n");
	else
		temp = stack_buf->base;
	for(i=0;i<stack_buf->count;i++){
		temp--;
		printf("\tprint from stack: %x \n",*temp);

	}
}

