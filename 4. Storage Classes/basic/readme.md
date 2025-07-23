# Giải thích về `extern`, `static`, `volatile`, và `register` trong C

Trong ngôn ngữ lập trình C, các **storage classes** và **type qualifiers** như `extern`, `static`, `volatile`, và `register` giúp định nghĩa cách lưu trữ, phạm vi truy cập (scope), và hành vi của biến/hàm trong suốt chương trình.

---

## 1. `extern`

- **Mục đích:** Dùng để khai báo một biến hoặc hàm **được định nghĩa ở file khác hoặc ngoài khối hiện tại**.
- **Phạm vi (Scope):** Global (tầm vực toàn cục).
- **Thời gian tồn tại (Lifetime):** Tồn tại suốt chương trình.
- **Liên kết (Linkage):** External linkage (có thể được truy cập từ file khác).
- **Vị trí lưu trữ:** `Data segment` hoặc `BSS segment` (tùy có khởi tạo hay không).

**Ví dụ:**
```c
// file1.c
int globalVar = 10;

// file2.c
#include <stdio.h>
extern int globalVar;  // Chỉ khai báo, không tạo biến mới
int main() {
    printf("%d\n", globalVar);  // In ra 10
    return 0;
}

2. static
Mục đích:

Với biến cục bộ: Giữ giá trị của biến giữa các lần gọi hàm (chỉ khởi tạo 1 lần).

Với biến toàn cục hoặc hàm: Hạn chế phạm vi sử dụng trong nội bộ file (internal linkage).

Phạm vi (Scope):

Cục bộ: Trong block {} của hàm.

Toàn cục: Trong file .c định nghĩa.

Thời gian tồn tại (Lifetime): Suốt chương trình.

Vị trí lưu trữ: Data segment.

Ví dụ:

void counter() {
    static int count = 0; // Khởi tạo 1 lần
    count++;
    printf("Count = %d\n", count);
}
3. volatile
Mục đích: Thông báo cho compiler rằng giá trị của biến có thể thay đổi bất kỳ lúc nào do yếu tố bên ngoài (hardware, ISR, threads), do đó không được tối ưu hóa việc truy cập biến này.

Ứng dụng:

Biến được cập nhật trong hàm ngắt (ISR).

Biến ánh xạ thanh ghi phần cứng (memory-mapped registers).

Biến được dùng trong đa luồng (multithreading).

Ví dụ:

volatile int flag = 0;

void ISR() {  // ISR giả lập
    flag = 1;
}

int main() {
    while (flag == 0) {
        // Nếu không có volatile, compiler có thể tối ưu thành vòng lặp vô tận
    }
    return 0;
}
4. register

Mục đích: Gợi ý compiler lưu biến trong thanh ghi CPU để truy cập nhanh hơn (không đảm bảo).

Phạm vi (Scope): Trong block {}.

Thời gian tồn tại (Lifetime): Khi block {} còn hiệu lực.

Vị trí lưu trữ: CPU register (hoặc stack nếu không có thanh ghi khả dụng).

Hạn chế: Không thể lấy địa chỉ của biến register bằng toán tử &.

Ví dụ:

void example() {
    register int counter = 0;
    // printf("%p", &counter); // LỖI: không thể lấy địa chỉ của register variable
}