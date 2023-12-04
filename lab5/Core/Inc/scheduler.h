/*
 * scheduler.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Lan Vi
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "main.h"

#define SCH_MAX_TASKS 6
#define NO_TASK_ID	0
#define ERROR_SCH_TOO_MANY_TASKS 1
#define ERROR_SCH_CANNOT_DELETE_TASK 2
#define RETURN_NORMAL 5
#define RETURN_ERROR 6

int Error_code_G;
int numTask;
typedef struct{
	void (*pTask)(void);
	uint32_t delay;
	uint32_t period;
	uint8_t runme;
	uint32_t taskID;
}sTask;

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period);
uint8_t SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
