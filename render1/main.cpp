#include <iostream>
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void swap(float& x0, float& y0, float& x1, float& y1) {
	float temp = x0;
	x0 = x1;
	x1 = temp;
	temp = y0;
	y0 = y1;
	y1 = temp;
}

void line(float x0, float y0, float x1, float y1, TGAImage& image, TGAColor color) {
	float y;
	if (x0 > x1) {
		swap(x0, y0, x1, y1);
	}
	for (float x = x0; x < x1; x++) {
		y = (y1 - y0) / (x1 - x0) * x*1.0 + (y1 - (y1 - y0) / (x1 - x0) * x1*1.0);
		image.set(x, y, color);
		std::cout << "x:" << x << " y:" << y << std::endl;
	}
}

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	line(13, 20, 80, 40, image, white); 
	line(20, 13, 40, 80, image, red); 
	line(80, 40, 13, 20, image, red);
	image.flip_vertically(); 
	image.write_tga_file("D:\\VS2022Files\\TinyRender\\output.tga");
	return 0;
}

