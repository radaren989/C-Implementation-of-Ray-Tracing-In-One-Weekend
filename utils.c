#include <stdio.h>
#include "utils.h"

uint8_t determine_object(void *object)
{
  return *(uint8_t *)object;
}

void printObject(uint8_t type, void *ptr)
{
  switch (type)
  {
  case 0:
    sphere *sphere_ptr = (sphere *)ptr;
    printSphere(sphere_ptr);
    break;
  case 1:
    foo *foo_ptr = (foo *)ptr;
    printFoo(foo_ptr);
    break;
  }
  return;
}

void printSphere(sphere *sp)
{
  printf("type: %d\n  x: %f\n  y: %f\n  z: %f\nradius: %f\n", sp->type, sp->center.x, sp->center.y, sp->center.z, sp->radius);
  fflush(stdout);
  return;
}

void printFoo(foo *f)
{
  printf("type: %d\na: %d\nb: %d\n", f->type, f->a, f->b);
  return;
}