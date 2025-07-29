#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int Data;
    struct Node_t *pNext;
} NodeType;

NodeType *Head = NULL;

// Thêm Node vào vị trí đầu tiên
void insertAtBeginning(int Data){
    // Cấp phát bộ nhớ
    NodeType *pNewNode = (NodeType *)malloc(sizeof(NodeType));
    // Cập nhật data thêm vào
    pNewNode->Data = Data;
    // Chuyển địa chỉ node cũ
    pNewNode->pNext = Head;
    // cập nhật địa chỉ node mới cho head
    Head = pNewNode;
}

// Thêm Node vào vị trí cuối
void insertAtEnd(int Data){
    NodeType *pNewNode = (NodeType *)malloc(sizeof(NodeType));
    pNewNode->Data = Data;
    pNewNode->pNext = NULL;

    if(Head == NULL) // không có Node nào
    {
        Head = pNewNode; // thì trỏ tới Node đầu tiên
    }
    else
    {
        NodeType *temp = Head;
        while(temp->pNext != NULL){
            temp = temp->pNext;
        }
        temp->pNext = pNewNode;
    }
}

int main() {
    insertAtBeginning(17);
    insertAtBeginning(25);
    insertAtEnd(31);
    insertAtBeginning(2);

    printf("Linked List: ");
    NodeType *current = Head;
    while(current != NULL){
        printf("%d -> ", current->Data);
        current = current->pNext;
    }
    printf("NULL\n");

    return 0;
}
