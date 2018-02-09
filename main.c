#include"include/draw.h"
#include"include/output.h"

int main() {
	struct pixel test[IMG_HEIGHT][IMG_WIDTH];
	memset(test, 0, sizeof(test));
	
	struct pixel hi;
	hi.r = 255;
	hi.g = 235;
	hi.b = 205;
	
	//(10, 100) (100, 10)
	//(0, 0) (10, 1)
	int x1 = 0, y1 = 0, x2 = 10, y2 = 1;
	drawLine(test, x1, y1, x2, y2);
	
	writeToFile(test);
	
	return 0;
}
