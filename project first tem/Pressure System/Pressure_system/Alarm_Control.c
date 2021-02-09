#include "Alarm_Control.h"
int Time_Of_alarm = 200000; // assume 1 minute
void High_pressure_detected(){
	Set_Alarm_actuator(1);
	Delay(Time_Of_alarm);
	Set_Alarm_actuator(0);
	Delay(Time_Of_alarm);
}
