/*
 * gui_list.c
 *
 * Created: 12-6-2017 17:41:59
 *  Author: P
 */ 

#include <stdlib.h>
#include "sam.h"
#include "../graphics.h"
#include "gui_list.h"
#include "gui.h"
#include "../Bitmaps/all_bitmaps.h"




#define LIST_USER_INDENT		26
#define LIST_SERVER_INDENT		2
#define LIST_CHANNEL_INDENT		14
#define LIST_WIFI_INDENT		14

#define LIST_ICON_TO_TEXT_X_SPACING 2
#define LIST_ICON_TO_TEXT_Y_SPACING 2
#define LIST_ITEM_START		2
#define LIST_ITEM_HEIGHT	15
#define MAX_ITEMS_ON_SCREEN ((LCD_Y_SIZE-(LIST_ITEM_START*2))/LIST_ITEM_HEIGHT)






void gui_destroyObject(gui_list_object_t* obj){	
	free(obj);
}



gui_list_object_t* gui_createObject(gui_list_object_type_t type){
	
	gui_list_object_t *newObj = malloc(sizeof(gui_list_object_t));	
	return newObj;
}



void gui_renderListObject(gui_list_object_t *obj, int16_t screenListPosition){
	bitmap_t const *img;
	screen_pos_t pos = gui_objToCoords(obj, screenListPosition);
	
	img = gui_objToImg(obj);
	
	graphics_drawBitmap(pos,img);
	
	pos.x = pos.x + LIST_ICON_TO_TEXT_X_SPACING + img->xSize; //add one for some whitespace between the image and the text
	pos.y = pos.y + (img->ySize - gui_listFont->height)/2 + LIST_ICON_TO_TEXT_Y_SPACING; //add one to have the text one pixel higher than the image
	
	text_RenderString(pos,obj->name,gui_listFont, gui_listTextColor);
}


screen_pos_t gui_objToCoords(gui_list_object_t *obj, int16_t screenListPos){
	screen_pos_t pos;
	
	switch(obj->objectType){
		case USER:
			pos.x = LIST_USER_INDENT;
		break;
		case SERVER:
			pos.x = LIST_SERVER_INDENT;
		break;
		case CHANNEL:
			pos.x = LIST_CHANNEL_INDENT;
		break;
		case WIFI_AP:
			pos.x = LIST_WIFI_INDENT;
		break;
		default:
		case GUI_NULL:
			pos.x = LCD_X_SIZE;
		break;		
	}	
	
	if(screenListPos >= 0 && screenListPos < MAX_ITEMS_ON_SCREEN){
		pos.y = screenListPos * LIST_ITEM_HEIGHT + LIST_ITEM_START;	
	}else{
		pos.y = LCD_Y_SIZE; 
	}	
	
	return pos;	
}

bitmap_t const* gui_objToImg(gui_list_object_t *obj){
	bitmap_t const *img;
	switch(obj->status){
		case USER_QUITE:
		img = &user_quite;
		break;
		case USER_SPEAKING:
		img = &user_speaking;
		break;
		case USER_MIC_MUTE:
		img = &user_mic_mute;
		break;
		case USER_MIC_BAD:
		img = &user_mic_bad;
		break;
		case USER_SOUND_MUTE:
		img = &user_sound_mute;
		break;
		case USER_AFK:
		img = &user_afk;
		break;
		case SERVER_RUNNING:
		img = &server;
		break;
		case CHANNEL_PERM:
		img = &channel_perm;
		break;
		case CHANNEL_TEMP:
		img = &channel_temp;
		break;
		case WIFI_GREAT:
		img = &rssi_3;
		break;
		case WIFI_GOOD:
		img = &rssi_2;
		break;
		case WIFI_NORMAL:
		img  = &rssi_1;
		break;
		case WIFI_BAD:
		img  = &rssi_0;
		break;
		default:
		img = NULL;
		break;
	}
	return img;
}



/*

void gui_populateUser(gui_object_t* Obj, screen_pos_t position){
	
	Obj->graphicalObjs[0].type = BITMAP; 
	Obj->graphicalObjs[0].data.bitmap.data = &user_quite;
	Obj->graphicalObjs[0].data.bitmap.position = position;
	
	Obj->graphicalObjs[1].type = TEXT;
	Obj->graphicalObjs[1].data.text.color = gui_textColor;
	Obj->graphicalObjs[1].data.text.str = "Default User";
	Obj->graphicalObjs[1].data.text.font = gui_font;	
	Obj->graphicalObjs[1].data.text.position.x = position.x + 1 + Obj->graphicalObjs[0].data.bitmap.data->xSize;
	Obj->graphicalObjs[1].data.text.position.y = position.y + (Obj->graphicalObjs[0].data.bitmap.data->ySize - gui_font->height)/2 + 1;
	Obj->graphicalObjs[1].data.text.wrap.x = 0;
	Obj->graphicalObjs[1].data.text.wrap.y = 0;
	
	Obj->bounds[0] = position;
	Obj->bounds[1].x = LCD_X_MAX;
	Obj->bounds[1].y = position.y + Obj->graphicalObjs[0].data.bitmap.position.y;
}


void gui_populateServer(gui_object_t* Obj, screen_pos_t position){
	
	Obj->graphicalObjs[0].type = BITMAP;
	Obj->graphicalObjs[0].data.bitmap.data = &channel_perm;
	Obj->graphicalObjs[0].data.bitmap.position = position;
	
	Obj->graphicalObjs[1].type = TEXT;
	Obj->graphicalObjs[1].data.text.color = gui_textColor;
	Obj->graphicalObjs[1].data.text.str = "Default Server";
	Obj->graphicalObjs[1].data.text.font = gui_font;
	Obj->graphicalObjs[1].data.text.position.x = position.x + 1 + Obj->graphicalObjs[0].data.bitmap.data->xSize;
	Obj->graphicalObjs[1].data.text.position.y = position.y + (Obj->graphicalObjs[0].data.bitmap.data->ySize - gui_font->height)/2 + 1;
	Obj->graphicalObjs[1].data.text.wrap.x = 0;
	Obj->graphicalObjs[1].data.text.wrap.y = 0;
	
	Obj->graphicalObjs[2].type = BITMAP;
	Obj->graphicalObjs[2].data.bitmap.data = &password_icon;
	Obj->graphicalObjs[2].data.bitmap.position.x = LCD_X_MAX - Obj->graphicalObjs[2].data.bitmap.data->xSize - 3;
	Obj->graphicalObjs[2].data.bitmap.position.y = position.y;
	
	Obj->bounds[0] = position;
	Obj->bounds[1].x = LCD_X_MAX;
	Obj->bounds[1].y = position.y + Obj->graphicalObjs[0].data.bitmap.position.y;

}	

	
void gui_populateKeyboard(gui_object_t* Obj, screen_pos_t position){
	
	Obj->graphicalObjs[0].type = KEYBOARD;
	Obj->graphicalObjs[0].data.keyboard.keys = &kbLettersSmall;
	Obj->graphicalObjs[0].data.keyboard.backgroundColor = KB_BCKGND_COLOR;
	Obj->graphicalObjs[0].data.keyboard.keyColor = KB_BORDER_COLOR;
	Obj->graphicalObjs[0].data.keyboard.symbolColor = KB_CHAR_COLOR;
	Obj->graphicalObjs[0].data.keyboard.height = 0;

}


void gui_populateWifiName(gui_object_t* Obj, screen_pos_t position){
		
	Obj->graphicalObjs[0].type = BITMAP;
	Obj->graphicalObjs[0].data.bitmap.data = &rssi_3;
	Obj->graphicalObjs[0].data.bitmap.position = position;
	
	Obj->graphicalObjs[1].type = TEXT;
	Obj->graphicalObjs[1].data.text.color = gui_textColor;
	Obj->graphicalObjs[1].data.text.str = "Default AP";
	Obj->graphicalObjs[1].data.text.font = gui_font;
	Obj->graphicalObjs[1].data.text.position.x = position.x + 1 + Obj->graphicalObjs[0].data.bitmap.data->xSize;
	Obj->graphicalObjs[1].data.text.position.y = position.y + (Obj->graphicalObjs[0].data.bitmap.data->ySize - gui_font->height)/2 + 1;
	Obj->graphicalObjs[1].data.text.wrap.x = 0;
	Obj->graphicalObjs[1].data.text.wrap.y = 0;	

	
	Obj->bounds[0] = position;
	Obj->bounds[1].x = LCD_X_MAX;
	Obj->bounds[1].y = position.y + Obj->graphicalObjs[0].data.bitmap.position.y;
		
	
}

void gui_populateUserOptions(gui_object_t* Obj, screen_pos_t position){
	int8_t xSize;
	int8_t buttonSize;
	
	if(position.x + USER_OPTIONS_X_SIZE <= LCD_X_MAX){
		xSize = USER_OPTIONS_X_SIZE;
	}else{
		xSize = -USER_OPTIONS_X_SIZE;
	}
	if(position.y + USER_OPTIONS_Y_SIZE > LCD_Y_MAX){
		position.y = LCD_Y_MAX - USER_OPTIONS_Y_SIZE;
	}
	
	buttonSize = (USER_OPTIONS_Y_SIZE/3);
	
	Obj->graphicalObjs[0].type = RECTANGLE_SOLID;
	Obj->graphicalObjs[0].data.solidRectangle.color = gui_popupColor;
	Obj->graphicalObjs[0].data.solidRectangle.positions[0] = position;
	Obj->graphicalObjs[0].data.solidRectangle.positions[1].x = position.x + xSize;
	Obj->graphicalObjs[0].data.solidRectangle.positions[1].y = position.y + USER_OPTIONS_Y_SIZE;
	
	for(uint8_t i = 1; i < 4; i++){
		Obj->graphicalObjs[i].type = RECTANGLE;
		Obj->graphicalObjs[i].data.rectangle.color = gui_borderColor;
		Obj->graphicalObjs[i].data.rectangle.positions[0].x = position.x;
		Obj->graphicalObjs[i].data.rectangle.positions[0].y = position.y + ((i-1)*buttonSize);
		Obj->graphicalObjs[i].data.rectangle.positions[1].x = position.x + xSize;
		Obj->graphicalObjs[i].data.rectangle.positions[1].y = position.y + (i*buttonSize);
	}
	
	Obj->graphicalObjs[4].data.text.str = "Kick";
	Obj->graphicalObjs[5].data.text.str = "Ban";
	Obj->graphicalObjs[6].data.text.str = "Cancel";
	
	for(uint8_t i = 4; i < 7; i++){
		Obj->graphicalObjs[i].type = TEXT;
		Obj->graphicalObjs[i].data.text.color = gui_textColor;		
		Obj->graphicalObjs[i].data.text.font = gui_font;
		Obj->graphicalObjs[i].data.text.position.x = position.x + xSize/2 - ((text_getStringWidth(Obj->graphicalObjs[i].data.text.str,Obj->graphicalObjs[i].data.text.font)/2));
		Obj->graphicalObjs[i].data.text.position.y = position.y + buttonSize/2 - (Obj->graphicalObjs[i].data.text.font->height/2) + (i-4)*buttonSize + 1;
		Obj->graphicalObjs[i].data.text.wrap.x = 0;
		Obj->graphicalObjs[i].data.text.wrap.y = 0;
	}	
	
	Obj->bounds[0] = position;
	Obj->bounds[1].x = position.x + xSize;
	Obj->bounds[1].y = position.y + USER_OPTIONS_Y_SIZE;


}


*/