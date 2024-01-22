#pragma once
#include "vec3.h"

typedef struct
{
  point3 origin;
  point3 direction;
} ray;

point3 ray_at(ray r, double t);