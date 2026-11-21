#ifndef  INT_VECTOR_H
#define  INT_VECTOR_H

#include <stddef.h>

typedef struct{
    int *data;
    size_t size;
    size_t capacity;

} int_vector;

void int_vector_init(int_vector *vector);
void int_vector_clear(int_vector *vector);
void int_vector_destroy(int_vector *vector);
int int_vector_push(int_vector *vector, int number);
int int_vector_pop(int_vector *vector, int *popped_element);
int int_vector_get(const int_vector *vector, size_t index, int *value);
int int_vector_set(int_vector *vector, size_t index, int element);
int int_vector_insert(int_vector *vector, size_t index, int element);
int int_vector_remove(int_vector *vector, size_t index);
int int_vector_size(const int_vector *vector, size_t *result);
int int_vector_capacity(const int_vector *vector, size_t *result);

#endif
