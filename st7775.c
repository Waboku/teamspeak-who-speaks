/*
* display.c
*
* Created: 20-9-2013 0:29:21
*  Author: Aran Dokoupil
*/

#include "commons.h"
#include <delay.h>
#include "st7775.h"
#include "st7775_cmd.h"
#include "graphics.h"
#include "sam.h"



static void st7775_writeByte(uint8_t data);
static void writeWr(uint8_t command, uint16_t data);
static void st7775_readMode(void);
static void st7775_writeMode(void);
static void writeWrReg(uint8_t command);
static void writeWrData(uint16_t data);


static const uint8_t   command_reg[] = {DRIVER_OUTPUT_CTRL, LCD_DRIVING_CTRL, ENTRY_MODE, DISP_CTRL_2, RGB_INTRFC_CTRL_1,  POWER_CTRL_2, POWER_CTRL_3, POWER_CTRL_4, POWER_CTRL_5,  GATE_SCAN_CTRL, VERT_SCROLL_CTRL_1, VERT_SCROLL_CTRL_2, VERT_SCROLL_CTRL_3, PARTIAL_DRIVING_CTRL_1, PARTIAL_DRIVING_CTRL_2, HORI_ADDR_END_POS, HORI_ADDR_START_POS, VERT_ADDR_END_POS, VERT_ADDR_START_POS,  GAMMA_CTRL_1, GAMMA_CTRL_2, GAMMA_CTRL_3, GAMMA_CTRL_4, GAMMA_CTRL_5, GAMMA_CTRL_6, GAMMA_CTRL_7, GAMMA_CTRL_8, GAMMA_CTRL_9, GAMMA_CTRL_10, HORI_ADDR_SET, VERT_ADDR_SET, DISP_CTRL_1};
static const uint16_t command_data[] = {0x011C, 0x0100, 0x1230, 0x0808, 0x0002, 0x1038, 0x1411, 0x0202, 0x0313, 0x0000, 0x00DB, 0x0000, 0x0000, 0x00DB, 0x0000, 0x00AF, 0x0000, 0x00DB, 0x0000, 0x0000, 0x0300, 0x0103, 0x2011, 0x0703, 0x0000, 0x0400, 0x0107, 0x2011, 0x0703, 0x0000, 0x0000, 0x1017};


/*! \brief Sends a byte over the LCD bus and clocks it in.
*
*	uses nop's to adhere to the slow speed of the LCD
*
*	\param data The byte that should appear on the bus.
*
*/
static void st7775_writeByte(uint8_t data){
	
	WR_LO(); //set clock low	
	asm volatile("NOP");
	LCD_DATA_PORT.OUTSET.reg = data; //put data on the bus
	LCD_DATA_PORT.OUTCLR.reg = ~(data)&LCD_DATA_gm; //put data on the bus
	asm volatile("NOP");
	asm volatile("NOP");
	WR_HI();	//set clock high again
	asm volatile("NOP");
}


/*! \brief Initializes the display for use with the microcontroller
*
*	writes all the needed commands to correctly interface with the display
*
*/
void st7775_init(void){
	CS_HI();
	WR_HI();
	RD_HI();
	RS_HI();
	
	RESET_HI();
	delay_ms(10);
	RESET_LO();
	delay_ms(10);
	RESET_HI();	

	CS_LO();
	st7775_writeMode();	
	
	for(uint8_t i = 0; i < sizeof(command_reg); i++){
		writeWr(command_reg[i],command_data[i]);
	}
	/*
	writeWr(DRIVER_OUTPUT_CTRL,	 0x011C);
	writeWr(LCD_DRIVING_CTRL,	 0x0100);
	writeWr(ENTRY_MODE,			 0x1230);
	writeWr(DISP_CTRL_2,		 0x0808);
	writeWr(RGB_INTRFC_CTRL_1,	 0x0002);

	writeWr(POWER_CTRL_2, 0x1038);
	writeWr(POWER_CTRL_3, 0x1411);
	writeWr(POWER_CTRL_4, 0x0202);
	writeWr(POWER_CTRL_5, 0x0313);

	writeWr(GATE_SCAN_CTRL,			 0x0000);
	writeWr(VERT_SCROLL_CTRL_1,		 0x00DB);
	writeWr(VERT_SCROLL_CTRL_2,		 0x0000);
	writeWr(VERT_SCROLL_CTRL_3,		 0x0000);
	writeWr(PARTIAL_DRIVING_CTRL_1,	 0x00DB);
	writeWr(PARTIAL_DRIVING_CTRL_2,	 0x0000);
	writeWr(HORI_ADDR_END_POS,		 0x00AF);
	writeWr(HORI_ADDR_START_POS,	 0x0000);
	writeWr(VERT_ADDR_END_POS,		 0x00DB);
	writeWr(VERT_ADDR_START_POS,	 0x0000);

	writeWr(GAMMA_CTRL_1,	 0x0000);
	writeWr(GAMMA_CTRL_2,	 0x0300);
	writeWr(GAMMA_CTRL_3,	 0x0103);
	writeWr(GAMMA_CTRL_4,	 0x2011);
	writeWr(GAMMA_CTRL_5,	 0x0703);
	writeWr(GAMMA_CTRL_6,	 0x0000);
	writeWr(GAMMA_CTRL_7,	 0x0400);
	writeWr(GAMMA_CTRL_8,	 0x0107);
	writeWr(GAMMA_CTRL_9,	 0x2011);
	writeWr(GAMMA_CTRL_10,	 0x0703);
	writeWr(HORI_ADDR_SET,	 0x0000);
	writeWr(VERT_ADDR_SET,	 0x0000);
	writeWr(DISP_CTRL_1,	 0x1017);
	*/
	
	CS_HI();
}



/*! \brief Send a command byte and to data bytes to the display
*
*	\param command command byte, send first
*	\param data two data bytes, send second
*
*/
static void writeWr(uint8_t command, uint16_t data) {
	writeWrReg(command);
	writeWrData(data);
}

/*! \brief Send a command byte to the display
*
*	\param command command byte being send
*
*/
static void writeWrReg(uint8_t command) {
	CS_LO();
	RS_LO();	
	st7775_writeByte(0x00);
	st7775_writeByte(command);		
	RS_HI();
}

/*! \brief Send a two data bytes to the display
*
*	\param data data bytes being send
*
*/
static void writeWrData(uint16_t data) {	
	st7775_writeByte(data >> 8);
	st7775_writeByte(data & 0xff);
	CS_HI();
}


/*! \brief sets the LCD bus in read mode
*
*	set's the IO's that interface with the LCD as input's and changes the control signals to specify the bus direction
*
*/
static void st7775_readMode(void){
	LCD_DATA_PORT.DIRCLR.reg = LCD_DATA_gm; //set IO's to input
	WR_HI(); //tell the display the bus is an input
	RD_LO();
}


/*! \brief sets the lcd bus in write mode
*
*	set's the IO's that interface with the LCD as output's and changes the control signals to specify the bus direction
*
*/
static void st7775_writeMode(void){
	RD_HI(); //tel the display that the bus is an output
	WR_LO();
	LCD_DATA_PORT.DIRSET.reg = LCD_DATA_gm; //set IO's to output
}


/*! \brief Sets the cursor (position where the next graphical data will be send to) to the specified screen coordinates
*
*	\param position The X and Y coordinates where the cursor will be positioned, x=0, y=0 is the top left
*
*/
void st7775_setCursor(screen_pos_t position){
	writeWr(HORI_ADDR_SET,position.x);
	writeWr(VERT_ADDR_SET,position.y);
}


/*! \brief Sets the region (position of ram that will wrap automatically) to the specified screen coordinates
*
*	\param start The X and Y coordinates where the region will start, the start coordinates MUST be smaller than the end coordinates!
*	\param end The X and Y coordinates where the region will end, the end coordinates MUST be larger than the start coordinates!
*
*/
void st7775_setRegion(screen_pos_t start, screen_pos_t end){
	writeWr(HORI_ADDR_END_POS, end.x);
	writeWr(HORI_ADDR_START_POS,start.x);
	writeWr(VERT_ADDR_END_POS,end.y);
	writeWr(VERT_ADDR_START_POS,start.y);
}


/*! \brief Sets the display in Graphical Ram mode, all subsequent bytes send will be written to the graphical ram, depending on the cursor position. 
*	
*
*/
void st7775_setGramMode(void){
	writeWrReg(READ_WRITE_GRAM);
}

/*! \brief Writes three bytes tot the current Gram address corresponding to the specified color
*
*	\param color  the color that is send to the display
*
*/
void st7775_writePixel(const RGBcolor_t color){
	st7775_writeByte(color.red);
	st7775_writeByte(color.green);
	st7775_writeByte(color.blue);
}

/*! \brief Writes three bytes tot the specified Gram address corresponding to the specified color
*
*	\param position The coordinates of the pixel that is changed of color
*	\param color the color that is send to the display
*
*/
void st7775_writeSpecificPixel(screen_pos_t position, RGBcolor_t color){
	st7775_setCursor(position);
	writeWrReg(READ_WRITE_GRAM);
	st7775_writePixel(color);
}

