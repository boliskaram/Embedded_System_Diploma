/*
 * Utils.h
 *
 * Created: 6/6/2022 11:55:54 PM
 *  Author: Bolis
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define SET_BIT(ADDRESS, BIT)		ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT)		ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS, BIT)	ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS, BIT)		((ADDRESS & (1<<BIT))>>BIT)


#endif /* UTILS_H_ */