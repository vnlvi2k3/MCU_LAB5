/*
 * scheduler.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Lan Vi
 */
#include "scheduler.h"
void SCH_Init(void){
	for(uint32_t i = 0; i < SCH_MAX_TASKS; i++){
		SCH_tasks_G[i].pTask = 0x0000;
		SCH_tasks_G[i].delay = 0;
		SCH_tasks_G[i].period = 0;
		SCH_tasks_G[i].runme = 0;
		SCH_tasks_G[i].taskID = i;
	}
	Error_code_G = 0;
}
//void SCH_Update(void){
//	for(uint32_t index = 0; index < SCH_MAX_TASKS; index++){
//		if(SCH_tasks_G[index].pTask){
//			if(SCH_tasks_G[index].delay == 0){
//				SCH_tasks_G[index].runme += 1;
//				if(SCH_tasks_G[index].period){
//					SCH_tasks_G[index].delay = SCH_tasks_G[index].period;
//				}
//			}
//			else{
//				SCH_tasks_G[index].delay -= 1;
//			}
//		}
//	}
//}
//void SCH_Dispatch_Tasks(void){
//	for(uint32_t index = 0; index < SCH_MAX_TASKS; index++){
//		if(SCH_tasks_G[index].runme > 0){
//			(*SCH_tasks_G[index].pTask)();
//			SCH_tasks_G[index].runme -= 1;
//			if(SCH_tasks_G[index].period == 0){
//				SCH_Delete_Task(index);
//			}
//		}
//	}
//}
//uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period){
//	uint32_t index = 0;
//	while((index < SCH_MAX_TASKS) && (SCH_tasks_G[index].pTask != 0)){
//		index ++;
//	}
//	if(index == SCH_MAX_TASKS){
//		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
//		return SCH_MAX_TASKS;
//	}
//	SCH_tasks_G[index].pTask = pFunction;
//	SCH_tasks_G[index].delay = delay;
//	SCH_tasks_G[index].period = period;
//	SCH_tasks_G[index].runme = 0;
//	return index;
//}
//uint8_t SCH_Delete_Task(uint32_t taskID){
//	uint8_t return_code;
//	if(SCH_tasks_G[taskID].pTask == 0){
//		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
//		return_code = RETURN_ERROR;
//	}
//	else{
//		return_code = RETURN_NORMAL;
//	}
//	SCH_tasks_G[taskID].pTask = 0x0000;
//	SCH_tasks_G[taskID].delay = 0;
//	SCH_tasks_G[taskID].period = 0;
//	SCH_tasks_G[taskID].runme = 0;
//	return return_code;
//}
int numTask = 0;

void SCH_Update(void){
	if(SCH_tasks_G[0].pTask && SCH_tasks_G[0].runme == 0){
		if(SCH_tasks_G[0].delay == 0){
			SCH_tasks_G[0].runme = 1;
			if(SCH_tasks_G[0].period){
				SCH_tasks_G[0].delay = SCH_tasks_G[0].period;
			}
		}
		else{
			SCH_tasks_G[0].delay -= 1;
		}
	}
}
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period){
	uint32_t sumdelay = 0;
	for(uint32_t i = 0; i < SCH_MAX_TASKS; i++){
		if(!SCH_tasks_G[i].pTask){
			SCH_tasks_G[i].pTask = pFunction;
			SCH_tasks_G[i].delay = delay - sumdelay;
			SCH_tasks_G[i].period = period;
			SCH_tasks_G[i].taskID = i;
			SCH_tasks_G[i].runme = 0;
			if(delay == 0){
				SCH_tasks_G[i].runme = 1;
			}
			numTask++;
			return SCH_tasks_G[i].taskID;
		}
		else{
			if(delay < sumdelay + SCH_tasks_G[i].delay){
				uint32_t temp = delay - sumdelay;
				SCH_tasks_G[i].delay -= temp;
				for(uint32_t j = numTask; j > i; j--){
					SCH_tasks_G[j].pTask = SCH_tasks_G[j-1].pTask;
					SCH_tasks_G[j].delay = SCH_tasks_G[j-1].delay;
					SCH_tasks_G[j].period = SCH_tasks_G[j-1].period;
					SCH_tasks_G[j].runme = SCH_tasks_G[j-1].runme;
					SCH_tasks_G[j].taskID = SCH_tasks_G[j-1].taskID + 1;
				}
                SCH_tasks_G[i].pTask = pFunction;
                SCH_tasks_G[i].delay = delay - sumdelay;
                SCH_tasks_G[i].period = period;
                SCH_tasks_G[i].runme = 0;
                if(delay == 0){
                	SCH_tasks_G[i].runme = 1;
                }
                SCH_tasks_G[i].taskID = i;
                numTask++;
                return SCH_tasks_G[i].taskID;
			}
			else{
				sumdelay += SCH_tasks_G[i].delay;
			}
		}
	}
	Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
	return SCH_MAX_TASKS;
}
void SCH_Dispatch_Tasks(void){
	if(SCH_tasks_G[0].runme > 0){
		(*SCH_tasks_G[0].pTask)();
		SCH_tasks_G[0].runme = 0;
		sTask temp = SCH_tasks_G[0];
		SCH_Delete_Task(0);
		if(temp.period > 0){
			SCH_Add_Task(temp.pTask, temp.delay, temp.period);
		}
	}
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}
uint8_t SCH_Delete_Task(uint32_t taskID){
	uint8_t return_code = 0;
	if(taskID >= 0 && taskID < SCH_MAX_TASKS && SCH_tasks_G[taskID].pTask){
		return_code = 1;
		for(uint32_t i = taskID; i < numTask; i++){
			SCH_tasks_G[i].pTask = SCH_tasks_G[i+1].pTask;
			SCH_tasks_G[i].delay = SCH_tasks_G[i+1].delay;
			SCH_tasks_G[i].period = SCH_tasks_G[i+1].period;
			SCH_tasks_G[i].runme = SCH_tasks_G[i+1].runme;
			SCH_tasks_G[i].taskID = SCH_tasks_G[i+1].taskID - 1;
		}
        SCH_tasks_G[numTask - 1].pTask = 0x0000;
        SCH_tasks_G[numTask - 1].delay = 0;
        SCH_tasks_G[numTask - 1].period = 0;
        SCH_tasks_G[numTask - 1].runme = 0;
        SCH_tasks_G[numTask - 1].taskID = 0;
        numTask -= 1;
	}
	return return_code;
}











