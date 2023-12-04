/*
 * button.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


//#define NO_OF_BUTTONS	3
//#define DURATION_FOR_AUTO_INCREASING 100
//#define BUTTON_IS_PRESSED            GPIO_PIN_RESET
//#define BUTTON_IS_RELEASED			GPIO_PIN_SET
//#include "global.h"
//void button_reading(void);
//int is_button_pressed(int index);
//int is_button_pressed_1s(int index);

#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define N_BUTTON 3
int isButtonPressed(int i);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
