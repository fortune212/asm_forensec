/*
    pattern = i(index) => v(value)

    input => output
    0 => 0
    1 => 1
    2 => 3
    3 => 6
    4 => 10
    5 => 15
    .
    .
    .
    i =>  5253

    (i)index => value[i] = (value[i-1] + i)

*/

#include <stdio.h>


int main(){
    int i = 0;
    int r = 5253;
    int v = 0;

    printf("index: %d, value: %d\n", i, v);
    for(i=1; v < r || i > 10000;i++){
        v = i + v;
        printf("index: %d, value: %d (%x)\n", i, v, v);
    }

    return 0;
}