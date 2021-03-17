/*
 * main.c
 *
 *  Created on: Mar 17, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

void waitForUser();

int main() {

	int32_t startNumber, endNumber;
	uint32_t even;

	printf("Enter starting and ending numbers, separated by space:");
	scanf("%d %d", &startNumber, &endNumber);

	if (endNumber < startNumber) {
		printf("Ending number must be bigger than starting number\n");
		waitForUser();
		return 0;
	}

	printf("Even numbers are :\n");
	even = 0;
	for (; startNumber <= endNumber; startNumber++) {
		if (!(startNumber % 2)) {
			printf("%4d\t", startNumber);
			even++;
		}
	}
	//Same but as while loop
	/*while(startNumber <= endNumber){
	 if(!(startNumber % 2)){
	 printf("%4d\t", startNumber);
	 even++;
	 }
	 startNumber++;
	 }*/

	printf("\nTotal even numbers : %u\n", even);

	waitForUser();
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {
	}
	getchar();
}
