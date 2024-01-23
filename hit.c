#include <hit.h>
#include <math.h>

bool hit_sphere(ray r, sphere sphere, double ray_tmin, double ray_tmax, hit_record *rec)
{
  vec3 oc = vec3_subtr_vec(r.origin, sphere.center);
  double a = vec3_length_squared(r.direction);
  double half_b = vec3_dot(r.direction, oc);
  double c = vec3_length_squared(oc) - sphere.radius * sphere.radius;

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
  vec3 outward_normal = vec3_div(vec3_subtr_vec(rec->p, sphere.center), sphere.radius);
  hit_set_face_normal(r, outward_normal, rec);

  return true;
}

void hit_set_face_normal(ray r, vec3 outward_normal, hit_record *rec)
{
  rec->front_face = vec3_dot(r.direction, outward_normal) < 0;
  rec->normal = rec->front_face ? outward_normal : vec3_reversed(outward_normal);
}