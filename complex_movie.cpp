#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"
using namespace std;

// Это программа создаёт анимацию (набор картинок)
// которая задаётся как меняющееся во времени
// комплексная функция (описана в функции func)


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

	// Повторяем 200 раз
	int max_time_steps = 200;
	Complex c = { -1.5, -0.5 };
	float dx = (0 - c.re) / max_time_steps;
	float dy = (1.0 - c.im) / max_time_steps;
	const int n = 20;

	for (int time = 0; time < max_time_steps; time++)
	{
		// Задаём изображение в массиве data
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				Complex z = { x0 + (x1 - x0) / width * i, y0 + (y1 - y0) / width * j };
				for (int k = 0; k < n; k++)
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

		c.re += dx;
		c.im += dy;

		// Создаём в строке filename имя изображения
		// Папка animation должна существовать!
		char filename[100];
		sprintf(filename, "C:/Users/ars/Desktop/code/animation/complex_%03d.ppm", time);

		// Сохраняем изображение в картинке по имени filename
		FILE* file = fopen(filename, "wb");
		fprintf(file, "P6\n%d %d\n255\n", width, height);
		fwrite(data, sizeof(Color), height * width, file);
		fclose(file);
	}
	free(data);
}