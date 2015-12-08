//
//  main.c
//  2.18
//
//  Created by 赖志懿 on 15/4/7.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int test(unsigned short x){
    unsigned short n=0,mask=1;
    for (int i=0; i<sizeof(x)-1; i++) {
        n=n^(x>>i);
    }
    printf("%d %d %d\n",n,(n&mask),x>>(sizeof(x)*4-1));
    if ((n&mask)^(x>>(sizeof(x)*4-1))) {
        return 0;
    }else{
        return 1;
    }
}

int main(void) {
    unsigned short n=129;
    printf("%d %d\n",n,test(n));
    if (test(n)) {
        printf("legal data\n");
    }else{
        printf("illegal data\n");
    }
    return 0;
}