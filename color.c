#include <stdio.h>
#include "color.h"

void color_write(FILE *out, color pixel)
{
  fprintf(out, "%d %d %d\n", (int)(255 * pixel.x), (int)(255 * pixel.y), (int)(255 * pixel.z));
  return;
};

color color_create(double r, double g, double b)
{
  return (color){r, g, b};
};