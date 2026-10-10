#include <stdio.h>
#include "arena.h"

#include <string.h>

struct string {
  size_t size;
  size_t offset;
  char *ptr;
};

struct string *new_string(struct arena *arena, const char *c_string) {
  if (strlen(c_string) == 0) {
    perror("c_string is empty");
    return NULL;
  }

  struct string *string;

  return string;
}

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

  free_arena(arena);
  
  return 0;
}
