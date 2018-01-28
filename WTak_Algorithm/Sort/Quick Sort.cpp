//
//  Quick Sort.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//

// 시간복잡도 평균(N*logN) , 최악(N^2)

// pivot을 기준으로 부분리스트 2개로 나누고 순환 호출을 하면서
// 더이상 호출할 수 없을 때까지 진행한다.

#include <stdio.h>
#define SWAP(a,b,type) do{type temp; temp = a; a = b; b = temp;}while(0);
#define MAX_SIZE 10
enum {
    MIN,
    MAX
};

// Quick Sort

void quickSort(int *arr, int left, int right, int type) {
    
    if(left > right) return;
    int L = left;
    int R = right;
    int mid = (L + R) / 2;
    int pivot = arr[mid];
    
    while(L <= R) {
        
        // Min Quick Sort
        if(type == MIN) {
            while (arr[L] < pivot) L++;
            while (pivot < arr[R]) R--;
        }
        
        // Max Quick Sort
        else if(type == MAX) {
            while (arr[L] > pivot) L++;
            while (pivot > arr[R]) R--;
        }
        if (L <= R) {
            SWAP(arr[L], arr[R], int);
            L++;
            R--;
        }
    }
    
    if (L < right) quickSort(arr, L, right, type);
    if (left < R) quickSort(arr, left, R, type);
}


void print_arr(int *arr, int len) {
    for(int i=0; i<len; i++) printf("%d ",arr[i]);
    puts("");
}

int main() {
    
    int arr[MAX_SIZE] = {6,3,4,1,8,2,5,9,0,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, len);
    quickSort(arr, 0, len-1,MIN);
    print_arr(arr, len);
    quickSort(arr, 0, len-1,MAX);
    print_arr(arr, len);
    
    return 0;
}
