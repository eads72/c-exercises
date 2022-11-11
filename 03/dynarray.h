#ifndef _H_DYNARRAY
#define _H_DYNARRAY

#include "book.h"


typedef struct BookArr{
    book* bookPtr;
    int buffer_length;
    int num_of_books;
} bookArr;

int dummy();

bookArr create_book_array(int length);

void add_book(book aBook, bookArr* bookArray);
unsigned char add_single_book(bookArr* bookArray, book newBook);
void print_array(bookArr array);
book get(bookArr* array, int what_you_want);
book remove_element(bookArr* array, unsigned int index_of_book_to_be_removed);

#endif