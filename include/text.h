/*
 * text.h
 *
 * Created: 29-5-2017 2:09:30
 *  Author: P
 */ 


#ifndef TEXT_H_
#define TEXT_H_

#include "sam.h"

#define PRINT_UNKNOWN_CHAR 1

#define ASCII_START		32 /**< \brief The start of the font in relation to ASCII the first 31 characters are non-print control characters that aren't specified in the font*/
#define ASCII_END		126 /**< \brief The end of the printable characters in ASCII non extended format*/


typedef struct{
	uint8_t const *name;
	uint8_t const *charWidth;
	uint16_t const *charData;
	const uint8_t height;
	const uint8_t totalCharAmount;
}font_t;



uint8_t text_renderLetter(screen_pos_t topLeft, uint8_t letter, const font_t *font, RGBcolor_t color);
uint8_t text_getLetterWidth(uint8_t letter, const font_t *font);
uint8_t text_RenderString(screen_pos_t topLeft, uint8_t *str, const font_t *font, RGBcolor_t color);
uint16_t text_getStringWidth(uint8_t *str, const font_t *font);
uint16_t text_getNextWordWidth(uint8_t *str, const font_t *font);


#endif /* TEXT_H_ */