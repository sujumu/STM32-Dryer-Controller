/*
 * oled_controll.c
 *
 *  Created on: Oct 20, 2026
 *      Author: 20201
 */
#include "oled_image.h"
#include "ssd1306.h"
#include "fonts.h"
#include "main.h"
#include "stdio.h"
#include "controlType.h"
#include "oled_controll.h"

void Display_first() {
	SSD1306_InvertDisplay(0);
	LOGO_IM();
	HAL_Delay(2000);
	SSD1306_Clear();
	SSD1306_GotoXY(0, 0);
	SSD1306_Puts("HELLO", &Font_11x18, 1);
	SSD1306_UpdateScreen();
	HAL_Delay(2000);
	SSD1306_Clear();
	SSD1306_GotoXY(17, 8);
	SSD1306_Puts("Temper", &Font_7x10, 1);
	SSD1306_GotoXY(75, 8);
	SSD1306_Puts("Target", &Font_7x10, 1);
	SSD1306_GotoXY(0, 23);
	SSD1306_Puts("------------", &Font_11x18, 1);
	SSD1306_GotoXY(10, 40);
	SSD1306_Puts("0.00", &Font_11x18, 1);
	SSD1306_GotoXY(73, 40);
	SSD1306_Puts(USUALLY_CHAR, &Font_11x18, 1);
	SSD1306_UpdateScreen();
}

void Print_temper(int temper){
	char temper_str[100]={0};
	SSD1306_GotoXY(10,40);
	sprintf(temper_str, "%2d.0", temper);
	SSD1306_Puts(temper_str, &Font_11x18, 1);
	SSD1306_UpdateScreen();
}

void Print_Target(int target){
	char target_str[100]={0};
	SSD1306_GotoXY(73,40);
	sprintf(target_str, "%2d.0", target);
	SSD1306_Puts(target_str, &Font_11x18, 1);
	SSD1306_UpdateScreen();
}



