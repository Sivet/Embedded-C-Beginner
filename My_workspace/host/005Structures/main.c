/*
 * main.c
 *
 *  Created on: 7 Apr 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

typedef struct{
	unsigned int carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float carWeight;
}carModel_t;

int main(){
	carModel_t BMW = {2021, 15000, 220, 1330};
	carModel_t Skoda = {.carNumber=4031, .carPrice=35000, .carMaxSpeed=160, .carWeight=1900.96};

	printf("BMW Nr: %u - Price: %u - Speed: %u - Weight: %f\n", BMW.carNumber, BMW.carPrice, BMW.carMaxSpeed, BMW.carWeight);
	printf("Skoda Nr: %u - Price: %u - Speed: %u - Weight: %f\n", Skoda.carNumber, Skoda.carPrice, Skoda.carMaxSpeed, Skoda.carWeight);
	fflush(stdout);

	printf("Size of BMW struct: %u byte\n", sizeof(BMW));
	fflush(stdout);

	while(getchar() != '\n'){}
	getchar();
	return 0;
}
