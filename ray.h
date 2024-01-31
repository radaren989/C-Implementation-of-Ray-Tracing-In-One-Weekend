#pragma once
#include "vec3.h"

typedef struct ray
{
  point3 origin;
  point3 direction;
} ray;

ray ray_create(point3 origin, point3 direction);
point3 ray_at(ray r, double t);