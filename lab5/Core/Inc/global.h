/*
 * global.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "input_processing.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"

#define DEFAULT_RED 5
#define DEFAULT_AMBER 2
#define DEFAULT_GREEN 3

#define INIT 1
#define RED_GREEN 2
#define RED_AMBER 3
#define GREEN_RED 4
#define AMBER_RED 5

#define MAN_RED 6
#define MAN_AMBER 7
#define MAN_GREEN 8

extern int status;
int red_timer;
int amber_timer;
int green_timer;
int led_buffer[4];
int index_buffer;
int index_led;
int counter1;
int counter2;
int modify_val;
extern UART_HandleTypeDef huart2;

void red_green();
void red_amber();
void green_red();
void green_amber();
void blink_red();
void blink_amber();
void blink_green();
void updateBuffer();
void update7SEG(int);
void clearTerminal();
void printString(const char*);
void printValue(int);
void displayTLValues();
void button_signal();
void routine_1sec(void );
void scan7SEG(void );
void blinkLEDs(void );

#endif /* INC_GLOBAL_H_ */
