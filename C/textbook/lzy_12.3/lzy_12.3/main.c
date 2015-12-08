//
//  main.c
//  lzy_12.3
//
//  Created by 赖志懿 on 15/4/26.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void reverse(void);

int main(void) {
    printf("Please input a string : ");
    reverse();
    
    return 0;
}

void reverse(void){
    char a=getchar();
    if (a!='\n') {
        reverse();
        printf("%c",a);
    }
}