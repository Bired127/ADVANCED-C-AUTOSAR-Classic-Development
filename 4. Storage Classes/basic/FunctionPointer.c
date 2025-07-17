#include <stdio.h>
/*
Với mỗi dạng của hàm thì ta phải khai báo dạng con trỏ hàm tương ứng như vậy
<return_type> (*func_pointer) (<data_type_1>, <data_type_2>);
*/
void func1(){
    printf("Đây là Function 1\n");
};
void func2(int x, double y){
    printf("%d - %f\n", x, y);
};
int  func3(int x){
    printf("%d", x);
};

int main(){
    // khai báo con trỏ hàm
    void (*ptr1)(); // chỉ trỏ đến được hàm kiểu void và không có tham số
    void (*ptr2)(int,double); // chỉ trỏ đến hàm void có tham số
    int  (*ptr3)(int);
    // gán địa chỉ cho con trỏ hàm
    ptr1 = func1;
    ptr2 = func2;
    ptr3 = func3;
    // gọi hàm thông qua con trỏ hàm
    func1();
    func2(2, 5.5);
    func3(4);
    //Mảng con trỏ hàm
    return 0;
}