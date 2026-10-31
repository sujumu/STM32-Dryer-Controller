/*
 * HeaterControl.h
 *
 *  Created on: 2026. 10. 11.
 *      Author: 20201
 */

#ifndef INC_HEATERCONTROL_H_
#define INC_HEATERCONTROL_H_
#include "controlType.h"
void Heater_Init();
void HeaterON();
void HeaterOFF();
void SetTemperature(int temp);
void HeaterControl(float temp);
t_OnOff getHeaterState();
int getTarget();
#endif /* INC_HEATERCONTROL_H_ */
