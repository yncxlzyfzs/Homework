//
//  main.c
//  lzy_ex2.3_3_1
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    unsigned int n;
    printf("Please input your salary: ");
    scanf("%u",&n);
    if (n<1000) {
        printf("tax:%d",0);
    }else if(n<2000){
        printf("tax:%.2f",n*0.05);
    }else if(n<3000){
        printf("tax:%.2f",n*0.10);
    }else if(n<4000){
        printf("tax:%.2f",n*0.15);
    }else if(n<5000){
        printf("tax:%.2f",n*0.20);
    }else{
        printf("tax:%.2f",n*0.25);
    }
    return 0;
}
