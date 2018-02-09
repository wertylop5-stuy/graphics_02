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
	struct pixel test[IMG_HEIGHT][IMG_WIDTH];
	memset(test, 0, sizeof(test));
	
	struct pixel hi;
	hi.r = 255;
	hi.g = 235;
	hi.b = 205;
	
	//(10, 100) (10, 10)
	//(0, 0) (10, 1)
	//(20, 10) (30, 150)
	//(20, 0) (30, 150)
	//(0, 0) (200, 150)
	int x1 = 0, y1 = 0, x2 = 600, y2 = 150;
	drawLine(test, x1, y1, x2, y2);
	
	writeToFile(test);
	
	return 0;
}
