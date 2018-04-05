//
//  팰린드롬 만들기 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 2..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
char name[51],head[30],tail[30],ans[51];
int alpha[26];
int main() {
    
    int odd = 0;
    char mid;
    
    scanf("%s",name);
    for(int i=0; name[i] != '\0'; i++) {
        alpha[name[i] - 'A']++;
    }
    
    for(int i=0; i<26; i++) {
        if((alpha[i] % 2) == 1) {
            odd++;
            mid = i + 65;
        }
    }
    
    if(odd > 1) {
        puts("I'm Sorry Hansoo");
        return 0;
    }
    
    int hidx=0;
    for(int i=0; i<26; i++) {
        for(;alpha[i] >= 2;) {
            head[hidx++] = i + 65;
            alpha[i] -= 2;
        }
    }
    
    int tidx=0;
    for(int i=hidx-1; i>=0; i--) {
        tail[tidx++] = head[i];
    }
    int k=0;
    for(int i=0; i<hidx; i++) {
        ans[k++] = head[i];
    }
    if(odd == 1) ans[k++] = mid;
    for(int i=0; i<tidx; i++) {
        ans[k++] = tail[i];
    }
    printf("%s\n",ans);
}
