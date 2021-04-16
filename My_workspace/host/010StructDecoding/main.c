/*
 * main.c
 *
 *  Created on: Apr 9, 2021
 *      Author: simon
 */


#include <stdio.h>
#include <stdint.h>

//32-bit packet to decode
//Consists of data packets in the sizes: crc=2bit, status=1bit, payload=12bit, bat=3bit, sensor=3bit, longAddr=8bit, shortAddr=2bit, addrMode=1bit
typedef struct{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode;
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
	packet.crc 			= (uint8_t)(rawPacket & 0x3);
	packet.status 		= (uint8_t)(rawPacket >> 2) & 0x1;
	packet.payload 		= (uint16_t)(rawPacket >> 3) & 0xFFF;
	packet.bat 			= (uint8_t)(rawPacket >> 15) & 0x7;
	packet.sensor 		= (uint8_t)(rawPacket >> 18) & 0x7;
	packet.longAddr		= (uint8_t)(rawPacket >> 21) & 0xFF;
	packet.shortAddr	= (uint8_t)(rawPacket >> 29) & 0x3;
	packet.addrMode 	= (uint8_t)(rawPacket >> 31) & 0x1;

	printf("Crc:		%#x\n",packet.crc);
	printf("Status:		%#x\n",packet.status);
	printf("payload:	%#x\n",packet.payload);
	printf("Bat:		%#x\n",packet.bat);
	printf("Sensor:		%#x\n",packet.sensor);
	printf("LongAddr:	%#x\n",packet.longAddr);
	printf("ShortAddr:	%#x\n",packet.shortAddr);
	printf("AddrMode:	%#x\n",packet.addrMode);

	printf("Size of Packet: %lu\n", sizeof(packet));
	printf("Original Size:  %lu\n", sizeof(rawPacket));
	printf("Memory lost:    %lu\n", sizeof(packet) - sizeof(rawPacket));
	//See bit-field project for optimization
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {}
	getchar();
}
