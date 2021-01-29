/*
 * main.c
 *
 *  Created on: Jan 19, 2021
 *      Author: simon
 */
#include <stdio.h>

float simpleVersion();
float allAtOnce();
void exercise();

int main(){

	//printf("Average: %f\n", simpleVersion());
	//printf("Average: %f\n", allAtOnce());
	//exercise();

	/*while(getchar() != '\n'){
	}
	getchar();*/
}

float simpleVersion(){
	float number1, number2, number3;

	printf("Enter the first number: ");
	scanf("%f", &number1);
	printf("Enter the second number: ");
	scanf("%f", &number2);
	printf("Enter the third number: ");
	scanf("%f", &number3);
	return ((number1 + number2 + number3) / 3);
}

float allAtOnce(){
	float number1, number2, number3;

	printf("Enter 3 numbers:");
	scanf("%f %f %f", &number1, &number2, &number3);
	return ((number1 + number2 + number3) / 3);
}

void exercise(){
	char char1, char2, char3, char4, char5, char6;

	printf("Enter 6 characters of your choice:");
	scanf("%c %c %c %c %c %c", &char1, &char2, &char3, &char4, &char5, &char6);
	printf("ACII codes: %u, %u, %u, %u, %u, %u", char1, char2, char3, char4, char5, char6);
}
