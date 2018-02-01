//
//  2941.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 2. 1..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX_STRING_SIZE 105
using namespace std;

char str[MAX_STRING_SIZE];
int cnt;

int main() {
    
    // input string
    scanf("%s",str);
    
    // compare
    for(int i=0; str[i] != '\0'; i++) {
        
        if(str[i] == 'c') {
            if(str[i+1] == '=' || str[i+1] == '-') {
                i++;
            }
        }
        
        else if(str[i] == 'd') {
            if(str[i+1] == '-') {
                i++;
            }
            else if(str[i+1] == 'z' && str[i+2] == '=') {
                i+=2;
            }
        }
        
        else if(str[i] == 'l') {
            if(str[i+1] == 'j') {
                i++;
            }
        }
        
        else if(str[i] == 'n') {
            if(str[i+1] == 'j') {
                i++;
            }
        }
        
        else if(str[i] == 's') {
            if(str[i+1] == '=') {
                i++;
            }
        }
        
        else if(str[i] == 'z') {
            if(str[i+1] == '=') {
                i++;
            }
        }
        cnt++;
    }
    
    printf("%d\n",cnt);
    return 0;
}

