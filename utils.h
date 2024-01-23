#pragma once
#include <stdint.h>
#include <stdint.h>
#include "sphere.h"

typedef struct
{
  uint8_t type;
  int a;
  int b;
} foo;

#define SPHERE_TYPE 0
#define FOO_TYPE 1

uint8_t determine_object(void *object);
void printObject(uint8_t type, void *ptr);
void printSphere(sphere *sp);
void printFoo(foo *f);