//
//  1647.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 31..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define SWAP(a,b,type) do{ type temp; temp = a; a = b; b = temp; }while(0);
using namespace std;

typedef struct {
    int from, to, cost;
}Edge;

Edge adj[1000005];
int p[100005];
int n,m,x,y;


void quicksort(Edge *arr, int left, int right) {
    if(left > right) return;
    
    int L = left;
    int R = right;
    int mid = (left + right) / 2;
    int pivot = arr[mid].cost;
    
    while(L <= R) {
        while(arr[L].cost < pivot) L++;
        while(pivot < arr[R].cost) R--;
        if(L <= R) {
            SWAP(arr[L],arr[R],Edge);
            L++;
            R--;
        }
    }
    
    if(L < right) quicksort(arr, L, right);
    if(left < R) quicksort(arr,left,R);
}

int Find(int a) {
    if(a == p[a])
        return a;
    else
        return p[a] = Find(p[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    p[a] = b;
}


int main() {
    scanf("%d %d",&n,&m);
    
    // 자기 자신을 부모로 저장
    for(int i=1; i<=n; i++) {
        p[i] = i;
    }
    
    // 간선 정보 입력
    int total = 0;
    for(int i=0; i<m; i++) {
        scanf("%d %d %d",&adj[i].from,&adj[i].to,&adj[i].cost);
        total += adj[i].cost;
    }
    
    quicksort(adj, 0, m-1);
    
    int ans = 0;
    int tmp = 0;
    for(int i=0; i<m; i++) {
        Edge now = adj[i];
        //printf("path : %d %d %d\n",adj[i].from,adj[i].to,adj[i].cost);
        x = Find(now.from);
        y = Find(now.to);
        
        if (x != y) {
            tmp++;
            Union(now.from, now.to);
            ans += now.cost;
            if(tmp == n -2) break;
        }
    }
    printf("%d\n",ans);
}
