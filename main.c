#include"include/draw.h"
#include"include/output.h"

int main() {
	struct pixel test[IMG_HEIGHT][IMG_WIDTH];
	memset(test, 0, sizeof(test));
	
	struct pixel hi;
	hi.r = 255;
	hi.g = 235;
	hi.b = 205;
	
	int x1 = 10, y1 = 50, x2 = 100, y2 = 10;
	drawLine(test, x1, y1, x2, y2);
	
	writeToFile(test);
	
	return 0;
}
