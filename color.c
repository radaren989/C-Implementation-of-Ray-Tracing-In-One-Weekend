#include "color.h"
#include "utils.h"

double linear_to_gamma(double linear_component)
{
  return sqrt(linear_component);
}

void color_write(FILE *out, color pixel, int samples_per_pixel)
{
  double r = pixel.x;
  double g = pixel.y;
  double b = pixel.z;

  double scale = 1.0 / samples_per_pixel;
  r *= scale;
  g *= scale;
  b *= scale;

  r = linear_to_gamma(r);
  g = linear_to_gamma(g);
  b = linear_to_gamma(b);

  r = clamp(r, 0.0, 1.0) * 255;
  g = clamp(g, 0.0, 1.0) * 255;
  b = clamp(b, 0.0, 1.0) * 255;

  fprintf(out, "%d %d %d\n", (int)r, (int)g, (int) b);
  return;
};

color color_create(double r, double g, double b)
{
  return (color){r, g, b};
};
