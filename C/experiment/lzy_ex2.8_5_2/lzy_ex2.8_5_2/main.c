//
//  main.c
//  lzy_ex2.8_5_2
//
//  Created by 赖志懿 on 15/6/11.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define STRLEN 30
int main(void) {
    char *(*p[2])(const char *,const char *);
    char s1[STRLEN],s2[STRLEN],*result;
    p[0] = strstr;
    p[1] = strpbrk;
    
    printf("use strstr\n");
    printf("Please input two strings: \n");
    scanf("%s %s",s1,s2);
    result = p[0](s1,s2);
    printf("first match: %c\n\n",*result);
    
    printf("use strpbrk\n");
    printf("Please input two strings:\n");
    scanf("%s %s",s1,s2);
    result = p[1](s1,s2);
    printf("first match: %c\n",*result);
    return 0;
}
