//
//  성적 정렬하기 알고리즘.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 2..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define SWAP(a,b,type) do{ type temp = a; a = b; b = temp; } while(0);
using namespace std;

typedef struct {
    char name[11];
    int kor;
    int eng;
    int math;
}Student;

int n;
Student stu[100005];

bool str_cmp(char *arr, char*brr) {
    while(*arr == *brr && *arr != '\0' && *brr != '\0') {
        arr++;
        brr++;
    }
    if(*arr < *brr) return 1;
    else return 0;
    
}

bool cmp(Student& u, Student& v) {
    if(u.kor == v.kor) {
        if(u.eng == v.eng) {
            if(u.math == v.math) {
                return str_cmp(u.name,v.name);
            }
            else
                return u.math > v.math;
        }
        else
            return u.eng < v.eng;
    }
    else
        return u.kor > v.kor;
}

void _qSort(Student *arr, int left, int right) {
    
    if(left > right) return;
    int L = left;
    int R = right;
    int mid = (left + right) / 2;
    Student pivot = arr[mid];
    
    while(L <= R) {
        while(cmp(arr[L],pivot)) L++;
        while(cmp(pivot,arr[R])) R--;
        if(L <= R) {
            SWAP(arr[L],arr[R],Student);
            L++;
            R--;
        }
    }
    if(left < R) _qSort(arr, left, R);
    if(L < right) _qSort(arr, L, right);
}




int  main() {
    scanf("%d",&n);
    
    for(int i=0; i<n; i++) {
        scanf("%s %d %d %d", stu[i].name, &stu[i].kor, &stu[i].eng, &stu[i].math);
    }
    
    _qSort(stu, 0, n-1);
    
    for(int i=0; i<n; i++) {
        printf("%s\n",stu[i].name);
    }
    return 0;
}
