//
//  Insertion Sort.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//

// 시간복잡도 O(N^2)
// 정렬되어있는 경우 O(N)

#include <stdio.h>
#define SWAP(a,b,type) do{type temp; temp = a; a = b; b = temp;}while(0);


enum {
    MIN,
    MAX
};

// Insertion Sort
void insertionSort(int *arr, int len, int type) {
    
    // Min Insertion Sort
    if(type == MIN) {
        for(int i=1; i<len; i++) {
            int key = arr[i], position = i;
            while(position > 0 && key < arr[position-1]) {
                SWAP(arr[position],arr[position-1],int);
                position--;
            }
        }
    }
    
    // Max Insertion Sort
    else if(type == MAX) {
        for(int i=1; i<len; i++) {
            int key = arr[i], positon = i;
            while(positon > 0 && key > arr[positon-1]) {
                SWAP(arr[positon], arr[positon-1], int);
                positon--;
            }
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
    
    // Insertion Sort
    insertionSort(arr, len, MIN);
    print_arr(arr, len);
    
    insertionSort(arr, len, MAX);
    print_arr(arr, len);
    
    puts("");
    
    
    
    return 0;
}

