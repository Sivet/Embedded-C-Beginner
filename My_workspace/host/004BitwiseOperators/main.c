/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: simon
 */


#include <stdio.h>
#include <stdint.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

void exerciseOne();
void exerciseTwo();
void exerciseThree();
void exerciseFour();
void exerciseFive();

int main(){

	//exerciseOne();
	//exerciseTwo();
	//exerciseThree();
	//exerciseFour();
	exerciseFive();
	while(getchar() != '\n'){}
	getchar();
}

void exerciseOne(){
	//Do bitwise calculations
	int32_t num1, num2;

	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	printf("You entered "BYTE_TO_BINARY_PATTERN" (%d)\n        and "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num1), num1, BYTE_TO_BINARY(num2), num2);

	int32_t bitwiseAnd = num1 & num2;
	printf("Bitwise &: "BYTE_TO_BINARY_PATTERN" (%d)\n",
			BYTE_TO_BINARY(bitwiseAnd), bitwiseAnd);

	int32_t bitwiseOr = num1 | num2;
	printf("Bitwise |: "BYTE_TO_BINARY_PATTERN" (%d)\n",
			BYTE_TO_BINARY(bitwiseOr), bitwiseOr);

	int32_t bitwiseXOR = num1 ^ num2;
	printf("Bitwise ^: "BYTE_TO_BINARY_PATTERN" (%d)\n",
			BYTE_TO_BINARY(bitwiseXOR), bitwiseXOR);

	int32_t bitwiseNot = ~num1;
	printf("Bitwise ~: "BYTE_TO_BINARY_PATTERN" (%d)\n",
			BYTE_TO_BINARY(bitwiseNot), bitwiseNot);
}
void exerciseTwo(){
	//Testing of bits : Test if number is even or odd
	//Bit Masking

	int32_t num;
	int32_t mask = 1;
	printf("Enter a number: ");
	scanf("%d", &num);

	int32_t output = num & mask; //Use the mask value with the And bit operator to test the bits we set as 1 in the mask
	printf("Output is: "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(output), output);
	(output) ? printf("Number is even") : printf("Number is odd");

}
void exerciseThree(){
	//Setting of bits
	//Set 4th and 7th bit to 1

	int32_t num;
	//int32_t mask = 0b10010000;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("You entered "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num), num);

	//num = mask | num; //Use the mask value with the Or bit operator to set the bits we set as 1 in the mask
	num |= 0b1001 << 4; //This makes a mask and applies it to num
	printf("Output is:  "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num),num);
}
void exerciseFour(){
	//Clearing of bits
	//Clear the 4th, 5th and 6th bit position
	int32_t num;
	//int32_t mask = 0b11000111; Not needed to calculate mask directly
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("You entered "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num), num);

	//num = mask & num; //Use the mask value with the And bit operator to clear the bits we set as 0 in the mask
	num &= ~(0b0111 << 4); //This makes a mask and applies it to num

	printf("Output is:  "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num), num);
}
void exerciseFive(){
	//Toggling of bits
	//Toggle a bit using the XOR operator
	int32_t num;
	//int32_t mask = 0b00000001; //Gonna toggle the lsb
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("You entered "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num), num);

	for(int8_t i = 0; i<5; i++){
		printf("Toggling the bit using the mask:\n");
		//num = mask ^ num; //Use the mask value with the XOR bit operator to toggle the bits we set as 1 in the mask
		num ^= 0b01; //This makes a mask and applies it to num
		printf("Output is:  "BYTE_TO_BINARY_PATTERN" (%d)\n", BYTE_TO_BINARY(num), num);
	}

}
