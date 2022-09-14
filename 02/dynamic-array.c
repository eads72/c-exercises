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
    int* a;
    a = malloc(sizeof(int)*INIT_LEN);
    array.beginning_address = a;
    array.buffer_length = INIT_LEN;
    array.number_of_elements = 0;
    return array;
}

void print_array(struct DynArray array){
    printf("Buffer length is: %d \n", array.buffer_length);
}

//adds elements to the end of the array
//takes the struct of the array and the new element as a parameter
void add_single_element(struct DynArray* array, int new_element){

}

int main(){
    struct DynArray myArray = create_array();
    print_array(myArray);
}