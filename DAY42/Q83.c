//Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

int main() {
    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    
    while(!isQueueEmpty()) {
        push(dequeue());
    }

    
    while(!isStackEmpty()) {
        enqueue(pop());
    }

    
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
