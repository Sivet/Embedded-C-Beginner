/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: simon
 */


#include <stdio.h>
#include <stdint.h>

void exerciseOne();
void exerciseTwo();
void exerciseThree();
void exerciseFour();

int main(){

	//exerciseOne();
	//exerciseTwo();
	//exerciseThree();
	exerciseFour();

}

void exerciseOne(){
	uint32_t age;
	printf("Enter your age: ");
	scanf("%d", &age);

	if (age >= 18) {
		printf("User can vote\n");
	} else {
		printf("User cannot vote\n");
	}
}
void exerciseTwo(){
	float n1;
	float n2;

	printf("Enter two numbers: ");
	//Scanf return the number of items successfully read
	if(scanf("%f %f", &n1, &n2) != 2){
		printf("Invalid input\n");
		return;
	}


	if (n1 == n2) {
		printf("Numbers are equal\n");
	} else {
		if (n1 > n2) {
			printf("Number one the biggest with: %f", n1);
		} else {
			printf("Number two the biggest with: %f", n2);
		}
	}

}
void exerciseThree(){
	uint32_t age;
	printf("Enter your age: ");
	scanf("%d", &age);

	//Conditional operator
	(age > 18) ? printf("User can vote\n") : printf("User cannot vote\n");

}
void exerciseFour(){
	int8_t type; //8bit value aka char

	printf("Area calculation program\n");
	printf("Circle    --> c\n"
			"Triangle  --> t\n"
			"Rectangle --> r\n"
			"Square    --> s\n"
			"Trapezoid --> z\n");
	printf("Enter code: ");
	scanf("%c", &type);

	printf("Value of type: %c %d\n", type, type);

	//only takes int value, char is handled as ascii value
	switch (type) {
	case 'c':{
		int32_t radius;
		printf("Circle calculation\nEnter the radius here: ");
		scanf("%d", &radius);
		printf("Circle radius is: %f", (3.14*radius*radius));
		break;
	}
	case 't':{
		int32_t base, height;
		printf("Triangle calculation\nEnter the base and height here: ");
		scanf("%d %d", &base, &height);
		printf("Triangle radius is: %f", ((height*base)/2.0));
		break;
	}
	case 'r':{
		int32_t height, width;
		printf("Rectangle calculation\nEnter the height and width here: ");
		scanf("%d %d", &height, &width);
		printf("Rectangle radius is: %d", (height*width));
		break;
	}
	case 's':{
		int32_t side;
		printf("Square calculation\nEnter the side here: ");
		scanf("%d", &side);
		printf("Square radius is: %d", (side*side));
		break;
	}
	case 'z':{
		int32_t baseA, baseB, height;
		printf("Trapezoid calculation\nEnter the baseA, baseB and height here: ");
		scanf("%d %d %d", &baseA, &baseB, &height);
		printf("Trapezoid radius is: %f", (((baseA+baseB)/2.0)*height));
		break;
	}
	default:
		printf("Invalid key");
	}
}
