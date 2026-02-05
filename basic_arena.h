#ifndef basic_arena.h
#define basic_arena.h

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t offset;
} arena;

arena arena_init(size_t size);
void *arena_alloc(arena *a, size_t size);
void arena_reset(arena *a);
void arena_free(arena *a);

#endif
