//
//  main.c
//  lzy_ex2.5_3
//
//  Created by 赖志懿 on 15/5/14.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>                                              //导入stdio.h、assert.h
#include <assert.h>
#define R

int integer_fraction(float x);                                  //声明函数

int main(void) {
    float r,s;
    int s_integer=0;
    printf("input a number:");
    scanf("%f",&r);
#ifdef R
    s=3.14159*r*r;
    printf("area of round is:%f\n",s);
    s_integer=integer_fraction(s);
    printf("the integer fraction of area is %d\n",s_integer);
    assert((s-s_integer)<1.0);
#endif
    return 0;
}

int integer_fraction(float x){
    int i=x;
    return i;
}