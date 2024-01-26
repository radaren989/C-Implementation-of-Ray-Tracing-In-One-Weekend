#include "material.h"

bool lambertian_scatter(material *mat, ray *r_in, hit_record *rec, color *attenuation, ray scattered)
{
  vec3 scatter_direction = vec3_add_vec(rec->normal, vec3_random_unit());

  if (vec3_near_zero(scatter_direction))
    scatter_direction = rec->normal;

  scattered = (ray){rec->p, scatter_direction};
  atteniuation = mat->albedo;

  return true;
}

bool metal_scatter(material *mat, ray *r_in, hit_record *rec, color *attenuation, ray scattered)
{
  vec3 reflected = vec3_reflect(vec3_unit(r_in->direction), rec->normal);
  scattered = ray(rec->p, reflected);
  attenuation = mat->albedo;
  return true;
}