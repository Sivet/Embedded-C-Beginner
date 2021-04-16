/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "main.h"

//Declare pointers
RCC_AHB1ENR *const pClkCtrlReg = (RCC_AHB1ENR*) 0x40023830;
GPIOx_MODE *const pGpioMode = (GPIOx_MODE*) 0x40020C00;
GPIOx_OutDReg *const pPortDOutReg = (GPIOx_OutDReg*) 0x40020C14;

int main(void)
{
	//Enable Clock for GPOID peripheral in the AHB1ENR
	pClkCtrlReg->GPIO_D = 0x1;

	//Configure the mode of the IO pin as output
	pGpioMode->pin_12 = 0x01;

	while (1) {
		//Turn on Led by writing to GPIO data register
		pPortDOutReg->pin_12 = 0x1;
		//*pPortDOutReg |= 1 << 12;

		//Introduce observable delay
		for (uint32_t i = 0; i < 300000; i++);

		//Turn off the led
		pPortDOutReg->pin_12 = 0x0;
		//*pPortDOutReg &= ~(1 << 12);

		//Introduce observable delay
		for (uint32_t j = 0; j < 300000; j++);
	}
}