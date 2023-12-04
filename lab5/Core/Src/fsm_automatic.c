/*
 * fsm_automatic.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	updateBuffer();
	switch(status){
	case INIT:
		clearTerminal();
		printString("MODE 1\r\n");
		initialize();
		displayTLValues();
		setTimer(0, green_timer * 1000);
		setTimer(1, 1000);
		setTimer(2, 100);
		status = RED_GREEN;
		break;
	case RED_GREEN:
		red_green();
		if(timer_flag[1]){
			displayTLValues();
			setTimer(1, 1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[0]){
			setTimer(0, amber_timer * 1000);
			counter2 = amber_timer - 1;
			status = RED_AMBER;
		}
		if(isButtonPressed(0)){
			setTimer(3, 250);
			modify_val = red_timer;
			status = MAN_RED;
			clearTerminal();
			printString("MODE 2\r\n");
		}
		break;
	case RED_AMBER:
		red_amber();
		if(timer_flag[1]){
			displayTLValues();
			setTimer(1, 1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[0]){
			setTimer(0, green_timer * 1000);
			counter1 = green_timer - 1;
			counter2 = red_timer - 1;
			status = GREEN_RED;
		}
		if(isButtonPressed(0)){
			setTimer(3, 250);
			modify_val = red_timer;
			status = MAN_RED;
			clearTerminal();
			printString("MODE 2\r\n");
		}
		break;
	case GREEN_RED:
		green_red();
		if(timer_flag[1]){
			displayTLValues();
			setTimer(1, 1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[0]){
			setTimer(0, amber_timer * 1000);
			counter1 = amber_timer -1;
			status = AMBER_RED;
		}
		if(isButtonPressed(0)){
			setTimer(3, 250);
			modify_val = red_timer;
			status = MAN_RED;
			clearTerminal();
			printString("MODE 2\r\n");
		}
		break;
	case AMBER_RED:
		amber_red();
		if(timer_flag[1]){
			displayTLValues();
			setTimer(1, 1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
		}
		if(timer_flag[2]){
			setTimer(2, 100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(timer_flag[0]){
			setTimer(0, green_timer * 1000);
			counter1 = red_timer - 1;
			counter2 = green_timer - 1;
			status = RED_GREEN;
		}
		if(isButtonPressed(0)){
			setTimer(3, 250);
			modify_val = red_timer;
			status = MAN_RED;
			clearTerminal();
			printString("MODE 2\r\n");
		}
		break;
	default:
		break;
	}
}

