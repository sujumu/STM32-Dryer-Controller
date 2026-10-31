/*
 * serial_studio.c
 *
 *  Created on: Oct 22, 2026
 *      Author: 20201
 */
#include "main.h"
#include "serial_studio.h"
#include "HeaterControl.h"
#include "ds18b20.h"
#include "controlType.h"
#include "stdio.h"

static char tx_buff[64];
static volatile uint8_t uart_tx_busy = 0;
void serial_studio_TX(UART_HandleTypeDef *handle) {
	if(uart_tx_busy){
		return;
	}
	t_OnOff heater = getHeaterState();
	int target = getTarget();
	float temp = getCurrentTemp();
	int len = snprintf(tx_buff, sizeof(tx_buff), "%.1f, %d, %d\r\n", temp,
			target, heater);
	if (len > 0 && len < sizeof(tx_buff)) {
		uart_tx_busy = 1;
		if((HAL_UART_Transmit_DMA(handle, (uint8_t*) tx_buff, len) != HAL_OK)){
			uart_tx_busy = 0;
		}
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART2)
    {
        uart_tx_busy = 0;
    }
}



