/*
 * text.c
 *
 * Created: 29-5-2017 2:01:20
 *  Author: P
 */ 


#include "commons.h"
#include "graphics.h"
#include "text.h"
#include "system_font.h"
#include "st7775.h"


/*! \brief Renders a character of the specified font on the display in the specified color
*
*	\param top_left The top left position of the letter that is rendered, is padded to align all letters of different height on the same 'line'
*	\param letter The ASCII character to be rendered, only basic (non-extended) ASCII is supported, only printable characters will have any effect.
*	\param font, The font that will be rendered !!NOT SUPPOERTED YET!! Default font is always used, send NULL pointer for now
*	\param *color pointer to the color that the letter will be rendedered in
*
*	\return The width of the character that was just printed, useful for incrementing a cursor. returns zero if invalid character was specified
*/
uint16_t text_renderLetter(screen_pos_t top_left, char letter, void *font, RGBcolor_t *color){
	
	//TODO: Add support for multiple fonts, font generating matlab script should be updated first
	
	if(letter < ASCII_START || letter > ASCII_END){
		//maybe render a Invalid character character
		return 0x00;
	}
	
	uint16_t cur_char = 0;
	uint16_t width = systemFont[letter-ASCII_START][SPACINGINDEX];
	
	
	for(uint8_t row = 0; row < SPACINGINDEX; row++){ //for the height of the character
		cur_char = systemFont[letter-ASCII_START][row];
		for(uint8_t colum = 0; colum < width; colum++){ // and the width of the character			
			if(cur_char & (1<<colum)){ //if the bit on the row-colum place is high
				st7775_writeSpecificPixel((screen_pos_t){top_left.x+width-colum-1, top_left.y+row}, color); //draw a pixel on that row-colum in the specified colour
			}
		}
	}
	return width;
}