/*
 * ledcontroll.c
 *
 *  Created on: 2026. 10. 21.
 *      Author: 20201
 */
#include "main.h"
#include "ledcontroll.h"

void Heater_OFF_LED(){
	HAL_GPIO_WritePin(PC8_LED2_GPIO_Port, PC8_LED2_Pin, 0);
	HAL_GPIO_WritePin(PC7_LED1_GPIO_Port, PC7_LED1_Pin, 1);
}

void Heater_ON_LED(){
	HAL_GPIO_WritePin(PC8_LED2_GPIO_Port, PC8_LED2_Pin, 1);
	HAL_GPIO_WritePin(PC7_LED1_GPIO_Port, PC7_LED1_Pin, 0);
}
