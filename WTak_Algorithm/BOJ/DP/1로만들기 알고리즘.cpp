//
//  1로만들기 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define SWAP(X,Y,Type) do{ Type temp = a; a = b; b = temp;}while(0);
#define ABS(X)  ((X < 0) ? (-X) : (X))
#define MAX_SIZE 1000005
using namespace std;

int dp[MAX_SIZE];

void init1() {
    // DP테이블 초기화
    for(int i=0; i<MAX_SIZE; i++) {
        dp[i] = -1;
    }
}

void init2() {
    // DP테이블 초기화
    for(int i=0; i<MAX_SIZE; i++) {
        dp[i] = 1e9;
    }
}

// top - down
int recursion(int n) {
    if(n == 1)  return 0; // base case;
    if(dp[n] != -1) return dp[n];
    
    int result = recursion(n-1)+1;
    if(n%3 == 0) result = MIN(result,recursion(n/3)+1);
    if(n%2 == 0) result = MIN(result,recursion(n/2)+1);
    dp[n] = result;
    return result;
}

int main() {
    int n;
    scanf("%d",&n);
    init1();
    printf("%d\n",recursion(n));
    
    // bottom - up
    init2();
    
    dp[1] = 0;
    for(int i=1; i<n; i++) {
        dp[i+1] = MIN(dp[i+1],dp[i]+1);
        if(i*2 < MAX_SIZE) dp[i*2] = min(dp[i*2],dp[i]+1);
        if(i*3 < MAX_SIZE) dp[i*3] = min(dp[i*3],dp[i]+1);
    }
    printf("%d\n",dp[n]);

    return 0;
}
