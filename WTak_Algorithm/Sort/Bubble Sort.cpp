//
//  Bubble Sort.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//

// 시간복잡도 O(n^2)

#include <stdio.h>
#define SWAP(a,b,type) do{type temp; temp = a; a = b; b = temp;}while(0);
enum {
    MIN,
    MAX
};


// Bubble Sort

void bubbleSort(int *arr, int len, int type) {
    
    // Min Bubble Sort
    if(type == MIN) {
        
        for(int i=len-1; i>=0; i--) {
            for(int j=0; j<i; j++) {
                if(arr[j] > arr[j+1]) {
                    SWAP(arr[j],arr[j+1],int);
                }
            }
        }
        
    }
    
    // Max Bubble Sort
    else if(type == MAX) {
        
        for(int i=len-1; i>=0; i--) {
            for(int j=0; j<i; j++) {
                if(arr[j] < arr[j+1]) {
                    SWAP(arr[j],arr[j+1],int);
                }
            }
        }
        
    }
}

void print_arr(int *arr, int len) {
    for(int i=0; i<len; i++) printf("%d ",arr[i]);
    puts("");
}


int main() {
    int arr[5] = {3,1,4,5,2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, len, MIN);
    print_arr(arr, len);
    
    bubbleSort(arr, len, MAX);
    print_arr(arr, len);
    
    
    return 0;
}
