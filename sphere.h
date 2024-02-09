#pragma once

#include <stdint.h>
#include "vec3.h"
#include "material.h"

typedef struct sphere
{
  uint8_t type; // to determine in the hittable list
  point3 center;
  double radius;
  material *mat;
} sphere;

#include "hit.h"
