#include <stdio.h>
#include "dynarray.h"
#include "book.h"

book create_me_a_book() {
    char otherName[20] = "Lord of the Rings";
    char authorA[20] = "Tolkien";
    book otherBook = create_book(otherName, authorA, 2001);
    return otherBook;
}

char prompt_user(){
    char control;
    printf("Type Q to quit, A to add book, R to remove a book, and L to list all books: \n");
    scanf(" %c", &control);
    return control;
}

book get_book_input(){
    int userYear;
    char userBook[30];
    char userAuthor[30];

    printf("Enter the book name: \n");
    scanf("%s", userBook);

    printf("Enter the author name: \n");
    scanf("%s", userAuthor);

    printf("Type a year: \n");
    scanf("%d", &userYear);
    book newBook = create_book(userBook, userAuthor, userYear);

    return newBook;
}



int main() {

    printf("Size of book: %ld\n", sizeof(book));

    bookArr myBookArr = create_book_array(5);
    bookArr* myBookArrPtr= & myBookArr;

    char control = prompt_user();

    while (control != 'Q') {
        
        if(control == 'A'){
            book newBook = get_book_input();
            add_single_book(myBookArrPtr, newBook);
            
        }else if(control == 'R'){
            if(myBookArr.num_of_books ==0){
                printf("There is nothing to remove \n");
            }
            else{
                printf("This is the book list: \n");
                print_array(myBookArr);
                int removeNum;
                printf("Type the number of book to remove: \n");
                scanf("%d", &removeNum);
                remove_element(myBookArrPtr, removeNum);
            }
        }else if(control == 'L'){
            print_array(myBookArr);
        }else{
            break;
        }
        //printf("The control letter:  |%c|%d|\n", control, (int) control);
        control = prompt_user();
    }

    
    
    //add_single_book(myBookArrPtr, otherBook);
    
    //add_single_book(myBookArrPtr, otherBook);
    
   
    
    //add_single_book(myBookArrPtr, myBook);

    //print_array(myBookArr);

    
    //remove_element(myBookArrPtr, 0);
    //add_single_book(myBookArrPtr, otherBook);
    //print_array(myBookArr);

    //print_book(get(myBookArrPtr, 5));
    return 0;
}
