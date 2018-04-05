//
//  해싱으로 수 찾기 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 7..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MOD 997
#pragma GCC optimize("O3")
using namespace std;


template <typename T>
class _vector {
public:
    int c = 2, _size = 0;
    T* arr;
    
    _vector() {arr = new T[c];}
    ~_vector() {delete[] arr;}
    
    void resize(int n) {
        T* temp = new T[n*2];
        for(int i=0; i<_size; i++) temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        c *= 2;
    }
    
    void push_back(T data) {
        if(_size == c) resize(c);
        arr[_size++] = data;
    }
    
    int size() { return _size; }
    T* begin() { return &arr[0]; }
    T* end() { return &arr[0] + _size; }
    
    void clear() {
        c = 2; _size = 0;
        delete[] arr;
        arr = new T[c];
    }
    
    T operator [](int idx) {
        return arr[idx];
    }
};



_vector<int> hashTable[1003];

int abs(int a) {
    int tmp;
    if(a < 0) tmp = -a;
    else tmp = a;
    return tmp;
}

int main() {
    
    int n,a;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        int p =  abs(a);
        hashTable[p % MOD].push_back(a);
    }
    
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        int p = abs(a);
        
        int result = 0;
        int size = hashTable[p % MOD].size();
        for(int j=0; j<size; j++) {
            if(hashTable[p % MOD][j] == a) {
                result++;
                break;
            }
        }
        
        if (result > 0)
            printf("%d\n", 1);
        else
            printf("0\n");
        
    }
    return 0;
}
