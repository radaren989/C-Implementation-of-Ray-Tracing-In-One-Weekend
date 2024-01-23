#include <math.h>
#include "hit.h"

#include <stdio.h>

bool is_hit(void *obj, ray r, double ray_tmin, double ray_tmax, hit_record *rec)
{
  switch (determine_object(obj))
  {
  case SPHERE_TYPE:

    sphere sph = *(sphere *)obj;
    return hit_sphere(r, sph, ray_tmin, ray_tmax, rec);
    break;
  default:
    return false;
    break;
  }
}

bool hit_sphere(ray r, sphere sph, double ray_tmin, double ray_tmax, hit_record *rec)
{
  vec3 oc = vec3_subtr_vec(r.origin, sph.center);
  double a = vec3_length_squared(r.direction);
  double half_b = vec3_dot(r.direction, oc);
  double c = vec3_length_squared(oc) - sph.radius * sph.radius;

  double discriminant = half_b * half_b - a * c;
  if (discriminant < 0.0)
    return false;

  double sqrtd = sqrt(discriminant);
  double root = (-half_b - sqrtd) / a;
  if (ray_tmin >= root || ray_tmax <= root)
  {
    root = (-half_b + sqrtd) / a;
    if (ray_tmin >= root || ray_tmax <= root)
      return false;
  }

  rec->t = root;
  rec->p = ray_at(r, root);
  vec3 outward_normal = vec3_div(vec3_subtr_vec(rec->p, sph.center), sph.radius);
  hit_set_face_normal(r, outward_normal, rec);

  return true;
}

void hit_set_face_normal(ray r, vec3 outward_normal, hit_record *rec)
{
  rec->front_face = vec3_dot(r.direction, outward_normal) < 0;
  rec->normal = rec->front_face ? outward_normal : vec3_reversed(outward_normal);
}

void printSphere(sphere sp)
{
  printf("type: %d\n  x: %f\n  y: %f\n  z: %f\nradius: %f\n", sp.type, sp.center.x, sp.center.y, sp.center.z, sp.radius);
  fflush(stdout);
  return;
}