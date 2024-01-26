#pragma once

#include "sphere.h"
#include <stdbool.h>
#include "utils.h"
#include "material.h"

typedef struct hit_record
{
  point3 p;
  vec3 normal;
  double t;
  struct material *mat;
  bool front_face;
} hit_record;

bool is_hit(void *obj, ray r, double ray_tmin, double ray_tmax, struct material *mat, hit_record *rec);
bool hit_sphere(ray r, sphere sph, double ray_tmin, double ray_tmax, struct material *mat, hit_record *rec);
void hit_set_face_normal(ray r, vec3 outward_normal, hit_record *rec);

void printSphere(sphere sph);
