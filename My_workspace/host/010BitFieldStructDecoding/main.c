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
//Struct defined with bit-field definition of the uint32_t
typedef struct{
	uint32_t crc:2;
	uint32_t status:1;
	uint32_t payload:12;
	uint32_t bat:3;
	uint32_t sensor:3;
	uint32_t longAddr:8;
	uint32_t shortAddr:2;
	uint32_t addrMode:1;
}Packet;

//Example of mix bitmap with full variables
/*
typedef struct{
	uint32_t speed	:7; //Max 400km/H (7bits)
	uint32_t weight	:13;//Max 500kg (13bits)
	uint32_t colour	:7; //An Ascii code (7bits)
	//27 bits used, 5bits left. Is not space enough for price
	uint32_t price; 	//Is its own uint32
}carDetails;
*///takes 4+4 = 8 bytes

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

	packet.crc 			= (rawPacket & 0x3);
	packet.status 		= (rawPacket >> 2) & 0x1;
	packet.payload 		= (rawPacket >> 3) & 0xFFF;
	packet.bat 			= (rawPacket >> 15) & 0x7;
	packet.sensor 		= (rawPacket >> 18) & 0x7;
	packet.longAddr		= (rawPacket >> 21) & 0xFF;
	packet.shortAddr	= (rawPacket >> 29) & 0x3;
	packet.addrMode 	= (rawPacket >> 31) & 0x1;

	printf("Crc:		%#x\n",packet.crc);
	printf("Status:		%#x\n",packet.status);
	printf("Payload:	%#x\n",packet.payload);
	printf("Bat:		%#x\n",packet.bat);
	printf("Sensor:		%#x\n",packet.sensor);
	printf("LongAddr:	%#x\n",packet.longAddr);
	printf("ShortAddr:	%#x\n",packet.shortAddr);
	printf("AddrMode:	%#x\n",packet.addrMode);

	printf("Size of Packet: %lu\n", sizeof(rawPacket));
	printf("Original Size:  %lu\n", sizeof(packet));
	printf("Memory lost:    %lu\n", sizeof(rawPacket) - sizeof(packet));
}

void waitForUser() {
	printf("Press Enter to exit the application");
	while (getchar() != '\n') {}
	getchar();
}
