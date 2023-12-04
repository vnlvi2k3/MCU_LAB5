/*
 * fsm_manual.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */
#include "fsm_manual.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>
char str[100];

void fsm_manual_run(){
	switch(status){
	updateBuffer();
	case MAN_RED:
		if(isButtonPressed(0)){
			modify_val = amber_timer;
			clearTerminal();
			printString("MODE 3\r\n");
			status = MAN_AMBER;
		}
		if(isButtonPressed(1)){
			if((modify_val <= 1) || (modify_val >= 99)){
				modify_val = 2;
			}
			else{
				modify_val ++;
			}
			printString("INCREASE RED TIMER : ");
			printValue(modify_val);
		}
		if(isButtonPressed(2)){
			red_timer = modify_val;
			if(red_timer >= (green_timer + amber_timer)){
				green_timer = red_timer - amber_timer;
			}
			else{
				int half = red_timer / 2;
				int mod = red_timer % 2;
				amber_timer = half;
				green_timer = half + mod;
			}
			clearTerminal();
			printString("SET RED TIMER : ");
			printValue(red_timer);
		}
		if(timer_flag[0]){
			setTimer(0, 1000);
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[3]){
			setTimer(3, 250);
			blink_red();
		}
		break;
	case MAN_AMBER:
		if(isButtonPressed(0)){
			modify_val = green_timer;
			clearTerminal();
			printString("MODE 4\r\n");
			status = MAN_GREEN;
		}
		if(isButtonPressed(1)){
			if(modify_val >= 98){
				modify_val = 1;
			}
			else{
				modify_val++;
			}
			printString("INCREASE AMBER TIMER : ");
			printValue(modify_val);
		}
		if(isButtonPressed(2)){
			amber_timer = modify_val;
			if(red_timer >= (amber_timer + green_timer)){
				green_timer = red_timer - amber_timer;
			}
			else{
				if((green_timer + amber_timer) <= 99){
					red_timer = green_timer + amber_timer;
				}
				else{
					red_timer = 99;
					green_timer = red_timer - amber_timer;
				}
			}
			clearTerminal();
			printString("SET AMBER TIMER : ");
			printValue(amber_timer);
		}
		if(timer_flag[0]){
			setTimer(0, 1000);
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[3]){
			setTimer(3, 250);
			blink_amber();
		}
		break;
	case MAN_GREEN:
		if(isButtonPressed(0)){
			counter1 = red_timer - 1;
			counter2 = green_timer - 1;
			setTimer(0, green_timer * 1000);
			clearTerminal();
			printString("MODE 1\r\n");
			status = RED_GREEN;
		}
		if(isButtonPressed(1)){
			if(modify_val >= 98){
				modify_val = 1;
			}
			else{
				modify_val++;
			}
			printString("INCREASE GREEN TIMER : ");
			printValue(modify_val);
		}
		if(isButtonPressed(2)){
			if(red_timer >= (green_timer + amber_timer)){
				amber_timer = red_timer - green_timer;
			}
			else{
				if((amber_timer + green_timer) <= 99){
					red_timer = amber_timer + green_timer;
				}
				else{
					red_timer = 99;
					amber_timer = red_timer - green_timer;
				}
			}
			clearTerminal();
			printString("SET GREEN TIMER : ");
			printValue(green_timer);
		}
		if(timer_flag[0]){
			setTimer(0, 1000);
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[3]){
			setTimer(3, 250);
			blink_green();
		}
		break;
	default:
		break;
	}
}
