#include <stdio.h>
#include "arena.h"

int main() {

  static int ARENA_SIZE = 10;
  static int A_SIZE = 10;


  struct arena *arena = new_arena(sizeof(int) * ARENA_SIZE);

  int *a = (int*) alloc_arena(arena ,sizeof(int) * A_SIZE);

  for (size_t i = 0; i < A_SIZE; i++) {
    a[i] = i;
  }

  for (size_t i = 0; i < A_SIZE; i++) {
    printf("%ld: %d\n", i, a[i]);
  }
  
  return 0;
}
