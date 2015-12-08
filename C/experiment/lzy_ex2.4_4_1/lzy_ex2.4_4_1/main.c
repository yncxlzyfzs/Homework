//
//  main.c
//  lzy_ex2.4_4_1
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void Euclidean(int a, int b);

int main(void) {
    int a,b;
    printf("Please input two numbers: \n");
    scanf("%d %d",&a,&b);
    Euclidean(a, b);
    return 0;
}

void Euclidean(int a, int b){
    if (a%b==0) {
        printf("gcd = %d",b);
    }else{
        Euclidean(b, a%b);
    }
}