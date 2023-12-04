/*
 * button.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */

//#include "button.h"
//
//
//static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
//static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
//int button_flag[NO_OF_BUTTONS] = {0,0,0};
//
//GPIO_TypeDef *buttons[NO_OF_BUTTONS] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
//uint16_t buttonpins[NO_OF_BUTTONS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};
//
//void button_reading(void){
//	for(int i = 0; i<NO_OF_BUTTONS; i++){
//		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
//		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttons[i], buttonpins[i]);
//		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
//			buttonBuffer[i] = debounceButtonBuffer1[i];
//			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
//				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
//					counterForButtonPress1s[i] ++;
//				}
//				else{
//					flagForButtonPress1s[i] = 1;
//				}
//			}
//			else{
//				counterForButtonPress1s[i] = 0;
//				flagForButtonPress1s[i] = 0;
//			}
//		}
//	}
//}
//
//int is_button_pressed(int index){
//	if(index >= NO_OF_BUTTONS) return 0;
//	if(button_flag[index]){
//		button_flag[index] = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int is_button_pressed_1s(int index){
//	if(index >= NO_OF_BUTTONS) return 0;
//	return (flagForButtonPress1s[index] == 1);
//}

#include "button.h"
int KeyReg0[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress[N_BUTTON] = {200, 200, 200};
int button_flag[N_BUTTON] = {0, 0, 0};
GPIO_TypeDef* but[N_BUTTON] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
uint16_t pin[N_BUTTON] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int isButtonPressed(int i){
	if(button_flag[i]){
		button_flag[i] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int i){
	button_flag[i] = 1;
}

void getKeyInput(){
	for(int i =0; i<N_BUTTON; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(but[i], pin[i]);
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					TimerForKeyPress[i] = 200;
				}
			}
			else{
				TimerForKeyPress[i] --;
				if(TimerForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}



