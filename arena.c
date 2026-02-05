#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t offset;
} Arena;

Arena arena_init(size_t size) {
    Arena a;
    a.buffer = malloc(size);
    a.size = size;
    a.offset = 0;

    return a;
}

void *arena_alloc(Arena *a, size_t size) {
    if (a->offset + size > a->size) {  //incase out of space
        return NULL;
    }

    void *ptr = &a->buffer[a->offset];
    a->offset += size;
    return ptr;
}

void arena_reset(Arena *a) {
    a->offset = 0;
}

void arena_free(Arena *a) {
    free(a->buffer);
    a->buffer = NULL;
    a->size = 0;
    a->offset = 0;
}