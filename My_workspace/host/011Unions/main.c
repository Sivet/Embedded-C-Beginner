/*
 * main.c
 *
 *  Created on: Apr 14, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

typedef union{
	uint16_t shortAddr;
	uint32_t longAddr;
}Address;

void waitForUser();

int main() {

	Address addr;

	addr.shortAddr = 0xABCD;
	addr.longAddr = 0xEEEECCCC;

	//Short is overridden by long, printing short will give the first 2 bytes (CCCC)
	printf("Short address: %#X\n", addr.shortAddr);
	printf("Long address: %#X\n", addr.longAddr);
	waitForUser();
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {}
	getchar();
}
