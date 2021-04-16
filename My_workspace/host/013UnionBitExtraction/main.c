/*
 * main.c
 *
 *  Created on: Apr 14, 2021
 *      Author: simon
 */

#include <stdio.h>
#include <stdint.h>

//All union members are referencing the same memory address
//Therefore setting the value in packetValue
//Will enable reading it via the packetFields
typedef union{
	uint32_t packetValue;
	struct{
		uint32_t crc		:2;
		uint32_t status		:1;
		uint32_t payload	:12;
		uint32_t bat		:3;
		uint32_t sensor		:3;
		uint32_t longAddr	:8;
		uint32_t shortAddr	:2;
		uint32_t addrMode	:1;
	}packetFields;
}Packet;

void decodePacket(uint32_t rawPacket);
void waitForUser();

int main() {
	uint32_t packet;
	printf("Enter the 32bit packet value:");
	scanf("%X", &packet);

	decodePacket(packet);
	waitForUser();
}

void decodePacket(uint32_t rawPacket){
	Packet packet;
	packet.packetValue = rawPacket;

	printf("Crc:		%#x\n",packet.packetFields.crc);
	printf("Status:		%#x\n",packet.packetFields.status);
	printf("Payload:	%#x\n",packet.packetFields.payload);
	printf("Bat:		%#x\n",packet.packetFields.bat);
	printf("Sensor:		%#x\n",packet.packetFields.sensor);
	printf("LongAddr:	%#x\n",packet.packetFields.longAddr);
	printf("ShortAddr:	%#x\n",packet.packetFields.shortAddr);
	printf("AddrMode:	%#x\n",packet.packetFields.addrMode);

	printf("Size of Packet: %lu\n", sizeof(rawPacket));
	printf("Original Size:  %lu\n", sizeof(packet));
	printf("Memory lost:    %lu\n", sizeof(rawPacket) - sizeof(packet));
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {}
	getchar();
}

