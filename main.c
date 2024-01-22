#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "vec3.h"
#include "color.h"
#include "ray.h"

double hit_sphere(point3 center, double radius, ray r)
{
	vec3 oc = vec3_subtr_vec(r.origin, center);
	double a = vec3_length_squared(r.direction);
	double half_b = vec3_dot(r.direction, oc);
	double c = vec3_length_squared(oc) - radius * radius;
	double discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
	{
		return -1.0;
	}
	else
	{
		return (-half_b - sqrt(discriminant)) / a;
	}
}

color ray_color(ray r)
{
	double t = hit_sphere((point3){0, 0, -1}, .5, r);

	fprintf(stderr, "%f\n", t);
	fflush(stderr);

	if (t > 0.0)
	{
		vec3 N = vec3_unit(vec3_subtr_vec(ray_at(r, t), (vec3){0, 0, -1}));
		return vec3_mult((color){N.x + 1, N.y + 1, N.z + 1}, .5);
	}
	vec3 unit_direction = vec3_unit(r.direction);
	double a = .5 * (unit_direction.y + 1.0);
	// blendVal = (1-a)*startVal + a*endVal
	return vec3_add_vec(vec3_mult((color){1.0, 1.0, 1.0}, (1.0 - a)), vec3_mult((color){0.5, 0.7, 1.0}, a));
}

int main()
{
	// Image

	double aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// Calculate the image height, and ensure that it's at least 1.
	int image_height = (int)(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera

	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height * ((double)image_width / image_height);
	vec3 camera_center = {0, 0, 0};

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	vec3 viewport_u = (vec3){viewport_width, 0, 0};
	vec3 viewport_v = (vec3){0, -viewport_height, 0};

	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	vec3 pixel_delta_u = vec3_div(viewport_u, image_width);
	vec3 pixel_delta_v = vec3_div(viewport_v, image_height);

	// Calculate the location of the upper left pixel.
	// camera_center - focal_length_vector_z - viewport_u/2 - viewport_v/2
	vec3 viewport_upper_left = vec3_subtr_vec(vec3_subtr_vec(vec3_subtr_vec(camera_center, (vec3){0, 0, focal_length}), vec3_div(viewport_u, 2)), vec3_div(viewport_v, 2));
	// viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v)
	vec3 pixel00_loc = vec3_add_vec(viewport_upper_left, vec3_mult(vec3_add_vec(pixel_delta_u, pixel_delta_v), 0.5));

	// Render

	printf("P3\n%d %d\n255\n", image_width, image_height);

	for (int j = 0; j < image_height; j++)
	{
		fprintf(stderr, "Scanlines Remaining: %d\n", (image_height - j));
		fflush(stderr);
		for (int i = 0; i < image_width; i++)
		{
			// pixel00_loc + (i * viewport_u) + (j * viewport_v)
			vec3 pixel_center = vec3_add_vec(pixel00_loc, vec3_add_vec(vec3_mult(pixel_delta_u, i), vec3_mult(pixel_delta_v, j)));
			vec3 ray_direction = vec3_subtr_vec(pixel_center, camera_center);
			ray r = {pixel_center, ray_direction};

			color pixel_color = ray_color(r);
			color_write(stdout, pixel_color);
		}
	}

	fprintf(stderr, "\rDone      \n");
	fflush(stderr);

	return 0;
}