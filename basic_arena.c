#include "basic_arena.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t offset;
} arena;

arena arena_init(size_t size) {
    arena a;
    a.buffer = malloc(size);
    a.size = size;
    a.offset = 0;

    return a;
}

void *arena_alloc(arena *a, size_t size) {
    if (a->offset + size > a->size) {  //incase out of space
        return NULL;
    }

    void *ptr = &a->buffer[a->offset];
    a->offset += size;
    return ptr;
}

void arena_reset(arena *a) {
    a->offset = 0;
}

void arena_free(arena *a) {
    free(a->buffer);
    a->buffer = NULL;
    a->size = 0;
    a->offset = 0;
}