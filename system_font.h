/*
 * system_font.h
 *
 * Created: 25-10-2013 21:06:14
 *  Author: Aran Dokoupil
 */ 


#ifndef SYSTEM_FONT_H_
#define SYSTEM_FONT_H_


//system font is Arial size 8


/* the actual system font, sorted in ASCII, the comment near every sub-array specifies the character*/
const uint16_t systemFont[][11] =	
									{	{	0b0000000000000000,		//' '
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											3			},

										{	0b0000000000000001,		//!
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											2			},

										{	0b0000000000000101,		//"
											0b0000000000000101,
											0b0000000000000101,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											4			},

										{	0b0000000000000101,		//#
											0b0000000000000101,
											0b0000000000011111,
											0b0000000000001010,
											0b0000000000001010,
											0b0000000000011111,
											0b0000000000010100,
											0b0000000000010100,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000001110,		//$
											0b0000000000010101,
											0b0000000000010100,
											0b0000000000001110,
											0b0000000000000101,
											0b0000000000000101,
											0b0000000000010101,
											0b0000000000001110,
											0b0000000000000100,
											0b0000000000000000,
											6			},

										{	0b0000000011000100,		//%
											0b0000000100101000,
											0b0000000100101000,
											0b0000000011010000,
											0b0000000000010110,
											0b0000000000101001,
											0b0000000000101001,
											0b0000000001000110,
											0b0000000000000000,
											0b0000000000000000,
											10			},

										{	0b0000000000001100,		//&
											0b0000000000010010,
											0b0000000000010010,
											0b0000000000001100,
											0b0000000000010100,
											0b0000000000100011,
											0b0000000000100010,
											0b0000000000011101,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000000001,		//'
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											2			},

										{	0b0000000000000001,		//(
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000010,
											0b0000000000000001,
											4			},

										{	0b0000000000000100,		//)
											0b0000000000000010,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000100,
											4			},

										{	0b000000000000010,		//*
											0b000000000000111,
											0b000000000000010,
											0b000000000000101,
											0b000000000000000,
											0b000000000000000,
											0b000000000000000,
											0b000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											4			},

										{	0b0000000000000000,		//+
											0b0000000000000000,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000011111,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000000,		//,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											2			},

										{	0b0000000000000000,		//-
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000111,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											4			},

										{	0b0000000000000000,		//.
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											2			},

										{	0b0000000000000001,		///
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000000,
											4			},

										{	0b0000000000001110,		//0
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000001,		//1
											0b0000000000000011,
											0b0000000000000101,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											4			},

										{	0b0000000000001110,		//2
											0b0000000000010001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000001000,
											0b0000000000011111,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000001110,		//3
											0b0000000000010001,
											0b0000000000000001,
											0b0000000000000110,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000010,		//4
											0b0000000000000110,
											0b0000000000001010,
											0b0000000000001010,
											0b0000000000010010,
											0b0000000000011111,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000001111,		//5
											0b0000000000001000,
											0b0000000000010000,
											0b0000000000011110,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000001110,		//6
											0b0000000000010001,
											0b0000000000010000,
											0b0000000000011110,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000011111,		//7
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000001110,		//8
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000001110,		//9
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001111,
											0b0000000000000001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000000,		//:
											0b0000000000000000,
											0b0000000000000010,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000010,
											0b0000000000000000,
											0b0000000000000000,
											3			},

										{	0b0000000000000000,		//;
											0b0000000000000000,
											0b0000000000000010,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											3			},

										{	0b0000000000000000,		//<
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000001000,
											0b0000000000010000,
											0b0000000000001000,
											0b0000000000000100,
											0b0000000000000010,
											0b0000000000000001,
											6			},

										{	0b0000000000000000,		//=
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000011111,
											0b0000000000000000,
											0b0000000000011111,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000000,		//>
											0b0000000000010000,
											0b0000000000001000,
											0b0000000000000100,
											0b0000000000000010,
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000001000,
											0b0000000000010000,
											6			},

										{	0b0000000000001110,		//?
											0b0000000000010001,
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000001111100,		//@
											0b0000000010000010,
											0b0000000100110101,
											0b0000001001001101,
											0b0000001010001001,
											0b0000001010001001,
											0b0000001010011010,
											0b0000000101101100,
											0b0000000100000001,
											0b0000000011111110,
											11			},

										{	0b0000000000001000,		//A
											0b0000000000010100,
											0b0000000000010100,
											0b0000000000010100,
											0b0000000000100010,
											0b0000000000111110,
											0b0000000001000001,
											0b0000000001000001,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000000000111110,		//B
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000111111,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000111110,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000001110,		//C
											0b0000000000010001,
											0b0000000000100000,
											0b0000000000100000,
											0b0000000000100000,
											0b0000000000100000,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000111100,		//D
											0b0000000000100010,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100010,
											0b0000000000111100,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000011111,		//E
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000011111,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000011111,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000011111,		//F
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000011110,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000011100,		//G
											0b0000000000100010,
											0b0000000001000001,
											0b0000000001000000,
											0b0000000001000111,
											0b0000000001000001,
											0b0000000000100010,
											0b0000000000011100,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000000000100001,		//H
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000111111,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000000001,		//I
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											2			},

										{	0b0000000000000001,		//J
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000001001,
											0b0000000000001001,
											0b0000000000000110,
											0b0000000000000000,
											0b0000000000000000,
											5			},

										{	0b0000000000100001,		//K
											0b0000000000100010,
											0b0000000000100100,
											0b0000000000101100,
											0b0000000000110100,
											0b0000000000100010,
											0b0000000000100010,
											0b0000000000100001,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000010000,		//L
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000011111,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000001000001,		//M
											0b0000000001100011,
											0b0000000001100011,
											0b0000000001010101,
											0b0000000001010101,
											0b0000000001010101,
											0b0000000001001001,
											0b0000000001001001,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000000000100001,		//N
											0b0000000000110001,
											0b0000000000101001,
											0b0000000000101001,
											0b0000000000100101,
											0b0000000000100101,
											0b0000000000100011,
											0b00000000001000001,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000011100,		//O
											0b0000000000100010,
											0b0000000001000001,
											0b0000000001000001,
											0b0000000001000001,
											0b0000000001000001,
											0b0000000000100010,
											0b0000000000011100,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000000000011110,		//P
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000011110,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000011100,		//Q
											0b0000000000100010,
											0b0000000001000001,
											0b0000000001000001,
											0b0000000001000001,
											0b0000000001001101,
											0b0000000000100010,
											0b0000000000011101,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000000000111110,		//R
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000111110,
											0b0000000000100100,
											0b0000000000100010,
											0b0000000000100010,
											0b0000000000100001,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000011110,		//S
											0b0000000000100001,
											0b0000000000100000,
											0b0000000000011000,
											0b0000000000000110,
											0b0000000000000001,
											0b0000000000100001,
											0b0000000000011110,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000011111,		//T
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000100001,		//U
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000100001,
											0b0000000000011110,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000001000001,		//V
											0b0000000001000001,
											0b0000000000100010,
											0b0000000000100010,
											0b0000000000010100,
											0b0000000000010100,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000010000100001,		//W
											0b0000010001010001,
											0b0000001001010010,
											0b0000001001010010,
											0b0000001010001010,
											0b0000001010001010,
											0b0000000100000100,
											0b0000000100000100,
											0b0000000000000000,
											0b0000000000000000,
											12			},

										{	0b0000000000100001,		//X
											0b0000000000010010,
											0b0000000000010010,
											0b0000000000001100,
											0b0000000000001100,
											0b0000000000010010,
											0b0000000000010010,
											0b0000000000100001,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000001000001,		//Y
											0b0000000000100010,
											0b0000000000100010,
											0b0000000000010100,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000000000,
											0b0000000000000000,
											8			},

										{	0b0000000000011111,		//Z
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000001000,
											0b0000000000001000,
											0b0000000000010000,
											0b0000000000111111,
											0b0000000000000000,
											0b0000000000000000,
											7			},

										{	0b0000000000000011,		//[
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000011,
											3			},

										{	0b0000000000000100,		// '\' 
											0b0000000000000100,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											4			},

										{	0b0000000000000011,		//]
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000011,
											3			},

										{	0b0000000000000100,		//^
											0b0000000000001010,
											0b0000000000001010,
											0b0000000000010001,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000000,		//_
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000111111,
											7			},

										{	0b0000000000000010,		//`
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											3			},
											
										{	0b0000000000000000,		//a
											0b0000000000000000,
											0b0000000000001110,
											0b0000000000010001,
											0b0000000000001111,
											0b0000000000010001,
											0b0000000000010011,
											0b0000000000001101,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000010000,		//b
											0b0000000000010000,
											0b0000000000010110,
											0b0000000000011001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000011001,
											0b0000000000010110,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//c
											0b0000000000000000,
											0b0000000000001110,
											0b0000000000010001,
											0b0000000000010000,
											0b0000000000010000,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000001,		//d
											0b0000000000000001,
											0b0000000000001101,
											0b0000000000010011,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010011,
											0b0000000000001101,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//e
											0b0000000000000000,
											0b0000000000001110,
											0b0000000000010001,
											0b0000000000011111,
											0b0000000000010000,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000001,		//f
											0b0000000000000010,
											0b0000000000000111,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000000,
											0b0000000000000000,
											4			},
										{	0b0000000000000000,		//g
											0b0000000000000000,
											0b0000000000001101,
											0b0000000000010011,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010011,
											0b0000000000001101,
											0b0000000000000001,
											0b0000000000011110,
											6			},
										{	0b0000000000010000,		//h
											0b0000000000010000,
											0b0000000000010110,
											0b0000000000011001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000001,		//i
											0b0000000000000000,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											2			},
										{	0b0000000000000001,		//j
											0b0000000000000000,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000010,
											2			},
										{	0b0000000000001000,		//k
											0b0000000000001000,
											0b0000000000001001,
											0b0000000000001010,
											0b0000000000001100,
											0b0000000000001010,
											0b0000000000001010,
											0b0000000000001001,
											0b0000000000000000,
											0b0000000000000000,
											5			},
										{	0b0000000000000001,		//l
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000000,
											0b0000000000000000,
											2			},
										{	0b0000000000000000,		//m	
											0b0000000000000000,
											0b0000000001011110,
											0b0000000001101001,
											0b0000000001001001,
											0b0000000001001001,
											0b0000000001001001,
											0b0000000001001001,
											0b0000000000000000,
											0b0000000000000000,
											8			},
										{	0b0000000000000000,		//n
											0b0000000000000000,
											0b0000000000011110,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//o
											0b0000000000000000,
											0b0000000000001110,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//p
											0b0000000000000000,
											0b0000000000010110,
											0b0000000000011001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000011001,
											0b0000000000010110,
											0b0000000000010000,
											0b0000000000010000,
											6			},
										{	0b0000000000000000,		//q
											0b0000000000000000,
											0b0000000000001101,
											0b0000000000010011,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010011,
											0b0000000000001101,
											0b0000000000000001,
											0b0000000000000001,
											6			},
										{	0b0000000000000000,		//r
											0b0000000000000000,
											0b0000000000000101,
											0b0000000000000110,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000000,
											4			},
										{	0b0000000000000000,		//s
											0b0000000000000000,
											0b0000000000001110,
											0b0000000000010001,
											0b0000000000001100,
											0b0000000000000010,
											0b0000000000010001,
											0b0000000000001110,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000010,		//t
											0b0000000000000010,
											0b0000000000000111,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000000,
											0b0000000000000000,
											3			},
										{	0b0000000000000000,		//u
											0b0000000000000000,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000010011,
											0b0000000000001101,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//v
											0b0000000000000000,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001010,
											0b0000000000001010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//w hierdoor zijn het 16 bits per rij, oplossing?
											0b0000000000000000,
											0b0000000100010001,
											0b0000000100101001,
											0b0000000010101010,
											0b0000000010101010,
											0b0000000001000100,
											0b0000000001000100,
											0b0000000000000000,
											0b0000000000000000,
											10			},
										{	0b0000000000000000,
											0b0000000000000000,		//x
											0b0000000000010001,
											0b0000000000001010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000001010,
											0b0000000000010001,
											0b0000000000000000,
											0b0000000000000000,
											6			},
										{	0b0000000000000000,		//y
											0b0000000000000000,
											0b0000000000010001,
											0b0000000000010001,
											0b0000000000001010,
											0b0000000000001010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000001000,
											6			},
										{	0b0000000000000000,		//z
											0b0000000000000000,
											0b0000000000011111,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000100,
											0b0000000000001000,
											0b0000000000011111,
											0b0000000000000000,
											0b0000000000000000,
											6			},

										{	0b0000000000000001,		//{
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000100,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000001,
											4			},

										{	0b0000000000000001,		//|
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											0b0000000000000001,
											2			},

										{	0b0000000000000100,		//}
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000001,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000010,
											0b0000000000000100,
											4			},
											

										{	0b0000000000000000,		//
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000011101,
											0b0000000000010110,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											0b0000000000000000,
											6			},
											
										{	0b0000000000111110,		//unknown character character
											0b0000000001100011,
											0b0000000001011101,
											0b0000000001111101,
											0b0000000001111011,
											0b0000000001110111,
											0b0000000001110111,
											0b0000000001111111,
											0b0000000001110111,
											0b0000000000111110,
											8			}};




#endif /* SYSTEM_FONT_H_ */