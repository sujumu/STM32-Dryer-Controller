/*
 * FND_CONTROLL.h
 *
 *  Created on: Sep 30, 2026
 *      Author: 20201
 */

#ifndef INC_FND_CONTROLL_H_
#define INC_FND_CONTROLL_H_

#include "main.h"
void init_a();
extern uint8_t _LED_0F[29];
void send_a(uint8_t X);
void send_b(uint8_t X, uint8_t port);
void digit4_temper(int temper);


#endif /* INC_FND_CONTROLL_H_ */
