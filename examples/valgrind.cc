#include <cstdlib>

int* f(void)
{
  int *x = (int*) malloc(10 * sizeof(int));
  x[9] = 0;        // problem 1: heap block overrun
                    // problem 2: memory leak -- x not freed
  return x;
}

int main(void)
{
  free(f());
  
  return 0;
}
