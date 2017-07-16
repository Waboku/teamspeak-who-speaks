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

#define RAND_POS (screen_pos_t){rand()%LCD_X_SIZE,rand()%LCD_Y_SIZE}
#define RAND_COLOR (RGBcolor_t){rand()%255,rand()%255,rand()%255}


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
	
	
	printf("Starting..\n");	
	
	graphics_drawSolidRectangle((screen_pos_t){0,0},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},WHITE);
	
	
	while (true) {
		graphics_drawSolidRectangle(RAND_POS,RAND_POS,RAND_COLOR);
	}
}
