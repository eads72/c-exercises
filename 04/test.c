#include <stdio.h>
#include <assert.h>
#include "merge-sort.h"

void test_compare() {
    assert(EQUAL == compare(0, 0));
    assert(FIRST_BIGGER == compare(1, 0));
    assert(SECOND_BIGGER == compare(0, 1));
}

void test_merge(){
    if(1) {
        int a1[] = {0};
        int a2[] = {1};
        int r1[] = {0, 1};
        int* r2 = merge(a1, a2, 1, 1);
        assert(compare_array(r1, r2, 2));
    }
    if(1) {
        int a1[] = {0, 1};
        int a2[] = {2, 3};
        int r1[] = {0, 1, 2, 3};
        int* r2 = merge(a1, a2, 2, 2);
        assert(compare_array(r1, r2, 4));
    }
    if(1) {
        int a1[] = {0, 2};
        int a2[] = {1, 3};
        int r1[] = {0, 1, 2, 3};
        int* r2 = merge(a1, a2, 2, 2);
        assert(compare_array(r1, r2, 4));
    }
    if(1) {
        int b3[] = {3, 8, 9};
        int b4[] = {1, 7, 12};
        int p3[] = {1, 3, 7, 8, 9, 12};
        int* p4 = merge(b3, b4, 3, 3);
        assert(compare_array(p3, p4, 6));
    }
    if(1) {
        int c3[] = {3, 8, 9};
        int c4[] = {2, 7, 9};
        int s3[] = {2, 3, 7, 8, 9, 9};
        int* s4 = merge(c3, c4, 3, 3);
        assert(compare_array(s3, s4, 6));
    }
    if(1) {
        int d3[] = {-8, 3, 9};
        int d4[] = {2, 7, 12};
        int q3[] = {-8, 2, 3, 7, 9, 12};
        int* q4 = merge(d3, d4, 3, 3);
        assert(compare_array(q3, q4, 6));
    }
    if(1) {
        int d3[] = {-9, 3, 8};
        int d4[] = {2, 7, 12};
        int q3[] = {-9, 2, 3, 7, 8, 12};
        int* q4 = merge(d3, d4, 3, 3);
        assert(compare_array(q3, q4, 6));
    }
    if(1) {
        int e3[] = {3, 8};
        int e4[] = {2, 7, 12};
        int t3[] = {2, 3, 7, 8, 12};
        int* t4 = merge(e3, e4, 2, 3);
        assert(compare_array(t3, t4, 5));   
    }
}

void test_mergesort(){
    if(1){
        int a[] = {1};
        int b[] = {1};
        int* c = mergesort(a, 1);
        assert(compare_array(c, b, 1));
    }
    if(1){
        int a[] = {5, 1};
        int b[] = {1, 5};
        int* c = mergesort(a, 2);
        assert(compare_array(c, b, 2));
    }
    if(1){
        int a[] = {5, 1, 2};
        int b[] = {1, 2, 5};
        int* c = mergesort(a, 3);
        assert(compare_array(c, b, 3));
    }
    if(1){
        int a[] = {5, 1, 2, -10};
        int b[] = {-10, 1, 2, 5};
        int* c = mergesort(a, 4);
        assert(compare_array(c, b, 4));
    }
    if(1){
        int a[] = {5, 5, 5, 5};
        int b[] = {5, 5, 5, 5};
        int* c = mergesort(a, 4);
        assert(compare_array(c, b, 4));
    }
    if(1){
        int a[] = {-20, -16, -12, -10};
        int b[] = {-20, -16, -12, -10};
        int* c = mergesort(a, 4);
        assert(compare_array(c, b, 4));
    }
    if(1){
        int a[] = {20, 16, 10, 5};
        int b[] = {5, 10, 16, 20};
        int* c = mergesort(a, 4);
        assert(compare_array(c, b, 4));
    }
    if(1){
        int a[] = {5, 15, 6, 1, 9, 9, 7};
        int b[] = {1, 5, 6, 7, 9, 9, 15};
        int* c = mergesort(a, 7);
        assert(compare_array(c, b, 7));
    }
}


int main() {
    test_compare();
    test_merge();
    test_mergesort();

    printf("tests done!\n");
    return 0;
}