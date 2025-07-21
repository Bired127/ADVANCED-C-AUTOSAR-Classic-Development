#include <stdio.h>
#define A 20
void test(){
    printf("This is the test function\n");
}

int main(){

    int a = A;
    printf("%d\n", a);
    test();
    return 0;
}