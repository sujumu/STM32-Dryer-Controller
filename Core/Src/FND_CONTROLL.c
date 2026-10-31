#include "FND_CONTROLL.h"
#define false 0
#define true 1

static SPI_HandleTypeDef * hspi;
uint8_t _LED_0F[29];
void init_a(SPI_HandleTypeDef * mspi){
	 hspi = mspi;
	_LED_0F[0] = 0xC0; //0
	_LED_0F[1] = 0xF9; //1
	_LED_0F[2] = 0xA4; //2
	_LED_0F[3] = 0xB0; //3
	_LED_0F[4] = 0x99; //4
	_LED_0F[5] = 0x92; //5
	_LED_0F[6] = 0x82; //6
	_LED_0F[7] = 0xF8; //7
	_LED_0F[8] = 0x80; //8
	_LED_0F[9] = 0x90; //9
	_LED_0F[10] = 0x88; //A
	_LED_0F[11] = 0x83; //b
	_LED_0F[12] = 0xC6; //C
	_LED_0F[13] = 0xA1; //d
	_LED_0F[14] = 0x86; //E
	_LED_0F[15] = 0x8E; //F
	_LED_0F[16] = 0xC2; //G
	_LED_0F[17] = 0x89; //H
	_LED_0F[18] = 0xF9; //I
	_LED_0F[19] = 0xF1; //J
	_LED_0F[20] = 0xC3; //L
	_LED_0F[21] = 0xA9; //n
	_LED_0F[22] = 0xC0; //O
	_LED_0F[23] = 0x8C; //P
	_LED_0F[24] = 0x98; //q
	_LED_0F[25] = 0x92; //S
	_LED_0F[26] = 0xC1; //U
	_LED_0F[27] = 0x91; //Y
	_LED_0F[28] = 0xFE; //hight -
}

void send_a(uint8_t X) {

	/*for (int i = 8; i >= 1; i--) {
		if (X & 0x80) {
			HAL_GPIO_WritePin(DIO_GPIO_Port, DIO_Pin, 1);
		} else {
			HAL_GPIO_WritePin(DIO_GPIO_Port, DIO_Pin, 0);
		}
		X <<= 1;
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
	}*/
	HAL_SPI_Transmit(hspi, &X, 1, 100);
}

void send_b(uint8_t X, uint8_t port) {
	send_a(X);
	send_a(port);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, 0);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, 1);
}

static uint8_t m_tempercount = 0;
void digit4_temper(int temper) {
	int n1, n2, n3, n4;

	n1 = temper % 10;
	n2 = (temper / 10) % 10;
	n3 = (temper / 100) % 10;
	n4 = (temper / 1000) % 10;

	switch (m_tempercount) {
	case 0:
		send_b(_LED_0F[n1], 0b0001);
		break;

	case 1:
		send_b(_LED_0F[n2] & 0x7F, 0b0010);
		break;
	case 2:
		if (temper > 99)
			send_b(_LED_0F[n3], 0b0100);
		break;
	case 3:
		if (temper > 999)
			send_b(_LED_0F[n4], 0b1000);
		break;
	default:
		break;
	}
	m_tempercount++;
    if (temper <= 99 && m_tempercount >= 2)
    {
        m_tempercount = 0;
    }
    else if (temper <= 999 && m_tempercount >= 3)
    {
        m_tempercount = 0;
    }
    else if (m_tempercount >= 4)
    {
        m_tempercount = 0;
    }
}







