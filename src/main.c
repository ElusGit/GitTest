/**
 *****************************************************************************
 * @defgroup	Project
 * @brief		Project related code
 * @{
 *
 * @file		main.c
 * @version		1.0
 * @date		2013-11-22
 * @author		rct1
 *
 * @brief		main.c template
 *
 *****************************************************************************
 * @copyright
 * @{
 * Copyright &copy; 2013, Bern University of Applied Sciences.
 * All rights reserved.
 *
 * ##### GNU GENERAL PUBLIC LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 * @}
 *****************************************************************************
 */

/*----- Header-Files -------------------------------------------------------*/
#include <stm32f4xx.h>				/* Processor STM32F407IG				*/
#include <carme.h>					/* CARME Module							*/

/*----- Macros -------------------------------------------------------------*/
#define INT_PER_SEC			1000U	/**< SysTick interrupts per second		*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
void Delay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
int main(void);

/*----- Data ---------------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief		This function waits for nTime / INT_PER_SEC seconds.
 *
 * @param[in]	nTime	Time to wait
 */
void Delay(__IO uint32_t nTime) {
	TimingDelay = nTime;
	while (TimingDelay != 0U) {
	}
}

/**
 * @brief		Decrement the TimingDelay. This function is called in the
 *				SysTick_Handler.
 */
void TimingDelay_Decrement(void) {
	if (TimingDelay > 0U) {
		TimingDelay--;
	}
}

/**
 * @brief		main
 * @return		0 if success
 */
int main(void) {

	uint8_t i = 0U;

	if (SysTick_Config(SystemCoreClock / INT_PER_SEC) == 1U) {
		while (1) {
		}
	}

	for (;;) {
		i++;
	}

	return 0U;
}

/**
 * @}
 */
