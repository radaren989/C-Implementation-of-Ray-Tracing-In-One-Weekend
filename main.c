#include <stdio.h>

#include "utils.h"
#include "list.h"

#include "camera.h"
#include "color.h"
#include "material.h"
#include "sphere.h"

int main()
{
	// cam settings
	camera cam;
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;
	cam.samples_per_pixel = 10;
	cam.max_depth = 50;
  cam.vfov = 90;

	// material
	material left = {lambertian_scatter, (color){0, 0, 1}};
	material right = {lambertian_scatter, (color){1, 0, 0}};

  double R = cos(PI/4);

	// world build
	struct node *world = NULL;
	sphere sph1 = {SPHERE_TYPE, vec3_create(-R, 0, -1), R, left};
	sphere sph2 = {SPHERE_TYPE, vec3_create(R, 0, -1), R, right};
	insertAtBeginning(&world, &sph1);
	insertAtBeginning(&world, &sph2);

	// render
	camera_render(&cam, world);

	return 0;
}
