//
//  가장 많은 글자 찾기 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 2..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

char str[5005];
int alpha[28];

/*
 abcdefgh
 abcdefgh
 iiijjj
*/

int main() {
    
    while(scanf("%s",str) != EOF) {
        
        for(int i=0; str[i] != '\0'; i++) {
            alpha[str[i] - 'a']++;
        }
        
    }
    
    int res = -1;
    int idx;
    for(int i=0; i<26; i++) {
        if(res < alpha[i]) {
            res = alpha[i];
        }
    }
    
    for(int i=0; i<26; i++) {
        if(res == alpha[i]) {
            printf("%c",i+97);
        }
    }
    puts("");
    
    return 0;
}
