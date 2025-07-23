// main.c
#include <stdio.h>

// Khai báo sử dụng biến và hàm từ file extern_var.c
extern int globalVar;        // extern variable
void printGlobalVar();       // extern function

// static global variable (chỉ sử dụng trong main.c)
static int staticGlobal = 100;

// volatile variable (giá trị có thể thay đổi bất ngờ)
volatile int flag = 0;

// Hàm đếm sử dụng static local variable
void countCalls() {
    static int callCount = 0; // Chỉ khởi tạo 1 lần, giữ giá trị giữa các lần gọi
    callCount++;
    printf("Function countCalls() has been called %d times.\n", callCount);
}

int main() {
    // register variable (trình biên dịch *gợi ý* lưu trong thanh ghi CPU)
    register int i;
    
    // In giá trị từ extern variable
    printGlobalVar();
    globalVar = 20;
    printGlobalVar();

    // Sử dụng static local variable
    countCalls();
    countCalls();
    countCalls();

    // Mô phỏng kiểm tra volatile flag
    printf("\nWaiting for flag to be set...\n");
    for (i = 0; i < 5; i++) {
        if (flag) {
            printf("Flag is set!\n");
            break;
        }
        printf("Loop %d: Flag = %d\n", i, flag);
    }

    printf("\nStatic global = %d\n", staticGlobal);
    return 0;
}
