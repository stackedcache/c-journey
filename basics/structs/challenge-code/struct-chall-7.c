#include <stdio.h>
#include <stdlib.h>

// CHALLENGE 7 - Linked List 
/*
    - Implement a singly linked list node struct (ProcessNode) representing OS Processes including:
        - Process ID
        - Priority 
        - Status Pointer to next node 

    - Create a simple linked list of 3 nodes and traverse it, printing each node's data.
*/

struct ProcessNode{
    int process_id;
    int priority;
    struct ProcessNode *next; // Pointer to next process 
};

/* SYNTAX NOTES:
    The below syntax struct ProcessNode* createProcess(...) means:
        - This is a function that returns a pointer to a ProcessNode struct.
        - Whenever this function is called, it returns a pointer to a newly created `ProcessNode`.

        - struct ProcessNode *newProcess
            - creates a pointer variable newProcess that stores the memory address of the newly allocated struct. 
        
        -(struct ProcessNode*)malloc(..) --> casting because malloc returns void pointe.
            - We cast it so it becomes a pointer to our struct.
*/

// Function to create processes (nodes) 
struct ProcessNode* createProcess(int pid, int priority){
    struct ProcessNode *newProcess = (struct ProcessNode*)malloc(sizeof(struct ProcessNode));
    newProcess->process_id = pid;
    newProcess->priority = priority;
    newProcess->next = NULL;
    return newProcess;
}

// Functon to delete process by PID 
struct ProcessNode* deleteProcess(struct ProcessNode *head, int pid){
    struct ProcessNode *temp = head;
    struct ProcessNode *prev = NULL;

    // CASE 1; Process to delete is the head 
    if (head != NULL && head->process_id == pid) {
        head = head->next; // Move head to the next node 
        free(temp); // Free the old head 
        return head; // Return the new head 
    }

    // CASE 2; Search for the process in the list 
    while (temp != NULL && temp->process_id != pid){
        prev = temp; // Keep track of previous node 
        temp = temp->next; // Move to the next node 
    }

    // If process is not found, return unchanged list 
    if (temp == NULL) return head;

    // Case 3; Process is in the middle or end
    prev->next = temp->next; // unlink the node from the list 
    free(temp);

    return head; // Return the updated head 

}

// Function to free all processes 
void freeProcessList(struct ProcessNode *head){
    struct ProcessNode *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    struct ProcessNode *head = createProcess(25, 5);
    head->next = createProcess(26, 1);
    head->next->next = createProcess(27, 4);

    // Printing the structs 
    struct ProcessNode *temp = head;
    while (temp != NULL){
        printf("PID: %d, PRIOR: %d\n", temp->process_id, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n\n");

    // Delete process with ID 25
    head = deleteProcess(head, 27);
    
    // Printing the structs
    struct ProcessNode *temp1 = head;
    while (temp1 != NULL){
        printf("PID: %d, PRIOR: %d\n", temp1->process_id, temp1->priority);
        temp1 = temp1->next;
    }
    printf("NULL\n");

    // Free all memory 
    freeProcessList(head);

    return 0;
}


/* LEARNING NOTES: 

    - This is an advanced concept. 
    - The key thing to understand is that linked lists are structs which have a member that is a 
    pointer to the next instance of the same struct.

    - By using this pointer, you can create and traverse across members in the list.

    - The last member is NULL, signifying the end of the list.

    - When you get into larger number, like say 1000 processes, or logged in members, you need to use 
    more efficient methods such as hash tables, additional pointers, etc. to traverse/insert/delete more efficiently.

    - Leaving this challenge as is as a reference for now, and will visit linked lists again as learning progresses.

*/
