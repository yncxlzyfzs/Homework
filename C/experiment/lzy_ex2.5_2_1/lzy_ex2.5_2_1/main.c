//
//  main.c
//  lzy_ex2.5_2_1
//
//  Created by 赖志懿 on 15/5/14.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int max(int x,int y,int z);                                 //声明函数max和sum
float sum(float x,float y);

int main(void) {                                            //返回值从void改为int
    int a,b,c;
    float d,e;
    printf("Enter three integers:");
    scanf("%d,%d,%d",&a,&b,&c);
    printf("\nthe maximum of them is %d\n",max(a,b,c));
    printf("Enter two floating point numbers:");
    scanf("%f,%f",&d,&e);
    printf("\nthe sum of them is %f\n",sum(d,e));
    return 0;
}

int max(int x,int y,int z){
    int t;
    if (x>y)
        t=x;
    else
        t=y;
    if (t<z)
        t=z;
    return t;
}

float sum(float x,float y){
    return x+y;
}