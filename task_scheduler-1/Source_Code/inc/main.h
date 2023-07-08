/*
 * main.h
 *
 *  Created on: Jul 7, 2023
 *      Author: 91701
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASK		4
#define DUMMY_XPSR		0x01000000U



/* Some stack memory calculations */
#define SIZE_TASK_STACK			1024U
#define SIZE_SCHED_STACK		1024U

#define SRAM_START				0X20000000
#define SIZE_SRAM				((1024)*(128))
#define SRAM_END				((SRAM_START) + (SIZE_SRAM))

#define T1_STACK_START			SRAM_END
#define T2_STACK_START			((SRAM_END) - (1 * SIZE_TASK_STACK))
#define T3_STACK_START			((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START			((SRAM_END) - (3 * SIZE_TASK_STACK))
#define SCHED_STACK_START		((SRAM_END) - (4 * SIZE_TASK_STACK))

#define TICK_HZ				1000U
#define HSI_CLOCK			16000000U
#define SYSTIC_TIM_CLOCK	HSI_CLOCK

void init_systic_timer(uint32_t tick_hz);

__attribute__((naked)) void int_scheduler_stack(uint32_t sched_top_of_stack);


void task1_handler(void); //This is Task 1
void task2_handler(void); //This is Task 2
void task3_handler(void); //This is Task 3
void task4_handler(void); //This is Task 4

void init_task_stack(void);

void enable_processor_faults(void);

__attribute__((naked)) void switch_sp_to_psp(void);

uint32_t get_psp_value(void);




#endif /* MAIN_H_ */
