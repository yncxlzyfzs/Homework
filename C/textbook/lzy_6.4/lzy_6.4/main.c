//
//  main.c
//  lzy_6.4
//
//  Created by 赖志懿 on 15/5/3.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define swap(x,y) x=x+y;y=x-y;x=x-y


int main(void) {
    int x=1,y=2;
    printf("%d %d\n",x,y);
    swap(x, y);
    printf("%d %d\n",x,y);
    return 0;
}
