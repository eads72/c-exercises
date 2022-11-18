#ifndef _H_MERGESORT
#define _H_MERGESORT

#define FIRST_BIGGER -1
#define SECOND_BIGGER 1
#define EQUAL 0

int compare(int num1, int num2);
int* merge(int* arr1, int* arr2, int len1, int len2);
int* mergesort(int* arr, int len);
void print_array(int* array, int len);
int compare_array(int* a, int* b, unsigned int len);
int* copy_array(int* arr, unsigned int len);

#endif