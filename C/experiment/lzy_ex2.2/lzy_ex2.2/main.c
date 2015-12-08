//
//  main.c
//  lzy_ex2.2
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define PI 3.14159//定义常量时加；会把；同时定义到符号里

int main( void ) {//void 和 main 之间少一个空格，一般main函数返回一个int值，改为int
    int f,newint;
    short p,k;
    double c,r,s;
    /*for task 1*/
    printf("Input Fahrenheit:");//中文双引号
    scanf("%d",&f);//f前需要加&
    c=5.0/9*(f-32);//要得到浮点数需要把5或9变成浮点数形式
    printf("\n%d(F)=%.2f(C)\n\n",f,c);
    /*for task 2*/
    printf("input the radius r:");
    scanf("%lf",&r);//把f改为lf
    s=PI*r*r;
    printf("\nThe acreage is %.2f\n\n",s);//删除&符号
    /*for task 3*/
    printf("input hex int k,p:");
    scanf("%hu%hu",&k,&p);//把x改为hu
    newint=(p&0xff00)|(k&0xff00)>>8;//未声明newint变量,把<<改成>>
    printf("new int=%d\n\n",newint);
    return 0;//增加return
}