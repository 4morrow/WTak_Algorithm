//
//  스티커 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <cstdio>
#include <iostream>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MAX_SIZE 100005
using namespace std;

int n;
int stickers[2][MAX_SIZE];
int dp[MAX_SIZE][3];

void init() {
    for(int i=0; i<2; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            stickers[i][j] = 0;
        }
    }
    
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<3; j++) {
            dp[i][j] = -1;
        }
    }
}

int recursive(int c, int status) {
    if(c == n) return 0;
    if(dp[c][status] != -1) return dp[c][status];
    
    int result = recursive(c+1, 0);
    if(status != 1) result = MAX(result, recursive(c+1, 1) + stickers[0][c]);
    if(status != 2) result = MAX(result, recursive(c+1, 2) + stickers[1][c]);
    
    dp[c][status] = result;
    return result;
}


int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0; t<tc; t++) {
        init();
        scanf("%d",&n);
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d",&stickers[i][j]);
            }
        }
        printf("%d\n",recursive(0,0));
    }
    return 0;
}
