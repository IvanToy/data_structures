#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "./include/int_vector.h"

#define POP_BOUNDARY 6

int main(void)
{
    int_vector vector;
    int_vector_init(&vector);

    for (int i = 1; i <= 10; i++) {
        if (int_vector_push(&vector, i * 10) != 0) {
            fprintf(stderr, "Failed to append element\n");
            int_vector_destroy(&vector);
            return 1;
        }
    }

    printf("Size: %zu\n", vector.size);
    printf("Capacity: %zu\n", vector.capacity);

    for (size_t i = 0; i < vector.size; i++) {
        printf("vector[%zu] = %d\n", i, vector.data[i]);
    }

    int value;


    for( size_t i = 0; i < vector.size; i++){

        if (int_vector_get(&vector, i, &value) == 0) {
            printf("Element: %d\n", value);
        } else {
            fprintf(stderr, "Invalid vector index\n");
        }
    }


    for( size_t i = 0; i  < vector.size; i++){
        if(int_vector_set(&vector, i, i  * 5)  == 0){
            printf("vector[%zu] = %d\n", i, vector.data[i]);
        }else{
            fprintf(stderr, "Failed to set an element\n");
        }
    }


    while (vector.size > POP_BOUNDARY) {

        int popped_element;

        if (int_vector_pop(&vector, &popped_element) != 0) {
            fprintf(stderr, "Failed to pop element\n");
            int_vector_destroy(&vector);
            return 1;
        }

        printf("Popped: %d\n", popped_element);
    }

    printf("INSERT:\n");

    if(int_vector_insert(&vector, 3, 55) == 0){
        for(size_t i = 0; i < vector.size; i++){
            printf("vector[%zu] = %d\n", i, vector.data[i]);
        }
    }else{
        fprintf(stderr, "Failed to insert an element\n");
    }

    printf("REMOVE:\n");

    if(int_vector_remove(&vector, 3) == 0){
        for(size_t i = 0; i < vector.size; i++){
            printf("vector[%zu] = %d\n", i, vector.data[i]);
        }
    }else{
        fprintf(stderr, "Failed to remove an element\n");
    }

    size_t size;
    size_t capacity;
    int_vector_size(&vector, &size);
    int_vector_capacity(&vector, &capacity);
    printf("Vector's size: %zu\n",size);
    printf("Vector's capacity: %zu\n", capacity);

    int_vector_clear(&vector);

    int_vector_destroy(&vector);

    return 0;
}
