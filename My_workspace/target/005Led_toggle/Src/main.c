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

#include <stdint.h>

/*#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif*/

int main(void)
{
	//Declare pointers for calculated addresses
	uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;

	//Enable Clock for GPOID peripheral in the AHB1ENR
	*pClkCtrlReg |= 0x01 << 3;

	//Configure the mode of the IO pin as output
	*pPortDModeReg &= ~(0x03 << 24);
	*pPortDModeReg |= 0x01 << 24;

	while(1){
		//Turn on Led by writing to GPIO data register
		*pPortDOutReg |= 1 << 12;

		//Introduce observable delay
		for(uint32_t i = 0; i < 300000; i++);

		//Turn off the led
		*pPortDOutReg &= ~(1 << 12);

		//Introduce observable delay
		for(uint32_t j = 0; j < 300000; j++);
	}

    /* Loop forever */
	//for(;;);
}
