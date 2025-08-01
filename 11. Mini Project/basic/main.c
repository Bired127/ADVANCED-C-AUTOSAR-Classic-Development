#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY -1

//Tạo cấu trúc dữ liệu cho queue
typedef struct
{
    int *items;
    int size;
    int front;
    int rear;
} Queue;

//Khởi tại Queue
void Init_Queue(Queue *queue, int size)
{
    queue->items = (Queue *)malloc(sizeof(Queue));
    if(queue->items == NULL){
        printf("Vùng nhớ cấp phát không đủ");
        return;
    }
    queue->size = size;
    queue->front = queue->rear = -1;
}

//Kiểm tra Queue đang rỗng - Hàm trả ra True False
bool IsEmpty(Queue queue)
{
    return (queue.front == QUEUE_EMPTY);
}

//Kiểm tra Queue đang đầy - Hàm trả ra True False
bool IsFull(Queue queue)
{
    return (queue.rear == queue.size - 1);
}

//Thao tác thêm phần tử vào hàng đợi
void enqueue(Queue *queue,int Data)
{
    if(IsFull(*queue)){
        printf("Queue đã đầy!\n");
    }
    else{
        if(IsEmpty(*queue)){
            printf("Queue rỗng\n");
            printf("Bắt đầu cập nhật front và rear bằng 0\n");
            queue->front = queue->rear = 0;
            printf("Cập nhật thành công!\n");
        }
        else 
        {
            printf("Tăng chỉ số rear lên thêm 1\n");
            queue->rear++;
        }
        printf("Cập nhật Data vào cuối Queue, vị trí rear trỏ vào!\n");
        queue->items[queue->rear] = Data;
        printf("enqueue %d\t address: %p\n",queue->items[queue->rear], &queue->items[queue->rear]);
    }
}

//Thao tác xóa phần tử khỏi hàng đợi
void dequeue(Queue *queue)
{
    if(IsEmpty(*queue)){
        printf("Queue đang rỗng!\n Không thể xóa các phần tử");
        return;
    }
    else{
        printf("dequeue: %d\t %p",queue->items[queue->front],&queue->items[queue->front]);
        queue->items[queue->front] = 0;
        if(queue->front == queue->rear && queue->rear == queue->size-1){
            printf("front = rear và đang ở cuối hàng đợi");
            queue->front = queue->rear = -1;
        }
        else{
            queue->front++;
        }
    }
}

//Thao tác lấy phần tử ở đầu hàng đợi
int getFront(Queue queue)
{
    return IsEmpty(queue) ? QUEUE_EMPTY : queue.items[queue.front];
}

//Thao tác lấy phần tử cuối hàng đợi
int getRear(Queue queue)
{
    return IsEmpty(queue) ? QUEUE_EMPTY : queue.items[queue.rear];
}

//Thao tác in toàn bộ phần tử hàng đợi
void printQueue(Queue queue)
{
    if(IsEmpty(queue)){
        printf("Queue rỗng!\n");
        return;
    }
    else{
        int i = queue.front;
        printf("Queue: ");
        while(1){
            printf("%d\n",queue.items[i]);
            if(i == queue.rear) break;
            i++;
        }
        printf("\n");
    }
}

//Giải phóng hàng đợi
void freeQueue(Queue *queue){
    if(queue->items != NULL){
        free(queue->items);
        queue->items = NULL;
    }
    queue->front = queue->rear = -1;
    queue->size = 0;
}