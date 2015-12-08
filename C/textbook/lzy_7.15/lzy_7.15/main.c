//
//  main.c
//  lzy_7.15
//
//  Created by 赖志懿 on 15/5/9.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int transform(char a[]);

int main(void) {
    char a[20];
    scanf("%s",a);
    
    printf("transformed : %d",transform(a));
    
    return 0;
}

int transform(char a[]){
    int n=0,i;
    
    for (i=0; a[i]!='\0'; i++) {
        if (a[i]<='f' && a[i]>='a') {
            n = n*16+10+a[i]-'a';
        }else{
            n = n*16+a[i]-'0';
        }
    }
    
    return n;
}