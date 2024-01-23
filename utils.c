#include "utils.h"

double degrees_to_radians(double degrees)
{
  return degrees * PI / 180;
}

uint8_t determine_object(void *object)
{
  return *(uint8_t *)object;
}