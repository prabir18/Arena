#ifndef arena.h
#define arena.h

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t offset;
} Arena;

Arena arena_init(size_t size);
void *arena_alloc(Arena *a, size_t size);
void arena_reset(Arena *a);
void arena_free(Arena *a);

#endif
