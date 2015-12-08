//
//  main.c
//  lzy_ex2.4_2_1
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

long sum_fac(int n);

int main(void) {
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
    return 0;
}

long sum_fac(int n){
    static long s=0,fac=1;
    fac*=n;
    s+=fac;
    return s;
}