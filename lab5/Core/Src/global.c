/*
 * global.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */

#include "global.h"
#include <string.h>
#include <stdio.h>

int status = 0;
int led_buffer[4] = {0,0,0,0};
int index_buffer = 0;
int counter1 = 0;
int counter2 = 0;
int modify_val = 0;
int red_timer = 5;
int amber_timer = 2;
int green_timer = 3;
int TF_buffer[4] = {RED_GREEN, RED_AMBER, GREEN_RED, AMBER_RED};
int index_normal_state = 0;

void initialize(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//	init_timer();
	status = RED_GREEN;
	counter1 = red_timer;
	counter2 = green_timer;
}

void red_green(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
}
void red_amber(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void green_red(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void amber_red(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void blink_red(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void blink_amber(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_TogglePin(AMBER1_GPIO_Port, AMBER1_Pin);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_TogglePin(AMBER2_GPIO_Port, AMBER2_Pin);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
}
void blink_green(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
}

void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}
void update7SEG(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_buffer[3]);
		break;
	default:
		break;
	}
}
void updateBuffer(){
	switch(status){
	case MAN_RED:
		led_buffer[0] = 0;
		led_buffer[1] = 2;
		led_buffer[2] = modify_val / 10;
		led_buffer[3] = modify_val % 10;
		break;
	case MAN_AMBER:
		led_buffer[0] = 0;
		led_buffer[1] = 3;
		led_buffer[2] = modify_val / 10;
		led_buffer[3] = modify_val % 10;
		break;
	case MAN_GREEN:
		led_buffer[0] = 0;
		led_buffer[1] = 4;
		led_buffer[2] = modify_val / 10;
		led_buffer[3] = modify_val % 10;
		break;
	default:
		led_buffer[0] = counter1 / 10;
		led_buffer[1] = counter1 % 10;
		led_buffer[2] = counter2 / 10;
		led_buffer[3] = counter2 % 10;
		break;
	}
}
void clearTerminal(){
	char clr[] = "\x0C";
	HAL_UART_Transmit(&huart2, (uint8_t *)clr, sizeof(clr) - 1, HAL_MAX_DELAY);
}
void printString(const char *str){
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}
void printValue(int val){
	char str[100];
	HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%d\r\n", val), HAL_MAX_DELAY);
}
void displayTLValues(){
	clearTerminal();
	switch(status){
	case RED_GREEN:
		printString("RED: ");
		printValue(counter1);
		printString("GREEN: ");
		printValue(counter2);
		break;
	case RED_AMBER:
		printString("RED: ");
		printValue(counter1);
		printString("AMBER: ");
		printValue(counter2);
		break;
	case GREEN_RED:
		printString("GREEN: ");
		printValue(counter1);
		printString("RED: ");
		printValue(counter2);
		break;
	case AMBER_RED:
		printString("GREEN: ");
		printValue(counter1);
		printString("AMBER: ");
		printValue(counter2);
		break;
	default:
		break;
	}
}

void blinkLEDs(void ){
	switch(status){
	case MAN_RED:
		HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
		HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
		HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	case MAN_AMBER:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_TogglePin(AMBER1_GPIO_Port, AMBER1_Pin);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_TogglePin(AMBER2_GPIO_Port, AMBER2_Pin);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
		HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
		HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
		break;
	default:
		break;
	}
}
void scan7SEG(void ){
	switch(index_buffer){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_buffer[3]);
		break;
	default:
		break;
	}
	index_buffer++;
	if(index_buffer >= 4) index_buffer = 0;
}
void routine_1sec(void ){
	switch(status){
	case RED_GREEN:
	case RED_AMBER:
	case GREEN_RED:
	case AMBER_RED:
		counter1--;
		counter2--;
		break;
	default:
		break;
	}
	if(counter1 < 0 || counter2 < 0){
		switch (status) {
		case RED_GREEN:
			status = RED_AMBER;
			counter2 = amber_timer - 1;
			break;
		case RED_AMBER:
			status = GREEN_RED;
			counter1 = green_timer - 1;
			counter2 = red_timer - 1;
			break;
		case GREEN_RED:
			status = AMBER_RED;
			counter1 = amber_timer - 1;
			break;
		case AMBER_RED:
			status = RED_GREEN;
			counter1 = red_timer - 1;
			counter2 = green_timer - 1;
			break;
		default:
			break;
		}
	}
	switch(status){
	case RED_GREEN:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
		break;
	case RED_AMBER:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	case AMBER_RED:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		break;
	default:
		break;
	}
}
void button_signal(){
	updateBuffer();
	if(isButtonPressed(0)){
		switch(status){
		case RED_GREEN:
		case RED_AMBER:
		case GREEN_RED:
		case AMBER_RED:
			modify_val = red_timer;
			status = MAN_RED;
			break;
		case MAN_RED:
			modify_val = amber_timer;
			status = MAN_AMBER;
			break;
		case MAN_AMBER:
			modify_val = green_timer;
			status = MAN_GREEN;
			break;
		case MAN_GREEN:
			counter1 = red_timer - 1;
			counter2 = green_timer - 1;
			status = RED_GREEN;
			break;
		default:
			break;
		}
	}
	if(isButtonPressed(1)){
		switch(status){
		case MAN_RED:
		case MAN_AMBER:
		case MAN_GREEN:
			modify_val++;
			if(modify_val > 99){
				modify_val = 1;
			}
			break;
		default:
			break;
		}
	}
	if(isButtonPressed(2)){
		switch(status){
		case MAN_RED:
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
			break;
		case MAN_AMBER:
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
			break;
		case MAN_GREEN:
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
			break;
		default:
			break;
		}
	}
}

















