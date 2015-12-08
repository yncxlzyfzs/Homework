//
//  main.c
//  lzy_12.1
//
//  Created by 赖志懿 on 15/4/26.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

long Fibonacci(long n){
    static long a[1000];
    if (a[n]) {
        return a[n];
    }
    
    if (n==1 || n==2) {
        return 1;
    }else{
        return (a[n]=Fibonacci(n-1)+Fibonacci(n-2));
    }
}

int main(void) {
    printf("35 : %ld\n",Fibonacci(35));
    printf("40 : %ld\n",Fibonacci(40));
    printf("45 : %ld\n",Fibonacci(45));
    return 0;
}
