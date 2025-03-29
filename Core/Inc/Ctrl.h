#ifndef __Ctrl_H__
#define __Ctrl_H__

#include <stdint.h>
#include "main.h"

#define BIT 4




#define LX_LSB               0
#define LX_MSB               1
#define LY_LSB               2
#define LY_MSB               3
#define RX_LSB               4
#define RX_MSB               5
#define RY_LSB               6
#define RY_MSB               7
#define BUTTON_PACKET     	 8
#define SWITCH_PACKET     	 9
//#define KNOB_PACKET       10



#define BOTTOM_1   HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)
#define BOTTOM_2   HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)
#define BOTTOM_3   HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)
#define BOTTOM_4   HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)
#define BOTTOM_5   HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)
#define BOTTOM_6   HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)
#define BOTTOM_7   HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)
#define BOTTOM_8   HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)
//BOTTOM 9-16 reserved
#define SWITCH_1  HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)
#define SWITCH_2  HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)
#define SWITCH_3  HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)
#define SWITCH_4  HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)
#define KNOB_L1  	HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)
#define KNOB_L2  	HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)
#define KNOB_R1  	HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7) 
#define KNOB_R2  	HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)


#define BOTTOM_1_ON     0X01
#define BOTTOM_1_OFF		0xFE
#define BOTTOM_2_ON     0X02
#define BOTTOM_2_OFF		0xFD
#define BOTTOM_3_ON     0X04
#define BOTTOM_3_OFF		0xFB
#define BOTTOM_4_ON     0X08
#define BOTTOM_4_OFF		0xF7
#define BOTTOM_5_ON     0X10
#define BOTTOM_5_OFF		0xEF
#define BOTTOM_6_ON     0X20
#define BOTTOM_6_OFF		0xDF
#define BOTTOM_7_ON     0X40
#define BOTTOM_7_OFF		0xBF
#define BOTTOM_8_ON     0X80
#define BOTTOM_8_OFF		0x7F
#define SWITCH_1_ON    	0X01
#define SWITCH_1_OFF		0xFE
#define SWITCH_2_ON    	0X02
#define SWITCH_2_OFF		0xFD
#define SWITCH_3_ON    	0X04
#define SWITCH_3_OFF		0xFB
#define SWITCH_4_ON    	0X08
#define SWITCH_4_OFF		0xF7
#define KNOB_L_UP   	 	0X10
#define KNOB_L_DOWN			0x20
#define KNOB_L_NULL   	0XCF
#define KNOB_R_UP				0x40
#define KNOB_R_DOWN			0x80
#define KNOB_R_NULL			0x3F

/*------------------------------------------------------------------------------
  ��Ļ����RX������
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
  ADC��ʱ����
------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
  ������ȡ����
  Int_Voltage��ӳ�����
  Avg_Voltage��ƽ������
  Vol_Level�������ٷֱ�
  Vol_Color��������ɫ
  Trans_Time��ת��ʱ�䣨ms��
------------------------------------------------------------------------------*/
extern short KNOB_L_FLAG,KNOB_R_FLAG;

/*------------------------------------------------------------------------------
  ����ADC����
------------------------------------------------------------------------------*/
extern int32_t LX,LY,RX,RY;  
//��ʼ��־
extern uint8_t ADC1_Flag; 

/*------------------------------------------------------------------------------
  ADC��ȡ����
------------------------------------------------------------------------------*/
extern uint16_t ADC_Value[BIT]; 

/*------------------------------------------------------------------------------
  �ߵͰ�λ��ʱ����
------------------------------------------------------------------------------*/
extern int binary[4] ;
extern int highByte[6] ;
extern int lowByte[6] ;

/*------------------------------------------------------------------------------
  ��ʼ������
------------------------------------------------------------------------------*/
extern int32_t INIT_data[4];

/*------------------------------------------------------------------------------
  ������������
------------------------------------------------------------------------------*/
extern uint8_t TXData[10]; 

/*------------------------------------------------------------------------------
  MAP����
------------------------------------------------------------------------------*/
int32_t map(int32_t x, int32_t in_min, int32_t in_mid, int32_t in_max, int32_t out_min, int32_t out_mid, int32_t out_max); 

/*------------------------------------------------------------------------------
    ADC���º���
------------------------------------------------------------------------------*/
void Update_ADC(void);

/*------------------------------------------------------------------------------
    �������º���
------------------------------------------------------------------------------*/
void Update_BOTTOM(void);

/*------------------------------------------------------------------------------
    ADC��ʼ������
------------------------------------------------------------------------------*/
void init_ADC_data(void);
void init_ADC_MaxMin();
extern uint8_t emergencySuspend;
extern uint8_t emergencySuspensionFlag;
extern uint16_t emergencySuspensionTimer;
void Flags_clear();
#endif
