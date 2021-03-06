/*
 * gui_popup.h
 *
 * Created: 20-6-2017 15:53:17
 *  Author: P
 */ 


#ifndef GUI_POPUP_H_
#define GUI_POPUP_H_


typedef enum{
	POP_NONE, POP_USER_OPTIONS, POP_LOADING, POP_WIFI_LOGIN, POP_SERVER_ADDR, POP_SERVER_LOGIN, POP_USERNAME
}gui_popup_type_t;

typedef struct{
	struct gui_list_object_t *source;
	gui_popup_type_t type;
	screen_pos_t position;
}gui_popup_t;




#endif /* GUI_POPUP_H_ */