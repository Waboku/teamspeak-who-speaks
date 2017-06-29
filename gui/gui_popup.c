/*
 * gui_popup.c
 *
 * Created: 20-6-2017 15:53:05
 *  Author: P
 */ 



#define USER_OPTIONS_X_SIZE 60
#define USER_OPTIONS_Y_SIZE 60

#define POP_ITEM_Y_SIZE 20


void pop_spawnNew(gui_list_object_t *obj, screen_pos_t touch){
	switch(obj->objectType){		
	case USER:
		pop_createBoundingBox(touch,width,items);
	break;
	case SERVER:
	break;
	case CHANNEL:
	break;
	case WIFI_AP:
	break;
	default:
	case GUI_NULL:
	break;
		
	}
}

uint8_t pop_typeToItemCount(popup_type_t type){
	switch(type){
	}
}

screen_pos_t pop_renderItemBox(popup_state_t pop){
	
		uint8_t itemCount = pop_typeToItemCount(pop.type);
		int16_t xSize = pop.bound[0].x - pop.bound[1].x;
		int16_t ySize = pop.bound[0].y - pop.bound[1].y;
		int8_t  yButtonSize = POP_ITEM_Y_SIZE;
		
		//these functions cause the menu to expand to the top or to the left when the default direction doesnt fit
		if(pos.x + xSize > LCD_X_MAX){ //expand to the left if true
			xSize = -xSize;
		}		
		if(pos.y + ySize > LCD_Y_MAX){ //expand upward if true
			ySize = -ySize;
			yButtonSize = -yButtonSize;
		}
		
		
		Obj->graphicalObjs[0].type = RECTANGLE_SOLID;
		Obj->graphicalObjs[0].data.solidRectangle.color = gui_popupColor;
		Obj->graphicalObjs[0].data.solidRectangle.positions[0] = pos;
		Obj->graphicalObjs[0].data.solidRectangle.positions[1].x = pos.x + xSize;
		Obj->graphicalObjs[0].data.solidRectangle.positions[1].y = pos.y + ySize;
		
		for(uint8_t i = 1; i < 4; i++){
			Obj->graphicalObjs[i].type = RECTANGLE;
			Obj->graphicalObjs[i].data.rectangle.color = gui_borderColor;
			Obj->graphicalObjs[i].data.rectangle.positions[0].x = pos.x;
			Obj->graphicalObjs[i].data.rectangle.positions[0].y = pos.y + ((i-1)*buttonSize);
			Obj->graphicalObjs[i].data.rectangle.positions[1].x = pos.x + xSize;
			Obj->graphicalObjs[i].data.rectangle.positions[1].y = pos.y + (i*buttonSize);
		}
		
		Obj->graphicalObjs[4].data.text.str = "Kick";
		Obj->graphicalObjs[5].data.text.str = "Ban";
		Obj->graphicalObjs[6].data.text.str = "Cancel";
		
		for(uint8_t i = 4; i < 7; i++){
			Obj->graphicalObjs[i].type = TEXT;
			Obj->graphicalObjs[i].data.text.color = gui_textColor;
			Obj->graphicalObjs[i].data.text.font = gui_font;
			Obj->graphicalObjs[i].data.text.touch.x = pos.x + xSize/2 - ((text_getStringWidth(Obj->graphicalObjs[i].data.text.str,Obj->graphicalObjs[i].data.text.font)/2));
			Obj->graphicalObjs[i].data.text.touch.y = pos.y + buttonSize/2 - (Obj->graphicalObjs[i].data.text.font->height/2) + (i-4)*buttonSize + 1;
			Obj->graphicalObjs[i].data.text.wrap.x = 0;
			Obj->graphicalObjs[i].data.text.wrap.y = 0;
		}
		
		Obj->bounds[0] = position;
		Obj->bounds[1].x = pos.x + xSize;
		Obj->bounds[1].y = pos.y + ySize;


	
	
}