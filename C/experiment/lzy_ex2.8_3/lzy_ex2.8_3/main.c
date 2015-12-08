//
//  main.c
//  lzy_ex2.8_3
//
//  Created by 赖志懿 on 15/6/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

char *mystrcpy(char *,char *);

int main(void) {
    char a[60],b[60]="there is a boat on the lake.";
    printf("%s\n",mystrcpy(a, b));
    
    return 0;
}

char *mystrcpy(char *s,char *t){
    char *p = s;
    while((*s++ = *t++) != '\0')
        ;
    return p;
}