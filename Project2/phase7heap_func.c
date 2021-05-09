#include <stdio.h>

int phase7heap_func(int arg1, int arg2){
  if (arg2 <= arg1) return arg1;
  return (arg2 - arg1 + 4);
}


int main(){

    int arg1[] = {10, 18, 1};
    int arg2[] = {205, 56, 0};

    for (int i = 0; i < 3; i++){
        int ret = phase7heap_func(arg1[i], arg2[i]);
        printf("arg1: %d, arg2: %d, return val: %d(0x%x)\n\n", arg1[i], arg2[i], ret, ret);
    }

    return 0;
}