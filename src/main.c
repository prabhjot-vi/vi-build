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

  size_t size = strlen(c_string);

  if (c_string[size] != '\0') {
    perror("c_string is not null terminating");
    return NULL;
  }

  struct string *string = (struct string *) alloc_arena(arena, sizeof(struct string) + (sizeof(char) * size));
  if (string == NULL) {
    perror("unable to allocate memory for string struct");
    return NULL;
  }

  string->size = size;
  string->offset = 0;
  strncpy(string->ptr, c_string, size);

  return string;
}

int main() {

  /* static int ARENA_SIZE = 10; */
  /* static int A_SIZE = 10; */

  /* struct arena *arena = new_arena(sizeof(int) * ARENA_SIZE); */

  /* struct string *str1 = new_string(arena, "Hello World"); */

  /* printf("str1: %s\n", str1->ptr); */

  /* free_arena(arena); */

  printf("Hello World\n");
  
  return 0;
}
