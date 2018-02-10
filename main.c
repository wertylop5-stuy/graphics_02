#include"include/draw.h"
#include"include/output.h"

//BUG: x bounds is messed up
/*
Observations:

sizeof a row is 600
sizeof struct pixel is 3
600/3 is 200 (aka the width)

[150][1663] is valid (null values)
[0][31663] is valid the bounds
[159][0] is invalid
[158][0] is valid
[158][63] is valid the bounds
*/

int main() {
	Frame test;
	memset(test, 0, sizeof(test));
	
	struct Pixel hi;
	pixelColor(&hi, 255, 235, 205);
	
	//(10, 100) (10, 10)
	//(0, 0) (10, 1)
	//(20, 10) (30, 150)
	//(20, 0) (30, 150)
	//(0, 0) (200, 150)
	/*
	int x1 = 0, y1 = IMG_HEIGHT-1, x2 = 5, y2 = 0;
	drawLine(test, x1, y1, x2, y2);
	*/
	
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
