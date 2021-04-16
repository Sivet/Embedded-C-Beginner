/*
 * main.c
 *
 *  Created on: Apr 16, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

void displayArray(uint8_t*, uint8_t);
void waitForUser();

int main() {
	uint8_t myArray[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

	for(uint32_t i = 0; i < 5; i++){
		myArray[i] = 0x33;
	}

	uint32_t nItems = sizeof(myArray) / sizeof(uint8_t);
	displayArray(myArray, nItems);
}

void displayArray(uint8_t *pArray, uint8_t nItems){
	for(uint32_t i = 0; i < nItems; i++){
		printf("%x\t", pArray[i]);
	}
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {}
	getchar();
}
