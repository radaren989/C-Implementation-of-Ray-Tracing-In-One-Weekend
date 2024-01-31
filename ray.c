#include "ray.h"

ray ray_create(point3 origin, point3 direction)
{
  ray r = {origin, direction};
  return r;
}

point3 ray_at(ray r, double t)
{
  // P(t) = origin + t*direction
  return vec3_add_vec(r.origin, vec3_mult(r.direction, t));
}