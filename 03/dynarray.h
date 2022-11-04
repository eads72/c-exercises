typedef struct Book{
    char* name;
    int year;
} book;

typedef struct BookArr{
    book* bookPtr;
    int buffer_length;
    int num_of_books;
} bookArr;

int dummy();
book create_book(char* name, int year);
bookArr create_book_array(int length);
int print_book(book book);
void add_book(book aBook, bookArr* bookArray);
unsigned char add_single_book(bookArr* bookArray, book newBook);
void print_array(bookArr array);
book get(bookArr* array, int what_you_want);
book remove_element(bookArr* array, int index_of_book_to_be_removed);