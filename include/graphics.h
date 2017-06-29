/*
 * graphics.h
 *
 * Created: 22-5-2017 19:20:39
 *  Author: P
 */ 


#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "commons.h"


#define LCD_X_SIZE 176 
#define LCD_Y_SIZE 220

#define LCD_X_MAX LCD_X_SIZE-1
#define LCD_Y_MAX LCD_Y_SIZE-1



typedef struct{
	#if (LCD_X_MAX <= UINT8_MAX) && (LCD_Y_MAX <= UINT8_MAX)
	uint8_t x;
	uint8_t y;
 	#else
 	uint16_t x;
 	uint16_t y;
 	#endif
}screen_pos_t;

typedef struct{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
}RGBcolor_t;


	
typedef struct{
	uint16_t xSize;
	uint16_t ySize;
	const RGBcolor_t *data;
}bitmap_t;




//default colors 
#define BLACK	(RGBcolor_t){.red = 0, .green = 0, .blue = 0}
#define WHITE	(RGBcolor_t){.red = 255, .green = 255, .blue = 255}
#define RED		(RGBcolor_t){.red = 255, .green = 0, .blue = 0}
#define GREEN	(RGBcolor_t){.red = 0, .green = 255, .blue = 0}
#define BLUE	(RGBcolor_t){.red = 0, .green = 0, .blue = 255}
#define YELLOW	(RGBcolor_t){.red = 255, .green = 255, .blue = 0}
#define MAGENTA (RGBcolor_t){.red = 255, .green = 0, .blue = 255}
#define CYAN	(RGBcolor_t){.red = 0, .green = 255, .blue = 255}

void graphics_drawLine(screen_pos_t start, screen_pos_t end, RGBcolor_t color);
void graphics_drawRectangle(screen_pos_t start, screen_pos_t end, RGBcolor_t color);
void graphics_drawSolidRectangle(screen_pos_t start, screen_pos_t end, RGBcolor_t color);
void graphics_drawBitmap(screen_pos_t topLeft, const bitmap_t *bitmap);


#endif /* GRAPHICS_H_ */