#include <stdio.h>
#include "merge-sort.h"

int main(){

    //int array[] = {5, 5, 6, 0, 2, 1};
    //int* sorted = mergesort(array, 6);
    //print_array(sorted, 6);

    int left_array[] = {5, 1, 7, 0};
    //int right_array[] = {0, 6, 9};
    int* mergesorted = mergesort(left_array, 4);
    print_array(mergesorted, 4);
    return 0;
}