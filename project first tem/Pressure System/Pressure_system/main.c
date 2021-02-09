/*
 * @file           : main.c
 * @author         : Bolis Karam
 */
#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "Alarm_Control.h"

int main (){
	GPIO_INITIALIZATION();
	int Pvalue ;
	int threshold = 20;
	while (1)
	{
		Pvalue = getPressureVal();
		if (Pvalue > threshold){
			High_pressure_detected();
		}
		Delay(200000);
	}
}
