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
   // unsigned char theString[buffer_length];
   unsigned char* string_buf = (unsigned char*) malloc(buffer_length);
   printf("Type a string: \n");
   scanf("%s", string_buf);
   //*theString = string_buf;
   printf("your pointer is : %p \n", string_buf);
   printf("your pointer as a number is: %hhn \n", string_buf);
   printf("your string is: %s \n", string_buf);
   printf("length of the string is: %d \n", get_length(string_buf));
   printf("buffer size: %lu\n", sizeof(string_buf));
   free(string_buf);
}

