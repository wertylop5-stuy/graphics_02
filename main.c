#include"include/draw.h"
#include"include/output.h"

int main() {
	struct pixel test[IMG_HEIGHT][IMG_WIDTH];
	memset(test, 0, sizeof(test));
	
	struct pixel hi;
	hi.r = 255;
	hi.g = 235;
	hi.b = 205;
	
	/*
	int x, y;
	for (y = 250; y < 300; y++) {
	for (x = 350; x < 400; x++) {
		plotPoint(test, x, y, &hi);
	}
	}
	*/
	
	int x1 = 0, y1 = 0, x2 = 100, y2 = 50;
	drawLine(test, x1, y1, x2, y2);
	
	writeToFile(test);
	
	return 0;
}
