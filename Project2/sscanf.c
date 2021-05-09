#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char str[] = "0";
   int str_[1];

   printf("str val char: %s\nreturn val: %d\nstr val int: %d\n", str, sscanf(str, " %x",  str_), str_);
    
   return(0);
}