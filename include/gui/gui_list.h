/*
 * gui.h
 *
 * Created: 12-6-2017 17:42:11
 *  Author: P
 */ 


#ifndef GUI_LIST_H_
#define GUI_LIST_H_

#include "../text.h"


typedef enum{
	GUI_NULL, USER, SERVER, CHANNEL, WIFI_AP, //etc. etc. probably alot more i havent thought about
}gui_list_object_type_t;



typedef enum{
	USER_QUITE,
	USER_SPEAKING,
	USER_MIC_MUTE,
	USER_MIC_BAD,
	USER_SOUND_MUTE,
	USER_AFK,
	
	SERVER_RUNNING,
	
	CHANNEL_PERM,
	CHANNEL_TEMP,
	
	WIFI_GREAT,
	WIFI_GOOD,
	WIFI_NORMAL,
	WIFI_BAD,
}gui_list_object_status_t;


typedef struct{
	uint32_t id;
	uint8_t *name;
	gui_list_object_status_t status;
	gui_list_object_type_t objectType;
}gui_list_object_t;

void gui_destroyObject(gui_list_object_t* obj);
screen_pos_t gui_objToCoords(gui_list_object_t *obj, int16_t screenListPos);
gui_list_object_t* gui_createObject(gui_list_object_type_t type);
void gui_renderListObject(gui_list_object_t *obj, int16_t screenListPosition);
bitmap_t const* gui_objToImg(gui_list_object_t *obj);

/*
void gui_populateUser(gui_object_t* Obj, screen_pos_t position);
void gui_populateServer(gui_object_t* Obj, screen_pos_t position);
void gui_populateKeyboard(gui_object_t* Obj, screen_pos_t position);
void gui_populateWifiName(gui_object_t* Obj, screen_pos_t position);
void gui_populateUserOptions(gui_object_t* Obj, screen_pos_t position);

*/

#endif /* GUI_LIST_H_ */