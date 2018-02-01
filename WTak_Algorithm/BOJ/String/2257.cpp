//
//  2257.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 31..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#define MAX_STRING_SIZE 105
using namespace std;

char str[MAX_STRING_SIZE];

stack<int> st;

int main() {
    scanf("%s",str);
    int ans = 0;
    for(int i=0; str[i] != 0; i++) {
       
        if(str[i] == 'H') {
            st.push(1);
        }
        else if(str[i] == 'C') {
            st.push(12);
        }
        else if(str[i] == 'O') {
            st.push(16);
        }
        else if('2'<= str[i] && str[i] <= '9') {
            int k = str[i] - '0';
            k *= st.top();
            st.pop();
            st.push(k);
        }
        else if(str[i] == '(') {
            st.push(-1);
        }
        else if(str[i] == ')') {
            int cnt = 0;
            while(1) {
                if(st.top() != -1) {
                    cnt += st.top();
                    st.pop();
                }
                else
                    break;
            }
            st.pop();
            st.push(cnt);
        }
    }
    
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    printf("%d\n",ans);
    
    return 0;
}
