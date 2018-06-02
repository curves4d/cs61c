#include <stdio.h>
#include <string.h>

// you may ignore the following two lines
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
int f = 9324356;

int main(int argc, char** argv) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s\n",argv[i]);
    }
    return 0;
}