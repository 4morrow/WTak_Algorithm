//
//  linear queue(Array).cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 29..
//  Copyright © 2018년 WTak. All rights reserved.
//


// 선형 큐
#include <stdio.h>
#define MAX_QUEUE_SIZE 100

int linearQueue[MAX_QUEUE_SIZE];
int head = -1;
int tail = -1;

bool isEmpty() { return head == tail; }
bool isFull() { return tail == MAX_QUEUE_SIZE; }

void push(int e) {
    if(isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    linearQueue[tail++] = e;
}

int pop() {
    if(isEmpty()) {
        printf("Queue Underflow\n");
        return 0;
    }
    return linearQueue[head++];
}

int size() {
    return tail - head;
}

int front() {
    return linearQueue[head];
}

void display() {
    for(int i=head; i<=tail; i++) printf("[ %d] ",linearQueue[i]);
    puts("");
}

int main() {
    for(int i=1; i<8; i++) {
        push(i);
    }
    display();
    pop();
    pop();
    pop();
    display();
    
    return 0;
}




