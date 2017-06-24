/*
 * usb_callback.c
 *
 * Created: 3-6-2017 21:55:14
 *  Author: vito-
 */ 

#include <stdint.h>
#include <udi_cdc.h>

#include "usb_callback.h"

void usb_callback_cdc_rx_notify(uint8_t port)
{
	UNUSED(port); // Unused
		
	uint8_t tx_data;
	
	tx_data = udi_cdc_getc();

	if (!udi_cdc_is_tx_ready()) {
		/* Fifo full */
		udi_cdc_signal_overrun();
	} else {
		udi_cdc_putc(tx_data);
	}
}