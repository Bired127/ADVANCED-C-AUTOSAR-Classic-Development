STORAGE CLASSES

Tổng quan về Storage Classes

    Trong ngôn ngữ C, lớp lưu trữ giúp xác định phạm vi, thời gian tồn tại (lifetime), tính liên kết và vị trí lưu trữ của biến hoặc function. Chúng giúp trình biên dịch hiểu cách cấp phát bộ nhớ và cách truy cập biến trong chương trình.

    Có 4 lớp lưu trữ chính trong C:
    - extern
    - static
    - volatile
    - register

1. Extern

    - Dùng để khai báo biến hoặc hàm đã được định nghĩa ở file khác hoặc bên ngoài khối hiện tại.
    - Phạm vi truy cập theo nơi khai báo.
    - Thời gian tồn tại suốt chương trình.
    - Có thể truy cập từ file khác.
    - Vị trí lưu trữ: Data Segment hoặc BSS Segment tùy vào giá trị khởi tạo ban đầu.

    Ví dụ: 

    file1.c
    int globalVar = 10;

    file2.c
    #include <stdio.h>
    extern int globalVar; // khai báo để sử dụng biến từ file1.c
    int main() {
        printf("%d\n", globalVar);
        return 0;
    }

    Việc dùng từ khóa trên để báo cho trình biên dịch biết được là biến globalVar đã được định nghĩa từ file khác rồi.

2. Static

    - Chức năng chính:
        + Với biến cục bộ (local): Giữ nguyên giá trị của biến giữa các lần gọi hàm.
        + Với biến toàn cục (global): Giới hạn phạm vi sử dụng biến hoặc hàm trong file định nghĩa.
    - Phạm vi truy cập:
        + Với local static var: Trong hàm khai báo.
        + với global static var: Trong phạm vi file.c hiện tại
    - Thời gian tồn tại: Suốt chương trình (Lưu trong Data Segment)
    - Vị trí lưu trữ: Data segment của chương trình.

    #include <stdio.h>
    void count() {
        static int counter = 0; // chỉ khởi tạo 1 lần duy nhất
        counter++;
        printf("Counter = %d\n", counter);
    }

    int main() {
        count(); // Counter = 1
        count(); // Counter = 2
        count(); // Counter = 3
        return 0;
    }

    Có thể thấy biến Counter không bị khởi tạo lại giá trị vì khi dùng từ khóa static, trình biến dịch đã cấp cho biến 1 vùng nhớ riêng và tồn tại suốt runtime.

3. Volatile

    Chức năng của từ khóa Volatile là để thông báo cho trình biên dịch rằng giá trị của biến có thể thay đổi bất kỳ lúc nào ngoài sự kiểm soát của chương trình.

    Khi không dùng Volatile, tính năng optimize của trình biên dịch có thể giả định rằng biến giữ nguyên giá trị trong một khoảng thời gian nếu không gán giá trị mới.

    Khi dùng Volatile, bạn ra lệnh cho trình biên dịch không tối ưu hóa việc truy cập biến, nghĩa là mỗi lần truy cập biến đều đọc trực tiếp từ bộ nhớ thay vì từ bản sao trong register.

4. register

    - Đề nghị compiler lưu biến trong thanh ghi CPU để tăng tốc độ truy cập thay vì thông qua DMA.
    - Phạm vi truy cập: trong khối lệnh {}.
    - Thời gian tồn tại: Chỉ tồn tại khi khối lệnh được thực thi.
    - Vị trí lưu trữ: Trong thanh ghi CPU.

    Ví dụ:
    #include <stdio.h>
    void func() {
        register int counter = 0;
        // printf("%p", &counter); // LỖI: không thể lấy địa chỉ của register variable
        printf("%d\n", counter);
    }


