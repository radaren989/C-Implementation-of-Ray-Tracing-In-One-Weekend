#pragma once
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// common headers
#include "vec3.h"
#include "list.h"
#include "ray.h"

#define PI 3.1415926535897932385
#define SPHERE_TYPE 0
#define FOO_TYPE 1

double degrees_to_radians(double degrees);
uint8_t determine_object(void *object);
double random_double();
double random_double_in(double min, double max);
double clamp(double x, double min, double max);
