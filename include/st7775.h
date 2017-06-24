/*
 * st7775.h
 *
 * Created: 21-5-2017 15:19:07
 *  Author: P
 */ 


#ifndef ST7775_H_
#define ST7775_H_

#include "commons.h"
#include "graphics.h"


/*macro's used for readable and easy toggling of the control signals*/
#define CS_LO()		LCD_CS_PORT.OUTCLR.reg = LCD_CS_bm		/**< \brief Set chip select low*/
#define CS_HI()		LCD_CS_PORT.OUTSET.reg = LCD_CS_bm		/**< \brief Set chip select high*/

#define RS_LO()		LCD_RS_PORT.OUTCLR.reg = LCD_RS_bm		/**< \brief Set the bus in command mode*/
#define RS_HI()		LCD_RS_PORT.OUTSET.reg = LCD_RS_bm		/**< \brief Set the bus in data mode*/
									  
#define WR_LO()		LCD_WR_PORT.OUTCLR.reg = LCD_WR_bm		/**< \brief Set the write signal low*/
#define WR_HI()		LCD_WR_PORT.OUTSET.reg = LCD_WR_bm		/**< \brief Set the write signal high*/
									  
#define RD_LO()		LCD_RD_PORT.OUTCLR.reg = LCD_RD_bm		/**< \brief Set the read signal low*/
#define RD_HI()		LCD_RD_PORT.OUTSET.reg = LCD_RD_bm		/**< \brief Set the read signal high*/

#define RESET_LO()	LCD_RESET_PORT.OUTCLR.reg = LCD_RESET_bm	 /**< \brief Set the reset signal low*/
#define RESET_HI()	LCD_RESET_PORT.OUTSET.reg = LCD_RESET_bm	/**< \brief Set the reset signal high*/





void st7775_init(void);
void st7775_setCursor(screen_pos_t position);
void st7775_setRegion(screen_pos_t start, screen_pos_t end);
void st7775_setGramMode(void);
void st7775_writePixel(const RGBcolor_t color);
void st7775_writeSpecificPixel(screen_pos_t position, RGBcolor_t color);


#endif /* ST7775_H_ */