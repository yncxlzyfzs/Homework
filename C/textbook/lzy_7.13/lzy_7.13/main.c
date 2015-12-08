//
//  main.c
//  lzy_7.13
//
//  Created by 赖志懿 on 15/5/9.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void mystrncpy(char s[],char t[], int n);

int main(void) {
    char s[20],t[]="Hello World!";
    mystrncpy(s,t,5);
    printf("s is : %s\n",s);
    return 0;
}


void mystrncpy(char s[],char t[], int n){
    int i;
    for (i=0; i<n; i++) {
        s[i]=t[i];
    }
    s[i+1]='\0';
}