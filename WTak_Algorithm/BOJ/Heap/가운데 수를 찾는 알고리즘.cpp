//
//  가운데 수를 찾는 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 7..
//  Copyright © 2018년 WTak. All rights reserved.
//
#include <iostream>
#include <cstdio>
using namespace std;

struct ELEMENT {
    int num;
};

class HEAP {
public:
    ELEMENT* arr;
    int sz;
    HEAP();
    HEAP(int size);
    ~HEAP();
    
    bool empty();
    ELEMENT top();
    void swap(ELEMENT& a, ELEMENT& b);
    void push(ELEMENT& a);
    void push(int num);
    void upheap();
    void pop();
    void downheap();
    
};

HEAP::HEAP() {
    
}
HEAP::HEAP(int size) {
    arr = new ELEMENT[size];
    sz = 0;
}

HEAP::~HEAP() {
    delete[] arr;
}

bool HEAP::empty() {
    return sz == 0;
}

ELEMENT HEAP::top() {
    return arr[1];
}


void HEAP::push(ELEMENT &a) {
    arr[++sz] = a;
    upheap();
}

void HEAP::push(int num) {
    arr[++sz] = {num};
    upheap();
}

void HEAP::swap(ELEMENT &a, ELEMENT &b) {
    ELEMENT tmp = a;
    a = b;
    b = tmp;
}

bool cmpele(const ELEMENT& a, const ELEMENT& b) {
    return a.num < b.num;
}

void HEAP::upheap() {
    int cur = sz;
    
    // 부모 노드가 존재하고, 부모와 현재노드를 바꿔야 하는 동안
    while(cur/2 > 0 && cmpele(arr[cur], arr[cur/2])) {
        // 두 노드를 교환하고 위로 올라간다.
        swap(arr[cur],arr[cur/2]);
        cur = cur/2;
    }
}


void HEAP::pop() {
    if(sz == 0) return;
    
    // 마지막 원소를 top자리에 놓는다. (사이즈감소)
    arr[1] = arr[sz--];
    
    //그 후, 내려가면서 heap속성을 만족시킨다.
    downheap();
}

void HEAP::downheap() {
    
    // top에서 시작한다. (top에 원소를 가져다 놨으므로)
    int cur = 1;
    
    // 현재 노드의 left 노드에 원소가 있는 동안.
    while(cur * 2 <= sz) {
        int target = cur * 2;
        
        // 오른쪽 원소와 왼쪽 원소 중 작은 쪽을 target으로 한다.
        if(cur * 2 + 1 <= sz && cmpele(arr[cur * 2 + 1], arr[cur * 2]))
            target = cur * 2 + 1;
        
        // 현재 원소와 target을 바꿔야 한다면, 바꾸고 내려간다
        if(cmpele(arr[target], arr[cur])) {
            swap(arr[target],arr[cur]);
            cur = target;
        }
        else
            break;

    }
    
}


using namespace std;

int main() {
    
    int n; scanf("%d", &n);
    HEAP maxHeap;
    HEAP minHeap;
    
    for (int i = 0; i < n; i++) {
        int inp; scanf("%d", &inp);
        
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(inp);
        }
        else {
            minHeap.push(-inp);
        }
        if (!minHeap.empty() && !maxHeap.empty() && -minHeap.top() < maxHeap.top()) {
            int a = maxHeap.top(), b = -minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(-a);
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}
