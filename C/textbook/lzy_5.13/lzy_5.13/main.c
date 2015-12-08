//
//  main.c
//  lzy_5.13
//
//  Created by 赖志懿 on 15/4/22.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int digit(int n,int k);

int main(void) {
    int n,k;
    printf("Please input two numbers : ");
    scanf("%d%d",&n,&k);
    printf("%d",digit(n, k));
    return 0;
}

int digit(int n,int k){
    int i,m=1,len;
    for (i=1; n/m!=0; i++) {
        m*=10;
    }
    len = i-1;
    if (k>len) {
        return -1;
    }else{
        for (i=1,m=1;i<=k;i++) m *= 10;
        return (n%m)/(m/10);
    }
}