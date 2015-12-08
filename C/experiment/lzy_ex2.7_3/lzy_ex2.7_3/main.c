//
//  main.c
//  lzy_ex2.7_3
//
//  Created by 赖志懿 on 15/5/21.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void my_strncat(char [],char [],int);

int main(void) {
    char a[50]="The adopted symbol is ",b[27]="abcdefghijklmnopqrstuvwxyz";
    my_strncat(a, b, 4);
    printf("%s\n",a);
    return 0;
}

void my_strncat(char s[],char t[],int n){
    int i=0,j;
    while (s[++i]);                 //i++ -> ++i
    for (j=0;j<n && t[j];)
        s[i++] = t[j++];
    s[i]='\0';
}