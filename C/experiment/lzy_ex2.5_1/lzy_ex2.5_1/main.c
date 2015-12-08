//
//  main.c
//  lzy_ex2.5_1
//
//  Created by 赖志懿 on 15/5/14.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define SUM (a+b)                            //a+b和a-b需要加括号保护
#define DIF (a-b)
#define SWAP(a,b) a=a+b,b=a-b,a=a-b          //不能直接交换变量，需加中间变量或使用两者的和差关系来调换


int main(void) {
    int a,b;                                //变量定义错误，需要a和b，把t改为a
    printf("Input two integers a,b:");
    scanf("%d,%d",&a,&b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM,SUM*DIF);
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);        //函数名称错误，把P改为小写p
    return 0;
}
