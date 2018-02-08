#ifndef OUTPUT_H
#define OUTPUT_H

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#include"draw.h"

#define FILE_NAME	"picture.ppm"
#define IMG_WIDTH	10//700
#define IMG_HEIGHT	5//500
#define MAX_COLOR	255

//p must be the same dimension as the desired image
void writeToFile(struct pixel p[][IMG_WIDTH]);

#endif
