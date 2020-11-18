/*
 * platform_types.h
 *
 *  Created on: Nov 18, 2020
 *      Author: Bolis
 */
#include <stdint.h>

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef _Bool 				boolean_t;
typedef signed char 		sint8_t;
typedef unsigned char 		uint8_t;
typedef signed short  		sint16_t;
typedef unsigned short  	uint16_t;
typedef signed int  		sint32_t;
typedef unsigned int  		uint32_t;
typedef signed long long	sint64_t;
typedef unsigned long long	uint64_t;

typedef volatile signed char    	vint8_t;
typedef volatile unsigned char  	vuint8_t;
typedef volatile signed short   	vint16_t;
typedef volatile unsigned short		vuint16_t;
typedef volatile signed int	    	vint32_t;
typedef volatile unsigned int		vuint32_t;
typedef volatile signed long long	vint64_t;
typedef volatile unsigned long long	vuint64_t;

#endif /* PLATFORM_TYPES_H_ */
