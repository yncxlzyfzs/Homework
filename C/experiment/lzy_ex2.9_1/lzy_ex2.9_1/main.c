//
//  main.c
//  lzy_ex2.9_1
//
//  Created by 赖志懿 on 15/6/11.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

char u[]="UVWXYZ";
char v[]="xyz";
struct T{
    int x;
    char c;
    char *t;
}a[]={{11,'A',u},{100,'B',v}},*p=a;

int main(void) {
    int i;
    
    for (i=1; i<=6; i++) {
        p=a;
        printf("<%d> ",i);
        switch (i) {
            case 1:
                printf("%d\n",(++p)->x);
                break;
            case 2:
                printf("%c\n",(p++,p->c));
                break;
            case 3:
                printf("%c\n",(*p++->t,*p->t));
                break;
            case 4:
                printf("%c\n",(*(++p)->t));
                break;
            case 5:
                printf("%c\n",(*++p->t));
                p->t--;
                break;
            case 6:
                printf("%c\n",(++*p->t));
                break;
                
            default:
                printf("Error!\n");
                return 0;
                break;
        }
    }
    
    return 0;
}
