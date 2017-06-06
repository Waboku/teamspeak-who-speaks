/*
 * commons.h
 *
 * Created: 21-5-2017 12:15:49
 *  Author: P
 */ 


#ifndef COMMONS_H_
#define COMMONS_H_

#include "sam.h"


#define LCD_DATA_PORT	PORT->Group[0]
#define LCD_DATA0_bm	(1<<0)
#define LCD_DATA1_bm	(1<<1)
#define LCD_DATA2_bm	(1<<2)
#define LCD_DATA3_bm	(1<<3)
#define LCD_DATA4_bm	(1<<4)
#define LCD_DATA5_bm	(1<<5)
#define LCD_DATA6_bm	(1<<6)
#define LCD_DATA7_bm	(1<<7)
#define LCD_DATA_gm		(LCD_DATA0_bm|LCD_DATA1_bm|LCD_DATA2_bm|LCD_DATA3_bm|LCD_DATA4_bm|LCD_DATA5_bm|LCD_DATA6_bm|LCD_DATA7_bm)
#define LCD_DATA_gp		0

#define BCKLGHT_PORT	PORT->Group[0]
#define BCKLGHT_pin		17
#define BCKLGTH_bm		(1<<BCKLGHT_pin)

#define LCD_RESET_PORT	PORT->Group[0]
#define LCD_RESET_bm	(1<<16)

#define LCD_RD_PORT		PORT->Group[0]
#define LCD_RD_bm		(1<<11)

#define LCD_WR_PORT		PORT->Group[0]
#define LCD_WR_bm		(1<<10)

#define LCD_RS_PORT		PORT->Group[0]
#define LCD_RS_bm		(1<<9)

#define LCD_CS_PORT		PORT->Group[0]
#define LCD_CS_bm		(1<<8)

#define ESP_RX_PORT		PORT->Group[0]
#define ESP_RX_bm		(1<<18)

#define ESP_TX_PORT		PORT->Group[0]
#define ESP_TX_bm		(1<<19)

#define ESP_BOOT_PORT	PORT->Group[0]
#define ESP_BOOT_bm		(1<<22)

#define ESP_BOOT_PORT	PORT->Group[0]
#define ESP_BOOT_bm		(1<<22)

#define ESP_RESET_PORT	PORT->Group[0]
#define ESP_RESET_bm	(1<<27)

#define ESP_SHTDWN_PORT	PORT->Group[0]
#define ESP_SHTDWN_bm	(1<<28)


#endif /* COMMONS_H_ */