/*
 * touch.h
 *
 * Created: 6-6-2017 13:19:21
 *  Author: P
 */ 


#ifndef TOUCH_H_
#define TOUCH_H_

typedef enum{
	TOUCH_IDLE, TOUCH_X_DIR, TOUCH_Y_DIR
}touch_measure_mode_t;

#include "asf.h"
#include "adc.h"


extern struct adc_module adc_instance;

screen_pos_t touch_adcToScreen(uint16_t adc_x, uint16_t adc_y);
uint16_t touch_adcValue(void);
void touch_init(void);
void touch_uninit(void);
uint16_t touch_getPos(touch_measure_mode_t dir);



#endif /* TOUCH_H_ */