//
//  Selection Sort.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//

// 시간복잡도 O(N^2)


#include <stdio.h>
#define SWAP(a,b,type) do{type temp; temp = a; a = b; b = temp;}while(0);

enum {
    MIN,
    MAX
};

// Selection Sort
void selectionSort(int *arr, int len, int type) {
    
    // Min Selection Sort
    if(type == MIN) {
        for(int i=0; i<len-1; i++) {
            int minIdx = i;
            
            for(int j=i+1; j<len; j++) {
                if(arr[minIdx] > arr[j]) {
                    minIdx = j;
                }
            }
            SWAP(arr[i], arr[minIdx], int);
        }
    }
    
    // Max Selection Sort
    else if(type == MAX) {
        for(int i=0; i<len-1; i++) {
            int maxIdx = i;
            for(int j=i+1; j<len; j++) {
                if(arr[maxIdx] < arr[j]) {
                    maxIdx = j;
                }
            }
            SWAP(arr[i], arr[maxIdx], int);
        }
    }
    
}


void print_arr(int *arr, int len) {
    for(int i=0; i<len; i++) printf("%d ",arr[i]);
    puts("");
}



int main() {
    
    int arr[5] = {4,1,2,5,3};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    // Seletion sort
    selectionSort(arr, len, MIN);
    print_arr(arr, len);
    
    selectionSort(arr, len, MAX);
    print_arr(arr, len);
    
    puts("");
    
    return 0;
}

