//
//  LinkedList StudentStack.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 31..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX_STRING 100
using namespace std;


void str_cpy(char *arr, char *brr) {
    int idx;
    for (idx = 0; arr[idx] != 0; idx++) brr[idx] = arr[idx];
    brr[idx] = '\0';
}

class Student{
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];
public:
    Student() {}
    Student(int i, char* n, char* d) { set(i,n,d); }
    void set(int i, char* n, char* d) {
        id = i;
        strcpy(name, n);
        strcpy(dept, d);
    }
    void display() {
        printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n",id,name,dept);
    }
};

class Node : public Student {
    Node* link;
public:
    Node() {}
    Node(int id, char* name, char* dept) : Student(id,name,dept) {link = NULL;}
    ~Node(void) {}
    Node* getLink() { return link; }
    void setLink(Node *p) { link = p;}
};

class LinkedStack {
    Node* top;
public:
    LinkedStack() { top = NULL;}
    ~LinkedStack(){ while(!isEmpty()) delete pop(); }
    bool isEmpty() { return top == NULL; }
    
    void push(Node *p) {
        if(isEmpty()) top = p;
        else {
            p->setLink(top);
            top = p;
        }
    }
    
    Node* pop() {
        if(isEmpty()) return NULL;
        Node *p = top;
        top = top->getLink();
        return p;
    }
    
    Node* peek() { return top; }
    
    void display() {
        printf("[LinkedStack]\n");
        for(Node *p = top; p!= NULL; p=p->getLink()) {
            p->display();
        }
        puts("");
    }
    
};

int main() {
    
    LinkedStack stack;
    int id;
    char str[MAX_STRING];
    char dept[MAX_STRING];
    for(int i=0; i<3; i++) {
        scanf("%d",&id);
        scanf("%s",str);
        scanf("%s",dept);
        stack.push(new Node(20124973,str,dept));
    }
    stack.display();
    
    
    Node *node = stack.pop();
    printf("[Pop항목]\n");
    node->display();
    puts("");
    delete node;
    stack.display();
    
    return 0;
}


/*
 [testCase]
 
 20124973 차범근 컴퓨터공학과
 20142322 박지성 전자공학과
 20153435 손흥민 산업공학과
 */
