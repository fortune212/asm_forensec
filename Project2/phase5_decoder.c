#include <stdio.h>
#include <stdlib.h>

/*cmp 112 & 122 & 105 & 110 & 116 & 102*/
int main(int argc, char** argv){

    if (argc < 2) {
        printf("no arg(s)\n");
        return;
    }

    int i;
    for (i=1; i< argc; i++){
        int arg = atoi(argv[i]);
        if (arg + 7 > 96 && arg + 7 > 122) printf("arg: %d => %d\n",arg, arg - 18);
        else if (arg > 96 && arg < 123) printf("arg: %d => %d\n",arg, arg + 7);
        else printf("%d exploded\n", arg);
    }

    return 0;
}