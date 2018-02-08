#include"include/output.h"

void writeToFile(struct pixel p[][IMG_WIDTH]) {
	int fd = open(FILE_NAME, O_CREAT | O_WRONLY, 0644);
	char buf[1024];
	
	sprintf(buf, "P3\n%d %d\n%d\n", IMG_WIDTH, IMG_HEIGHT, MAX_COLOR);
	write(fd, buf, strlen(buf));
	
	int x, y;
	for (y = 0; y < IMG_HEIGHT; y++) {
	for (x = 0; x < IMG_WIDTH; x++) {
		sprintf(buf, "%d %d %d ", p[y][x].r, p[y][x].g, p[y][x].b);
		write(fd, buf, strlen(buf));
	}
		sprintf(buf, "\n");
		write(fd, buf, strlen(buf));
	}
}

