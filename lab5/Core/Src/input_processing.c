/*
 * input_processing.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Lan Vi
 */

#include "input_processing.h"

//enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1S};
//enum ButtonState buttonState[NO_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};
//int button_signal[NO_OF_BUTTONS] = {0,0,0};
//int timerForKeyPress[NO_OF_BUTTONS] = {2000, 2000, 2000};

void fsm_for_input_processing(){
//	for(int i =0 ; i< NO_OF_BUTTONS; i++){
//		switch(buttonState[i]){
//		case BUTTON_RELEASED:
//			if(is_button_pressed(i)){
//				button_signal[i] = 1;
//				buttonState[i] = BUTTON_PRESSED;
//			}
//			break;
//		case BUTTON_PRESSED:
//			if(!is_button_pressed(i)){
//				button_signal[i] = 0;
//				buttonState[i] = BUTTON_RELEASED;
//			}
//			else{
//				if(is_button_pressed_1s(i)){
//					timerForKeyPress[i] = 2000;
//					buttonState[i] = BUTTON_PRESSED_MORE_THAN_1S;
//				}
//			}
//			break;
//		case BUTTON_PRESSED_MORE_THAN_1S:
//			if(!is_button_pressed(i)){
//				button_signal[i] = 0;
//				buttonState[i] = BUTTON_RELEASED;
//			}
//			timerForKeyPress[i]--;
//			if(timerForKeyPress[i] == 0){
//				button_signal[i] = 1;
//				buttonState[i] = BUTTON_PRESSED;
//			}
//			break;
//		default:
//			break;
//		}
//	}
}
