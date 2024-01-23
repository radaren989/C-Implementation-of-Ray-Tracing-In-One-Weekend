#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "list.h"
#include "utils.h"
#include "sphere.h"
#include "vec3.h"

int main()
{
  struct node *list = NULL;
  sphere n1 = {SPHERE_TYPE, (point3){5, 5, 5}, 1};
  sphere n2 = {SPHERE_TYPE, (point3){4, 3, 2}, 1};
  foo n3 = {FOO_TYPE, 1, 2};

  insertAtBeginning(&list, (void *)&n1);
  insertAtBeginning(&list, (void *)&n2);
  insertAtBeginning(&list, (void *)&n3);

  struct node *cursor = list;
  while (cursor != NULL)
  {
    printObject(determine_object(cursor->ptr), cursor->ptr);
    cursor = cursor->next;
  }
  return 0;
}