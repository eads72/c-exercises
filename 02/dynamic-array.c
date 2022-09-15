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

// First paramter is the pointer to the structure 
// Takes the index as the second parameter, and removes that value in the index.
// Returns the removed value
int remove_element(struct DynArray* array, int index_of_element_to_be_removed){
    
    int removed_num = array->beginning_address[index_of_element_to_be_removed];

    for( int i = index_of_element_to_be_removed; i < array->number_of_elements; i++){
        array->beginning_address[i] = array->beginning_address[i+1];
    }

    array->number_of_elements--;
    return  removed_num;
}


// Inserts the new value to the desired index
void insert_element(struct DynArray* array, int target_index, int new_value){

    add_single_element(array, 0);

    for( int i = array->number_of_elements-1; i > target_index ; i--){
        array->beginning_address[i] = array->beginning_address[i-1];
    }

    array->beginning_address[target_index]= new_value;
}


// Reverses the elements in the array
void reverse(struct DynArray* array){
    for(int i = 0; i < array->number_of_elements/2; i++){
        int from_start = array->beginning_address[i];
        int from_end = array->beginning_address[array->number_of_elements-i-1];
        array->beginning_address[i] = from_end;
        array->beginning_address[array->number_of_elements-i-1] = from_start;
    }
}




int get(struct DynArray* array, int what_you_want){

    if(what_you_want < array->number_of_elements && what_you_want >= 0){
        return array->beginning_address[what_you_want];
    }
    
    printf("Invalid index: %d, size is %d. Terminating.\n", what_you_want, array->number_of_elements);
    exit(1);

}


int main(){

    struct DynArray myArray = create_array();
    print_array(myArray);
    int removed_num;

    for(int i = 0; i < 12; i++) {
        add_single_element(&myArray, i * i);
    }
    print_array(myArray);
    removed_num = remove_element(&myArray, 3);
    printf("Removed number is: %d\n", removed_num);
    print_array(myArray);

    insert_element(&myArray, 2, 3);
    print_array(myArray);
    reverse(&myArray);
    print_array(myArray);
    printf("the index 3 is: %d\n", get(&myArray, 3));
    get(&myArray, -6);
}