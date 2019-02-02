#include "fdf_header.h"
#include <printf.h>

#define IMAGE_WIDTH 1000
#define IMAGE_HEIGHT 1000
#define SIZE_LEN 1000


void    put_point_to_image(char *image_data, int x, int y, int color)
{
    int index;
    
    index = SIZE_LEN * y * 4 + x * 4;
	image_data[index + 2] = color >> 16; // RED COLOR COMPONENT
	image_data[index + 1] = (color & 0x00ff00) >> 8; // GREEN COLOR COMPONENT
}