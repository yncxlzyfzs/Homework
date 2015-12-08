//
//  main.c
//  lzy_ex2.2_2
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    int a,b;
    printf("Input two integers:");
    scanf("%d%d",&a,&b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("\na=%d,b=%d",a,b);
    return 0;
}
