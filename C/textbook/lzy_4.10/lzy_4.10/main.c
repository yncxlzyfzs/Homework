//
//  main.c
//  lzy_4.10
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float pi = 0;
    int operator = 1;
    for (int i=1; 1.0/(2*i-1)>1e-5; i++) {
        pi += 1.0/(2*i-1) * operator;
        operator = -operator;
    }
    printf("pi = %f\n",4*pi);
    return 0;
}
