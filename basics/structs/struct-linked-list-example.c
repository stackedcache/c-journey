#include <stdio.h>
#include <stdlib.h>

// Node Struct 
struct Node{
    int data;
    struct Node *next; // Pointer to next node 
};

// Function to create a new node
struct Node* createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Print the List 
    struct Node *temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}
