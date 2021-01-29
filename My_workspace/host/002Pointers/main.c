/*
 * main.c
 *
 *  Created on: Jan 21, 2021
 *      Author: simon
 */


#include <stdio.h>


int main(){

	//initialize variable
	char value = 100;
	//print values of variable
	printf("Variable char value: %c\n", value);
	printf("Variable int value: %d\n", value);
	printf("Address of variable: %p\n", &value);

	//initialize pointer
	char* p1 = &value;

	//print values of pointer
	printf("Pointer1 int Value: %d\n", *p1);
	printf("Pointer1 char Value: %c\n", *p1);
	printf("Pointer1 Address: %p\n", p1);

	//Store pointer address in new pointer
	char** p2 = &p1;

	printf("Pointer2 Value: %p\n", *p2);

	//Write new value to the first pointer
	*p1 = 65;
	printf("Point1 int Value: %d\n", *p1);
	printf("Point1 char Value: %c\n", *p1);

	printf("Pointer2 Fun: %d\n", **p2);

}
