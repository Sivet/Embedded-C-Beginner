/*
 * main.h
 *
 *  Created on: Apr 16, 2021
 *      Author: simon
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct {
	uint32_t GPIO_A :1;
	uint32_t GPIO_B :1;
	uint32_t GPIO_C :1;
	uint32_t GPIO_D :1;
	uint32_t GPIO_E :1;
	uint32_t GPIO_F :1;
	uint32_t GPIO_G :1;
	uint32_t GPIO_H :1;
	uint32_t GPIO_I :1;
	uint32_t Reserved_A :3;
	uint32_t CRC :1;
	uint32_t Reserved_B :5;
	uint32_t BKPSRAM :1;
	uint32_t Reserved_C :1;
	uint32_t CCMDATARAM :1;
	uint32_t DMA1 :1;
	uint32_t DMA2E :1;
	uint32_t Reserved_D :2;
	uint32_t ETHMAC :1;
	uint32_t ETHMACTX :1;
	uint32_t ETHMACRX :1;
	uint32_t ETHMACPTP :1;
	uint32_t OTGHS :1;
	uint32_t OTGHSULPI :1;
	uint32_t Reserved_E :1;
}RCC_AHB1ENR;

typedef struct{
	uint32_t pin_0	:1;
	uint32_t pin_1	:1;
	uint32_t pin_2	:1;
	uint32_t pin_3	:1;
	uint32_t pin_4	:1;
	uint32_t pin_5	:1;
	uint32_t pin_6	:1;
	uint32_t pin_7	:1;
	uint32_t pin_8	:1;
	uint32_t pin_9	:1;
	uint32_t pin_10	:1;
	uint32_t pin_11	:1;
	uint32_t pin_12	:1;
	uint32_t pin_13	:1;
	uint32_t pin_14	:1;
	uint32_t pin_15	:1;
	uint32_t reserved	:16;
}GPIOx_OutDReg;

typedef struct{
	uint32_t pin_0	:2;
	uint32_t pin_1	:2;
	uint32_t pin_2	:2;
	uint32_t pin_3	:2;
	uint32_t pin_4	:2;
	uint32_t pin_5	:2;
	uint32_t pin_6	:2;
	uint32_t pin_7	:2;
	uint32_t pin_8	:2;
	uint32_t pin_9	:2;
	uint32_t pin_10	:2;
	uint32_t pin_11	:2;
	uint32_t pin_12	:2;
	uint32_t pin_13	:2;
	uint32_t pin_14	:2;
	uint32_t pin_15	:2;
}GPIOx_MODE;

#endif /* MAIN_H_ */
