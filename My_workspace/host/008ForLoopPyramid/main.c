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

	int32_t height;

	printf("Enter pyramid height:");
	scanf("%d", &height);


	for (int i = 1; i <= height; i++) {
		for(int j = i; j > 0; j--){
			printf("%4d\t", j);
		}
		printf("\n");
	}

	waitForUser();
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {
	}
	getchar();
}
