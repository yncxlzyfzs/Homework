//
//  main.c
//  lzy_ex2.5_4_1
//
//  Created by 赖志懿 on 15/5/14.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define s(a,b,c) (a + b + c)/2
#define AREA(s,a,b,c) sqrt(s*(s - a)*(s - b)*(s - c))


int main(void) {
    int a,b,c;
    printf("Please input three edge of the triangle a b c : ");
    scanf("%d %d %d",&a,&b,&c);
    printf("area : %lf\n",AREA(s(a,b,c),a,b,c));
    return 0;
}
