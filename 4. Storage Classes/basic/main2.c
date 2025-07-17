//Con trỏ và mảng
#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,5};
    /*Note:
    - địa chỉ của các biến trong mảng liền kề nhau
    - Số bytes của mảng: số lượng(5)*(sizeof(int))= 5*4 =20
    1: 0x01 0x02 0x03 0x04
    2: 0x05 0x06 0x07 0x08
    .
    .
    */
    int n = (sizeof(arr)/sizeof(arr[0]));
    int *ptr = arr;
    // ptr: vùng địa chỉ của phần tử 0
    // ptr + 1: vùng địa chỉ của phần tử 1
    // ptr + 2: vùng địa chỉ của phần tử 2
    // ptr + i.sizeof(data_type)
    for(int i =0;i < n; i++)
    {
        printf("Địa chỉ: %p  Giá trị: %d\n", ptr+i, *(ptr+i));
    }
    return 0;
}