//
//  좌표정렬하기 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 2..
//  Copyright © 2018년 WTak. All rights reserved.
//



#include <stdio.h>
#include <iostream>
#define SWAP(a,b,type) do{ type temp = a; a = b; b = temp; } while(0);
using namespace std;

typedef struct {
    int x,y;
}Data;

Data arr[100005];
int n;

bool cmp(const Data& u, const Data& v) {
    if(u.y == v.y) {
        return u.x < v.x;
    }
    return u.y < v.y;
}

void _qsort(Data *arr, int left, int right) {
    if(left > right) return;
    int L = left;
    int R = right;
    int mid = (left + right) /2;
    Data pivot = arr[mid];
    
    while(L <= R) {
        while(cmp(arr[L],pivot)) L++;
        while(cmp(pivot,arr[R])) R--;
        if(L <= R) {
            SWAP(arr[L], arr[R], Data);
            L++;
            R--;
        }
    }
    
    if(left < R) _qsort(arr, left, R);
    if(L < right) _qsort(arr,L,right);
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d %d",&arr[i].x, &arr[i].y);
    }
    
    _qsort(arr,0,n-1);
    
    for(int i=0; i<n; i++) {
        printf("%d %d\n",arr[i].x, arr[i].y);
    }
    
    
    return 0;
}
