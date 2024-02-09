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
	cam.image_width = 1200;
	cam.samples_per_pixel = 10;
	cam.max_depth = 50;

  cam.vfov = 20;
  cam.lookfrom = (point3){-2,2,1};
  cam.lookat = (point3){0,0,-1};
  cam.vup = (vec3){0,1,0};

	// material
	material ground = {lambertian_scatter, (color){.8, .8, .0}, 0};
	material center = {lambertian_scatter, (color){.1, .2, .3}, 0};
	material left = {metal_scatter, (color){.8, .8, .8}, .3};
	material right = {metal_scatter, (color){.8, .6, .2}, 1.0};

	// world build
	struct node *world = NULL;
	sphere sph2 = {SPHERE_TYPE, vec3_create(0, -101, -1), 100, &ground};
	sphere sph1 = {SPHERE_TYPE, vec3_create(0, 0, -1), .5, &center};
	sphere sph3 = {SPHERE_TYPE, vec3_create(-1, 0, -1), .5, &left};
	sphere sph4 = {SPHERE_TYPE, vec3_create(1, 0, -1), .5, &right};
	insertAtBeginning(&world, &sph1);
	insertAtBeginning(&world, &sph2);
	insertAtBeginning(&world, &sph3);
	insertAtBeginning(&world, &sph4);

	// render
	camera_render(&cam, world);

	return 0;
}
