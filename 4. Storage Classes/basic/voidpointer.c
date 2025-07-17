// Loại 1: void Pointer
#include <stdio.h>
int main(){
    double x= 3.7;
    int y = 9;
    char c = 'v';
    void *ptr;
    ptr = &x;
    printf("Giá trị của x: %f\n", *(double *)ptr);
    ptr = &y;
    printf("Giá trị của y: %d\n", *(int *)ptr);
    ptr = &c;
    printf("Giá trị của y: %c\n", *(char *)ptr);

    // mảng con trỏ
    void *ptr1[]={&x,&y,&c};
    printf("Giá trị của x: %f\n", *(double *)ptr1[0]);
    printf("Giá trị của y: %d\n", *(int *)ptr1[1]);
    printf("Giá trị của c: %c\n", *(char *)ptr1[2]);
    return 0;
}