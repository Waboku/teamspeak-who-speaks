/*
 * commons.h
 *
 * Created: 21-5-2017 12:15:49
 *  Author: P
 */ 


#ifndef COMMONS_H_
#define COMMONS_H_

#include <inttypes.h>

#define LCD_DATA_PORT	PORT->Group[0]
#define LCD_DATA0_bp	0
#define LCD_DATA0_bm	(1<<LCD_DATA0_bp)
#define LCD_DATA1_bp	1
#define LCD_DATA1_bm	(1<<LCD_DATA1_bp)
#define LCD_DATA2_bp	2
#define LCD_DATA2_bm	(1<<LCD_DATA2_bp)
#define LCD_DATA3_bp	3
#define LCD_DATA3_bm	(1<<LCD_DATA3_bp)
#define LCD_DATA4_bp	4
#define LCD_DATA4_bm	(1<<LCD_DATA4_bp)
#define LCD_DATA5_bp	5
#define LCD_DATA5_bm	(1<<LCD_DATA5_bp)
#define LCD_DATA6_bp	6
#define LCD_DATA6_bm	(1<<LCD_DATA6_bp)
#define LCD_DATA7_bp	7
#define LCD_DATA7_bm	(1<<LCD_DATA7_bp)

#define LCD_DATA_gm		(LCD_DATA0_bm|LCD_DATA1_bm|LCD_DATA2_bm|LCD_DATA3_bm|LCD_DATA4_bm|LCD_DATA5_bm|LCD_DATA6_bm|LCD_DATA7_bm)
#define LCD_DATA_gp		LCD_DATA0_bp

#define BCKLGHT_PORT	PORT->Group[0]
#define BCKLGHT_bp		17
#define BCKLGHT_bm		(1<<BCKLGHT_bp)

#define LCD_RESET_PORT	PORT->Group[0] 
#define LCD_RESET_bp	16
#define LCD_RESET_bm	(1<<LCD_RESET_bp)

#define LCD_RD_PORT		PORT->Group[0]
#define LCD_RD_bp		11
#define LCD_RD_bm		(1<<LCD_RD_bp)

#define LCD_WR_PORT		PORT->Group[0]
#define LCD_WR_bp		10
#define LCD_WR_bm		(1<<LCD_WR_bp)

#define LCD_RS_PORT		PORT->Group[0]
#define LCD_RS_bp		9
#define LCD_RS_bm		(1<<LCD_RS_bp)

#define LCD_CS_PORT		PORT->Group[0]
#define LCD_CS_bp		8
#define LCD_CS_bm		(1<<LCD_CS_bp)

#define ESP_RX_PORT		PORT->Group[0]
#define ESP_RX_bmp		18
#define ESP_RX_bm		(1<<ESP_RX_bmp)

#define ESP_TX_PORT		PORT->Group[0]
#define ESP_TX_bp		19
#define ESP_TX_bm		(1<<ESP_TX_bp)

#define ESP_BOOT_PORT	PORT->Group[0]
#define ESP_BOOT_bp		22
#define ESP_BOOT_bm		(1<<ESP_BOOT_bp)

#define ESP_RESET_PORT	PORT->Group[0]
#define ESP_RESET_bp	27
#define ESP_RESET_bm	(1<<ESP_RESET_bp)

#define ESP_SHTDWN_PORT	PORT->Group[0]
#define ESP_SHTDWN_bp	28
#define ESP_SHTDWN_bm	(1<<ESP_SHTDWN_bp)


#define TOUCH_X_PLUS_PORT		PORT->Group[0]
#define TOUCH_X_PLUS_bp			6
#define TOUCH_X_PLUS_bm			(1<<TOUCH_X_PLUS_bp)
#define TOUCH_X_PLUS_ADC_pos	ADC_POSITIVE_INPUT_PIN6

#define TOUCH_X_MIN_PORT		PORT->Group[0]
#define TOUCH_X_MIN_bp			9
#define TOUCH_X_MIN_bm			(1<<TOUCH_X_MIN_bp)
#define TOUCH_X_MIN_ADC_pos		ADC_POSITIVE_INPUT_PIN17

#define TOUCH_Y_PLUS_PORT		PORT->Group[0]
#define TOUCH_Y_PLUS_bp			10
#define TOUCH_Y_PLUS_bm			(1<<TOUCH_Y_PLUS_bp)
#define TOUCH_Y_PLUS_ADC_pos	ADC_POSITIVE_INPUT_PIN18

#define TOUCH_Y_MIN_PORT		PORT->Group[0]
#define TOUCH_Y_MIN_bp			7
#define TOUCH_Y_MIN_bm			(1<<TOUCH_Y_MIN_bp)
#define TOUCH_Y_MIN_ADC_pos		ADC_POSITIVE_INPUT_PIN7


#define MAX(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })
 
 
#define MIN(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; })

#endif /* COMMONS_H_ */