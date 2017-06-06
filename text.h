/*
 * text.h
 *
 * Created: 29-5-2017 2:09:30
 *  Author: P
 */ 


#ifndef TEXT_H_
#define TEXT_H_


#define SPACINGINDEX	10 /**< \brief The place in the system font array that specifies the width of the character */
#define ASCII_START		32 /**< \brief The start of the font in relation to ASCII the first 31 characters are non-print control characters that aren't specified in the font*/
#define ASCII_END		126 /**< \brief The end of the printable characters in ASCII non extended format*/
#define UNKNOWCHAR		127	/**< \brief the character that value's that aren't in the font default to */


uint16_t text_renderLetter(screen_pos_t top_left, char letter, void *font, RGBcolor_t *color);

#endif /* TEXT_H_ */