/*
 * gui_system.c
 *
 * Created: 20-6-2017 15:55:38
 *  Author: P
 */ 

#include "../graphics.h"
#include "sam.h"
#include "gui.h"
#include "gui_system.h"
#include "../text.h"



static const uint8_t KB_LETTER_POS_C3[] = {0,19,36,54,71,89,106,124,141,158,176,0};
static const uint8_t KB_LETTER_POS_C2[] = {6,24,42,60,78,96,114,132,150,168,0};
static const uint8_t KB_LETTER_POS_C1[] = {0,24,42,60,78,96,114,132,150,176,0};
static const uint8_t KB_LETTER_POS_C0[] = {0,24,42,132,150,176,0};

static const uint8_t KB_LETTER_LO_C3[]	= {'q','w','e','r','t','y','u','i','o','p'};
static const uint8_t KB_LETTER_LO_C2[]	= {'a','s','d','f','g','h','j','k','l'};
static const uint8_t KB_LETTER_LO_C1[]	= {KB_CAPITAL_BTN,'z','x','c','v','b','n','m',KB_BACKSPACE_BTN};
static const uint8_t KB_LETTER_LO_C0[]	= {KB_SYMBOL_BTN,',',' ','.',KB_ENTER_BTN};

static const uint8_t KB_LETTER_HI_C3[]	= {'Q','W','E','R','T','Y','U','I','O','P'};
static const uint8_t KB_LETTER_HI_C2[]	= {'A','S','D','F','G','H','J','K','L'};
static const uint8_t KB_LETTER_HI_C1[]	= {KB_SMALL_BTN,'Z','X','C','V','B','N','M',KB_BACKSPACE_BTN};
static const uint8_t KB_LETTER_HI_C0[]	= {KB_SYMBOL_BTN,',',' ','.',KB_ENTER_BTN};

static const uint8_t KB_SYMBOL_POS_C3[] = {0,19,36,54,71,89,106,124,141,158,176,0};
static const uint8_t KB_SYMBOL_POS_C2[] = {0,19,36,54,71,89,106,124,141,158,176,0};
static const uint8_t KB_SYMBOL_POS_C1[] = {6,24,42,60,78,96,114,132,150,176,0};
static const uint8_t KB_SYMBOL_POS_C0[] = {0,24,42,60,78,96,114,132,150,176,0};

static const uint8_t KB_SYMBOL_C3[] = {'1','2','3','4','5','6','7','8','9','0'};
static const uint8_t KB_SYMBOL_C2[] = {'@','#','$','_','&','-','+','(',')','/'};
static const uint8_t KB_SYMBOL_C1[] = {'%','*','\"','\'',':',';','!','\?',KB_BACKSPACE_BTN};
static const uint8_t KB_SYMBOL_C0[] = {KB_LETTERS_BTN,'<','~','|','^','=','\\','>',KB_ENTER_BTN};


const keyboard_keys_t kbLettersSmall =	{ .characters[0] = KB_LETTER_LO_C3, .characters[1] = KB_LETTER_LO_C2, .characters[2] = KB_LETTER_LO_C1, .characters[3] = KB_LETTER_LO_C0 , .keyPos[0] = KB_LETTER_POS_C3, .keyPos[1] = KB_LETTER_POS_C2, .keyPos[2] = KB_LETTER_POS_C1,  .keyPos[3] = KB_LETTER_POS_C0 };
const keyboard_keys_t kbLettersBig	  =	{ .characters[0] = KB_LETTER_HI_C3, .characters[1] = KB_LETTER_HI_C2, .characters[2] = KB_LETTER_HI_C1, .characters[3] = KB_LETTER_HI_C0 , .keyPos[0] = KB_LETTER_POS_C3, .keyPos[1] = KB_LETTER_POS_C2, .keyPos[2] = KB_LETTER_POS_C1,  .keyPos[3] = KB_LETTER_POS_C0 };
const keyboard_keys_t kbSymbols		=	{ .characters[0] = KB_SYMBOL_C3, .characters[1] = KB_SYMBOL_C2, .characters[2] = KB_SYMBOL_C1, .characters[3] = KB_SYMBOL_C0 , .keyPos[0] = KB_SYMBOL_POS_C3, .keyPos[1] = KB_SYMBOL_POS_C2, .keyPos[2] = KB_SYMBOL_POS_C1,  .keyPos[3] = KB_SYMBOL_POS_C0 };


const uint8_t kb_colCords[KB_TOTAL_COLOMS+1] = {KB_COL0_S+1, KB_COL1_S+1, KB_COL2_S+1, KB_COL3_S, KB_END};


/*! \brief Renders The specified keyboard type at the bottom of the screen
*
*	\param *kb The pointer that points to the struct cotaining the symbols and coordiantes of the keyboard
*
*/
void gui_system_renderKeyboard(const keyboard_keys_t *kb){
	
	graphics_drawSolidRectangle((screen_pos_t){0,KB_COL0_S},(screen_pos_t){LCD_X_MAX,LCD_Y_MAX},KB_BCKGND_COLOR);
	
	uint8_t keyPos = 0;
	uint8_t letterPos = 0;
	
	for(uint8_t col = 0 ; col <  KB_TOTAL_COLOMS; col++){
		while(kb->keyPos[col][++keyPos]){
			graphics_drawSolidRectangle((screen_pos_t){kb->keyPos[col][keyPos-1]+1, kb_colCords[col]}, (screen_pos_t){kb->keyPos[col][keyPos]-1, kb_colCords[col+1]-2}, KB_BORDER_COLOR);
			//graphics_drawSolidRectangle((screen_pos_t){kb->keyPos[col][keyPos-1]+2, kb_colCords[col]+1}, (screen_pos_t){kb->keyPos[col][keyPos]-2, kb_colCords[col+1]-3}, KB_KEY_COLOR);
			
			letterPos = text_getLetterWidth(kb->characters[col][keyPos-1],gui_kbFont);
			letterPos = kb->keyPos[col][keyPos-1] + (kb->keyPos[col][keyPos] - kb->keyPos[col][keyPos-1])/2 - letterPos/2;
			text_renderLetter((screen_pos_t){letterPos, kb_colCords[col]+7},kb->characters[col][keyPos-1],gui_kbFont,KB_CHAR_COLOR);
		}
		keyPos = 0;
	}
}

/*! \brief Determines by means of a keyboard type and screen position, which key of the keyboard is pressed. returns 0x00 if there is no key at that location
*
*	\param *kb The pointer that points to the struct cotaining the symbols and coordiantes of the keyboard
*	\param touch The position that the touch occurred
*
*/
uint8_t gui_system_determineKey(const keyboard_keys_t *kb, screen_pos_t touch){
	uint8_t col = 0;
	uint8_t keyPos = 0;
	
	if(touch.y >= KB_COL3_S){
		col = 3;
		}else if(touch.y >= KB_COL2_S){
		col = 2;
		}else if(touch.y >= KB_COL1_S){
		col = 1;
		}else if(touch.y >= KB_COL0_S){
		col = 0;
		}else{
		return 0x00;
	}
	
	while(kb->keyPos[col][++keyPos]){
		if(touch.x < kb->keyPos[col][keyPos]){
			return kb->characters[col][keyPos-1];
		}
	}
	
	return 0x00;
	
}
