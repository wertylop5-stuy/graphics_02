#include"include/draw.h"
#include"include/output.h"

#include<math.h>

#define SQUARE(x)	(x*x)

#define NARROW_FACTOR	10.0f

#define FUNC(x)		( SQUARE( (x - (IMG_WIDTH/2.0f))/NARROW_FACTOR ) + (IMG_HEIGHT/2.0f) )
#define INV(y)		( NARROW_FACTOR * sqrt(y + (IMG_HEIGHT/2.0f)) + (IMG_WIDTH/2.0f) )
#define DERIV(x)	( (2.0f / SQUARE(NARROW_FACTOR)) * (x - (IMG_WIDTH/2.0f)) )

char inBounds(float n, int max) {
	return n >= 0 && n < max;
}

//gets the endpoint from a given point and slope
//delta of +1 = endpoint to the right, -1 for the left
//out[0] = x, out[1] = y
/*
void findEndpoint(int *out, int x, int y, float m, int delta) {
	float x1 = (float)x;
	
	while ( inBounds(m*(x1-x) + y, IMG_HEIGHT) ) x1+=delta;
	
	out[0] = x1-delta;
	out[1] = (int)roundf(m*(x1-delta-x) + y);
}
*/

//faster way: find intersection with bounding lines
void findEndpoint(int *left, int *right, int x, int y, float m) {
	float x1, y1;
	float boundX, boundY;
	float boundX2, boundY2;
	if (m >= 0) {	//top and right
		boundY = IMG_HEIGHT-1;
		boundX = IMG_WIDTH-1;
		
		boundY2 = boundX2 = 0;
	}
	else {		//bottom and right
		boundY = 0;
		boundX = IMG_WIDTH-1;
		
		boundY2 = IMG_HEIGHT-1;
		boundX2 = 0;
	}
	
	//printf("getting right bound\n");
	if (isinf(m)) {
		right[0] = x;
		right[1] = boundY;
	}
	else {
		//test if hits a horizontal wall
		x1 = ((boundY-y)/m) + x;
		if (inBounds(x1, IMG_WIDTH)) {
			//printf("x1: %f\n", x1);
			right[0] = (int)trunc(x1);
			right[1] = boundY;
		}
		
		//test if hits a vertical wall
		y1 = m*(boundX-x)+y;
		if (inBounds(y1, IMG_HEIGHT)) {
			//printf("y1: %f\n", y1);
			right[0] = boundX;
			right[1] = (int)trunc(y1);
		}
	}
	
	//now for the left
	//printf("getting left bound\n");
	if (isinf(m)) {
		left[0] = x;
		left[1] = boundY2;
	}
	else {
		//test if hits a horizontal wall
		x1 = ((boundY2-y)/m) + x;
		if (inBounds(x1, IMG_WIDTH)) {
			//printf("x1: %f\n", x1);
			left[0] = (int)trunc(x1);
			left[1] = boundY2;
		}
		
		//test if hits a vertical wall
		y1 = m*(boundX2-x)+y;
		if (inBounds(y1, IMG_HEIGHT)) {
			//printf("y1: %f\n", y1);
			left[0] = boundX2;
			left[1] = (int)trunc(y1);
		}
	}
}

int main() {
	Frame test;
	memset(test, 0, sizeof(test));
	
	struct Pixel p;
	pixelColor(&p, 0, 255, 0);
	
	drawLine(test, &p, IMG_WIDTH/2, 0, IMG_WIDTH/2, IMG_HEIGHT-1);
	drawLine(test, &p, 0, IMG_HEIGHT/2, IMG_WIDTH-1, IMG_HEIGHT/2);
	
	pixelColor(&p, 255, 235, 205);
	
	//drawing a parabola with lines
	int left[2], right[2];
	
	//find the start point
	int range = (int)INV(IMG_HEIGHT-1);
	int x, y;
	for (x = range; x >= -range; x-=5) {
		y = (int)FUNC(x);
		findEndpoint(left, right, x, y, DERIV(x));
		//printf("%d, %d\n", left[0], left[1]);
		//printf("%d, %d\n", right[0], right[1]);
		
		drawLine(test, &p, x, y, right[0], right[1]);
		drawLine(test, &p, x, y, left[0], left[1]);
	}
	writeToFile(test);
	
	return 0;
}
