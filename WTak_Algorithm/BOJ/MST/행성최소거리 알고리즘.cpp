//
//  2887.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 100005
using namespace std;

typedef long long ll;

// 익명 구조체 Data
typedef struct {
    int key;    //  행성의 좌표
    int idx;    //  행성의 index
}Data;


// 행성의 개수
int n;

// 행성의 X좌표,Y좌표,Z좌표 구조체 배열
Data A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE];

// 부모 배열
int p[MAX_SIZE];

// 우선순위 큐 (cost, (행성index, 행성index))
priority_queue< pair< int, pair<int,int> > > pq;

// 비교함수(sorting)
bool cmp(Data t, Data u) {
    return t.key < u.key;
}

// 부모를 찾는 함수
int Find(int a) {
    if(a == p[a]) return a;
    return p[a] = Find(p[a]);
}

// grouping 하는 함수
bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a == b) return false;
    p[a] = b;
    return true;
}

int main() {
    
    scanf("%d",&n);
    
    // 자기 자신을 부모로 intialize
    for(int i=0; i<=n; i++) p[i] = i;
    
    
    // X,Y,Z좌표를 담고있는 배열들의 정보를 입력
    int a,b,c;
    for(int i=0; i<n; i++) {
        scanf("%d %d %d",&a,&b,&c);
        A[i].key = a; A[i].idx = i;
        B[i].key = b; B[i].idx = i;
        C[i].key = c; C[i].idx = i;
    }
    
    // 오름차순으로 정렬
    sort(A,A+n,cmp);
    sort(B,B+n,cmp);
    sort(C,C+n,cmp);
    
    
    // 우선순위 큐에 넣어준다.
    // sorting을 오름차순으로 하고나면 단조증가의 형태를 지니게 된다.
    // 이 때, 좌표의 거리 차이는 앞과 뒤가 가장 가까울 수 밖에 없다.
    for(int i=0; i<n-1; i++) {
        pq.push({-(A[i+1].key - A[i].key),{A[i].idx, A[i+1].idx}});
        pq.push({-(B[i+1].key - B[i].key),{B[i].idx, B[i+1].idx}});
        pq.push({-(C[i+1].key - C[i].key),{C[i].idx, C[i+1].idx}});
    }
    
    int cnt=0;
    
    // 좌표는 -109보다 크거나 같고, 109보다 작거나 같은 정수
    // 그래서 비용은 int형의 자료형을 넘을 수 있어 long long으로 정의한다.
    ll ans=0;
    
    // Union - Find 과정
    while(!pq.empty()) {
        int z = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        if(Union(x,y)) {
            cnt++;
            ans += z;
        }
        if(cnt == n-1) break;
    }
    
    printf("%lld\n",ans);
    return 0;
}
