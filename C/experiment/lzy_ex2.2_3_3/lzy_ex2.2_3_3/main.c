//
//  main.c
//  lzy_ex2.2_3_3
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define N 2147483648 //2的31次方

int main(void) {
    unsigned int ip;
    int i,x=0,y=128,count=0,a[4];
    printf("Please input your ip : ");
    scanf("%d",&ip);
    
    //每8位存入数组一次
    for (i=1; i<=32; i++) {
        if (ip/N) x += y;
        ip <<= 1;
        y /= 2;
        if (i%8 == 0) {
            a[count++] = x;
            x=0;
            y=128;
        }
    }
    
    //输出IP
    for (i=1; i<=4; i++) {
        printf("%d",a[4-i]);
        if (i<4) printf(".");
    }
    printf("\n");
    
    
    return 0;
}