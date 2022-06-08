/*
 * Types.h
 *
 * Created: 6/6/2022 11:55:20 PM
 *  Author: Bolis
 */ 


#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char uint8_t;
typedef char sint8_t;

typedef unsigned char* p_uint8_t ;
typedef char* p_sint8_t;

typedef void(*p_VfunV)(void);
#define NULL_Ptr	((void*) (0))

typedef unsigned char E_STATUS_t;

#define E_OK	(E_STATUS_t)(0)
#define E_NOK	(E_STATUS_t)(1)

#endif /* TYPES_H_ */