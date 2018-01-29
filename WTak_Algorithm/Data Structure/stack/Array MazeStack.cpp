//
//  Array MazeStack.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 29..
//  Copyright © 2018년 WTak. All rights reserved.
//

// Maze Search - Stack solution

#include <stdio.h>
#define MAX_STACK_SIZE 50
#define MAZE_SIZE 6

char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

typedef struct {
    int y,x;
}D;


// stack template 적용
template <typename T>
class ArrayStack{
    int top;
    T data[MAX_STACK_SIZE];
public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE-1; }
    
    void push(T e) {
        if(isFull()) {
            printf("Stack Overflow\n");
            return;
        }
        data[++top] = e;
    }
    
    T pop() {
        if(isEmpty()) {
            printf("Stack Underflow\n");
        }
        return data[top--];
    }
    
    T peek() {
        if(isEmpty()) {
            printf("Stack Underflow\n");
        }
        return data[top];
    }
};


// 갈 수 있는 위치 확인
bool isRange(int y, int x) {
    if( y < 0 || x < 0 || y >= MAZE_SIZE || x >= MAZE_SIZE) return false;
    else return map[y][x] == '0' || map[y][x] == 'x';
}

int main() {
    
    ArrayStack<D> Maze;
    D entry({1,0});
    Maze.push(entry);
    
    while(!Maze.isEmpty()) {
        D here = Maze.peek();
        Maze.pop();
        
        int r = here.y;
        int c = here.x;
        printf("(%d,%d) ",r,c);
        if(map[r][c] == 'x') {
            printf("미로 탐색 성공\n");
            return 0;
        }
        else {
            map[r][c] = '.';
            if(isRange(r-1, c)) Maze.push(D({r-1,c}));
            if(isRange(r+1, c)) Maze.push(D({r+1,c}));
            if(isRange(r, c-1)) Maze.push(D({r,c-1}));
            if(isRange(r, c+1)) Maze.push(D({r,c+1}));
        }
    }
    printf("미로 탐색 실패\n");
    return 0;
}

















