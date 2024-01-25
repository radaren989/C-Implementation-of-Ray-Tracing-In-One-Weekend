#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double random_double()
{

  static int rand_called = 0;

  if (!rand_called)
  {
    printf("geldi\n");
    fflush(stdout);
    srand((unsigned int)time(NULL));
    rand_called = 1;
  }

  return rand() / (RAND_MAX + 1.0);
}
int main()
{
  for (int i = 0; i < 5; i++)
  {
    printf("%f\n", random_double());
  }

  return 0;
}