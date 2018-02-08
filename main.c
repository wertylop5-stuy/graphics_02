#include"include/draw.h"
#include"include/output.h"

int main() {
	struct pixel test[IMG_HEIGHT][IMG_WIDTH];
	memset(test, 0, sizeof(test));
	
	writeToFile(test);
	
	return 0;
}
