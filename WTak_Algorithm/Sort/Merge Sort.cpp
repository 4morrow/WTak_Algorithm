//
//  Merge Sort.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 28..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#define SWAP(a,b,type) {type temp; temp = a; a = b; b = temp;}while(0);
#define MAX_SIZE 10

enum {
    MIN,
    MAX
};

// 시간복잡도 최악의 경우에도 O(N*logN)

// 합병 과정에서 추가 배열을 사용하기 때문에 메모리 공간이 필요
// 퀵정렬은 시간복잡도 최악의 경우에 O(N^2)
// 합병정렬을 퀵정렬보다 성능이 전반적으로 떨어지고 데이터 크기만한 메모리 공간이 필요하지만
// 장점은 stable sort라는 것이다.

void merge(int *arr, int left, int mid, int right, int type) {
    int i,j,k;
    i = left;
    j = mid + 1;
    k = left;

    int temp[MAX_SIZE];
    
    // Min Merge Sort
    if(type == MIN) {
        // 두 개의 블록을 비교
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i];
                i++;
            }
            else{
                temp[k++] = arr[j];
                j++;
            }
        }
    }
    
    // Max Merge Sort
    else if(type == MAX) {
        while(i <= mid && j <= right) {
            if(arr[i] >= arr[j]) {
                temp[k++] = arr[i];
                i++;
            }
            else{
                temp[k++] = arr[j];
                j++;
            }
        }
    }
    
    // 남은 부분 처리
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    
    // 정렬 후 원본 배열에 복사
    for(int m=left; m<=right; m++) {
        arr[m] = temp[m];
    }
    
}

void mergeSort(int *arr, int left, int right, int type) {
    int mid;
    if(left < right) {
        
        // 절반으로 나누기 위한 mid값 찾기
        mid = (left + right) / 2;
        
        // 분할
        mergeSort(arr, left, mid, type);
        mergeSort(arr, mid+1, right, type);
        
        // 합병
        merge(arr, left, mid, right, type);
    }
}

void print_arr(int *arr, int len) {
    for(int i=0; i<len; i++) printf("%d ",arr[i]);
    puts("");
}


int main() {
    
    int arr[MAX_SIZE] = {6,3,4,1,8,2,5,9,0,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr,len);
    mergeSort(arr, 0, len-1, MIN);
    print_arr(arr,len);
    
    mergeSort(arr, 0, len-1, MAX);
    print_arr(arr, len);
    return 0;
}
