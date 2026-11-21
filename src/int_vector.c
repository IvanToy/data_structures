#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/int_vector.h"


void int_vector_init(int_vector *vector){

    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;

}

int int_vector_push(int_vector *vector, int number)
{
    if (vector == NULL) {
        return -1;
    }

    if (vector->size == vector->capacity) {

        size_t max_capacity = SIZE_MAX / sizeof(*vector->data);
        size_t new_capacity;

        if (vector->capacity == 0) {

            if (max_capacity < 4) {
                fprintf(stderr, "Vector capacity overflow\n");
                return -1;
            }

            new_capacity = 4;

            int *data = malloc(new_capacity * sizeof(*data));

            if (data == NULL) {
                perror("Failed to allocate memory");
                return -1;
            }

            vector->data = data;

        } else {

            if (vector->capacity > max_capacity / 2) {
                fprintf(stderr, "Vector capacity overflow\n");
                return -1;
            }

            new_capacity = vector->capacity * 2;

            int *temp = realloc(vector->data, new_capacity * sizeof(*vector->data));
            if (temp == NULL) {
                perror("Failed to reallocate memory");
                return -1;
            }

            vector->data = temp;
        }

        vector->capacity = new_capacity;
    }

    vector->data[vector->size] = number;
    vector->size++;

    return 0;
}

int int_vector_pop(int_vector *vector, int *popped_element)
{
    if (vector == NULL || popped_element == NULL) {
          return -1;
      }

    if (vector->size == 0) {
        return -1;
    }

    *popped_element = vector->data[vector->size - 1];
    vector->size--;

    return 0;
}

int int_vector_get(const int_vector *vector, size_t index, int *value)
{
    if (vector == NULL || value == NULL) {
        return -1;
    }

    if (index >= vector->size) {
        return -1;
    }

    *value = vector->data[index];

    return 0;
}

int int_vector_set(int_vector *vector, size_t index, int element){

    if(vector == NULL || index >= vector->size){
        return -1;
    }

    vector->data[index] = element;

    return 0;
}


int int_vector_insert(int_vector *vector, size_t index, int element)
{
    if (vector == NULL || index > vector->size) {
        return -1;
    }

    if (vector->size == vector->capacity) {

        size_t max_capacity = SIZE_MAX / sizeof(*vector->data);

        size_t new_capacity;

        if (vector->capacity == 0) {
            if (max_capacity < 4) {
                return -1;
            }

            new_capacity = 4;
        } else {
            if (vector->capacity > max_capacity / 2) {
                return -1;
            }

            new_capacity = vector->capacity * 2;
        }

        int *temp = realloc(vector->data, new_capacity * sizeof(*vector->data));
        if (temp == NULL) {
            perror("Failed to reallocate memory");
            return -1;
        }

        vector->data = temp;
        vector->capacity = new_capacity;
    }

    for (size_t i = vector->size; i > index; i--) {
        vector->data[i] = vector->data[i - 1];
    }

    vector->data[index] = element;
    vector->size++;

    return 0;
}

int int_vector_remove(int_vector *vector, size_t index){

    if(vector == NULL || index >= vector->size){
        return -1;
    }

    for(size_t i = index; i < vector->size - 1; i++){
        vector->data[i] = vector->data[i + 1];
    }

    vector->size--;

    return 0;
}

int int_vector_size(const int_vector *vector, size_t *result){
    if(vector == NULL){
        return -1;
    }
    *result = vector->size;
    return 0;
}

int int_vector_capacity(const int_vector *vector, size_t *result){
    if(vector == NULL){
        return -1;
    }
    *result = vector->capacity;
    return 0;
}

void int_vector_clear(int_vector *vector){
    if (vector == NULL) {
        return;
    }
    vector->size = 0;
}


void int_vector_destroy(int_vector *vector_data){
    free(vector_data->data);
}
