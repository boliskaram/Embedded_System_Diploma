/*
 * Timer.h
 *
 * Created: 6/7/2022 12:16:18 AM
 *  Author: Bolis
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include "avr/io.h"
#include "avr/interrupt.h"
#include "../../infrastructure/Types.h"
#include "../../infrastructure/Utils.h"

/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/
typedef enum {
	NORMAL,
	CTC = 0x08
}TIMER0_MODE_t;

typedef enum {
	NO_CLK_SRC,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING
}TIMER0_CLK_t;

typedef enum {
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE = 0x01
}TOVFIE0_MODE_t;

typedef enum {
	OCIE_DISABLE = 0x00,
	OCIE_ENABLE = 0x02
}OCMIE0_MODE_t;

/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/
typedef struct{
	TIMER0_MODE_t MODE;
	TIMER0_CLK_t CLK;
	TOVFIE0_MODE_t TOVF_Interrupt;
	OCMIE0_MODE_t OCM_Interrupt;
}TIMER0_CONFIG_t;


/******************************************************************************
*									APIS				                      *
*******************************************************************************/

E_STATUS_t TIMER0_Init(TIMER0_CONFIG_t* T_CONFIG);
E_STATUS_t TIMER0_Stop();

E_STATUS_t TIMER0_GetCompareVal(p_uint8_t pu8_TickNum);
E_STATUS_t TIMER0_SetCompareVal(uint8_t u8_TickNum);

E_STATUS_t TIMER0_GetCounterVal(p_uint8_t pu8_TickNum);
E_STATUS_t TIMER0_SetCounterVal(uint8_t u8_TickNum);

E_STATUS_t TIMER0_GetOverflowVal(p_uint8_t pu8_TickNum);
E_STATUS_t TIMER0_SetOverflowVal(uint8_t u8_TickNum);

void TIMER0_CALLBACK_Overflow_INTERRUPT(p_VfunV callback);
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(p_VfunV callback);

#endif /* TIMER_H_ */