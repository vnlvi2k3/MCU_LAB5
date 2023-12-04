/*
 * software_timer.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Lan Vi
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define MAX_TIMER 4
#define TICK 10

extern int timer_flag[MAX_TIMER];
void setTimer(int, int);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
