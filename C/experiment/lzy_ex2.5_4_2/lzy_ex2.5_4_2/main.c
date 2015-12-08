//
//  main.c
//  lzy_ex2.5_4_2
//
//  Created by 赖志懿 on 15/5/14.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define CHANGE 0                                //CHANGE 0:原文输出    CHANGE 1:变换字母大小写

int main(void) {
    char c;
#if CHANGE                                      //CHANGE 1
    while ((c=getchar())!=EOF) {
        if (c>='a' && c<='z')
            putchar(c-('a'-'A'));
        else if (c>='A' && c<='Z')
            putchar(c+('a'-'A'));
        else
            putchar(c);
    }
#else                                           //CHANGE 0
    while ((c=getchar())!=EOF) {
        putchar(c);
    }
#endif
    return 0;
}
