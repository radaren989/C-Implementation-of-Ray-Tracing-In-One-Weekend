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

	// material
	material ground = {&lambertian_scatter, (color){.8, .8, .0}};
	material center = {&lambertian_scatter, (color){.7, .3, .3}};
	material left = {&metal_scatter, (color){.8, .8, .8}};
	material right = {&metal_scatter, (color){.8, .6, .2}};

	// world build
	struct node *world = NULL;
	sphere sph2 = {SPHERE_TYPE, vec3_create(0, -101, -1), 100, ground};
	sphere sph1 = {SPHERE_TYPE, vec3_create(0, 0, -1), .5, center};
	sphere sph3 = {SPHERE_TYPE, vec3_create(-1, 0, -1), .5, left};
	sphere sph4 = {SPHERE_TYPE, vec3_create(1, 0, -1), .5, right};
	insertAtBeginning(&world, &sph1);
	insertAtBeginning(&world, &sph2);
	insertAtBeginning(&world, &sph3);
	insertAtBeginning(&world, &sph4);

	// render
	camera_render(&cam, world);

	return 0;
}