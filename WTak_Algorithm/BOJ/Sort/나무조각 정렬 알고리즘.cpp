//
//  나무조각 정렬 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define SWAP(X,Y,type) do{ type temp = X; X =  Y; Y = temp; }while(0);
using namespace std;

int arr[5];


int main() {
    
    for(int i=0; i<5; i++) {
        scanf("%d",&arr[i]);
    }
    
    // Bubble Sort
    for(int i=4; i>=0; i--) {
        for(int j=0; j<i; j++) {
            if(arr[j] > arr[j+1]) {
                SWAP(arr[j],arr[j+1],int);
                for(int k=0; k<5; k++) {
                    printf("%d ",arr[k]);
                }
                puts("");
            }
        }
    }
        
    
    return 0;
}
