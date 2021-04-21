/*
 * main.c
 *
 *  Created on: Apr 16, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

void displayArray(uint8_t*, uint8_t);
void swapArrays(uint8_t*, uint8_t*, uint32_t, uint32_t);
void waitForUser();

int main() {
	//Asking user for values, or something.
	uint8_t firstArray[5] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE };
	uint8_t otherArray[6] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };

	uint32_t nItems1 = sizeof(firstArray) / sizeof(uint8_t);
	uint32_t nItems2 = sizeof(otherArray) / sizeof(uint8_t);

	printf("Content of arrays before swapping:\n");
	displayArray(firstArray, nItems1);
	displayArray(otherArray, nItems2);

	swapArrays(firstArray, otherArray, nItems1, nItems2);

	printf("Content of arrays after swapping:\n");
	displayArray(firstArray, nItems1);
	displayArray(otherArray, nItems2);
}

void displayArray(uint8_t *pArray, uint8_t nItems) {
	for (uint32_t i = 0; i < nItems; i++) {
		printf("%x\t", pArray[i]);
	}
	printf("\n");
}

//If one array is larger than the other the extra elements will stay in that array
void swapArrays(uint8_t *firstArray, uint8_t *otherArray, uint32_t nItems1, uint32_t nItems2) {
	//In C an array is not a single "thing" you can swap. You will need to swap it element-by-element.
	//So no fun pointer action
	uint32_t len = nItems1 < nItems2 ? nItems1 : nItems2;

	for(uint32_t i = 0; i < len; i++){
		int32_t temp = firstArray[i];
		firstArray[i] = otherArray[i];
		otherArray[i] = temp;
	}
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {
	}
	getchar();
}
