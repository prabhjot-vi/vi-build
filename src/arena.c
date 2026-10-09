#include "arena.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct arena *new_arena(size_t size) {
  if (size == 0) {
    perror("size should be grater then zero");
    return NULL;
  }
  
  struct arena *arena = (struct arena*) malloc(sizeof(struct arena));
  if (arena == NULL) {
    perror("Unable to allocate memory for arena struct");
    exit(1);
  }

  arena->size = size;
  arena->offset = 0;
  arena->ptr = (uint8_t*) malloc(sizeof(uint8_t) * size);
  if (arena->ptr == NULL) {
    perror("Unable to allocate arena ptr");
    exit(1);
  }

  return arena;
}

void free_arena(struct arena *arena) {
  if (arena != NULL) {
    if (arena->ptr != NULL) {
      free(arena->ptr);
    }
    free(arena);
  }
}

void reset_arena(struct arena *arena) {
  if (arena == NULL) {
    perror("Arean is Null");
    return;
  }

  arena->offset = 0;
}

void *alloc_arena(struct arena *arena, size_t size) {
  if (arena == NULL) {
    perror("Arena is Null");
    return NULL;
  }

  if (size > (arena->size - arena->offset)) {
    perror("Arena is full");
    return NULL;
  }

  void *alloc_mem = (void*) (arena->ptr + arena->offset);
  arena->offset += size;

  return alloc_mem;
}
