/*
 * stdio_setup.c
 *
 * Created: 4-6-2017 00:46:06
 *  Author: vito-
 */ 
#include <udi_cdc.h>

#include "stdio_setup.h"

void stdio_init(void)
{
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
}

int _read (int file, char * ptr, int len);
int _read (int file, char * ptr, int len)
{
	int nChars = 0;

	if (file != 0) {
		return -1;
	}

	for (; len > 0; --len) {
		*ptr = udi_cdc_getc();
		ptr++;
		nChars++;
	}
	return nChars;
}

int _write (int file, char * ptr, int len);
int _write (int file, char * ptr, int len)
{
	int nChars = 0;

	if ((file != 1) && (file != 2) && (file!=3)) {
		return -1;
	}

	for (; len != 0; --len) {
		if (udi_cdc_putc(*ptr++) < 0) {
			return -1;
		}
		++nChars;
	}
	return nChars;
}