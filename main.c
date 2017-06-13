/*
 * teamspeak_who_speaks.c
 *
 * Created: 3-6-2017 22:17:00
 * Author : P
 */ 


#include <sam.h>
#include <delay.h>
#include "commons.h"
#include "st7775.h"
#include "st7775_cmd.h"
#include "keyboard.h"
#include "graphics.h"
#include "text.h"



#define RAND_POS (screen_pos_t){rand()%LCD_X_SIZE,rand()%LCD_Y_SIZE}
	


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
	gui_object_t *usr[13];
	SystemInit();	
	
	delay_init();	
	pin_init();
	st7775_init();
	//graphics_drawBitmap((screen_pos_t){0,0},&JDB);
	//graphics_drawBitmap((screen_pos_t){20,20},JDB);
	//delay_ms(200);
	graphics_drawSolidRectangle((screen_pos_t){0,0},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},WHITE);
	//delay_ms(200);

	//graphics_drawSolidRectangle((screen_pos_t){0,KB_COL0_S},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},KB_BCKGND_COLOR);
	//
	//text_renderLetter((screen_pos_t){50,10},'@',NULL,KB_BORDER_COLOR);
	while (1)
	{
		//graphics_drawSolidRectangle(RAND_POS,RAND_POS,colorLookup[i++/*%(sizeof(colorLookup)/sizeof(RGBcolor_t*))*/]);
		//graphics_drawRectangle(RAND_POS,RAND_POS,BLUE);
		//graphics_drawSolidRectangle((screen_pos_t){i,i++},(screen_pos_t){i+test.xSize,i+test.ySize},WHITE);
		//graphics_drawBitmap((screen_pos_t){0,0},JDB);
		//graphics_drawLine((screen_pos_t){10,10},(screen_pos_t){20,20},GREEN);
				

// 		chara = keyboard_determineKey(&kb_symbols,(screen_pos_t){x,y});
// 		keyboard_render(&kb_symbols);
// 		graphics_drawSolidRectangle((screen_pos_t){10,10},(screen_pos_t){25,25},KB_CHAR_COLOR);
// 		graphics_drawSolidRectangle((screen_pos_t){x-2,y-2},(screen_pos_t){x,y},KB_CHAR_COLOR);
// 		graphics_drawSolidRectangle((screen_pos_t){x-1,y-1},(screen_pos_t){x+1,y+1},KB_BCKGND_COLOR);
// 		text_renderLetter((screen_pos_t){10,10},chara,NULL,KB_BORDER_COLOR);
		
		//delay_ms(2000);

		delay_ms(2000);
 		keyboard_render(&kb_lettersSmall);
		delay_ms(2000);
		keyboard_render(&kb_lettersBig);
		delay_ms(2000);
		keyboard_render(&kb_lettersSmall);	
	}
}
