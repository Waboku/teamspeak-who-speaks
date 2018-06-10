/*
 * tetris.h
 *
 * Created: 7-12-2017 20:31:20
 *  Author: P
 */ 


#ifndef TETRIS_H_
#define TETRIS_H_

#include "bitmaps/blocks.h"



typedef enum{
	LBLOCK, RLBLOCK, SBLOCK, RSBLOCK, SQUARE, LINE, TBLOCK, EMPTY, EMPTY_LIT
}block_sprite_t;


const bitmap_t *const sprite_lut[] = {&block1, &block2, &block3, &block4, &block5, &block6, &block7, NULL, NULL};





#endif /* TETRIS_H_ */