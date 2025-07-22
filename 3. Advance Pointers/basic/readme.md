CON TRỎ C

1. CON TRỎ C LÀ GÌ ?

    Con trỏ được hiểu là biến có chức năng lưu trữ địa chỉ của biến khác và thay đổi giá trị tại địa chỉ mà con trỏ trỏ tới.

    Kích thước con trỏ trong hệ điều hành 64 thì là 8 bytes;
    Kích thước con trỏ trong hệ điều hành 32 thì là 4 bytes;

    Note: Kích thước này không thay đổi cho bất kỳ kiểu dữ liệu nào trong C.

    Code ví dụ để biết cách khai báo con trỏ và sử dụng con trỏ cho biến.
    Input:
    int main() {
        
        int a = 3;
        
        int *ptr = &a;
        printf("In ra giá trị của a thông qua con trỏ: %d\n", *ptr);
        printf("In ra địa chỉ của a thông qua con trỏ: %p", ptr);
        return 0;
    }

    Output:
    In ra giá trị của a thông qua con trỏ: 3
    In ra địa chỉ của a thông qua con trỏ: 0x7ffde40392e4

    Ở ví dụ trên ta thấy con trỏ ptr đang lưu địa chỉ của biến a ở bộ nhớ RAM và địa chỉ của a là 0x7ffde40392e4, Khi ta muốn xuất giá trị của a thì ta chỉ cần dùng cú pháp *ptr.

2. Con trỏ NULL 

    Con trỏ NULL có thể hiểu đơn giản là nó không trỏ tới bất kỳ cái gì hết và bộ nhớ sẽ cấp phát một vùng nhớ riêng dành cho con trỏ NULL này.

    2.1- Tại sao lại cần con trỏ NULL ?

        Việc sử dụng con trỏ NULL nhằm tránh việc trong lúc lập trình hoặc so xuất của coder mà con trỏ vô tình trỏ tới một địa chỉ nào đó mà người lập trình không hay biết mà lỗi này sẽ dẫn đến các hậu quả rất nghiêm trọng trong hệ thống.

        Con trỏ NULL thường được dùng trong các hàm có parameter là con trỏ nhằm tránh phát sinh lỗi.

        Ví dụ:

        void swap(int *a, *int b){
        if(a == NULL || b == NULL){
            printf("Error NULL pointer!")
            return;
            }   
        int temp = *a;
        *a = *b;
        *b = temp;
        }

        Việc kiểm tra trên nhằm đảm bảo con trỏ không trỏ sai, giống như việc sử dụng xong thì cần phải đặt lại vị trí đúng để tránh bị mất hoặc khó khăn khi tìm lại vậy.

3. Con trỏ Void

    Thông thường theo cách cơ bản khi ta muốn trỏ tới biến kiểu int thì ta cần khai báo con trỏ kiểu int và tương tự cho các kiểu dữ liệu khác.

    Nhưng chuyện gì sẽ xảy ra nếu ta có quá nhiều kiểu dữ liệu khác nhau trong cùng 1 file, nếu ta khai báo từng con trỏ thì sẽ bị mất thời gian và tốn tài nguyên bộ nhớ. Mà việc quản lý tài nguyên bộ nhớ là vấn đề rất quan trọng trong hệ thống nhúng. 

    ==> Con trỏ Void ra đời.

    Con trỏ Void có chức năng đặt biệt đó là nó được phép trỏ tới bất kỳ kiểu dữ liệu nào mà nó muốn nhưng với điều kiện đó là nếu muốn sử dụng thì cần phải ép kiểu con trỏ thì mới dùng được.

    ví dụ:
    Input:
    int main() {
    int a = 3;
    void *ptr = &a;
    printf("In ra giá trị của a thông qua con trỏ void : %d\n", *(int *)ptr);
    return 0;
    }

    Output:
    In ra giá trị của a thông qua con trỏ void : 3

4. Con trỏ Const

    Thường được gọi là con trỏ hằng, con trỏ hằng có điểm khác biệt so với các con trỏ khác đó là nó chỉ trỏ đến địa chỉ để đọc giá trị của biến nó trỏ đến nhưng không được thay đổi giá trị của biến đó.

    Một con trỏ hằng có thể trỏ đến nhiều địa chỉ khác và chỉ để đọc chứ không thay đổi giá trị.

    ví dụ:
    Input:

    int main() {
    int a = 3;
    const int *ptr = &a;
    *ptr = 5;
    printf("In ra giá trị của a thông qua con trỏ void : %d\n", *ptr);
    return 0;
    }

    Output:
    error: assignment of read-only location '*ptr

    Lỗi trên sẽ hiện lên khi ta cố thay đổi giá trị của biến bằng con trỏ hằng.

    4.1- Tại sao lại cần con trỏ hằng ?

        Việc sử dụng con trỏ hằng giúp người lập trình tránh các lỗi vô tình thay đổi giá trị của biến mà nó trỏ tới trong quá trình làm việc.

5. Con trỏ cấp 2

    Con trỏ cấp 2 được hiểu là một biến lưu trữ địa chỉ của một con trỏ khác.

    ví dụ: 
    int x = 10;
    int *p = &x;  // p là con trỏ cấp 1, lưu địa chỉ của x
    int **pp = &p; // pp là con trỏ cấp 2, lưu địa chỉ của p

    5.1. Cách sử dụng con trỏ cấp 2

    Input:
    int main() {
    int x = 10;
    int *p = &x;   // p trỏ tới x
    int **pp = &p; // pp trỏ tới p

    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp); // truy cập tới giá trị của x thông qua pp

    return 0;
    }

    Output:
    x = 10
    *p = 10
    **pp = 10

    5.2. Tại sao lại cần con trỏ cấp 2
    - Quản lý mảng con trỏ.
    - Truyền tham chiếu đến con trỏ vào hàm.
    - Mảng 2 chiều hoặc các cấu trúc dữ liệu phức tạp.


    