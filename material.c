#include "material.h"
#include "hit.h"
#include "ray.h"
#include "vec3.h"

bool lambertian_scatter(ray *r_in, struct hit_record *rec,
                        color *attenuation, ray *scattered) {
  vec3 scatter_direction = vec3_add_vec(rec->normal, vec3_random_unit());

  *scattered = ray_create(rec->p, scatter_direction);
  *attenuation = rec->mat->albedo;

  if (vec3_near_zero(scatter_direction))
    scatter_direction = rec->normal;

  *scattered = ray_create(rec->p, scatter_direction);
  *attenuation = rec->mat->albedo;

  return true;
}

bool metal_scatter(ray *r_in, struct hit_record *rec,
                   color *attenuation, ray *scattered) {
  double fuzz = (rec->mat->fuzz < 1) ? rec->mat->fuzz : 1;
  vec3 reflected = vec3_reflect(vec3_unit(r_in->direction), rec->normal);
  *scattered = ray_create(rec->p,vec3_add_vec(reflected, vec3_mult(vec3_random_unit(), fuzz)));
  *attenuation = rec->mat->albedo;
  return (vec3_dot(scattered->direction, rec->normal) > 0);
}
