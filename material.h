#pragma once

#include <stdbool.h>
#include "color.h" // Include the header where color struct is defined
#include "utils.h" // Include the header where ray struct is defined

typedef struct material
{
  bool (*scatter)(struct material *, ray *, hit_record *, color *, ray);
  color albedo;
} material;

bool lambertian_scatter(material *mat, ray *r_in, hit_record *rec, color *attenuation, ray scattered);
bool metal_scatter(material *mat, ray *r_in, hit_record *rec, color *attenuation, ray scattered);

#include "hit.h" // Include the header where hit_record struct is defined