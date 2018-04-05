//
//  단어정렬 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#define SWAP(X,Y,type) do{ type temp = X; X = Y; Y = temp;}while(0);
#define MAX_STRING_SIZE 55
using namespace std;

typedef struct {
    char word[MAX_STRING_SIZE];
    int length;
}Data;

int n;
Data str[20005];


int str_len(char *str) {
    int len=0;
    for(int i=0; str[i] != 0; i++) {
        len++;
    }
    return len;
}


bool str_cmp(char* arr, char* brr) {
    while(*arr == *brr && *arr != '\0' && *brr != '\0') {
        arr++;
        brr++;
    }
    if(*arr < *brr) return 1;
    else return 0;;
}


bool cmp(Data& u, Data& v) {
    if(u.length == v.length) {
        return str_cmp(u.word, v.word);
    }
    return u.length < v.length;
}


void quickSort(Data *arr, int left, int right) {
    if(left > right) return;
    int L = left;
    int R = right;
    int mid = (left + right) / 2;
    Data pivot = arr[mid];
    
    while(L <= R) {
        while(cmp(arr[L],pivot)) L++;
        while(cmp(pivot,arr[R])) R--;
        if(L<=R) {
            SWAP(arr[L], arr[R], Data);
            L++;
            R--;
        }
    }
    if(L < right) quickSort(arr, L, right);
    if(left < R) quickSort(arr,left,R);
}


int main() {
    scanf("%d",&n);
    
    for(int i=0; i<n; i++) {
        scanf("%s",str[i].word);
        str[i].length = str_len(str[i].word);
    }
    
    quickSort(str, 0, n-1);
    
    int i;
    for(i=0; i<n-1; i++) {
        if(cmp(str[i],str[i+1]))
        printf("%s\n",str[i].word);
    }
    printf("%s\n",str[i].word);
    
    return 0;
}
