#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <assert.h>
// #include "list.h"
// #include "utils.h"
// #include "sphere.h"
#include "vec3.h"

typedef struct
{
  int a;
  int b;
} foo;

int main()
{
  // struct node *list = NULL;
  // sphere n1 = {SPHERE_TYPE, (point3){5, 5, 5}, 1};
  // sphere n2 = {SPHERE_TYPE, (point3){4, 3, 2}, 1};
  // foo n3 = {FOO_TYPE, 1, 2};

  // insertAtBeginning(&list, (void *)&n1);
  // insertAtBeginning(&list, (void *)&n2);
  // insertAtBeginning(&list, (void *)&n3);

  // struct node *cursor = list;
  // while (cursor != NULL)
  // {
  //   printObject(determine_object(cursor->ptr), cursor->ptr);
  //   cursor = cursor->next;
  // }

  // Test vec3_create
  vec3 v1 = vec3_create(5, 7, 13);
  // Test vec3_inc
  vec3 v2 = vec3_create(6, 45, -8);
  // Test vec3_cross
  vec3 v10 = vec3_cross(v1, v2);
  assert(v10.x == -641 && v10.y == 118 && v10.z == 183);
  printf("helal\n");
  return 0;
}