/*
 * st7775_cmd.h
 *
 * Created: 21-5-2017 16:24:02
 *  Author: P
 */ 


#ifndef ST7775_CMD_H_
#define ST7775_CMD_H_



#define DRIVER_CODE_READ		(0x00)	//R
#define DRIVER_OUTPUT_CTRL		(0x01)	//W/R
#define LCD_DRIVING_CTRL		(0x02)	//W/R
#define ENTRY_MODE				(0x03)	//W/R
#define DISP_CTRL_1				(0x07)	//W/R
#define DISP_CTRL_2				(0x08)	//W/R
#define DISP_CTRL_4				(0x0B)	//W/R
#define RGB_INTRFC_CTRL_1		(0x0C)	//W/R
#define FRAME_MARKER_POS		(0x0F)	//W/R
#define POWER_CTRL_1			(0x10)	//W/R
#define POWER_CTRL_2			(0x11)	//W/R
#define HORI_ADDR_SET			(0x20)	//W/R
#define VERT_ADDR_SET			(0x21)	//W/R
#define READ_WRITE_GRAM			(0x22)	//W/R
#define SOFTWARE_RESET			(0x28)	//W
#define GATE_SCAN_CTRL			(0x30)	//W/R
#define VERT_SCROLL_CTRL_1		(0x31)	//W/R
#define VERT_SCROLL_CTRL_2		(0x32)	//W/R
#define VERT_SCROLL_CTRL_3		(0x33)	//W/R
#define PARTIAL_DRIVING_CTRL_1	(0x34)	//W/R
#define PARTIAL_DRIVING_CTRL_2	(0x35)	//W/R
#define HORI_ADDR_END_POS		(0x36)	//W/R
#define HORI_ADDR_START_POS		(0x37)	//W/R
#define VERT_ADDR_END_POS		(0x38)	//W/R
#define VERT_ADDR_START_POS		(0x39)	//W/R
#define GAMMA_CTRL_1			(0x50)	//W/R
#define GAMMA_CTRL_2			(0x51)	//W/R
#define GAMMA_CTRL_3			(0x52)	//W/R
#define GAMMA_CTRL_4			(0x53)	//W/R
#define GAMMA_CTRL_5			(0x54)	//W/R
#define GAMMA_CTRL_6			(0x55)	//W/R
#define GAMMA_CTRL_7			(0x56)	//W/R
#define GAMMA_CTRL_8			(0x57)	//W/R
#define GAMMA_CTRL_9			(0x58)	//W/R
#define GAMMA_CTRL_10			(0x59)	//W/R
#define ID_CODE					(0x65)	//R
#define SPI_READ_WRITE_CTRL		(0x66)	//W/R
#define POWER_CTRL_3			(0xB0)	//W/R
#define POWER_CTRL_4			(0xB1)	//W/R
#define POWER_CTRL_5			(0xB2)	//W/R
#define NVM_ID_CODE				(0xD2)	//W/R
#define NVM_CTRL_STATUS			(0xD9)	//W/R
#define NVM_WRITE_CMD			(0xDF)	//W
#define NVM_ENABLE				(0xFA)	//W/R
#define NVM_VCOM_OFFSET			(0xFE)	//W/R
#define NVM_CMD_ENABLE			(0xFF)	//W



#endif /* ST7775_CMD_H_ */