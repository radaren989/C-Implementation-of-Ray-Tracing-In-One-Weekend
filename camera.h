#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "color.h"
#include "material.h"
#include "hit.h"

typedef struct
{
  double aspect_ratio;
  int image_width;
  int image_height;
  int samples_per_pixel;
  int max_depth;
  double vfov;
  point3 center;
  point3 pixel00_loc;
  vec3 pixel_delta_u;
  vec3 pixel_delta_v;
  point3 lookfrom;
  point3 lookat;
  vec3 vup;
  vec3 u,v,w;
} camera;

void camera_init(camera *cam);
void camera_render(camera *cam, sphere world[], int size);
bool world_hit(ray r, double ray_tmin, double ray_tmax, sphere world[], int size, hit_record *rec);
color ray_color(ray *r, int depth, sphere world[], int size);
ray get_ray(int w, int h, camera *cam);
vec3 pixel_sample_square(camera *cam);
