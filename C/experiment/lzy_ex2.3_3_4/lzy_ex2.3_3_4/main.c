//
//  main.c
//  lzy_ex2.3_3_4
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void reverse(void);

int main(void) {
    printf("Please input a integer: ");
    reverse();
    return 0;
}

void reverse(void){
    int c;
    c = getchar();
    if (c=='\n') return ;
    if ((c>='0' && c<='9')) {
        reverse();
        printf("%c",c);
        
        return ;
    }
    printf("\nEnter Error!\n");
}