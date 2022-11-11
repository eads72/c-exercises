#include <stdlib.h>
#include <stdio.h>
#include "dynarray.h"
#include "book.h"


// creates a book array struct with 0 books, returns the struct
bookArr create_book_array(int length){
    bookArr BookArr;
    BookArr.buffer_length = length;
    book* ptr;
    ptr = (book*)malloc(length*sizeof(book));
    BookArr.bookPtr = ptr;
    BookArr.num_of_books = 0;
    return BookArr;
}

// takes a book and a book arry, and adds the book to the end.
// This function does not reallocate the buffer length for the new book
void add_book(book aBook, bookArr* bookArray){
    int empty_slot = bookArray->num_of_books;
    bookArray->bookPtr[empty_slot] = aBook;
    bookArray->num_of_books++;
}

// takes a book and a book arry, and adds the book to the end
unsigned char add_single_book(bookArr* bookArray, book newBook){
    if(bookArray->buffer_length <= bookArray->num_of_books){
        unsigned int new_buffer_size = 2 * bookArray->buffer_length;
        unsigned int new_realloc_size = new_buffer_size * sizeof(book);

        book* new_array = (book*) realloc(bookArray->bookPtr, new_realloc_size);

        if (new_array == 0){
            return 0;
        }
        
        bookArray->buffer_length = new_buffer_size;
        bookArray->bookPtr = new_array;
    }

    bookArray->bookPtr[bookArray->num_of_books] = newBook;
    bookArray->num_of_books++;

    return 1;
}


void print_array(bookArr array){
    printf("Buffer length is: %d \n", array.buffer_length);
    printf("Number of books is: %d \n", array.num_of_books);
    
    for(int i = 0; i < array.num_of_books; i++){
        //printf("%d ", array.bookPtr[i]);
        print_book(array.bookPtr[i]);
    }
    printf("\n");
}

// Takes the book array pointer and the position of book as parameters,a nd returns the book
book get(bookArr* array, int what_you_want){

    if(what_you_want < array->num_of_books && what_you_want >= 0){
        return array->bookPtr[what_you_want];
    }
    
    printf("Invalid index: %d, size is %d. Terminating.\n", what_you_want, array->num_of_books);
    exit(1);
}

//Takes the book array pointer and the position of book as parameters
//Removes the book from the position and returns the book
book remove_element(bookArr* array, unsigned int index_of_book_to_be_removed){

    if(index_of_book_to_be_removed >= array->num_of_books){
        printf("The index %d is not valid, number of books is %d.\n", 
            index_of_book_to_be_removed, array->num_of_books);
        exit(1);
    }
    
    book removed_book = array->bookPtr[index_of_book_to_be_removed];

    for( int i = index_of_book_to_be_removed; i < array->num_of_books; i++){
        array->bookPtr[i] = array->bookPtr[i+1];
    }

    array->num_of_books--;

    if(array->buffer_length/2 >= array->num_of_books){
        unsigned int new_buffer_size = array->buffer_length/2;
        unsigned int new_realloc_size = new_buffer_size * sizeof(book);

        book* new_array = (book*) realloc(array->bookPtr, new_realloc_size);
        printf("reallocated\n");

        if (new_array == 0){
            printf("realloc failed\n");
        }
        
        array->buffer_length = new_buffer_size;
        array->bookPtr = new_array;
    }

    printf("Removed Book:");
    print_book(removed_book);
    return  removed_book;
}

/* int dummy() {
    char aName[10] = "Adam";
    book myBook = create_book(aName, 2009);

    print_book(myBook);

    return sizeof(book);
}*/
