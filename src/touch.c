/*
 * touch.c
 *
 * Created: 6-6-2017 13:19:07
 *  Author: P
 */ 

#include "commons.h"
#include "graphics.h"
#include "touch.h"
#include "asf.h"
#include "adc.h"

struct adc_module adc_instance;
struct adc_config conf_adc;

screen_pos_t touch_adcToScreen(uint16_t adc_x, uint16_t adc_y){
	return (screen_pos_t){0,0};
}



uint16_t touch_getPos(touch_measure_mode_t direction){
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	switch (direction)
	{
	
	break;
	case TOUCH_X_DIR:
		TOUCH_Y_PLUS_PORT.OUTCLR.reg = TOUCH_Y_PLUS_bm;
		TOUCH_Y_MIN_PORT.OUTCLR.reg = TOUCH_Y_MIN_bm;
		TOUCH_Y_PLUS_PORT.DIRCLR.reg = TOUCH_Y_PLUS_bm;
		TOUCH_Y_MIN_PORT.DIRCLR.reg = TOUCH_Y_MIN_bm;
			
		TOUCH_X_PLUS_PORT.DIRSET.reg = TOUCH_X_PLUS_bm;
		TOUCH_X_MIN_PORT.DIRSET.reg = TOUCH_X_MIN_bm;
		TOUCH_X_PLUS_PORT.OUTSET.reg = TOUCH_X_PLUS_bm;
		TOUCH_X_MIN_PORT.OUTCLR.reg = TOUCH_X_MIN_bm;
		
		delay_ms(10);
		
		adc_set_positive_input(&adc_instance, TOUCH_Y_MIN_ADC_pos);
		touch_adcValue();

	break;
	case TOUCH_Y_DIR:
		TOUCH_X_PLUS_PORT.OUTCLR.reg = TOUCH_X_PLUS_bm;
		TOUCH_X_MIN_PORT.OUTCLR.reg = TOUCH_X_MIN_bm;
		TOUCH_X_PLUS_PORT.DIRCLR.reg = TOUCH_X_PLUS_bm;
		TOUCH_X_MIN_PORT.DIRCLR.reg = TOUCH_X_MIN_bm;
		
		
		TOUCH_Y_PLUS_PORT.DIRSET.reg = TOUCH_Y_PLUS_bm;
		TOUCH_Y_MIN_PORT.DIRSET.reg = TOUCH_Y_MIN_bm;
		TOUCH_Y_PLUS_PORT.OUTSET.reg = TOUCH_Y_PLUS_bm;
		TOUCH_Y_MIN_PORT.OUTCLR.reg = TOUCH_Y_MIN_bm;
		
		delay_ms(10);
		
		adc_set_positive_input(&adc_instance, TOUCH_X_MIN_ADC_pos);
		touch_adcValue();
	break;
	default:
	case TOUCH_IDLE:
		return 0;
	break;
	}
	
	
	adc_reset(&adc_instance);
	touch_uninit();
	return 8;		
}



uint16_t touch_adcValue(void)
{		
	uint16_t raw_result = 5;
	adc_enable(&adc_instance);
	adc_start_conversion(&adc_instance);
	
	while (STATUS_OK != adc_read(&adc_instance, &raw_result) );
	 	
	printf("\r\nRead ADC Value %u", raw_result);
	adc_disable(&adc_instance);
	return raw_result;
}



void touch_init(void){	
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.clock_source = GCLK_GENERATOR_0;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CTRLB_PRESCALER_DIV32;
	conf_adc.gain_factor = ADC_GAIN_FACTOR_DIV2;	
}

void touch_uninit(void){
	struct system_pinmux_config config;
	system_pinmux_get_config_defaults(&config);
	
	config.input_pull = SYSTEM_PINMUX_PIN_PULL_NONE;	
	
	system_pinmux_pin_set_config(TOUCH_Y_PLUS_bp, &config);
	system_pinmux_pin_set_config(TOUCH_Y_MIN_bp, &config);
	system_pinmux_pin_set_config(TOUCH_X_PLUS_bp, &config);
	system_pinmux_pin_set_config(TOUCH_X_MIN_bp, &config);	
}