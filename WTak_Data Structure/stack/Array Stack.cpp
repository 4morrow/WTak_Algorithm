//
//  Array Stack.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//


#include <cstdio>
#define MAX_STACK_SIZE 20

class ArrayStack {
    int top;
    int data[MAX_STACK_SIZE];
public:
    ArrayStack() { top = -1; }                          // 생성자
    ~ArrayStack() {}                                    // 소멸자
    
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE-1; }
    
    void push(int e) {
        if(isFull()) {
            printf("Stack Overflow\n");
            return;
        }
        data[++top] = e;
    }
    
    int pop() {
        if(isEmpty()) {
            printf("Stack Underflow\n");
            return -1;
        }
        return data[top--];
    }
    
    int peek() {
        if(isEmpty()) {
            printf("Empty\n");
            return -1;
        }
        return data[top];
    }
    
    void display() {
        for(int i=0; i<=top; i++) {
            printf("<%2d>",data[i]);
        }
        puts("");
    }
};


int main() {
    
    ArrayStack stack; // ArrayStack 객체 생성
    
    for(int i=0; i<10; i++) stack.push(i);
    
    stack.display();
    stack.pop(); stack.pop(); stack.pop();
    stack.display();
    
    return 0;
}


































