#ifndef _H_BOOK
#define _H_BOOK

typedef struct Book{
    char* name;
    char* author;
    int year;
} book;

book create_book(char* name, char* author, int year);
int print_book(book book);

#endif
