//
//  1922.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 31..
//  Copyright © 2018년 WTak. All rights reserved.
//

/*
 //크루스칼 알고리즘
 
 #include <cstdio>
 #include <iostream>
 #include <algorithm>
 #define SWAP(a,b,type) do{type temp; temp = a; a = b; b = temp; }while(0);
 using namespace std;
 
 // 간선 정보 구조체
 typedef struct {
    int from, to, cost;
 }Edge;
 
 // 간선 배열
 Edge adj[100001];
 
 // 부모를 담는 배열
 int p[1001];
 
 
 void quicksort(Edge *arr, int left, int right) {
 
     if(left > right) return;
     int L = left;
     int R = right;
     int mid = (L + R) / 2;
     int pivot = arr[mid].cost;
 
     while(L <= R) {
     while(arr[L].cost < pivot) L++;
     while(pivot < arr[R].cost) R--;
     if(L<=R) {
         SWAP(arr[L],arr[R],Edge);
         L++;
         R--;
     }
 }
 
 if(L < right) quicksort(arr, L, right);
 if(left < R) quicksort(arr, left, R);
 }
 
 
 // Find 함수 (대표자를 찾는 함수)
 int Find(int a) {
     if(a == p[a])
        return a;
     else
        return p[a] = Find(p[a]);
 }
 
 // sorting 하기 위한 기준이 되는 함수
 bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
 }
 
 // union 함수 (하나로 합치는 함수)
 void Union(int a, int b) {
     a = Find(a);
     b = Find(b);
     p[a] = b;
 }
 
 int n,m,x,y;
 
 int main()
 {
 
     scanf("%d %d", &n, &m);
 
     // 처음에 자기 자신을 대표로 정한다.
     for (int i = 1; i <= n; i++)
        p[i] = i;
 
     // 각 간선에 대한 정보를 받는다.
     for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &adj[i].from, &adj[i].to, &adj[i].cost);
     }
 
     // 퀵 소트
     quicksort(adj, 0, m-1);
 
 
     int ans = 0;
 
     // Union - Find 과정
     for (int i = 0; i < m; i++) {
         Edge now = adj[i];
         // printf("path : %d %d %d\n",adj[i].from,adj[i].to,adj[i].cost);
         x = Find(now.from);
         y = Find(now.to);
         if (x != y) {
             Union(now.from, now.to);
             ans += now.cost;
         }
     }
 
     printf("%d\n", ans);
 
 
     return 0;
 }
 
 */



 // 우선순위 큐
 
 #include <cstdio>
 #include <iostream>
 #include <queue>
 using namespace std;
 
 int n,m,x,y;
 int p[1005];
 priority_queue<pair<int, pair<int, int>> > pq;
 
 int Find(int a) {
     if(a == p[a]) return a;
     else return p[a] = Find(p[a]);
 }
 
 void Union(int a, int b) {
     a = Find(a);
     b = Find(b);
     p[a] = b;
 }

void pqSort() {
    int ans = 0;
    int cnt = 0;
    while(!pq.empty()) {
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        int cost = -pq.top().first;
        //printf("pq : %d %d %d\n",now.from,now.to,now.cost);
        pq.pop();
        
        x = Find(from);
        y = Find(to);
        
        if(x != y) {
            cnt++;
            Union(from,to);
            ans += cost;
        }
        if(cnt == n-1) break;
    }
    printf("%d\n",ans);
}

int main() {
     int a,b,c;
     scanf("%d %d",&n,&m);
     for(int i=1; i<=n; i++) p[i] = i;
     for(int i=0; i<m; i++) {
         scanf("%d %d %d",&a,&b,&c);
         pq.push({-c,{a,b}});
     }
     pqSort();
     return 0;
 }
 

