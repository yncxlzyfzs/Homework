//
//  main.c
//  lzy_4.11
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b,m=1;
    printf("Please input two numbers : ");
    scanf("%d%d",&a,&b);
    if (a>b) {
        for (int i=2; i<=b; i++) {
            if (a%i==0 && b%i==0) {
                m=i;
            }
        }
    }else{
        for (int i=2; i<=a; i++) {
            if (a%i==0 && b%i==0) {
                m=i;
            }
        }
    }

    if (a%b == 0 || b%a == 0) {
        if (a>b) printf("%d %d",m,a);
        if (a<=b) printf("%d %d",m,b);
    }else{
        printf("%d %d\n",m,a*b/m/m);
    }
    return 0;
}
