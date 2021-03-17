/*
 * main.c
 *
 *  Created on: Mar 17, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

void waitForUser();
uint8_t const data = 10; //Placed in ROM or FLASH

int main() {
	//uint8_t const data = 10; //Placed in RAM

	//Compile error as intended
	//data = 50;

	//Circumvent (if variable is stored in RAM) with pointer
	uint8_t *ptr = (uint8_t*)&data; //typecast to avoid warning
	*ptr = 50; // <-- Causes crash if data is placed as a global const aka in ROM or FLASH

	printf("Value: %u\n", data);
	waitForUser();
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {}
	getchar();
}
