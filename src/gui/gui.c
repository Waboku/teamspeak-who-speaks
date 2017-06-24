/*
 * gui.c
 *
 * Created: 20-6-2017 15:59:58
 *  Author: P
 */ 

#include "../graphics.h"
#include "gui/gui.h"
#include "../Fonts/Comic_Sans.h"
#include "../Fonts/Comic_Sans_Bold.h"
#include "../Fonts/Arial_Bold.h"
#include "../Fonts/Arial.h"

	
font_t const *gui_listFont = &comic_sans;
font_t const *gui_listEmphasisFont = &comic_sans_bold;
font_t const *gui_kbFont = &arial_bold;
font_t const *gui_statusBarFont = &comic_sans_bold;
font_t const *gui_popFont = &comic_sans;
font_t const *gui_popEmphasisFont = &comic_sans_bold;

RGBcolor_t gui_backgroundColor = {255,255,255};
RGBcolor_t gui_listTextColor = {30,30,30};
RGBcolor_t gui_popupColor = {255,255,190};
RGBcolor_t gui_borderColor = {100,100,100};