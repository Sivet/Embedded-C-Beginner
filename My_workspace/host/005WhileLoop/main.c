/*
 * main.c
 *
 *  Created on: Mar 5, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

int main(){

	uint8_t number = 0;

	while(number <= 10){
		printf("Counting: %d\n", number);
		number++;
	}

	while(getchar() != '\n'){}
	getchar();
}
