/*
    This is a program that makes dynamic arrays
    what it does? Create an array, remove elements, add elements, and change element
*/

const int INIT_LEN = 5;

// This structure is for the dynamic array 
// A dynamic array can grow and shrink if necessary
#include <stdio.h>
#include <stdlib.h>

struct DynArray{
    int* beginning_address;
    int buffer_length;
    int number_of_elements;
};

// Creates and returns an empty array.
//
// returns the struct of the array
struct DynArray create_array(){
    struct DynArray array;
    array.beginning_address = (int*) malloc(sizeof(int) * INIT_LEN);
    array.buffer_length = INIT_LEN;
    array.number_of_elements = 0;
    return array;
}

void print_array(struct DynArray array){
    printf("Buffer length is: %d \n", array.buffer_length);
    printf("Number of elements is: %d \n", array.number_of_elements);
    printf("[ ");
    for(int i = 0; i < array.number_of_elements; i++){
        printf("%d ", array.beginning_address[i]);
    }
    printf("]\n");
}

// Adds elements to the end of the array
// Takes the struct of the array and the new element as a parameter
//
// Returns 1 if the operation is successful, 0 otherwise
unsigned char add_single_element(struct DynArray* array, int new_element){
    if(array->buffer_length <= array->number_of_elements){
        unsigned int new_buffer_size = 2 * array->buffer_length;
        unsigned int new_realloc_size = new_buffer_size * sizeof(int);

        int* new_array = (int*) realloc(array->beginning_address, new_realloc_size);

        if (new_array == 0){
            return 0;
        }
        
        array->buffer_length = new_buffer_size;
        array->beginning_address = new_array;
    }

    array->beginning_address[array->number_of_elements] = new_element;
    array->number_of_elements++;

    return 1;
}

int main(){
    struct DynArray myArray = create_array();
    print_array(myArray);

    for(int i = 0; i < 100; i++) {
        add_single_element(&myArray, i * i);
    }
    print_array(myArray);
}