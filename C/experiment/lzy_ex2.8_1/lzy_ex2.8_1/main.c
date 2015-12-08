//
//  main.c
//  lzy_ex2.8_1
//
//  Created by 赖志懿 on 15/6/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    float a,*p;
    p = &a;                         //为悬挂指针赋值
    scanf("%f",p);
    printf("%f\n",*p);
    return 0;
}
