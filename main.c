#include "utils.h"
#include "list.h"

#include "camera.h"
#include "color.h"
#include "material.h"
#include "sphere.h"
#include "vec3.h"

int main()
{
	// cam settings
	camera cam;
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 1200;
	cam.samples_per_pixel = 500;
	cam.max_depth = 50;

  cam.vfov = 20;
  cam.lookfrom = (point3){13,2,3};
  cam.lookat = (point3){0,0,0};
  cam.vup = (vec3){0,1,0};

	// material

	// world build
  sphere world[1024];
  material ground = {lambertian_scatter, (color){.5, .5, .5}, 0};
  sphere gnd = {SPHERE_TYPE, vec3_create(0, -1000, 0), 1000, &ground};
  world[0] = gnd;

  material mat1 = {metal_scatter, (color){.5, .6, .7}, .7};
  sphere sph1 = {SPHERE_TYPE, vec3_create(0, 1, 0), 1, &mat1};
  world[1] = sph1;

  material mat2 = {lambertian_scatter, (color){.4, .2, .1}, 0};
  sphere sph2 = {SPHERE_TYPE, vec3_create(-4, 1, 0), .1, &mat2};
  world[2] = sph2;

  material mat3 = {metal_scatter, (color){.7, .6, .5}, 0};
  sphere sph3 = {SPHERE_TYPE, vec3_create(4, 1, 0), 1, &mat3};
  world[3] = sph3;

  int index = 4;

  for(int a = -11; a < 11; a++){
    for(int b = -11; b < 11; b++){
      double chosen_mat = random_double();
      point3 center = {a+.9*random_double(),.2,b+.9*random_double()};
      material *mat = (material *)malloc(sizeof(material));
      sphere *sph = (sphere *)malloc(sizeof(sphere));

      if(vec3_length(vec3_subtr_vec(center, (point3){4,.2,0}))> .9){
        
        if(chosen_mat < .7){
          color albedo = vec3_random();
          *mat = (material){lambertian_scatter, albedo,0};
          *sph = (sphere){SPHERE_TYPE,center,.2, mat};
          world[index] = *sph;
          
        }
        else{
          color albedo = vec3_random_in(.5, 1);
          double fuzz = random_double_in(0,.5);
          *mat = (material){metal_scatter, albedo,fuzz};
          *sph = (sphere){SPHERE_TYPE, center, .2, mat};
          world[index] = *sph;
        }
        index++;
      }
    }
  }


	// render
	camera_render(&cam, world, index + 1);

	return 0;
}
