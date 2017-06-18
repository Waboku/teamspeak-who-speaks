#include <asf.h>
#include "conf_usb.h"
#include "stdio_setup.h"

int main(void)
{
	irq_initialize_vectors();
	cpu_irq_enable();

	system_init();
	udc_start();
	delay_init();
	stdio_init();

	while (true) {
		printf("Hello world\r\n");
		delay_ms(1000);
	}
}

