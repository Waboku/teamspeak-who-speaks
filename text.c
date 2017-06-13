/*
 * text.c
 *
 * Created: 29-5-2017 2:01:20
 *  Author: P
 */ 


#include "commons.h"
#include "graphics.h"
#include "text.h"
#include "st7775.h"
#include "Fonts/icons.h"




/*! \brief Renders a character of the specified font on the display in the specified color
*
*	\param top_left The top left position of the letter that is rendered, is padded to align all letters of different height on the same 'line'
*	\param letter The ASCII character to be rendered, only basic (non-extended) ASCII is supported, only printable characters will have any effect.
*	\param font, The font that will be rendered
*	\param color the color that the letter will be rendedered in
*
*	\return The width of the character that was just printed, useful for incrementing a cursor. returns zero if invalid character was specified
*/
uint8_t text_renderLetter(screen_pos_t topLeft, uint8_t letter, const font_t *font, RGBcolor_t color){
	uint8_t arrayPos;
	uint16_t curCharLine = 0;
	
	
	if(letter >= SYS_ICON_START && letter <= kb_icons.totalCharAmount){
		font = &kb_icons;
		arrayPos = letter;
	}else if(letter < ASCII_START || letter > ASCII_END){
		#if PRINT_UNKNOWN_CHAR
		font = &kb_icons;
		arrayPos = 0x00;
		#else
		return;
		#endif
	}else{
		arrayPos = letter-ASCII_START;
	}
	
	
	uint16_t width = font->charWidth[arrayPos];

	
	for(uint8_t row = 0; row < font->height; row++){ //for the height of the character
		curCharLine = font->charData[font->height*arrayPos + row];
		for(uint8_t colum = 0; colum < width; colum++){ // and the width of the character			
			if(curCharLine & (1<<colum)){ //if the bit on the row-colum place is high
				st7775_writeSpecificPixel((screen_pos_t){topLeft.x+width-colum-1, topLeft.y+row}, color); //draw a pixel on that row-colum in the specified colour
			}
		}
	}
	return width;
}


uint8_t text_getLetterWidth(uint8_t letter, const font_t *font){
	uint8_t arrayPos;
	
	if(letter > 0 && letter <= kb_icons.totalCharAmount){
		font = &kb_icons;
		arrayPos = letter;
	}else if(letter < ASCII_START || letter > ASCII_END){
		return 0x00;
	}else{
		arrayPos = letter-ASCII_START;
	}
	
	return font->charWidth[arrayPos];
}

uint8_t text_RenderString(screen_pos_t topLeft, uint8_t *str, const font_t *font, RGBcolor_t color){
	uint8_t xStart = topLeft.x;
	
	while(*str){		
		if(topLeft.x + text_getLetterWidth(*str,font) > LCD_X_MAX){
			break;
		}
		topLeft.x += text_renderLetter(topLeft,*str++,font,color);
	}	
	return topLeft.x - xStart; //return the width of the printed string
}