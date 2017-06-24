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
#include "graphics.h"
#include "text.h"
#include "gui/gui_list.h"



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
	gui_list_object_t usr[19];
	SystemInit();	
	
	delay_init();	
	pin_init();
	st7775_init();
	//graphics_drawBitmap((screen_pos_t){0,0},&JDB);
	//graphics_drawBitmap((screen_pos_t){20,20},JDB);
	//delay_ms(200);
	graphics_drawSolidRectangle((screen_pos_t){0,0},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},WHITE);
	//delay_ms(200);
	

	usr[0].objectType = SERVER;
	usr[0].status = SERVER_RUNNING;
	usr[0].name = "Server Temp";
	
	usr[1].objectType = CHANNEL;
	usr[1].status = CHANNEL_PERM;
	usr[1].name = "Channel Temp 1";
	
	usr[2].objectType = USER;
	usr[2].status = USER_SPEAKING;
	usr[2].name = "User 1";
	
	usr[3].objectType = USER;
	usr[3].status = USER_SOUND_MUTE;
	usr[3].name = "User 2";
	
	usr[4].objectType = USER;
	usr[4].status = USER_MIC_BAD;
	usr[4].name = "User 3";
	
	usr[5].objectType = USER;
	usr[5].status = USER_MIC_MUTE;
	usr[5].name = "User 4";
	
	usr[6].objectType = CHANNEL;
	usr[6].status = CHANNEL_TEMP;
	usr[6].name = "Channel Temp 2";
		
	usr[7].objectType = USER;
	usr[7].status = USER_QUITE;
	usr[7].name = "User 5";
	
	usr[8].objectType = CHANNEL;
	usr[8].status = CHANNEL_TEMP;
	usr[8].name = "Channel Temp 2";
	
	usr[9].objectType = CHANNEL;
	usr[9].status = CHANNEL_PERM;
	usr[9].name = "Channel Temp 3";
	
	usr[10].objectType = USER;
	usr[10].status = USER_QUITE;
	usr[10].name = "User 6";
	
	usr[11].objectType = USER;
	usr[11].status = USER_QUITE;
	usr[11].name = "User 7";
	
	usr[12].objectType = USER;
	usr[12].status = USER_QUITE;
	usr[12].name = "User 8";
	
	usr[13].objectType = USER;
	usr[13].status = USER_QUITE;
	usr[13].name = "User 9";
	
	usr[14].objectType = CHANNEL;
	usr[14].status = CHANNEL_PERM;
	usr[14].name = "Channel Temp 4";
	
	usr[15].objectType = USER;
	usr[15].status = USER_QUITE;
	usr[15].name = "User 10";
	
	usr[16].objectType = USER;
	usr[16].status = USER_QUITE;
	usr[16].name = "User 11";
	
	usr[17].objectType = USER;
	usr[17].status = USER_QUITE;
	usr[17].name = "User 12";
	
	usr[18].objectType = CHANNEL;
	usr[18].status = CHANNEL_TEMP;
	usr[18].name = "Channel Temp 5";
			
			
	

	
	for(uint8_t i = 0 ; i < 18; i++){
		gui_renderListObject(&usr[i],i);	
	}
						

//	usr[5] = gui_createObject(USER_OPTIONS,(screen_pos_t){150,30});
// 	usr[6] = gui_createObject(USER_OPTIONS,(screen_pos_t){12,200});
// 	usr[7] = gui_createObject(USER_OPTIONS,(screen_pos_t){150,200});
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

		
		 
		//delay_ms(5000);
//  		keyboard_render(&kbLettersSmall);
// 		delay_ms(2000);
// 		keyboard_render(&kbLettersBig);
// 		delay_ms(2000);
// 		keyboard_render(&kbSymbols);		
	}
}
