//
//  Array StudentStack.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX_STRING 100
#define MAX_STACK_SIZE 100


// 문자열 복사 함수 구현
int _strcpy(char *str1, char * str2) {
    int i;
    for(i=0; str2[i] != '\0'; i++) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
    return 0;
}



// 학생 정보
class Student {
    int id;                     // 학번
    char name[MAX_STRING];      // 이름
    char dept[MAX_STRING];      // 학과
public:
    Student() {
        id = 0;
        name[0] = '\0';
        dept[0] = '\0';
    }
    Student(int i, char *n, char *d) {
        id = i;
        _strcpy(name, n);
        _strcpy(dept, d);
    }
    
    void display() {
        printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n",id,name,dept);
    }
};

// 학생 정보 스택
class StudentStack {
    int top;
    Student data[MAX_STACK_SIZE];
public:
    StudentStack() { top = -1; }    // 스택 생성자
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE-1; }
    
    void push(Student e) {
        if(isFull()) {
            printf("Stack Overflow\n");
            return;
        }
        data[++top] = e;
    }
    
    Student pop() {
        if(isEmpty()) {
            Student p;
            printf("Stack Underflow\n");
            return p;
        }
        return data[top--];
    }
    
    Student peek() {
        if(isEmpty()) {
            Student p;
            printf("StackUnderflow\n");
            return p;
        }
        return data[top];
    }
    
    void display() {
        printf("[전체 학생의 수 = %2d]\n", top+1);
        for(int i=0; i<=top; i++) {
            data[i].display();
        }
        puts("");
    }
};

int main() {
    
    StudentStack stack;
    stack.push(Student(20114932, "차범근", "컴퓨터공학과"));
    stack.push(Student(20126784, "박지성", "컴퓨터공학과"));
    stack.push(Student(20132345, "손흥민", "컴퓨터공학과"));
    stack.display();
    stack.pop();
    stack.display();
    
    return 0;
}






