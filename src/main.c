/*
 * teamspeak_who_speaks.c
 *
 * Created: 3-6-2017 22:17:00
 * Author : P
 */ 




#include "asf.h"
#include "conf_usb.h"
#include "stdio_setup.h"
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "commons.h"
#include "st7775.h"
#include "st7775_cmd.h"
#include "graphics.h"
#include "text.h"
#include "gui/gui_list.h"
#include "tetris.h"
#include "fonts/Arial.h"
#include "bitmaps/all_bitmaps.h"

#define RAND_POS (screen_pos_t){rand()%LCD_X_SIZE,rand()%LCD_Y_SIZE}
#define RAND_COLOR (RGBcolor_t){rand()%255,rand()%255,rand()%255}
	
	
	
	
struct usart_module usart_instance;

void uart_init(void){
	
	struct usart_config config_usart;
	usart_get_config_defaults(&config_usart);
	
	config_usart.baudrate    = 57600;
	config_usart.mux_setting = USART_RX_1_TX_0_XCK_1;
	config_usart.pinmux_pad0 = PINMUX_PA18C_SERCOM1_PAD2;
	config_usart.pinmux_pad1 = PINMUX_PA19C_SERCOM1_PAD3;
	config_usart.pinmux_pad2 = PINMUX_UNUSED;
	config_usart.pinmux_pad3 = PINMUX_UNUSED;
	
	while (usart_init(&usart_instance, ESP_SERCOM, &config_usart) != STATUS_OK) {
		
	}
	
	usart_enable(&usart_instance);
}


static void pin_init(void)
{
 	BCKLGHT_PORT.DIRSET.reg	= BCKLGTH_bm;
 	LCD_RESET_PORT.DIRSET.reg = LCD_RESET_bm;
 	LCD_CS_PORT.DIRSET.reg = LCD_CS_bm;
 	LCD_RD_PORT.DIRSET.reg = LCD_RD_bm;
 	LCD_WR_PORT.DIRSET.reg = LCD_WR_bm;
 	LCD_RS_PORT.DIRSET.reg = LCD_RS_bm;
 	LCD_RESET_PORT.OUTSET.reg = LCD_RESET_bm;
	BCKLGHT_PORT.OUTSET.reg	= BCKLGTH_bm;
}


int main(void)
{
	irq_initialize_vectors();
	cpu_irq_enable();

	system_init();
	pin_init();
	udc_start();
	delay_init();
	stdio_init();
	
	st7775_init();
	
	uart_init();
	
	
	printf("Starting..\n");	
	
	graphics_drawSolidRectangle((screen_pos_t){0,0},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},WHITE);
	graphics_drawSolidRectangle(RAND_POS,RAND_POS,YELLOW);	
	graphics_drawBitmap((screen_pos_t){10,10},&BIG_F);
	
	
	while (true)
	{
		for(uint8_t x = LCD_X_MAX; x>=10; x--){
			text_RenderWordWrapedString((screen_pos_t){5,100},(screen_pos_t){LCD_Y_MAX,x},"The quick brown fox jumps over the lazy dog",&arial,BLACK);
		}
	}
	
}

