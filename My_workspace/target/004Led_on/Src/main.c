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
	//Setting bit position 3 to 1
	//*pClkCtrlReg = *pClkCtrlReg | 0x08; //Old way, calculating the mask
	*pClkCtrlReg |= 0x01 << 3; //creating the mask by shifting a single bit into position, no calculation required

	//Configure the mode of the IO pin as output
	//Clearing the 24th and 25th bit position
	//*pPortDModeReg = *pPortDModeReg & 0xFCFFFFFF; //Old way, calculating the mask
	*pPortDModeReg &= ~(0x3 << 24); //creating the mask by shifting a single bit into position, no calculation required
	//Setting 24th bit position to 1
	//*pPortDModeReg = *pPortDModeReg | 0x01000000; //Old way, calculating the mask
	*pPortDModeReg |= 0x01 << 24; //creating the mask by shifting a single bit into position, no calculation required

	//Write to GPIO data register
	//Setting 12th bit position to 1
	//*pPortDOutReg = *pPortDOutReg | 0x01000; //Old way, calculating the mask
	*pPortDOutReg |= 0x01 <<  12; //creating the mask by shifting a single bit into position, no calculation required
    /* Loop forever */
	for(;;);
}
