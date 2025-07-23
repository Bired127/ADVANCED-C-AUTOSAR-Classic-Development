#include <stdio.h>
/* Ví dụ con trỏ NULL trong hàm có parameter là con trỏ */
void swap(int *a, int *b){
    if(a == NULL || b == NULL){
        printf("Error NULL pointer!");
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* Khai báo và sử dụng con trỏ cơ bản cho biến int */
int main() {
    int a = 3;
    int *ptr = &a;
    void *ptr1 = &a;
    printf("In ra giá trị của a thông qua con trỏ void : %d\n", *(int *)ptr1);
    printf("In ra giá trị của a thông qua con trỏ: %d\n", *ptr);
    printf("In ra địa chỉ của a thông qua con trỏ: %p", ptr);
    return 0;
}