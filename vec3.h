#pragma once

#include <math.h>
#include <stdbool.h>

typedef struct vec3
{
	double x;
	double y;
	double z;
} vec3;

typedef vec3 point3;

vec3 vec3_create(double x, double y, double z);
double vec3_length(vec3 u);
vec3 vec3_inc(vec3 u);
vec3 vec3_add(vec3 u, double val);
vec3 vec3_subtr(vec3 u, double val);
vec3 vec3_mult(vec3 u, double val);
vec3 vec3_div(vec3 u, double val);
vec3 vec3_add_vec(vec3 u, vec3 v);
vec3 vec3_subtr_vec(vec3 u, vec3 v);
vec3 vec3_mult_vec(vec3 u, vec3 v);
double vec3_dot(vec3 u, vec3 v);
vec3 vec3_cross(vec3 u, vec3 v);
vec3 vec3_unit(vec3 u);
double vec3_length_squared(vec3 u);
vec3 vec3_reversed(vec3 u);
vec3 vec3_random();
vec3 vec3_random_in(double min, double max);
vec3 vec3_random_unit();
vec3 vec3_random_in_unit_sphere();
vec3 random_on_hemisphere(vec3 normal);
bool vec3_near_zero(vec3 u);
vec3 vec3_reflect(vec3 u, vec3 n);
