/*
 * Open_Sans.h
 *
 *Generated by matlab
 */ 


#ifndef OPEN_SANS_H_
#define OPEN_SANS_H_


#include "../text.h"

//This font is Open Sans size 14

static const uint8_t fontName[] = "Open Sans";
static const uint8_t fontWidth[95];
static const uint16_t fontData[1330];

const font_t open_sans = {.name = fontName, .charWidth = fontWidth, .charData = fontData, .height = 14, .totalCharAmount = 95};


static const uint8_t fontWidth[95] =	{5, 4, 6, 11, 8, 12, 10, 3, 4, 4, 8, 8, 4, 5, 4, 7, 8, 5, 8, 8, 10, 8, 8, 8, 8, 8, 4, 4, 8, 8, 8, 7, 13, 11, 9, 9, 10, 8, 8, 10, 10, 4, 6, 10, 8, 13, 11, 11, 8, 11, 9, 8, 10, 10, 10, 15, 10, 10, 8, 6, 7, 6, 8, 8, 4, 8, 9, 7, 9, 8, 7, 10, 9, 4, 6, 8, 4, 13, 9, 8, 9, 9, 7, 7, 7, 9, 9, 13, 8, 9, 7, 6, 3, 6, 8, };


/* the actual system font, sorted in ASCII, the comment near every sub-array specifies the character*/
static const uint16_t fontData[1330] = 	
	{	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//' '
		0x0000, 0x0003, 0x0003, 0x0003, 0x0002, 0x0002, 0x0002, 0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 		//'!'
		0x0000, 0x0009, 0x0009, 0x0009, 0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'"'
		0x0000, 0x0024, 0x0024, 0x0024, 0x00ff, 0x0024, 0x0048, 0x01fe, 0x0048, 0x0048, 0x0048, 0x0000, 0x0000, 0x0000, 		//'#'
		0x0000, 0x001f, 0x0028, 0x0028, 0x0038, 0x000e, 0x000b, 0x0009, 0x0009, 0x003e, 0x0008, 0x0000, 0x0000, 0x0000, 		//'$'
		0x0000, 0x0384, 0x0244, 0x0248, 0x0250, 0x0256, 0x01a9, 0x0029, 0x0049, 0x00c9, 0x0086, 0x0000, 0x0000, 0x0000, 		//'%'
		0x0000, 0x0078, 0x0048, 0x0048, 0x0058, 0x0030, 0x00d1, 0x0089, 0x0086, 0x0086, 0x0079, 0x0000, 0x0000, 0x0000, 		//'&'
		0x0000, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'''
		0x0000, 0x0001, 0x0001, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0001, 0x0001, 0x0000, 		//'('
		0x0000, 0x0002, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0002, 0x0000, 		//')'
		0x000c, 0x0008, 0x003b, 0x000c, 0x001e, 0x0012, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'*'
		0x0000, 0x0000, 0x0000, 0x0000, 0x0008, 0x0008, 0x003f, 0x0008, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'+'
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0002, 0x0000, 0x0000, 		//','
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0007, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'-'
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 		//'.'
		0x0000, 0x0001, 0x0002, 0x0002, 0x0006, 0x0004, 0x0004, 0x000c, 0x0008, 0x0008, 0x0010, 0x0000, 0x0000, 0x0000, 		//'/'
		0x0000, 0x001e, 0x0033, 0x0021, 0x0021, 0x0021, 0x0021, 0x0021, 0x0021, 0x0033, 0x001e, 0x0000, 0x0000, 0x0000, 		//'0'
		0x0000, 0x0003, 0x0007, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 		//'1'
		0x0000, 0x001e, 0x0023, 0x0001, 0x0001, 0x0002, 0x0006, 0x000c, 0x0018, 0x0030, 0x003f, 0x0000, 0x0000, 0x0000, 		//'2'
		0x0000, 0x001e, 0x0023, 0x0001, 0x0002, 0x001c, 0x0003, 0x0001, 0x0001, 0x0003, 0x003e, 0x0000, 0x0000, 0x0000, 		//'3'
		0x0000, 0x0004, 0x000c, 0x0014, 0x0014, 0x0024, 0x0044, 0x0044, 0x00ff, 0x0004, 0x0004, 0x0000, 0x0000, 0x0000, 		//'4'
		0x0000, 0x003e, 0x0020, 0x0020, 0x0020, 0x003e, 0x0003, 0x0001, 0x0001, 0x0003, 0x003e, 0x0000, 0x0000, 0x0000, 		//'5'
		0x0000, 0x000f, 0x0010, 0x0030, 0x0020, 0x002e, 0x0031, 0x0021, 0x0021, 0x0031, 0x001e, 0x0000, 0x0000, 0x0000, 		//'6'
		0x0000, 0x003f, 0x0001, 0x0003, 0x0002, 0x0006, 0x0004, 0x0004, 0x0008, 0x0008, 0x0010, 0x0000, 0x0000, 0x0000, 		//'7'
		0x0000, 0x001e, 0x0021, 0x0021, 0x0032, 0x000c, 0x0033, 0x0021, 0x0021, 0x0021, 0x001e, 0x0000, 0x0000, 0x0000, 		//'8'
		0x0000, 0x001e, 0x0023, 0x0021, 0x0021, 0x0023, 0x001d, 0x0001, 0x0001, 0x0002, 0x003c, 0x0000, 0x0000, 0x0000, 		//'9'
		0x0000, 0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 		//':'
		0x0000, 0x0000, 0x0000, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0002, 0x0002, 0x0000, 0x0000, 		//';'
		0x0000, 0x0000, 0x0000, 0x0001, 0x0006, 0x0018, 0x0030, 0x000e, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'<'
		0x0000, 0x0000, 0x0000, 0x0000, 0x003f, 0x0000, 0x0000, 0x003f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'='
		0x0000, 0x0000, 0x0000, 0x0020, 0x0018, 0x0006, 0x0003, 0x001c, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'>'
		0x0000, 0x001e, 0x0002, 0x0001, 0x0002, 0x0004, 0x0008, 0x0008, 0x0000, 0x0008, 0x0008, 0x0000, 0x0000, 0x0000, 		//'?'
		0x0000, 0x00f8, 0x0106, 0x0201, 0x0479, 0x0489, 0x0489, 0x0489, 0x047e, 0x0600, 0x0300, 0x00f8, 0x0000, 0x0000, 		//'@'
		0x0000, 0x0010, 0x0028, 0x0028, 0x0028, 0x0044, 0x0044, 0x00fe, 0x0082, 0x0082, 0x0101, 0x0000, 0x0000, 0x0000, 		//'A'
		0x0000, 0x007e, 0x0063, 0x0061, 0x0063, 0x007c, 0x0063, 0x0061, 0x0061, 0x0063, 0x007e, 0x0000, 0x0000, 0x0000, 		//'B'
		0x0000, 0x001f, 0x0030, 0x0060, 0x0040, 0x0040, 0x0040, 0x0040, 0x0060, 0x0030, 0x001f, 0x0000, 0x0000, 0x0000, 		//'C'
		0x0000, 0x00fc, 0x00c6, 0x00c3, 0x00c1, 0x00c1, 0x00c1, 0x00c1, 0x00c3, 0x00c6, 0x00fc, 0x0000, 0x0000, 0x0000, 		//'D'
		0x0000, 0x003f, 0x0030, 0x0030, 0x0030, 0x003f, 0x0030, 0x0030, 0x0030, 0x0030, 0x003f, 0x0000, 0x0000, 0x0000, 		//'E'
		0x0000, 0x003f, 0x0020, 0x0020, 0x0020, 0x0020, 0x003e, 0x0020, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 		//'F'
		0x0000, 0x003f, 0x0060, 0x00c0, 0x0080, 0x0080, 0x0087, 0x0081, 0x00c1, 0x0061, 0x003f, 0x0000, 0x0000, 0x0000, 		//'G'
		0x0000, 0x0083, 0x0083, 0x0083, 0x0083, 0x00ff, 0x0083, 0x0083, 0x0083, 0x0083, 0x0083, 0x0000, 0x0000, 0x0000, 		//'H'
		0x0000, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 		//'I'
		0x0000, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0002, 0x000e, 		//'J'
		0x0000, 0x00c2, 0x00c4, 0x00c8, 0x00d0, 0x00f0, 0x00d8, 0x00c8, 0x00c4, 0x00c6, 0x00c3, 0x0000, 0x0000, 0x0000, 		//'K'
		0x0000, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x003f, 0x0000, 0x0000, 0x0000, 		//'L'
		0x0000, 0x0603, 0x0505, 0x0507, 0x058f, 0x048b, 0x048b, 0x0453, 0x0453, 0x0473, 0x0423, 0x0000, 0x0000, 0x0000, 		//'M'
		0x0000, 0x0183, 0x01c3, 0x0143, 0x0123, 0x01b3, 0x019b, 0x018b, 0x0185, 0x0187, 0x0183, 0x0000, 0x0000, 0x0000, 		//'N'
		0x0000, 0x007c, 0x00c6, 0x0183, 0x0101, 0x0101, 0x0101, 0x0101, 0x0183, 0x00c6, 0x007c, 0x0000, 0x0000, 0x0000, 		//'O'
		0x0000, 0x003e, 0x0021, 0x0021, 0x0021, 0x0023, 0x003e, 0x0020, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 		//'P'
		0x0000, 0x007c, 0x00c6, 0x0183, 0x0101, 0x0101, 0x0101, 0x0101, 0x0183, 0x00c6, 0x007c, 0x000c, 0x0006, 0x0000, 		//'Q'
		0x0000, 0x007e, 0x0063, 0x0061, 0x0061, 0x0063, 0x007c, 0x0064, 0x0062, 0x0063, 0x0061, 0x0000, 0x0000, 0x0000, 		//'R'
		0x0000, 0x001f, 0x0020, 0x0020, 0x0020, 0x0018, 0x0007, 0x0001, 0x0001, 0x0001, 0x003e, 0x0000, 0x0000, 0x0000, 		//'S'
		0x0000, 0x00ff, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0000, 0x0000, 0x0000, 		//'T'
		0x0000, 0x0081, 0x0081, 0x0081, 0x0081, 0x0081, 0x0081, 0x0081, 0x00c3, 0x0042, 0x003c, 0x0000, 0x0000, 0x0000, 		//'U'
		0x0000, 0x0081, 0x0042, 0x0042, 0x0042, 0x0024, 0x0024, 0x0024, 0x0018, 0x0018, 0x0018, 0x0000, 0x0000, 0x0000, 		//'V'
		0x0000, 0x1843, 0x08e2, 0x08a2, 0x08a2, 0x0da6, 0x0514, 0x0514, 0x0514, 0x060c, 0x0208, 0x0000, 0x0000, 0x0000, 		//'W'
		0x0000, 0x0042, 0x0042, 0x0024, 0x0018, 0x0018, 0x0018, 0x0024, 0x0024, 0x0042, 0x00c3, 0x0000, 0x0000, 0x0000, 		//'X'
		0x0000, 0x00c3, 0x0042, 0x0066, 0x0024, 0x0038, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0000, 0x0000, 0x0000, 		//'Y'
		0x0000, 0x003f, 0x0001, 0x0002, 0x0006, 0x0004, 0x0008, 0x0018, 0x0010, 0x0020, 0x003f, 0x0000, 0x0000, 0x0000, 		//'Z'
		0x0000, 0x000f, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x000f, 0x0000, 		//'['
		0x0000, 0x0010, 0x0008, 0x0008, 0x000c, 0x0004, 0x0004, 0x0002, 0x0002, 0x0002, 0x0001, 0x0000, 0x0000, 0x0000, 		//'\'
		0x0000, 0x000f, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x000f, 0x0000, 		//']'
		0x0000, 0x0008, 0x000c, 0x0012, 0x0012, 0x0021, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'^'
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x003f, 0x0000, 		//'_'
		0x0000, 0x0002, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'`'
		0x0000, 0x0000, 0x0000, 0x001e, 0x0003, 0x0001, 0x001f, 0x0021, 0x0021, 0x0023, 0x003d, 0x0000, 0x0000, 0x0000, 		//'a'
		0x0040, 0x0040, 0x0040, 0x005e, 0x0063, 0x0061, 0x0041, 0x0041, 0x0061, 0x0063, 0x005e, 0x0000, 0x0000, 0x0000, 		//'b'
		0x0000, 0x0000, 0x0000, 0x000f, 0x0018, 0x0010, 0x0010, 0x0010, 0x0010, 0x0018, 0x000f, 0x0000, 0x0000, 0x0000, 		//'c'
		0x0001, 0x0001, 0x0001, 0x003d, 0x0063, 0x0043, 0x0041, 0x0041, 0x0043, 0x0063, 0x003d, 0x0000, 0x0000, 0x0000, 		//'d'
		0x0000, 0x0000, 0x0000, 0x001e, 0x0031, 0x0021, 0x003f, 0x0020, 0x0020, 0x0030, 0x001f, 0x0000, 0x0000, 0x0000, 		//'e'
		0x0007, 0x0004, 0x0004, 0x001f, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0000, 0x0000, 0x0000, 		//'f'
		0x0000, 0x0000, 0x0000, 0x003f, 0x0044, 0x0042, 0x0046, 0x003c, 0x0040, 0x003e, 0x0042, 0x0083, 0x00c2, 0x007c, 		//'g'
		0x0040, 0x0040, 0x0040, 0x005e, 0x0063, 0x0061, 0x0041, 0x0041, 0x0041, 0x0041, 0x0041, 0x0000, 0x0000, 0x0000, 		//'h'
		0x0003, 0x0003, 0x0000, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 		//'i'
		0x0003, 0x0003, 0x0000, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0002, 0x000e, 		//'j'
		0x0020, 0x0020, 0x0020, 0x0022, 0x0024, 0x002c, 0x0038, 0x003c, 0x0024, 0x0022, 0x0023, 0x0000, 0x0000, 0x0000, 		//'k'
		0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0000, 0x0000, 0x0000, 		//'l'
		0x0000, 0x0000, 0x0000, 0x05ce, 0x0633, 0x0421, 0x0421, 0x0421, 0x0421, 0x0421, 0x0421, 0x0000, 0x0000, 0x0000, 		//'m'
		0x0000, 0x0000, 0x0000, 0x005e, 0x0063, 0x0061, 0x0041, 0x0041, 0x0041, 0x0041, 0x0041, 0x0000, 0x0000, 0x0000, 		//'n'
		0x0000, 0x0000, 0x0000, 0x001e, 0x0033, 0x0021, 0x0021, 0x0021, 0x0021, 0x0033, 0x001e, 0x0000, 0x0000, 0x0000, 		//'o'
		0x0000, 0x0000, 0x0000, 0x005e, 0x0063, 0x0061, 0x0041, 0x0041, 0x0061, 0x0063, 0x005e, 0x0040, 0x0040, 0x0040, 		//'p'
		0x0000, 0x0000, 0x0000, 0x003d, 0x0063, 0x0043, 0x0041, 0x0041, 0x0043, 0x0063, 0x003d, 0x0001, 0x0001, 0x0001, 		//'q'
		0x0000, 0x0000, 0x0000, 0x0017, 0x0018, 0x0018, 0x0010, 0x0010, 0x0010, 0x0010, 0x0010, 0x0000, 0x0000, 0x0000, 		//'r'
		0x0000, 0x0000, 0x0000, 0x000f, 0x0010, 0x0010, 0x000c, 0x0003, 0x0001, 0x0001, 0x001e, 0x0000, 0x0000, 0x0000, 		//'s'
		0x0000, 0x0000, 0x0008, 0x001f, 0x0008, 0x0008, 0x0008, 0x0008, 0x0008, 0x000c, 0x0007, 0x0000, 0x0000, 0x0000, 		//'t'
		0x0000, 0x0000, 0x0000, 0x0041, 0x0041, 0x0041, 0x0041, 0x0041, 0x0043, 0x0063, 0x003d, 0x0000, 0x0000, 0x0000, 		//'u'
		0x0000, 0x0000, 0x0000, 0x0041, 0x0022, 0x0022, 0x0022, 0x0014, 0x0014, 0x0014, 0x0008, 0x0000, 0x0000, 0x0000, 		//'v'
		0x0000, 0x0000, 0x0000, 0x0421, 0x0252, 0x0252, 0x0252, 0x0252, 0x018c, 0x018c, 0x018c, 0x0000, 0x0000, 0x0000, 		//'w'
		0x0000, 0x0000, 0x0000, 0x0011, 0x001b, 0x000a, 0x0004, 0x000c, 0x000a, 0x0011, 0x0031, 0x0000, 0x0000, 0x0000, 		//'x'
		0x0000, 0x0000, 0x0000, 0x0041, 0x0022, 0x0022, 0x0032, 0x0014, 0x0014, 0x000c, 0x0008, 0x0008, 0x0010, 0x0070, 		//'y'
		0x0000, 0x0000, 0x0000, 0x001f, 0x0001, 0x0002, 0x0004, 0x0004, 0x0008, 0x0010, 0x001f, 0x0000, 0x0000, 0x0000, 		//'z'
		0x0000, 0x0003, 0x0004, 0x0004, 0x0004, 0x0004, 0x000c, 0x000c, 0x0004, 0x0004, 0x0004, 0x0004, 0x0003, 0x0000, 		//'{'
		0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 		//'|'
		0x0000, 0x000c, 0x0002, 0x0002, 0x0002, 0x0002, 0x0003, 0x0003, 0x0002, 0x0002, 0x0002, 0x0002, 0x000c, 0x0000, 		//'}'
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0038, 0x0007, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 		//'~'
};


#endif /*OPEN_SANS_H_*/