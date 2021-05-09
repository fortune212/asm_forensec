#include <stdio.h>


int main(){

    char* ascii = "0x006f252000782520";
    int i = strlen(ascii) - 2;
    char get[3] = "";
    get[2] = 0;

    while ('0' != ascii[i] && 'x' != ascii[i+1]){
        get[0] = ascii[i];
        get[1] = ascii[i+1];

        long n = strtol(get, NULL, 16);

        if (n > 31 && n < 127) printf("%c", n);
        else printf("[%x is not a char]", n);

        i-=2;
    }
    printf("\n");

    return 0;
}