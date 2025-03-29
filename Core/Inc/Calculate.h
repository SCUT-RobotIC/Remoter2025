#ifndef __CALCULATE_H__
#define __CALCULATE_H__


#include <stdint.h>
#include "main.h"
#define MAX_DATA_SIZE 10 // �����������������С


typedef struct {
  uint8_t header;
	uint8_t parity;
	uint8_t emergencySuspension;
  uint8_t data[MAX_DATA_SIZE]; // ��������(10)
  uint8_t footer;
} DataPacket;	

//�ض���ṹ��


extern uint8_t RESET_State;
void packData(DataPacket* packet, const uint8_t* data, int dataSize);
uint8_t crc8_calculate(uint8_t data);
uint8_t filter(uint8_t current);

uint8_t crc8_calculate(uint8_t data) ;
uint8_t CalculateCRC(const uint8_t* data, int dataSize) ;
#endif
