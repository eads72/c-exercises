#include <stdio.h>
#include "dynarray.h"

int main() {
    char aName[10] = "Adam";
    book myBook = create_book(aName, 2009);

    bookArr myBookArr = create_book_array(5);
    bookArr* myBookArrPtr= & myBookArr;

    add_book(myBook, myBookArrPtr);
    print_book(myBookArr.bookPtr[0]);

    char otherName[10] = "Baybe";
    book otherBook = create_book(otherName, 2001);
    add_single_book(myBookArrPtr, otherBook);
    print_book(myBookArr.bookPtr[1]);
    print_array(myBookArr);
}
