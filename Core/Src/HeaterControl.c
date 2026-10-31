/*
 * HeaterControl.c
 *
 *  Created on: 2026. 10. 11.
 *      Author: 20201
 */
#include "HeaterControl.h"
#include "button_controll.h"
#include "ledcontroll.h"
#include "main.h"


static uint8_t m_state = 0;
static uint8_t target_temp = USUALLY;

void Heater_Init(){
	HeaterOFF();
}
void HeaterControl(float temp){
	if (!m_state) {
		if ((int) temp <= (target_temp-GAP)) {
			HeaterON();
		}
	} else {
		if ((int) temp >= (target_temp+GAP)) {
			HeaterOFF();
		}
	}
}

void HeaterON(){
	HAL_GPIO_WritePin(PB5_RELAY_GPIO_Port, PB5_RELAY_Pin, t_ON);
	Heater_ON_LED();
	m_state = 1;
}
void HeaterOFF(){
	HAL_GPIO_WritePin(PB5_RELAY_GPIO_Port, PB5_RELAY_Pin, t_OFF);
	Heater_OFF_LED();
	m_state = 0;
}
void SetTemperature(int temp){
	target_temp = temp;
}

int getTarget(){
	return target_temp;
}

t_OnOff getHeaterState(){
	if(m_state){
		return t_ON;
	}else{
		return t_OFF;
	}
}


