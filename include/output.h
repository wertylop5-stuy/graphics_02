#ifndef OUTPUT_H
#define OUTPUT_H

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include"draw.h"

#define FILE_NAME	"picture.ppm"
#define FILE_WIDTH	500
#define FILE_HEIGHT	500

void writeToFile(struct pixel **p);

#endif
