//
//  9536.cpp
//  WTak_Algorithm
//
//  Created by WTak on 2018. 1. 31..
//  Copyright © 2018년 WTak. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX_RECORD_SIZE 10110
using namespace std;

// recording : 1.all 2.split
char allRecord[MAX_RECORD_SIZE];
char partRecord[105][105];


// animail crying : 1.info 2.split
char animalInfo[MAX_RECORD_SIZE];
char partAnimal[105][105];

// question
char question[105] = "what does the fox say?";

int pidx, aidx;

// string compare
int _strcmp(char *str1, char *str2) {
    int idx = 0;
    while (1) {
        if (str1[idx] == 0 && str2[idx] == 0) {
            return 1;
        }
        else if (str1[idx] != str2[idx]) return 0;
        idx++;
    }
}

// initialize
void init() {
    for(int i=0; i<MAX_RECORD_SIZE; i++) {
        allRecord[i] = '\0';
        animalInfo[i] = '\0';
    }
    
    for(int i=0; i<105; i++) {
        for(int j=0; j<105; j++) {
            partRecord[i][j] = '\0';
            partAnimal[i][j] = '\0';
        }
    }
    
}

void cryRecord() {
    getchar();
    scanf("%[^\n]",allRecord);
    //printf("%s\n",allRecord);
    
    pidx = 0; int j = 0;
    for(int i=0; allRecord[i] != 0; i++) {
        if(allRecord[i] != ' ') {
            partRecord[pidx][j++] = allRecord[i];
        }
        else {
            pidx++;
            j= 0;
        }
    }
    pidx++;
}

void cryCollect() {
    
    aidx = 0;
    while(1) {
        int j=0;
        int cnt = 0;
        getchar();
        scanf("%[^\n]", animalInfo);
        if(_strcmp(animalInfo,question)) break;
        else {
            for(int i=0; animalInfo[i] != 0; i++) {
                if(cnt == 2) {
                    partAnimal[aidx][j++] = animalInfo[i];
                }
                if(animalInfo[i] == ' ') cnt++;
            }
            aidx++;
        }
    }
}

void judge() {
    
    int i;
    for(i=0; i<pidx; i++) {
        bool ok = false;
        char *ptemp = partRecord[i];
        for(int j=0; j<aidx; j++) {
            char *atemp = partAnimal[j];
            if(_strcmp(ptemp,atemp)) {
                ok = true;
            }
        }
        if(!ok) {
            printf("%s ",partRecord[i]);
        }
    }
    puts("");
}


int main() {
    int testCase, tc;
    scanf("%d",&tc);
    for(testCase=0; testCase<tc; testCase++) {
        init();
        cryRecord();
        cryCollect();
        judge();
    }
    return 0;
}

