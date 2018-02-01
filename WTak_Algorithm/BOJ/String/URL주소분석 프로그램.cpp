//
//  6324.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 31..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX_ADDRESS_SIZE 65
using namespace std;

// address
char address[MAX_ADDRESS_SIZE];

// address num
int n;

// intialize
void init() {
    for(int i=0; i<MAX_ADDRESS_SIZE; i++) {
        address[i] = '\0';
    }
}

// Input address
void addressInput() {
    getchar();
    scanf("%[^\n]",address);
}

// split
void _split() {
    int i;
    printf("Protocol = ");
    for(i=0; address[i] != ':'; i++) {
        printf("%c",address[i]);
    }
    i+=3;
    printf("\n");
    printf("Host     = ");
    for(;address[i] != ':' && address[i] != '/' && address[i] != '\0'; i++) {
        printf("%c",address[i]);
    }
    printf("\n");
    printf("Port     = ");
    if(address[i] == ':') {
        i++;
        for(; address[i] != '/' && address[i] != '\0'; i++) {
            printf("%c",address[i]);
        }
    }
    else {
        printf("<default>");
    }
    printf("\n");
    printf("Path     = ");
    if(address[i] == '\0') {
        printf("<default>");
    }
    else {
        i++;
        for(;address[i] != '\0'; i++) {
            printf("%c",address[i]);
        }
    }
    printf("\n");
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        init();
        addressInput();
        printf("URL #%d\n",i+1);
        _split();
        if(i != n-1)
            puts("");
    }
    return 0;
}
