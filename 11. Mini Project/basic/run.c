#include "main.c"

int main(){
    Queue queue1;
    int size = 5;
    Init_Queue(&queue1,5);

    for(int i = 0; i < size; i++){
        int data = i + 2;
        enqueue(&queue1,data);
    }
    printf("front: %d\nrear: %d",getFront(queue1),getRear(queue1));
}