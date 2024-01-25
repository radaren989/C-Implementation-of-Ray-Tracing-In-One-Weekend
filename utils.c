#include "utils.h"

double degrees_to_radians(double degrees)
{
  return degrees * PI / 180;
}

uint8_t determine_object(void *object)
{
  return *(uint8_t *)object;
}

double random_double()
{
  static int random_called = 0;

  if (!random_called)
  {
    srand((unsigned int)time(NULL));
    random_called = 1;
  }

  return rand() / (RAND_MAX + 1.0);
}

double random_double_in(double min, double max)
{
  return min + (max - min) * random_double();
}

double clamp(double x, double min, double max)
{
  if (x < min)
    return min;
  if (x > max)
    return max;
  return x;
}