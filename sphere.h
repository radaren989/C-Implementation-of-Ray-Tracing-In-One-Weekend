#pragma once
#include <stdint.h>
#include "vec3.h"

typedef struct
{
  uint8_t type; // to determine in the hittable list
  point3 center;
  double radius;
} sphere;