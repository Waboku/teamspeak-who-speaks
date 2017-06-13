/*
 * keyboard.h
 *
 * Created: 26-5-2017 11:33:58
 *  Author: P
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

typedef enum{
	INACTIVE, LETTER_SMALL, LETTER_CAPITAL, SYMBOL
}keyboard_state_t;


typedef struct{
	screen_pos_t last_touch;
	screen_pos_t curr_touch;
	touch_state_t touch_state;
	screen_state_t screen_state;
	keyboard_state_t keyboard_state;
}system_state_t;


//KEYBAORD DEFINITIONS

#define KB_COL_SPACING 28

#define KB_TOTAL_COLOMS 4

#define KB_END		LCD_Y_MAX-1
#define KB_COL3_S 	KB_END-KB_COL_SPACING
#define KB_COL2_S 	KB_COL3_S-KB_COL_SPACING
#define KB_COL1_S 	KB_COL2_S-KB_COL_SPACING
#define KB_COL0_S	KB_COL1_S-KB_COL_SPACING

#define KB_BORDER_COLOR (RGBcolor_t){.red = 30, .green = 110, .blue = 110}
#define KB_KEY_COLOR (RGBcolor_t){.red = 71, .green = 71, .blue = 71}
#define KB_CHAR_COLOR (RGBcolor_t){.red = 220, .green = 220, .blue = 220}
#define KB_BCKGND_COLOR (RGBcolor_t){.red = 31, .green = 31, .blue = 31}
	

#define KB_CAPITAL_BTN		0x01
#define KB_BACKSPACE_BTN	0x02
#define KB_SYMBOL_BTN		0x03
#define KB_ENTER_BTN		0x04
#define KB_SMALL_BTN		0x05
#define KB_LETTERS_BTN		0x06

typedef struct{
	const uint8_t* const characters[4];
	const uint8_t* const keyPos[4];
}keyboard_keys_t;

const extern keyboard_keys_t kb_lettersSmall;
const extern keyboard_keys_t kb_lettersBig;
const extern keyboard_keys_t kb_symbols;


void keyboard_render(const keyboard_keys_t *kbKeys);
uint8_t keyboard_determineKey(const keyboard_keys_t *kb, screen_pos_t touch);
								
#endif /* KEYBOARD_H_ */