#include"include/draw.h"

void plotPoint(struct pixel grid[][IMG_WIDTH], int x, int y, struct pixel *p) {
	grid[IMG_HEIGHT-y][x] = *p;
}

void drawLine(struct pixel grid[][IMG_WIDTH], int x1, int y1, int x2, int y2) {
	//make sure x1 y1 is the left point
	
	if (x1 > x2) {
		int temp = x1;
		x1 = x2;
		x2 = temp;
		
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	
	struct pixel point;
	point.r = 255;
	point.g = 235;
	point.b = 205;
	
	//octant 1
	int a = y2-y1;	//???
	int b = -(x2-x1);
	int d;
	
	d = 2*a + b;
	
	while (x1 < x2) {
		plotPoint(grid, x1, y1, &point);
		printf("%d\n", d);
		if (d > 0) {
			y1++;
			d += 2*b;
		}
		
		x1++;
		d += 2*a;
	}
}

