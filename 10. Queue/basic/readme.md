# DATA STRUCTURE - Queue

# Queue là gì ?

- Queue là một dạng cấu trúc dữ liệu tuân theo nguyên tắc "First In First out", nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ được lấy ra đầu tiên.
- Các thao tác cơ bản trên hàng đợi bao gồm:
    + enqueue: Thêm phần tử vào cuối hàng đợi.
    + dequeue: Xóa phần tử từ đầu hàng đợi.
    + front: Đọc giá trị của phần tử đứng đầu hàng đợi.
    + rear: Đọc giá trị của phần tử đứng cuối hàng đợi.
    + Kiểm tra hàng đợi trong 2 trạng thái IsFull và IsEmpty.

# Cấu trúc hàng đợi trong C

Trong ngôn ngữ C, hàng đợi có thể được triển khai bằng mảng hoặc danh sách liên kết.

# Ứng dụng thực tế của Queue

Queue được sử dụng rộng rãi trong nhiều bài toán và hệ thống thực tế như:
- Hệ điều hành: Quản lý tiến trình scheduling.
- Giao tiếp dữ liệu: Bộ đệp buffer giữa các luồng hoặc giữa producer-consumer.
- Xử lý yêu cầu trong Server.
- Mô phỏng hệ thống: Xếp hàng trong siêu thị, ngân hàng,...

# Circular Queue

1. Circular Queue là gì ?
        
    Circular Queue là một biến thể nâng cao của hàng đợi tuyến tính, nơi phần tử cuối cùng được liên kết với phần tử đầu tiên để tạo thành một vòng.
    => Mục tiêu chính của Circular Queue là  tối ưu bộ nhớ và tránh lãng phí không gian sau nhiều lần enqueue và dequeue.

    Trong hàng đợi tuyến tính, sau nhiều lần dequeue, vùng nhớ đầu mảng không được tái sử dụng dẫn đến lãng phí. Circular Queue giải quyết vấn đề này bằng cách xoay vòng chỉ số front và rear khi đến cuối mảng.

    Code Demo:
    ~~~c
    #define MAX 5

    typedef struct {
        int items[MAX];
        int front, rear;
    } CircularQueue;

    void initialize(CircularQueue *q) {
        q->front = -1;
        q->rear = -1;
    }

    int isEmpty(CircularQueue *q) {
        return q->front == -1;
    }

    int isFull(CircularQueue *q) {
        return ((q->rear + 1) % MAX == q->front);
    }

    void enqueue(CircularQueue *q, int value) {
        if (isFull(q)) {
            printf("Queue is full\n");
            return;
        }

        if (isEmpty(q)) {
            q->front = q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX;
        }

        q->items[q->rear] = value;
    }

    int dequeue(CircularQueue *q) {
        if (isEmpty(q)) {
            printf("Queue is empty\n");
            return -1;
        }

        int data = q->items[q->front];

        if (q->front == q->rear) {
            q->front = q->rear = -1;  // Reset when last item is removed
        } else {
            q->front = (q->front + 1) % MAX;
        }

        return data;
    }
