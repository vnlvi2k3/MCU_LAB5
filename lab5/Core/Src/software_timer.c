/*
 * software_timer.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */

#include "software_timer.h"

int timer_flag[MAX_TIMER];
int timer_counter[MAX_TIMER];

void init_timer(){
	for(int i = 0; i<MAX_TIMER; i++){
		timer_flag[i] = 0;
		timer_counter[i] = 0;
	}
}

void setTimer(int index, int duration){
	timer_counter[index] = duration / TICK;
	timer_flag[index] = 0;
}
void timerRun(){
	for(int i = 0; i< MAX_TIMER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i] --;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
