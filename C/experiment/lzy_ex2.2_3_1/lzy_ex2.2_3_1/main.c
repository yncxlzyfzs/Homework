//
//  main.c
//  lzy_ex2.2_3_1
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    char c;
    printf("Please input a character:");
    scanf("%c",&c);
    if (c>='A' && c<='Z') {
        c-='A'-'a';
    }
    printf("c=%c",c);
    return 0;
}
