//
//  main.c
//  lzy_ex2.4_5
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include "file.h"

int x,y;
char ch;

int main(void) {
    x=10;
    y=20;
    ch=getchar();
    printf("in file1 x=%d,y=%d,ch is %c\n",x,y,ch);
    func1();
    return 0;
}
