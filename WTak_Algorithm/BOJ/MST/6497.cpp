//
//  6497.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define SWAP(a,b,type) do{type temp; temp = a; a = b; b = temp;}while(0);
using namespace std;


typedef struct {
    int x,y,z;
}Edge;

// m : 집의 수 , n : 길의 수
int m,n;

// a : x번 집 , b : y번 집, c : z미터
int a,b,c;

// x,y : 임시 변수
int x,y;

// 구조체 배열
Edge adj[200005];

// 부모를 담는 배열
int p[200005];

// total : 전체 비용 ,  cost : 최소로 연결되는 비용
int total, cost, cnt;

bool cmp(Edge a, Edge b) {
    return a.z < b.z;
}

void init() {
    for(int i=0; i<200005; i++) {
        adj[i].x = adj[i].y = adj[i].z = 0;
        p[i] = 0;
    }
    total = cost = cnt = 0;
}


void quickSort(Edge *arr, int left, int right) {
    if(left > right) return;
    int L = left;
    int R = right;
    int mid = (L + R) / 2;
    int pivot = arr[mid].z;
    
    while(L<=R) {
        while(arr[L].z < pivot) L++;
        while(pivot < arr[R].z) R--;
        if(L<=R) {
            SWAP(arr[L],arr[R],Edge);
            L++;
            R--;
        }
    }
    if(L < right) quickSort(arr, L, right);
    if(left < R) quickSort(arr,left,R);
}

int Find(int a) {
    if(a == p[a]) return a;
    return p[a] = Find(p[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    p[a] = b;
}

int main() {
    
    while(scanf("%d %d",&m,&n)) {
        if(m == 0 && n == 0) break;
        init();
        for(int i=1; i<=m; i++) {
            p[i] = i;
        }
        
        for(int i=0; i<n; i++) {
            scanf("%d %d %d",&a,&b,&c);
            if(a == 0 && b == 0) break;
            adj[i].x = a; adj[i].y = b; adj[i].z = c;
            total += c;
        }
        
        quickSort(adj, 0, n-1);
        
        for(int i=0; i<n; i++) {
            Edge now = adj[i];
            x = Find(now.x);
            y = Find(now.y);
            cnt++;
            if(x != y) {
                Union(now.x,now.y);
                cost += now.z;
            }
            if(cnt == n-1) break;
        }
        
        printf("%d\n",total-cost);
    }
    return 0;
}
