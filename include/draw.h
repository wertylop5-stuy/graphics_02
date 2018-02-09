#ifndef DRAW_H
#define DRAW_H

struct pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#include"output.h"

//writes a pixel value to a spot on the grid
void plotPoint(struct pixel grid[][IMG_WIDTH], int x, int y, struct pixel *p);

void drawLine(struct pixel grid[][IMG_WIDTH], int x1, int y1, int x2, int y2);

#endif
