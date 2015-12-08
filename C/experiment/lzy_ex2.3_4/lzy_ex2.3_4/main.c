//
//  main.c
//  lzy_ex2.3_4
//
//  Created by 赖志懿 on 15/4/28.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define E 1e-6

float newton(float x);
float f(float x);
float df(float x);


int main(void) {
    printf("Answer is: %f",newton(0));
    return 0;
}

float newton(float x){
    static int first;
    float y;
    if (x==0 && first==0){
        first++;
        return newton(rand());
    }
    y=x-f(x)/df(x);
    if ((y-x>0 && y-x<=E) || (y-x<0 && x-y<=E)) {
        return y;
    }
    
    return newton(y);
}

float f(float x){
    return 3*x*x*x-4*x*x-5*x+13;
}

float df(float x){
    return 9*x*x-8*x-5;
}