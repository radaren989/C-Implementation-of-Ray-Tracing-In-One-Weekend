#pragma once
#include <stdint.h>

// common headers
#include "vec3.h"
#include "ray.h"
#include "list.h"
#include "math.h"

#define PI 3.1415926535897932385
#define SPHERE_TYPE 0
#define FOO_TYPE 1

double degrees_to_radians(double degrees);
uint8_t determine_object(void *object);
