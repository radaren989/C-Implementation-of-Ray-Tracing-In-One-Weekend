#pragma once
#include "vec3.h"

typedef vec3 color;

color color_create(double r, double g, double b);
void color_write(FILE *out, color pixel, int samples_per_pixel);