#include "Calculate.h"
#include "Ctrl.h"
#include "main.h"

// CRC-8-Dallas Polynomial: 0x31 (X^8 + X^5 + X^4 + 1)
uint8_t crc8_calculate(uint8_t data) {
    uint8_t crc = 0;
    uint8_t bit;

    for (uint16_t i = 0; i < 8; i++) { // Iterate through each bit
        bit = (crc ^ data) & 0x01; // XOR current CRC with data
        crc >>= 1; // Shift CRC right by 1 bit
        if (bit) { // If current bit is 1
            crc ^= 0x31; // XOR with polynomial
        }
        data >>= 1; // Shift data right by 1 bit
    }
    return crc;
}

uint8_t CalculateCRC(const uint8_t* data, int dataSize) {
	uint8_t crc =0;
  uint8_t crc_value = 0; // ��ʼ��CRCֵΪ0
  for (uint8_t i = 0; i < dataSize; i++) {
    // ���㵱ǰ�����ֽڵ�CRCֵ
    crc_value = crc8_calculate(data[i]);
    // ���ǰCRCֵ������У�����ÿ�ε��������ۻ����ݵ�CRC����
    crc ^= crc_value;
  }
  return crc; // �������յ�CRCֵ
}
void packData(DataPacket* packet, const uint8_t* data, int dataSize) {
  packet->header = 0x2B;  // ����֡ͷ

  // ��������
  for (uint8_t i = 0; i < dataSize; i++) {
    packet->data[i] = data[i];
  }

	// ����
  packet->parity = CalculateCRC(data, dataSize);
  packet->emergencySuspension=emergencySuspend;
  packet->footer = 0xB2;  // ����֡β
}
