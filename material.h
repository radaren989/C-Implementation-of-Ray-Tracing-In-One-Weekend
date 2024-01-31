#pragma once

#include <stdbool.h>
#include "color.h"
#include "utils.h"

struct hit_record;
typedef struct material
{
  bool (*scatter)(struct material *, ray *, struct hit_record *, color *, ray *);
  color albedo;
} material;

bool lambertian_scatter(material *mat, ray *r_in, struct hit_record *rec, color *attenuation, ray *scattered);
bool metal_scatter(material *mat, ray *r_in, struct hit_record *rec, color *attenuation, ray *scattered);
