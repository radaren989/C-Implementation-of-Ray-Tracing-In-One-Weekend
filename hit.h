#pragma once

#include "utils.h"
#include "sphere.h"
#include <stdbool.h>

typedef struct
{
  point3 p;
  vec3 normal;
  double t;
  bool front_face;
} hit_record;

bool is_hit(void *obj, ray r, double ray_tmin, double ray_tmax, hit_record *rec);
bool hit_sphere(ray r, sphere sphere, double ray_tmin, double ray_tmax, hit_record *rec);
void hit_set_face_normal(ray r, vec3 outward_normal, hit_record *rec);

void printSphere(sphere sp);