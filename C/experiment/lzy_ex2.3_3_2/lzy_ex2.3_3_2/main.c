//
//  main.c
//  lzy_ex2.3_3_2
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    char c,a[1000];
    int i;
    for (i=0; (c=getchar())!='\n'; i++) {
        a[i]=c;
        if (c==' ') {
            for (; (c=getchar())==' '; ){}
            a[++i]=c;
        }
    }
    for (i=0; a[i]!='\0'; i++) {
        printf("%c",a[i]);
    }
    return 0;
}
