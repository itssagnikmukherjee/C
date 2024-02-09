#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", data);
}

int isEmpty() {
    return top == NULL;
}

void pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    display();
    return 0;
}