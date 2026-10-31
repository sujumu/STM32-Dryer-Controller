/*
 * button_controll.c
 *
 *  Created on: Oct 20, 2026
 *      Author: 20201
 */

#include "HeaterControl.h"
#include "button_controll.h"
#include "oled_controll.h"
#include "controlType.h"

static int count = USUALLY;
void button_controll(uint16_t GPIO_Pin) {
	// SWITCH1 : SETTING TEMP TO UP
	if (GPIO_Pin == PC10_SET_UP_Pin) {
		count++;
		if (count > 99) {
			count = 0;
		}
		Print_temper(count);
	}

	// SWITCH2 : SETTING TEMP TO DOWN
	else if (GPIO_Pin == PC11_SET_DOWN_Pin) {
		count--;
		if (count < 0) {
			count = 99;
		}
		Print_temper(count);
	}

	// SWITCH3 : FIX TEMP
	else if (GPIO_Pin == PC12_SET_TARGET_Pin) {
		SetTemperature(count);
		Print_Target(count);
	}
}

t_OnOff Start_button(){
	if(HAL_GPIO_ReadPin(PC6_START_SW_PIN_GPIO_Port, PC6_START_SW_PIN_Pin)){
	return t_ON;
}else{
	return t_OFF;
}
}

