//
//  공통 부분 문자열.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 20..
//  Copyright © 2018년 WTak. All rights reserved.
//


// substring
#include <stdio.h>
#include <iostream>
using namespace std;

int lcs[4005][4005];
char a[4005], b[4005];
int ans = 0;

int str_len(char* str) {
    int idx;
    for(idx=0; str[idx]!=0; idx++);
    return idx;
}

int main() {
    
    int la, lb;
    scanf("%s %s",a+1,b+1);
    la = str_len(a+1);
    lb = str_len(b+1);
    
    for(int i = 1; i <= la; i++) {
        for(int j = 1; j <= lb; j++) {
            if(a[i] == b[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if(ans < lcs[i][j]) ans = lcs[i][j];
            }
            else lcs[i][j] = 0;
        }
    }
   
    printf("%d\n", ans);

    
    
    return 0;
}
