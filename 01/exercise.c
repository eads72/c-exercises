#include <stdio.h>
#include <stdlib.h>

int get_length(unsigned char* aString){
   int i =0;
   int length = 0;
   while(aString[i]>0){
      length++;
      i++;
   }
   return length;
}

int main(){
   int buffer_length;
   printf("Type the legnth of the buffer: \n");
   scanf("%d", &buffer_length);
   //printf("%d", buffer_length);
   // unsigned char theString[buffer_length];
   unsigned char* string_buf = (unsigned char*) malloc(sizeof(unsigned char) * buffer_length);
   printf("Type a string: \n");
   scanf("%s", string_buf);
   //*theString = string_buf;
   printf("your pointer is : %p \n", (void *) string_buf);

   unsigned long long int ptr_as_int = (unsigned long long int) string_buf;
   printf("your pointer as a number is: %llu \n", ptr_as_int);
   printf("your string is: %s \n", string_buf);
   printf("length of the string is: %d \n", get_length(string_buf));
   printf("buffer size: %lu\n", sizeof(string_buf));
   free(string_buf);
}

