/*
 * main.c
 *
 *  Created on: Apr 21, 2021
 *      Author: simon
 */

#include <stdio.h>

void waitForUser();

int main() {

	//Placed in Flash, copied to RAM in runtime, edits are made on the RAM copy during runtime.
	char msg1[] = "Hello Array String";

	//Placed in Flash, pointer assigned to point to Flash address, not able to edit because of that.
	//Should define it as <char const *msg2> or compiler wont give any warnings
	char *msg2 = "Hello Pointer String";

	msg1[0] = 'B';
	//msg2[0] = 'B';

	printf("Message 1 is: %s\n", msg1);
	printf("Address of msg 1: %p\n", &msg1);
	printf("Value of msg 1: %p\n", msg1);

	printf("\n");

	printf("Message 2 is: %s\n", msg2);
	printf("Address of msg 2: %p\n", &msg2);
	printf("Value of msg 2: %p\n", msg2);

	waitForUser();
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {
	}
	getchar();
}
