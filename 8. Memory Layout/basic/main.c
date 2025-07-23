#include <stdio.h>
#include <stdlib.h>

int g1 = 10;          // data segment
int g2;               // BSS segment

void test() {
    static int s = 5; // data segment
    int local = 7;    // stack
    printf("%d\n", local);
}

int main() {
    int x = 3;        // stack
    int *p = malloc(4 * sizeof(int)); // heap
    test();
    free(p);
    return 0;         // text segment
}
