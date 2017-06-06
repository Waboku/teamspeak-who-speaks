/*
 * teamspeak_who_speaks.c
 *
 * Created: 3-6-2017 22:17:00
 * Author : P
 */ 


#include <sam.h>
#include <port.h>
#include <delay.h>
#include <clock.h>
#include  "clock_feature.h"
#include "commons.h"
#include "st7775.h"
#include "st7775_cmd.h"
#include "keyboard.h"
#include "graphics.h"
#include "text.h"

#define RAND_POS (screen_pos_t){rand()%LCD_X_SIZE,rand()%LCD_Y_SIZE}
	
RGBcolor_t *colorLookup[] = {BLACK, WHITE, RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN};
	


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
	SystemInit();	
	
	delay_init();	
	pin_init();
	st7775_init();
	

	delay_ms(200);
	graphics_drawSolidRectangle((screen_pos_t){0,0},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},KB_CHAR_COLOR);
	delay_ms(200);
	
	uint8_t x = 80;
	uint8_t y = 80;
	int8_t xi = 1;
	int8_t yi = 1;
	
	volatile uint8_t chara = 0;
	uint16_t i = 0;
	delay_ms(300);
	//graphics_drawSolidRectangle((screen_pos_t){0,KB_COL0_S},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},KB_BCKGND_COLOR);
	//keyboard_render(&kb_symbols);
	//text_renderLetter((screen_pos_t){50,10},'@',NULL,KB_BORDER_COLOR);
	while (1)
	{
		graphics_drawSolidRectangle(RAND_POS,RAND_POS,colorLookup[i++/*%(sizeof(colorLookup)/sizeof(RGBcolor_t*))*/]);
		//graphics_drawRectangle(RAND_POS,RAND_POS,BLUE);
		//graphics_drawSolidRectangle((screen_pos_t){i,i++},(screen_pos_t){i+test.xSize,i+test.ySize},WHITE);
		//graphics_drawBitmap((screen_pos_t){x,y},test);
		//graphics_drawLine((screen_pos_t){10,10},(screen_pos_t){20,20},GREEN);
				
		x += xi;
		y += yi;
		
		if(x < 2 || x > LCD_X_MAX-8){
			xi = -xi;
		}
		if(y < 2 || y > LCD_Y_MAX-8){
			yi = -yi;
		}
		chara = keyboard_determineKey(&kb_symbols,(screen_pos_t){x,y});
		keyboard_render(&kb_symbols);
		graphics_drawSolidRectangle((screen_pos_t){10,10},(screen_pos_t){25,25},KB_CHAR_COLOR);
		graphics_drawSolidRectangle((screen_pos_t){x-2,y-2},(screen_pos_t){x,y},KB_CHAR_COLOR);
		graphics_drawSolidRectangle((screen_pos_t){x-1,y-1},(screen_pos_t){x+1,y+1},KB_BCKGND_COLOR);
		text_renderLetter((screen_pos_t){10,10},chara,NULL,KB_BORDER_COLOR);
		//_delay_ms(20);
		

		
		// 		for(uint8_t delay = 0; delay < j; delay++){
		// 			_delay_ms(2);
		// 		}
		
	}
}
