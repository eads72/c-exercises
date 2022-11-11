#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynarray.h"
#include "book.h"


// takes name, year, author, and rating as paramteres and returns a book
book create_book(char* name, char* author, int year){
    
    book new_book;
    new_book.name = strdup(name);
    new_book.author = strdup(author);
    new_book.year = year;
    return new_book;
}

// takes a book as a paremeter and prints the book.
int print_book(book book){
    printf("The name of the book is: %s\n", book.name);
    printf("The author of the book is: %s\n", book.author);
    printf("The year of the book is: %d\n", book.year);
    return 1;
}
