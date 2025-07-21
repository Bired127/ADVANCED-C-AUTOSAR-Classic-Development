COMPILER PROCESS

1- TẠI SAO LẠI CẦN COMPILER PROCESS ?

  Thông thường để có thể chạy được một file code bất kỳ thì ta cần phải chuyển đổi từ ngôn ngữ lập trình sang/
  ngôn ngữ máy để máy tính hoặc vi điều khiển có thể hiểu được.
  Vì vậy Compiler được tạo ra như một công cụ giúp lập trình viên có thể dễ dàng Build sang file hex dễ dàng/
  chỉ với một câu lệnh.

2- Compiler là gì ?

  Compiler thường được gọi là trình biên dịch được tạo ra nhằm chuyển đổi ngôn ngữ lập trình sang mã máy giúp/
  cho coder tiết kiệm thời gian.
  Trong bất kỳ IDE nào thì nhà phát triển cũng đều sẽ tích hợp 2 thứ cho người dùng :
  - Editer: Trình soạn thảo văn bản, nơi coder lập trình ngôn ngữ bậc cao
  - Trình biên dịch: Dùng để biên dịch code thành chuỗi nhị phân để máy có thể hiểu được

  Với File.c thì sẽ dùng trình GCC, File.cpp thì sẽ dùng trình G++.

3- Compiler hoạt động như thế nào ?

  3.1. Tiền xử lý (preprocessor)
  - Từ các file.h hoặc file.c sẽ được tạo ra thành file.i quá trình này gọi là tiền xử lý.

  Câu lệnh: gcc -E main.c -o main.i

  file main.i sẽ bỏ các command và copy các thông tin từ file include vào file chính
  Những cái nào được định nghĩa thông qua define sẽ đổi lại thành giá trị gốc như ban đầu.

  3.2. Biên dịch (Compiler)
  - Quá trình này sẽ chuyển file main.i thành file main.s
  
  Câu lệnh: gcc -S main.i -o main.s

  - File main.s thường được gọi là file assembly code, đây là ngôn ngữ gần mới mã máy nhất
  Đặc điểm của file main.s:
  - có thể thao tác trực tiếp với CPU, có thể điều khiển các thanh ghi thông qua các câu lệnh và gán giá trị hoặc thực hiện các phép toán.
  - Làm việc với các vùng nhớ cụ thể
  - Thao tác với phần cứng linh hoạt

  3.3. Assembler
  - Quá trình này chuyển từ file main.s thành file main.o , đây là file mã máy
  
  Câu lệnh: gcc -c main.s -o main.o

  3.4. Linker
  - Quá trình này sẽ liên kết lại toàn bộ file main.o thành file main.exe
  - Nếu có nhiều file.c thì cần phải liên kết lại thì mới gen ra file.exe nếu có include

  Câu lệnh: gcc main.o -o main

TÓM TẮT
- Có tổng cộng 4 bước chính : main.c |-gcc -E main.c -o main.i-> Preprocessor |-gcc -S main.i -o main.s-> Compiler |-gcc -c main.s -o main.o-> Assembler -gcc main.o -o main-> Linker -> main.exe