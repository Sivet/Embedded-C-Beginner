#include <stdint.h>

/*#if !defined(__SOFT_FP__) && defined(__ARM_FP)
 #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
 #endif*/

int main(void) {
	//Declare pointers for calculated addresses
	//Use volatile keyword on memory-mapped peripherals to ensure optimisation level doesn't affect them
	uint32_t volatile *pClkCtrlReg = (uint32_t*) 0x40023830;
	uint32_t volatile *pPortDModeReg = (uint32_t*) 0x40020C00;
	uint32_t volatile *pPortDOutReg = (uint32_t*) 0x40020C14;

	uint32_t volatile *pPortAModeReg = (uint32_t*) 0x40020000;
	uint32_t volatile *pPortAInReg = (uint32_t*) 0x40020010;

	//Enable Clock for GPOID and GPOA peripherals in the AHB1ENR
	*pClkCtrlReg |= 0x01 << 3; //Setting bit position 3 to 1
	*pClkCtrlReg |= 0x01 << 0; //Setting bit position 0 to 1

	//Configure PD12 as output
	*pPortDModeReg &= ~(0x3 << 24); //Clearing the 24th and 25th bit position
	*pPortDModeReg |= 0x01 << 24; //Setting 24th bit position to 1

	//Configure PA0 as input
	*pPortAModeReg &= ~(0x3 << 0); //Clearing the 0th and 1st bit position

	//Need a jumper on PA0 to either VDD(on) or GND(off) to affect the Led
	while (1) {
		//read the pin status of the pin PA0
		uint8_t pinStatus = (uint8_t) *pPortAInReg & 0x1; //Will give us 32bits, the "& 0x1" is to zero out everything except the position 0

		if (pinStatus != 0) {
			//Turn on Led
			*pPortDOutReg |= 0x01 << 12; //Setting 12th bit position to 1
		} else {
			//Turn off Led
			*pPortDOutReg &= ~(0x01 << 12); //Setting 12th bit position to 0
		}
	}
}
