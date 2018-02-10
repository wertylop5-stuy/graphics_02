#include"include/draw.h"
#include"include/output.h"

int main() {
	Frame test;
	memset(test, 0, sizeof(test));
	
	struct Pixel hi;
	pixelColor(&hi, 255, 235, 205);
	
	drawLine(test, 0, 0, 0, 100);
	drawLine(test, 6, 100, 6, 0);
	drawLine(test, 0, 100, 30, 100);
	drawLine(test, 40, 50, 10, 50);
	drawLine(test, 80, 80, 90, 90);
	drawLine(test, 67, 67, 45, 45);
	drawLine(test, 10, 5, 90, 9);
	drawLine(test, 10, 5, 90, IMG_HEIGHT-1);
	drawLine(test, 57, 20, 34, IMG_HEIGHT-3);
	drawLine(test, 123, 34, 34, 123);
	drawLine(test, 138, 45, 187, 21);
	
	writeToFile(test);
	
	return 0;
}
