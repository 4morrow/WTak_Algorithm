//
//  나이 정렬 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 2..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define SWAP(a,b,type) do{ type temp = a; a = b; b = temp; } while(0);
using namespace std;

int n;

typedef struct {
    int age;
    int idx;
    char name[101];
}Data;

Data user[100005];

bool cmp(Data &u, Data &v) {
    if(u.age == v.age) {
        return u.idx < v.idx;
    }
    return u.age < v.age;
}

void _qsort(Data *arr, int left, int right) {
    if(left > right) return;
    int L = left;
    int R = right;
    int mid = (left + right) / 2;
    Data pivot = arr[mid];
    
    while(L <= R) {
        while(cmp(arr[L],pivot)) L++;
        while(cmp(pivot, arr[R])) R--;
        if(L <= R) {
            SWAP(arr[L], arr[R], Data);
            L++;
            R--;
        }
    }
    
    if(left < R) _qsort(arr, left, R);
    if(L < right) _qsort(arr, L, right);
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d %s",&user[i].age, user[i].name);
        user[i].idx = i;
    }
    
    _qsort(user, 0, n-1);
    
    for(int i=0; i<n; i++) {
        printf("%d %s\n",user[i].age,user[i].name);
    }

    return 0;
}
