//
//  Circular Queue(Array).cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 29..
//  Copyright © 2018년 WTak. All rights reserved.
//

// Linear Queue는 front와 rear값이 계속 증가만 한다는 문제가 있다.
// 즉, 언젠가 배열의 끝에 도달하고 배열의 앞부분이 비어도 더이상 삽입 X
// 그래서 Circular Queue 등장

#include <stdio.h>
#define MAX_QUEUE_SIZE 100

class CircularQueue {
    int head;
    int tail;
    int data[MAX_QUEUE_SIZE];
public:
    CircularQueue() { head = tail = 0;}
    bool isEmpty() { return head == tail;}
    bool isFull() { return (tail + 1) % MAX_QUEUE_SIZE == head; }
    
    void push(int e) {
        if(isFull()) {
            printf("Queue Overflow\n");
            return;
        }
        tail = (tail + 1) % MAX_QUEUE_SIZE;
        data[tail] = e;
    }
    
    int pop() {
        if(isEmpty()) {
            printf("Queue Underflow\n");
            return 0;
        }
        else {
            head = (head + 1) % MAX_QUEUE_SIZE;
            return data[head];
        }
    }
    
    int top() {
        if(isEmpty()) {
            printf("Qeueu Underflow\n");
            return 0;
        }
        return data[(head + 1) % MAX_QUEUE_SIZE];
    }
    
    void display() {
        int max_idx = (head < tail) ? tail : tail + MAX_QUEUE_SIZE;
        for(int i=head+1; i<=max_idx; i++) {
            printf("[%2d] ",data[i%MAX_QUEUE_SIZE]);
        }
        puts("");
    }

};


int main() {
    
    CircularQueue queue;
    for(int i=1; i<10; i++) {
        queue.push(i);
    }
    queue.display();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.display();
    
    return 0;
}























