#include <stdio.h>
#include "color.h"

void color_write(FILE *out, color pixel, int samples_per_pixel)
{
  double r = pixel.x;
  double g = pixel.y;
  double b = pixel.z;

  double scale = 1.0 / samples_per_pixel;
  r *= scale;
  g *= scale;
  b *= scale;

  fprintf(out, "%d %d %d\n", (int)(255 * r), (int)(255 * g), (int)(255 * b));
  return;
};

color color_create(double r, double g, double b)
{
  return (color){r, g, b};
};