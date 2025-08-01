# MEMORY LAYOUT

TỔNG QUAN

    Memory layout trong C mô tả cách bộ nhớ của một chương trình khi chạy (runtime).

    Việc hiểu rõ cách tổ chức bộ nhớ trong máy hoặc vi điều khiển là việc rất quan trọng vì nó liên quan trực tiếp đến quản lý hiệu năng, bảo mật và quản lý tài nguyên.

1. CÁC VÙNG BỘ NHỚ TRONG MỘT CHƯƠNG TRÌNH C

    Khi chương trình được load vào RAM để thực thi mã lệnh, bộ nhớ được chia thành các phân vùng chính như sau theo địa chỉ từ thấp đến cao:
    - Text Segment.
    - Data Segment.
    - BSS segment.
    - Heap: Khi ta dùng cấp phát động bộ nhớ.
    - Stack: Khi ta gọi hàm, biến cục bộ, địa chỉ trả về.

2. Text Segment.

    - Chứa mã máy của chương trình.
    - Dữ liệu trong vùng này là "chỉ đọc" read-only để tránh lỗi vô tình ghi đè code.
    - Chứa các hàm (function) do người lập trình viết và code của thư viện liên kết.

    Ví dụ:
    
    int main() {
        return 0;  // lệnh này nằm trong text segment
    }

3. Data Segment.

    - Chứa các biến toàn cục (Global) và biến Static có giá trị khởi tạo ban đầu khác 0.
    - Dữ liệu được lưu trong file exe sẽ được load vào RAM khi chương trình khởi động.

    Ví dụ: 

    // Biến nằm ngoài hàm main
    int a = 10;       // a nằm ở data segment.
    static int b = 5; // b nằm ở data segment.

4. BSS Segment

    - Vùng này cũng có phần giống như Data Segment là chứa các biến Global hoặc Static nhưng giá trị khởi tạo ban đầu phải bằng 0.
    - Hệ điều hành sẽ tự động gán giá trị 0 cho chúng khi load chương trình.

    Ví dụ:

    int c;       // c nằm ở BSS segment.
    static int d;// d nằm ở BSS Segment.

5. Heap

    - Dùng cho cấp phát bộ nhớ động (dynamic memory) bằng cách sử dụng các hàm malloc(), calloc(), realloc() trong C cung cấp.
    - Bộ nhớ ở Heap tăng dần lên phía trên, được quản lý thủ công.
    - Cần phải giải phóng free() bộ nhớ cấp phát sau khi sử dụng xong.
    Note: Nếu quên free(), sẽ bị memory leak.

    Ví dụ:

    int *p = (int*) malloc(10 * sizeof(int)); // cấp phát trên heap

    Code trên cho ta biết người lập trình muốn cấp phát 10 ô nhớ với mỗi ô có kích thước là 4 byte kiểu int.

    Thông thường các hàm cấp phát động luôn trả về con trỏ Void, nên ta cần phải ép kiểu "(int *)" con trỏ này để có thể sử dụng được.

6. Stack

    - Chứa các biến cục bộ (biến local) là biến nằm trong hàm, các tham số hàm (parameter), địa chỉ trả về.
    - Hoạt động theo cơ chế LIFO (Last In First Out) tức là ai vào sau thì người đó được ra trước.
    - Tự động cấp phát và giải phóng khi hàm được gọi hoặc kết thúc.
    
    Ví dụ:

    void check() {
        int x = 10;  // x nằm trên stack
        return &x;
    }

    Nếu chạy đoạn code trên sẽ bị lỗi Segment Faild do ta cố găng truy cập địa chỉ của một biến sau khi nó được giải phóng.

    Để tránh trường hợp này ta có 2 cách:
    - Dùng static
    - Dùng cấp phát động trong Heap

7. KEY WORD TRỌNG TÂM

    - Biến global và static nằm trọng data segment hoặc BSS segment (tồn tại trong suốt chương trình).
    - Biến local nằm trên stack (tự động giải phóng khi hàm kết thúc).
    - malloc/free làm việc với heap và được quản lý thủ công.
    - Code Segment là Read-only, còn stack và heap có thể ghi.