//
//  최대힙.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 26..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


int heap[1000001];
int idx;

void SWAP(int &a, int &b) { int c = a; a = b; b = c; }
int pop() {
    
    int Root = heap[1];
    heap[1] = heap[idx];
    heap[idx--] = -2147463648;
    
    
    for (int i = 1; i * 2 <= idx;) {
        
        if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]) break;
        else if (heap[i * 2] > heap[i * 2 + 1]) { //왼쪽 자식과 오른쪽 자식 비교
            swap(heap[i], heap[i * 2]);
            i = i * 2; //왼쪽으로 이동
        }
        else {
            SWAP(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1; //오른쪽으로 이동
        }
        
    }
    heap[idx+1] = 0;
    return Root;
}

void add(int x) {
    
    idx++;
    heap[idx] = x;
    for (int i = idx; i>1; i /= 2) {
        if (heap[i / 2] < heap[i]) {
            swap(heap[i / 2], heap[i]);
        }
        else break;
    }
}

int main() {
    
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int a; scanf("%d",&a);
        if(a == 0) {
            if(idx == 0) {
                puts("0");
                continue;
            }
            printf("%d\n",pop()*-1);
        }
        else{
            add(-a);
        }
    }
    
    return 0;
}


