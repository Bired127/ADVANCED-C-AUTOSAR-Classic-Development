// Con trỏ hằng
/*
Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference những địa chỉ trỏ đến có thể thay đổi.
0x01 (10) -> Đọc giá trị 10, không được phép thay đổi
0x02 (20) -> Đọc giá trị 20, không được phép thay đổi
Cú pháp:
    <data_type> const *ptr_const;
    const <data_type> *ptr_const;
*/
#include <stdio.h>
