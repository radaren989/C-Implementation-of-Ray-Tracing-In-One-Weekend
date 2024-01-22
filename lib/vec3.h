#pragma once

typedef struct
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
