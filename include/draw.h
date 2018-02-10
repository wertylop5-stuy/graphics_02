#ifndef DRAW_H
#define DRAW_H

#include<stdio.h>

#include"dimen.h"

struct Pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

typedef struct Pixel Frame[IMG_HEIGHT][IMG_WIDTH];

//writes a pixel value to a spot on the grid
//(0, 0) is the bottom left of the grid
void plotPoint(Frame grid, int x, int y, struct Pixel *p);

void drawLine(Frame grid, int x1, int y1, int x2, int y2);

#endif
