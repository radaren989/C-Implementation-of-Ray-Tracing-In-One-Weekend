#include "camera.h"

void camera_init(camera *cam)
{
  if (!cam->aspect_ratio)
    cam->aspect_ratio = 1.0;
  if (!cam->image_width)
    cam->image_width = 100;

  if (!cam->samples_per_pixel)
    cam->samples_per_pixel = 10;

  if (!cam->max_depth)
    cam->max_depth = 10;

  // Calculate the image height, and ensure that it's at least 1.
  cam->image_height = (int)(cam->image_width / cam->aspect_ratio);
  cam->image_height = (cam->image_height < 1) ? 1 : cam->image_height;

  cam->center = (point3){0, 0, 0};

  // determine viewport dimensions
  double focal_length = 1.0;
  double viewport_height = 2.0;
  double viewport_width = viewport_height * ((double)(cam->image_width) / cam->image_height);

  // Calculate the vectors across the horizontal and down the vertical viewport edges.
  vec3 viewport_u = (vec3){viewport_width, 0, 0};
  vec3 viewport_v = (vec3){0, -viewport_height, 0};

  // Calculate the horizontal and vertical delta vectors from pixel to pixel.
  cam->pixel_delta_u = vec3_div(viewport_u, cam->image_width);
  cam->pixel_delta_v = vec3_div(viewport_v, cam->image_height);

  // Calculate the location of the upper left pixel.
  // camera_center - focal_length_vector_z - viewport_u/2 - viewport_v/2
  vec3 viewport_upper_left = vec3_subtr_vec(vec3_subtr_vec(vec3_subtr_vec(cam->center, (vec3){0, 0, focal_length}), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2));
  // viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v)
  cam->pixel00_loc = vec3_add_vec(viewport_upper_left, vec3_mult(vec3_add_vec(cam->pixel_delta_u, cam->pixel_delta_v), 0.5));
}

void camera_render(camera *cam, struct node *world)
{
  camera_init(cam);

  printf("P3\n%d %d\n255\n", cam->image_width, cam->image_height);

  const int height = cam->image_height, width = cam->image_width, num_samples = cam->samples_per_pixel;
  register int h, w;
  for (h = 0; h < height; h++)
  {
    fprintf(stderr, "Scanlines Remaining: %d\n", (height - h));
    fflush(stderr);
    for (w = 0; w < width; w++)
    {
      color pixel_color = {0, 0, 0};
      for (int s = 0; s < num_samples; s++)
      {
        ray r = get_ray(w, h, cam);
        pixel_color = vec3_add_vec(pixel_color, ray_color(r, cam->max_depth, world));
      }
      color_write(stdout, pixel_color, num_samples);
    }
  }

  fprintf(stderr, "\rDone      \n");
  freelist(world);
  fflush(stderr);
}

ray get_ray(int w, int h, camera *cam)
{
  // pixel00_loc + (i * viewport_u) + (j * viewport_v)
  vec3 pixel_center = vec3_add_vec(cam->pixel00_loc, vec3_add_vec(vec3_mult(cam->pixel_delta_u, w), vec3_mult(cam->pixel_delta_v, h)));
  vec3 pixel_sample = vec3_add_vec(pixel_center, pixel_sample_square(cam));

  vec3 ray_origin = cam->center;
  vec3 ray_direction = vec3_subtr_vec(pixel_sample, ray_origin);

  return (ray){ray_origin, ray_direction};
}

vec3 pixel_sample_square(camera *cam)
{
  double px = -0.5 + random_double();
  double py = -0.5 + random_double();

  return vec3_add_vec(vec3_mult(cam->pixel_delta_u, px), vec3_mult(cam->pixel_delta_v, py));
}

bool world_hit(ray r, double ray_tmin, double ray_tmax, struct node *world, hit_record *rec)
{
  hit_record temp_rec;
  bool hit_anything = false;
  double cloesest_so_far = ray_tmax;

  struct node *current = world;
  while (current != NULL)
  {

    if (is_hit(current->ptr, r, ray_tmin, cloesest_so_far, &temp_rec))
    {
      hit_anything = true;
      cloesest_so_far = temp_rec.t;
      *rec = temp_rec;
    }
    current = current->next;
  }

  return hit_anything;
}

color ray_color(ray r, int depth, struct node *world)
{
  hit_record rec;

  if (depth <= 0)
  {
    return (color){0, 0, 0};
  }
  if (world_hit(r, 0.001, INFINITY, world, &rec))
  {
    vec3 direction = random_on_hemisphere(rec.normal);
    return vec3_mult(ray_color((ray){rec.p, direction}, depth - 1, world), 0.5);
  }

  vec3 unit_direction = vec3_unit(r.direction);
  double a = .5 * (unit_direction.y + 1.0);
  // blendVal = (1-a)*startVal + a*endVal
  return vec3_add_vec(vec3_mult((color){1.0, 1.0, 1.0}, (1.0 - a)), vec3_mult((color){0.5, 0.7, 1.0}, a));
}