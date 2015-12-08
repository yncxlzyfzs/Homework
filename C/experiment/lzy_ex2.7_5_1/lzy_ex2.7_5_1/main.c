//
//  main.c
//  lzy_ex2.7_5_1
//
//  Created by 赖志懿 on 15/6/3.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 30

void strnins(char *, char *, int);

int main(void) {
    int n;
    char s[MAX_LEN],t[MAX_LEN];
    printf("Please input two string and insert number: \n");
    scanf("%s %s %d",s,t,&n);
    strnins(s, t, n);
    printf("%s\n",s);
    return 0;
}

void strnins(char *s, char *t, int n){
    int i,j;
    
    for (i=strlen(s)-1; i>=n; i--) {
        s[i+strlen(t)] = s[i];
    }
    
    for (j=0; j<strlen(t); j++) {
        *(s+n+j) = *(t+j);
    }
}