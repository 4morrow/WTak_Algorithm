//
//  문명 전파 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 5..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int N,K;
int par[2005][2005];
int map[2005][2005];




int main() {
    int a,b;
    scanf("%d %d",&N,&K);
    for(int i=0; i<K; i++) {
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }
    
    for(int i=0; i<2005; i++) {
        for(int j=0; j<2005; j++) {
            
        }
    }
    
    
    
    return 0;
}
