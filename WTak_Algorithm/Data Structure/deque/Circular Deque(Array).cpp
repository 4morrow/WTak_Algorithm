//
//  Circular Deque(Array).cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 30..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <cstdio>
#define MAX_QUEUE_SIZE 100

class CircularQueue {
public:
    int head;
    int tail;
    int data[MAX_QUEUE_SIZE];
    CircularQueue() { head = tail = 0; }
    bool isEmpty() { return head == tail; }
    bool isFull() { return (tail + 1) %  MAX_QUEUE_SIZE == head; }
    
    void push(int e) {
        if(isFull()) {
            printf("포화 상태입니다\n");
            return;
        }
        tail = (tail + 1) % MAX_QUEUE_SIZE;
        data[tail] = e;
    }
    
    int pop() {
        if(isEmpty()) {
            printf("공백 상태입니다\n");
            return 0;
        }
        head = (head + 1) % MAX_QUEUE_SIZE;
        return data[head];
    }
    
    int front() {
        if(isEmpty()) {
            printf("공백 상태입니다\n");
            return 0;
        }
        return data[(head + 1) % MAX_QUEUE_SIZE];
    }
    
    void display() {
        printf("큐 내용 : ");
        int maxi = (head < tail) ? tail : tail+MAX_QUEUE_SIZE;
        for(int i=head+1; i<=maxi; i++) {
            printf("[%2d] ",data[i%MAX_QUEUE_SIZE]);
        }
        puts("");
    }
};


class CircularDeque : public CircularQueue {
public:
    CircularDeque() {}
    void addRear(int e) { push(e); }    // 후단 삽입
    int  deleteFront() { return pop(); } // 전단 삭제
    int getFront() { return front(); } // 전단 확인
    void addFront(int e) {              // 전단 삽입
        if(isFull()) {
            printf("포화 상태입니다.\n");
            return;
        }
        data[head] = e;
        head = (head-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
    int deleteRear() {                  // 후단 삭제
        if(isEmpty()) {
            printf("공백 상태입니다.\n");
            return 0;
        }
        int ret = data[tail];
        tail = (tail-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        return ret;
    }
    int getRear() {                 // 후단 확인
        if(isEmpty()) {
            printf("공백 상태입니다.\n");
            return 0;
        }
        return data[tail];
    }
    void display() {
        printf("덱의 내용 : ");
        int maxi = (head < tail) ? tail : tail + MAX_QUEUE_SIZE;
        for(int i=head+1; i<=maxi; i++) {
            printf("[%2d] ",data[i%MAX_QUEUE_SIZE]);
        }
        puts("");
    }
};

int main() {
    CircularDeque deq;
    for(int i=1; i<10; i++) {
        if(i%2) deq.addFront(i);
        else deq.addRear(i);
    }
    deq.display();
    deq.deleteFront();
    deq.deleteRear();
    deq.deleteRear();
    deq.display();
    
    return 0;
}
