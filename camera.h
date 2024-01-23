#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "vec3.h"
#include "utils.h"
#include "hit.h"
#include "color.h"

typedef struct
{
  double aspect_ratio;
  int image_width;
  int image_height;
  point3 center;
  point3 pixel00_loc;
  vec3 pixel_delta_u;
  vec3 pixel_delta_v;
} camera;

void camera_init(camera *cam);
void camera_render(camera *cam, struct node *world);
bool world_hit(ray r, double ray_tmin, double ray_tmax, struct node *world, hit_record *rec);
color ray_color(ray r, struct node *world);
