// extern_var.c
#include <stdio.h>

// Biến toàn cục có liên kết ngoài (external linkage)
int globalVar = 10;

// Hàm sử dụng biến toàn cục
void printGlobalVar() {
    printf("GlobalVar = %d\n", globalVar);
}
