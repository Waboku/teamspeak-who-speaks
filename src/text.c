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
	
	if( topLeft.x + (uint16_t)text_getLetterWidth(letter,font) > LCD_X_MAX || topLeft.y > LCD_Y_MAX){
		return 0;
	}
	
	
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

/*! \brief returns the width of a character in a specific font
*
*	\param letter The character whos width is returned
*	\param font, The font that will be used to calculate the width
*
*	\return The width of the character that was just printed, useful for incrementing a cursor. returns zero if invalid character was specified
*/
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


/*! \brief Renders a string of characters of the specified font on the display in the specified color on a single line (\n is ignored)
*
*	\param top_left The top left position of the string that is rendered, is padded to align all letters of different height on the same 'line'
*	\param *str pointer to the null-terminated string, ASCII supported
*	\param font, The font that will be rendered
*	\param color the color that the letters will be rendered in
*
*	\return The width of the string that was just printed. returns zero if invalid character was specified
*/
uint8_t text_RenderString(screen_pos_t topLeft, uint8_t *str, const font_t *font, RGBcolor_t color){
	uint8_t xStart = topLeft.x;
	
	while(*str){		
		if(topLeft.x + text_getLetterWidth(*str,font) >= LCD_X_MAX){
			break;
		}
		topLeft.x += text_renderLetter(topLeft,*str++,font,color);
	}	
	return topLeft.x - xStart; //return the width of the printed string
}

/*! \brief Renders a string of characters of the specified font on the display in the specified color within a certain area where the string will wrap.
*
*	\param top_left The top left position of the string that is rendered, is padded to align all letters of different height on the same 'line'
*	\param wrap the zone in which the text is allowed to wrap, this is a bounding box around all the text. when there is no more space rendering will cease
*	\param *str pointer to the null-terminated string, ASCII supported
*	\param font, The font that will be rendered
*	\param color the color that the letters will be rendered in
*
*	\return The width of the string that was just printed. returns zero if invalid character was specified
*/
screen_pos_t text_RenderWrapedString(screen_pos_t topLeft, screen_pos_t wrap, uint8_t *str, const font_t *font, RGBcolor_t color){
	screen_pos_t start = topLeft;
	
	if(topLeft.y + font->height > wrap.y){
		return topLeft;
	}	
		
	if(wrap.x > LCD_X_MAX){
		wrap.x = LCD_X_MAX;
	}
	if(wrap.y > LCD_Y_MAX){
		wrap.y = LCD_Y_MAX;
	}	
	
	while(*str){
		if(topLeft.x + text_getLetterWidth(*str,font) >= wrap.x || *str == '\n'){ 
			if(topLeft.y + (font->height)*2 >= wrap.y){ //wrap to the bottom of the wrap zone, hence height*2
				break;
			}else{
				topLeft.y += font->height;
				topLeft.x = start.x;
			}
		}
		topLeft.x += text_renderLetter(topLeft,*str++,font,color);
	}
	return (screen_pos_t) {start.x - topLeft.x,(start.y - topLeft.y) + font->height}; //return the width of the printed string
}

/*! \brief Renders a string of characters of the specified font on the display in the specified color within a certain area where the string will wrap.
*
*	\param top_left The top left position of the string that is rendered, is padded to align all letters of different height on the same 'line'
*	\param wrap the zone in which the text is allowed to wrap, this is a bounding box around all the text. when there is no more space rendering will cease
*	\param *str pointer to the null-terminated string, ASCII supported
*	\param font, The font that will be rendered
*	\param color the color that the letters will be rendered in
*
*	\return The width of the string that was just printed. returns zero if invalid character was specified
*/
screen_pos_t text_RenderWordWrapedString(screen_pos_t topLeft, screen_pos_t wrap, uint8_t *str, const font_t *font, RGBcolor_t color){
	
	screen_pos_t start = topLeft;
	uint8_t xMax = 0;
	
	if(topLeft.y + font->height > wrap.y){
		return topLeft;
	}
	
	if(wrap.x > LCD_X_MAX){
		wrap.x = LCD_X_MAX;
	}
	if(wrap.y > LCD_Y_MAX){
		wrap.y = LCD_Y_MAX;
	}	
	
	while(*str){
		
		if(topLeft.x + text_getNextWordWidth(str,font) >= wrap.x || *str == '\n'){
			if(start.x + text_getNextWordWidth(str,font) < wrap.x || topLeft.x + text_getLetterWidth(*str,font) >= wrap.x){
				if(topLeft.y + (font->height)*2 >= wrap.y){ //wrap to the bottom of the wrap zone, hence height*2
					break;
				}else{
					topLeft.y += font->height;
					topLeft.x = start.x;
				}
			}			
		}
		
		topLeft.x += text_renderLetter(topLeft,*str++,font,color);
	}
	return (screen_pos_t) {start.x - topLeft.x,(start.y - topLeft.y) + font->height}; //return the width of the printed string
}

/*! \brief returns the width of a string until the next whitespace character (space or /n)
*
*	\param letter The character whos width is returned
*	\param font, The font that will be used to calculate the width
*
*	\return The width of the character that was just printed, useful for incrementing a cursor. returns zero if invalid character was specified
*/
uint16_t text_getNextWordWidth(uint8_t *str, const font_t *font){
	uint16_t accumulator = 0;
		
	while(*str != ' ' && *str != '\n' && *str != 0x00){
		accumulator += text_getLetterWidth(*str++,font);
	}
		
	return accumulator; //return the width of the string
}


/*! \brief returns the width of all the characters in a null terminated string 
*
*	\param *str the string whos width is returned
*	\param font, The font that will be used to calculate the width
*
*	\return The width of the string in pixels
*/
uint16_t text_getStringWidth(uint8_t *str, const font_t *font){
	uint16_t accumulator = 0;
	
	while(*str){
		accumulator += text_getLetterWidth(*str++,font);
	}
	
	return accumulator; //return the width of the string
}