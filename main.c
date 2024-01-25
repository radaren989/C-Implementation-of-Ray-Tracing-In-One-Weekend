#include <stdio.h>

#include "utils.h"
#include "list.h"
#include "sphere.h"
#include "camera.h"

int main()
{
	// cam settings
	camera cam;
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;
	cam.samples_per_pixel = 10;
	cam.max_depth = 50;

	// world build
	struct node *world = NULL;
	sphere sph1 = {SPHERE_TYPE, vec3_create(0, 0, -1), .5};
	sphere sph2 = {SPHERE_TYPE, vec3_create(0, -101, -1), 100};
	insertAtBeginning(&world, &sph1);
	insertAtBeginning(&world, &sph2);

	// render
	camera_render(&cam, world);

	return 0;
}