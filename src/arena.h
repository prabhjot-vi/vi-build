#pragma once

#include <stdlib.h>
#include <stdint.h>

struct arena {
  size_t size;
  size_t offset;
  uint8_t *ptr;
};

struct arena *new_arena(size_t size);
void free_arena(struct arena *arena);
void reset_arena(struct arena *arena);
void *alloc_arena(struct arena *arena, size_t size);
