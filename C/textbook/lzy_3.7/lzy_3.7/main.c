//
//  main.c
//  lzy_3.7
//
//  Created by 赖志懿 on 15/4/11.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    unsigned short k;
    scanf("%hu",&k);
    printf("%u\n",(k<<4)^(k>>4));
    return 0;
}
