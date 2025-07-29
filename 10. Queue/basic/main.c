#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
