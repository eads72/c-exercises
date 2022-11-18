#include <stdlib.h>
#include <stdio.h>
#include "merge-sort.h"

int compare(int num1, int num2){
    if(num1 > num2){
        return FIRST_BIGGER;
        }
	else if(num1 < num2){
        return SECOND_BIGGER;
        }
	else{
        return EQUAL;
        }
}

int* merge(int* arr1, int* arr2, int len1, int len2){
    int total_len = len1 + len2;
    //printf("Total length: %d \n", total_len);    
    int* newarr = (int*)malloc(total_len * sizeof(int));
	int counter1 = 0;
	int counter2 = 0;
    
    // Do this operation for the total number of items in both arrays
    for(int i=0; i< total_len; i++){
        int comparison = compare(arr1[counter1], arr2[counter2]);
        if(counter1 == len1){
            newarr[i] = arr2[counter2];
            counter2++;
        }
        else if(counter2 == len2){
            newarr[i] = arr1[counter1];
            counter1++;
        }
        // printf("First number: %d, Second number: %d \n", arr1[counter1], arr2[counter2]);
        // printf("Comparison is: %d \n", comparison);

	    else if (comparison == SECOND_BIGGER){
            newarr[i] = arr1[counter1];
            counter1++;
        }
	    else if (comparison == FIRST_BIGGER){
            newarr[i] = arr2[counter2];
            counter2++;
        }
	    else if (comparison == EQUAL){
            newarr[i] = arr1[counter1];
            counter1++;
            i++;
            newarr[i] = arr2[counter2];
            counter2++;
        }
    }

    return newarr;
}

int* mergesort(int* arr, int len){
    if(len > 1){
        int* sorted_arr;
        int left_len = len/2;
        int right_len = len - left_len;

        printf("Left lenght = %d , Right lenght = %d \n", left_len, right_len);

        int* left_arr = copy_array(arr, left_len);
        int* right_arr = copy_array(&arr[left_len], right_len);

        int* sorted_left = mergesort(left_arr, left_len);
		int* sorted_right = mergesort(right_arr, right_len);

        printf("merging:\n");
        print_array(left_arr, left_len);
        print_array(right_arr, right_len);

        sorted_arr = merge(sorted_left, sorted_right, left_len, right_len);
        printf("merge result:\n");
        print_array(sorted_arr, len);

        return sorted_arr;
    }else{
        return arr;
    }
}

void print_array(int* array, int len){
    printf("[");
    for(int i=0; i<len; i++){
        printf("%d, ", array[i]);
    }
    printf("]\n");
}

/// @brief Compares two arrays of the same size
/// @param a first array
/// @param b second array
/// @param len length of the arrays
/// @return 1 if they are the same, 0 otherwise
int compare_array(int* a, int* b, unsigned int len) {
    for(int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            printf("Comparison of arrays failed:\n");
            print_array(a, len);
            print_array(b, len);
            return 0;
        }
    }
    return 1;
}
	
int* copy_array(int* arr, unsigned int len){
    int* copy = (int*)malloc(len * sizeof(int));
    for(int i = 0; i < len; i++){
        copy[i] = arr[i];
    };
    return copy;
}