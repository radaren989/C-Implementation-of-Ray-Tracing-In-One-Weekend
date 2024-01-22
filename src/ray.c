#include "ray.h"

point3 ray_at(ray r, double t)
{
  // P(t) = origin + t*direction
  return vec3_add_vec(r.origin, vec3_mult(r.direction, t));
}