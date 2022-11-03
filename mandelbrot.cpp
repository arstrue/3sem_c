#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"
using namespace std;

struct Color {
	unsigned char r, g, b;
};

Complex func(Complex z, Complex c) {
	return z * z + c;
}


int main() {
	int width = 800, height = 800;
	float x0 = -2.0f, x1 = 2.0f;
	float y0 = -2.0f, y1 = 2.0f;

	Color* data = (Color*)malloc(sizeof(Color) * width * height);

	Complex c = { 0, 0 };
	int n = 100;

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Complex c = { x0 + (x1 - x0) / width * i, y0 + (y1 - y0) / width * j }, z = { 0, 0 };
			for(int k = 0; k < n; k++)
				z = func(z, c);
			if (z.re > 255)
				z.re = 255;
			if (z.im > 255)
				z.im = 255;

			data[i + width * j].r = 0;
			data[i + width * j].g = 255 - abs(z.re);
			data[i + width * j].b = 255 - abs(z.im);
		}
	}

	FILE* file = fopen("mandelbrot.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);

	free(data);
}