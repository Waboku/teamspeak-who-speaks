/*
 * gui.h
 *
 * Created: 20-6-2017 16:00:08
 *  Author: P
 */ 


#ifndef GUI_H_
#define GUI_H_

#include "../text.h"

extern font_t const *gui_listFont;
extern font_t const *gui_listEmphasisFont;
extern font_t const *gui_kbFont;
extern font_t const *gui_statusBarFont;
extern font_t const *gui_popFont;
extern font_t const *gui_popEmphasisFont;

extern RGBcolor_t gui_backgroundColor;
extern RGBcolor_t gui_listTextColor;
extern RGBcolor_t gui_popupColor;
extern RGBcolor_t gui_borderColor;

typedef struct{
	screen_pos_t touchLast;
	screen_pos_t touchStart;
	touch_state_t touchState;
	gui_state_t screenState;
	keyboard_state_t keyboardState;
	popup_state_t popState;
}system_state_t;

typedef enum{
	NO_TOUCH, TOUCHING, TOUCH_WAITING, TOUCH_MISSED
}touch_state_t;

typedef enum{
	IDLE, SELECT_WIFI, SELECT_SERVER, SELECT_CREDENTIALS, DISPLAY_USERS
}gui_state_t;



#endif /* GUI_H_ */