#include <stdio.h>

int *ptr_int; // con trỏ cho địa chỉ kiểu int
char *ptr_char; // con trở cho địa chỉ kiểu char
float *ptr_float; // con trỏ cho địa chỉ float
 
int main(){
    
    // lấy địa chỉ của một biến
    int x = 15;
    ptr_int = &x; // con trỏ ptr_int chứa địa chỉ của x

    // lấy giá trị của x thông qua con trỏ

    printf("giá trị của x : %d", *ptr_int);
}