/*
 * graphics.c
 *
 * Created: 22-5-2017 19:19:41
 *  Author: P
 */ 

#include "commons.h"
#include "st7775.h"
#include "st7775_cmd.h"
#include "graphics.h"
#include "sam.h"


/*! \brief Function that draws a single pixel line from	two coordinate sets
**	
*	\param start The screen coordinates for the beginning of the line
*	\param end The screen coordinates for the end of the line
*	\param color The color in which the line should appear
*
*/
void graphics_drawLine(screen_pos_t start, screen_pos_t end, RGBcolor_t color){

	if(end.x < start.x){
		graphics_drawLine(end, start, color);
		return;
	}
	
	int16_t deltaX = end.x-start.x;
	int16_t deltaY = end.y-start.y;
	int8_t slopeY;
	
	if(deltaY < 0){
		slopeY = -1;
		deltaY = -deltaY;
	}else{
		slopeY = 1;
	}
	
	if(deltaX >= deltaY){
		int16_t decision = ((deltaY)<<1)-deltaX;
		while(start.x != end.x){
			st7775_writeSpecificPixel(start, color);
			st7775_writeSpecificPixel(end, color);
			if(decision < 0){
				decision += (deltaY<<1);
			}else{
				decision += ((deltaY - deltaX)<<1);
				start.y += slopeY;
				end.y -= slopeY;
			}
			start.x+= 1;
			if(start.x == end.x){
				st7775_writeSpecificPixel(start, color);
				break;
			}
			end.x-= 1;
		}

		
		}else{
		int16_t decision = ((deltaX)<<1)-deltaY;
		while(start.y != end.y){
			st7775_writeSpecificPixel(end, color);
			st7775_writeSpecificPixel(start, color);
			if(decision < 0){
				decision += (deltaX<<1);
			}else{
				decision += ((deltaX - deltaY)<<1);
				start.x += 1;
				end.x -= 1;
			}
			start.y += slopeY;
			if(start.y == end.y){
				st7775_writeSpecificPixel(start, color);
				break;
			}
			end.y -= slopeY;
		}		
	}
	st7775_writeSpecificPixel(start, color);
}

/*! \brief Function that draws a single pixel border of a rectangle
**
*	\param start The screen coordinates for one of the corners of the rectangle
*	\param end The screen coordinates the opposing corner of the rectangle
*	\param color The color in which the rectangle boundary should appear
*
*/
void graphics_drawRectangle(screen_pos_t start, screen_pos_t end, RGBcolor_t color){
	
	if(start.x > end.x){
		graphics_drawRectangle((screen_pos_t){end.x, start.y}, (screen_pos_t){start.x, end.y}, color);
		return;
	}
	if(start.y > end.y){
		graphics_drawRectangle((screen_pos_t){start.x, end.y}, (screen_pos_t){end.x, start.y}, color);
		return;
	}
	
	if(start.x > LCD_X_MAX){
		return;
	}else if(end.x > LCD_X_MAX){
		end.x = LCD_X_MAX;
	}
	
	if(start.y > LCD_Y_MAX){
		return;
	}else if(end.y > LCD_Y_MAX){
		end.y = LCD_Y_MAX;
	}

	st7775_setCursor(start);
	st7775_setGramMode();
	for(uint16_t x = start.x; x <= end.x; x++){
		st7775_writePixel(color);
	}
	st7775_setCursor((screen_pos_t){start.x, end.y});
	st7775_setGramMode();
	for(uint16_t x = start.x; x <= end.x; x++){ // <= because otherwise one pixel is missing, really shoul
		st7775_writePixel(color);
	}
	for( ; start.y < end.y; start.y++){
		st7775_setCursor(start);
		st7775_setGramMode();
		st7775_writePixel(color);
		st7775_setCursor((screen_pos_t){end.x, start.y});
		st7775_setGramMode();
		st7775_writePixel(color);
	}
}


/*! \brief Function that draws a solid colored rectangle
**
*	\param start The screen coordinates for one of the corners of the rectangle
*	\param end The screen coordinates the opposing corner of the rectangle
*	\param color The color in which the rectangle should appear
*
*/
void graphics_drawSolidRectangle(screen_pos_t start, screen_pos_t end, RGBcolor_t color){

	if(start.x > end.x){
		graphics_drawSolidRectangle((screen_pos_t){end.x, start.y}, (screen_pos_t){start.x, end.y}, color);
		return;
	}
	if(start.y > end.y){
		graphics_drawSolidRectangle((screen_pos_t){start.x, end.y}, (screen_pos_t){end.x, start.y}, color);
		return;
	}
	
	if(start.x > LCD_X_MAX){
		return;
	}else if(end.x > LCD_X_MAX){
		end.x = LCD_X_MAX;
	}
	
	if(start.y > LCD_Y_MAX){
		return;
	}else if(end.y > LCD_Y_MAX){
		end.y = LCD_Y_MAX;
	}

	st7775_setCursor(start);
	st7775_setRegion(start,end);
	st7775_setGramMode();
	for(uint16_t y = start.y; y <= end.y; y++){
		for(uint16_t x = start.x; x <= end.x; x++){
			st7775_writePixel(color);
		}
	}
	//clear region?
	st7775_setRegion((screen_pos_t){0, 0},(screen_pos_t){LCD_X_MAX, LCD_Y_MAX});
}





/*! \brief Function that draws a bitmap on the coordinate specified
**
*	\param topLeft The coordinate for the top left pixel of the bitmap, the rest of the bitmap will continue down and to the right
*	\param bitmap The struct that contains the data required for the bitmap, easily generated with the bitmap.m file located in the tools folder
*
*/
void graphics_drawBitmap(screen_pos_t topLeft, const bitmap_t *bitmap){
	if(topLeft.x > LCD_X_MAX || topLeft.y > LCD_Y_MAX){
		return;
	}
	
	uint16_t xWidth = bitmap->xSize - 1;
	uint16_t yWidth = bitmap->ySize - 1;
	
	if(topLeft.x + bitmap->xSize > LCD_X_MAX){
		xWidth = LCD_X_MAX - topLeft.x;
	}
	
	if(topLeft.y + bitmap->ySize > LCD_Y_MAX){
		yWidth = LCD_Y_MAX - topLeft.y;
	}	
	
	st7775_setCursor(topLeft);	
	st7775_setRegion(topLeft, (screen_pos_t){topLeft.x + xWidth, topLeft.y + yWidth});
	st7775_setGramMode();	
	
	for(uint16_t y = 0 ; y <= yWidth; y++){
		for(uint16_t x = 0; x <= xWidth; x++){
			st7775_writePixel(bitmap->data[x + y*bitmap->xSize]);
		}
	}
	
	st7775_setRegion((screen_pos_t){0, 0},(screen_pos_t){LCD_X_MAX, LCD_Y_MAX});
}






