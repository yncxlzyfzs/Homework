//
//  main.c
//  lzy_ex2.4_1
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

long sum_fac(int n);//未声明函数

int main(void) {
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
    return 0;//把return移到main函数体内
}

long sum_fac(int n){//添加返回值类型long
    long s=0;
    int i;
    long fac=1;//给fac赋初始值1
    for(i=1;i<=n;i++){
        fac*=i;
        s+=fac;
    }//添加大括号
    return s;
}