#include "types.h"
#include "user.h"


void bubble_sort(int *v, int n){
  int i, j, aux;
  for(i = 0; i < n - 1; i++)
    for(j = 1; j < n - i; j++)
      if(v[j] < v[j-1])
      {
        aux = v[j-1];
        v[j-1] = v[j];
        v[j] = aux;
      }
}

int main(int argc, char *argv[])
{
  int *v = (int *) malloc(35000 *sizeof(int));
  for(int i = 0; i < 35000; i++)
    v[i] = 35000 - i;
  bubble_sort(v, 35000);
  free(v);
  test_stime();
  printf(1, "\n");
  exit();
}

